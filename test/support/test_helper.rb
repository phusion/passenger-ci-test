# Clean Bundler environment variables. Otherwise we can't test against multiple Rails versions.
if defined?(Bundler)
  clean_env = nil
  if Bundler.method_defined?(:with_unbundled_env)
    Bundler.with_unbundled_env do
      clean_env = ENV.to_hash
    end
  else
    Bundler.with_clean_env do
      clean_env = ENV.to_hash
    end
  end
  ENV.replace(clean_env)
end

require 'fileutils'
require 'resolv'
require 'net/http'
require 'uri'
require 'rspec/collection_matchers'
require 'support/multipart'
PhusionPassenger.require_passenger_lib 'constants'
PhusionPassenger.require_passenger_lib 'debug_logging'
PhusionPassenger.require_passenger_lib 'platform_info/ruby'

# Module containing helper methods, to be included in unit tests.
module TestHelper
  ######## Stub helpers ########

  class Stub
    attr_reader :app_root
    attr_reader :full_app_root

    def self.use(name, app_root = nil)
      stub = new(name, app_root)
      begin
        yield stub
      ensure
        stub.destroy
      end
    end

    def initialize(name, app_root = nil)
      @name = name
      if !File.exist?(stub_source_dir)
        raise Errno::ENOENT, "Stub '#{name}' not found."
      end

      if app_root
        @app_root = app_root
        @full_app_root = File.expand_path(app_root)
        remove_dir_tree(@full_app_root)
        FileUtils.mkdir_p(@full_app_root)
      else
        identifier = name.gsub('/', '-')
        @app_root = Dir.mktmpdir(identifier, '/tmp')
        @full_app_root = @app_root
        # The tmp dir may have the sticky bit, resulting
        # in subdirectories to be automatically owned by
        # the root group. That will mess up various
        # permission tests, so we chown explicitly here.
        File.chown(Process.uid, Process.gid, @app_root)
      end
      copy_stub_contents
      system("chmod", "-R", "a+rw", @full_app_root)
      system("chmod", "a+x", @full_app_root)
    end

    def reset
      # Empty directory without removing the directory itself,
      # allowing processes with this directory as current working
      # directory to continue to function properly.
      files = Dir["#{@full_app_root}/*"]
      files |= Dir["#{@full_app_root}/.*"]
      files.delete("#{@full_app_root}/.")
      files.delete("#{@full_app_root}/..")
      FileUtils.chmod_R(0777, files)
      FileUtils.rm_rf(files)

      copy_stub_contents
      system("chmod", "-R", "a+rw", @full_app_root)
    end

    def move(new_app_root)
      File.rename(@full_app_root, new_app_root)
      @app_root = new_app_root
      @full_app_root = File.expand_path(new_app_root)
    end

    def destroy
      remove_dir_tree(@full_app_root)
    end

    def full_app_root
      File.expand_path(@app_root)
    end

    def public_file(name)
      return File.binread("#{@full_app_root}/public/#{name}")
    end

  private
    def stub_source_dir
      return "stub/#{@name}"
    end

    def copy_stub_contents
      FileUtils.cp_r("#{stub_source_dir}/.", @full_app_root)
    end
  end

  class RackStub < Stub
    def startup_file
      return "#{@full_app_root}/config.ru"
    end

  private
    def copy_stub_contents
      super
      if PhusionPassenger.build_system_dir
        build_system_dir = PhusionPassenger.build_system_dir
        if !File.exist?("#{@full_app_root}/Gemfile")
          FileUtils.cp("#{build_system_dir}/Gemfile", @full_app_root)
          FileUtils.cp("#{build_system_dir}/Gemfile.lock", @full_app_root)
          FileUtils.cp("#{build_system_dir}/passenger.gemspec", @full_app_root)
          FileUtils.mkdir("#{@full_app_root}/src/")
          FileUtils.cp_r("#{build_system_dir}/src/ruby_supportlib", "#{@full_app_root}/src/")
          if File.exist?("#{build_system_dir}/.bundle")
            FileUtils.cp_r("#{build_system_dir}/.bundle", @full_app_root)
          end
        end
      end
    end
  end

  class PythonStub < Stub
    def startup_file
      return "#{@full_app_root}/passenger_wsgi.py"
    end
  end

  class NodejsStub < Stub
    def startup_file
      return "#{@full_app_root}/app.js"
    end

    def copy_stub_contents
      super
      if !ENV['PASSENGER_TEST_NODE_MODULES_DIR'].to_s.empty?
        FileUtils.ln_s(ENV['PASSENGER_TEST_NODE_MODULES_DIR'],
          "#{@full_app_root}/node_modules")
      elsif PhusionPassenger.build_system_dir
        FileUtils.ln_s("#{PhusionPassenger.build_system_dir}/node_modules",
          "#{@full_app_root}/node_modules")
      end
    end
  end


  ######## HTTP helpers ########
  # Before using these methods, one must set the '@server' instance variable
  # and implement the start_web_server_if_necessary method.

  def get(uri)
    if @server.nil?
      raise "You must set the '@server' instance variable before get() can be used. For example, @server = 'http://mydomain.test/'"
    end
    start_web_server_if_necessary
    return Net::HTTP.get(URI.parse("#{@server}#{uri}"))
  end

  def get_response(uri)
    if @server.nil?
      raise "You must set the '@server' instance variable before get() can be used. For example, @server = 'http://mydomain.test/'"
    end
    start_web_server_if_necessary
    return Net::HTTP.get_response(URI.parse("#{@server}#{uri}"))
  end

  def post(uri, params = {})
    if @server.nil?
      raise "You must set the '@server' instance variable before get() can be used. For example, @server = 'http://mydomain.test/'"
    end
    start_web_server_if_necessary
    url = URI.parse("#{@server}#{uri}")
    if params.values.any? { |x| x.respond_to?(:read) }
      mp = Multipart::MultipartPost.new
      query, headers = mp.prepare_query(params)
      Net::HTTP.start(url.host, url.port) do |http|
        return http.post(url.path, query, headers).body
      end
    else
      return Net::HTTP.post_form(url, params).body
    end
  end

  def check_hosts_configuration
    begin
      ok = Resolv.getaddress("passenger.test") == "127.0.0.1"
      ok = ok && Resolv.getaddress("1.passenger.test") == "127.0.0.1"
    rescue Resolv::ResolvError, ArgumentError
      # There's a bug in Ruby 1.8.6-p287's resolv.rb library, which causes
      # an ArgumentError to be raised instead of ResolvError when resolving
      # failed.
      ok = false
    end
    if !ok
      message = "To run the integration test, you must update " <<
        "your hosts file.\n" <<
        "Please add these to your /etc/hosts:\n\n" <<
        "127.0.0.1 passenger.test\n" <<
        "127.0.0.1 1.passenger.test 2.passenger.test 3.passenger.test\n" <<
        "127.0.0.1 4.passenger.test 5.passenger.test 6.passenger.test\n" <<
        "127.0.0.1 7.passenger.test 8.passenger.test 9.passenger.test\n"
      if RUBY_PLATFORM =~ /darwin/
        message << "\n\nThen run:\n\n" <<
          "  dscacheutil -flushcache"
      end
      STDERR.puts "---------------------------"
      STDERR.puts message
      exit!
    end
  end


  ######## Other helpers ########

  def when_user_switching_possible
    if Process.euid == 0
      yield
    end
  end

  alias when_running_as_root when_user_switching_possible

  def when_not_running_as_root
    if Process.euid != 0
      yield
    end
  end

  def eventually(deadline_duration = 2, check_interval = 0.05)
    deadline = Time.now + deadline_duration
    while Time.now < deadline
      if yield
        return
      else
        sleep(check_interval)
      end
    end
    raise "Time limit exceeded"
  end

  def should_never_happen(deadline_duration = 1, check_interval = 0.05)
    deadline = Time.now + deadline_duration
    while Time.now < deadline
      if yield
        raise "That which shouldn't happen happened anyway"
      else
        sleep(check_interval)
      end
    end
  end

  def remove_dir_tree(dir)
    # FileUtils.chmod_R is susceptible to race conditions:
    # if another thread/process deletes a file just before
    # chmod_R has chmodded it, then chmod_R will raise an error.
    # Keep trying until a real error has been reached or until
    # chmod_R is done.
    done = false
    while !done
      begin
        FileUtils.chmod_R(0777, dir)
        done = true
      rescue Errno::ENOENT
        done = !File.exist?(dir)
      end
    end
    FileUtils.rm_rf(dir)
  end

  def spawn_process(*args)
    args.map! do |arg|
      arg.to_s
    end
    if Process.respond_to?(:spawn)
      return Process.spawn(*args)
    else
      return fork do
        exec(*args)
      end
    end
  end

  # Run a script in a Ruby subprocess. *args are program arguments to
  # pass to the script. Returns the script's stdout output.
  def run_script(code, *args)
    stdin_child, stdin_parent = IO.pipe
    stdout_parent, stdout_child = IO.pipe
    program_args = [PhusionPassenger::PlatformInfo.ruby_command, "-e",
      "eval(STDIN.read, binding, '(script)', 0)",
      PhusionPassenger::LIBDIR, *args]
    if Process.respond_to?(:spawn)
      program_args << {
        STDIN  => stdin_child,
        STDOUT => stdout_child,
        STDERR => STDERR,
        :close_others => true
      }
      pid = Process.spawn(*program_args)
    else
      pid = fork do
        stdin_parent.close
        stdout_parent.close
        STDIN.reopen(stdin_child)
        STDOUT.reopen(stdout_child)
        stdin_child.close
        stdout_child.close
        exec(*program_args)
      end
    end
    stdin_child.close
    stdout_child.close
    stdin_parent.write(
      %Q[require(ARGV.shift + "/phusion_passenger")
      #{code}])
    stdin_parent.close
    result = stdout_parent.read
    stdout_parent.close
    Process.waitpid(pid)
    return result
  rescue Exception
    Process.kill('SIGKILL', pid) if pid
    raise
  ensure
    [stdin_child, stdout_child, stdin_parent, stdout_parent].each do |io|
      io.close if io && !io.closed?
    end
    begin
      Process.waitpid(pid) if pid
    rescue Errno::ECHILD, Errno::ESRCH
    end
  end

  def inspect_server(name)
    instance = PhusionPassenger::AdminTools::ServerInstance.list.first
    if name
      instance.connect(:passenger_status) do
        return instance.send(name)
      end
    else
      return instance
    end
  end

  if "".respond_to?(:force_encoding)
    def binary_string(str)
      return str.force_encoding("binary")
    end
  else
    def binary_string(str)
      return str
    end
  end
end

File.class_eval do
  def self.prepend(filename, data)
    original_content = File.read(filename)
    File.open(filename, 'w') do |f|
      f.write(data)
      f.write(original_content)
    end
  end

  def self.append(filename, data)
    File.open(filename, 'a') do |f|
      f.write(data)
    end
  end

  def self.write(filename, content = nil)
    if block_given?
      content = yield File.read(filename)
    end
    File.open(filename, 'w') do |f|
      f.write(content)
    end
  end

  def self.touch(filename, timestamp = nil)
    File.open(filename, 'w').close
    File.utime(timestamp, timestamp, filename) if timestamp
  end

  def self.binread(filename)
    return File.read(filename)
  end if !respond_to?(:binread)
end
