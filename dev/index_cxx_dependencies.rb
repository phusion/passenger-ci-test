#!/usr/bin/env ruby
require 'pp'

SEARCH_PATHS = [
  "src",
  "src/agent",
  "src/cxx_supportlib",
  "src/cxx_supportlib/vendor-copy",
  "src/cxx_supportlib/vendor-modified",
  "test/cxx"
]
SCAN_FILES = Dir[
  "src/**/*.{c,cpp,h,hpp}",
  "test/oxt/**/*.{c,cpp,h,hpp}",
  "test/cxx/**/*.{c,cpp,h,hpp}"
]
EXCLUDE_FILES = Dir[
  "src/cxx_supportlib/vendor-copy/**/*",
  "src/cxx_supportlib/vendor-modified/**/*"
]
EXCLUDE_FILES_INDEX = Hash[EXCLUDE_FILES.map { |v| [v, true] }]
EXCLUDE_NAMES = %w{
  string
  vector
  map
  list
  set
  exception
  utility
  stdexcept
  iterator
  iostream
  ostream
  sstream
  fstream
  algorithm
  iomanip
  ios
  memory
  new
  unordered_map
  typeinfo
  deque
  queue
  limits
  hash_map
  ext/hash_map
  cctype
  cassert
  cstdio
  cstdlib
  cstddef
  cstdarg
  cstring
  ctime
  csignal
  cmath
  cerrno
  climits

  stdio.h
  stdio_ext.h
  stdlib.h
  stdint.h
  stddef.h
  string.h
  limits.h
  ctype.h
  assert.h
  errno.h
  time.h
  alloca.h
  features.h
  cxxabi.h

  unistd.h
  signal.h
  pthread.h
  pwd.h
  port.h
  grp.h
  fcntl.h
  sched.h
  execinfo.h
  poll.h
  dirent.h
  utime.h
  libgen.h
  netdb.h
  Availability.h
  selinux/selinux.h
  BaseTsd.h
  libkern/OSAtomic.h

  httpd.h
  unixd.h
  nginx.h
  util_script.h
  ev++.h
  ev.h
  uv.h
  zlib.h
  version.h
}
EXCLUDE_NAMES_INDEX = Hash[EXCLUDE_NAMES.map { |v| [v, true] }]
EXCLUDE_NAME_REGEXP = %r{
  ^(
    sys/
    |mach/
    |netinet/
    |inet/
    |vm/
    |arpa/
    |linux/
    |tr1/
    |curl/
    |openssl/
    |CoreFoundation/
    |Security/
    |ruby
    |apr_
    |ap_
    |http_
    |ngx_
  ).+
}x

def extract_dependencies(source)
  result = []
  File.open(source, "r") do |f|
    f.each do |line|
      next if line !~ /^\s*#include (<.+?>|".+?")/

      raw_name = $1
      name = raw_name.gsub(/["<>]/, "")
      next if name_excluded?(name)

      if raw_name =~ /"(.+)"/
        dependency = search_include_file($1, File.dirname(source))
      elsif raw_name =~ /<(.+)>/
        dependency = search_include_file($1)
      else
        STDERR.puts "Warning: ignoring invalid include statement in #{source}: #{line.strip}"
        dependency = nil
      end

      if dependency
        if !EXCLUDE_FILES_INDEX.has_key?(dependency)
          result << dependency
        end
      else
        STDERR.puts "Warning: cannot find include file #{raw_name} (referenced from #{source})"
      end
    end
  end
  result.sort!
  result.uniq!
  result
end

def search_include_file(name, first_search_path = nil)
  if first_search_path
    search_paths = [first_search_path] + SEARCH_PATHS
  else
    search_paths = SEARCH_PATHS
  end
  search_paths.each do |path|
    if File.exist?("#{path}/#{name}")
      result = File.expand_path("#{path}/#{name}")
      result.sub!(/\A#{Regexp.escape(Dir.pwd)}\//, '')
      return result
    end
  end
  nil
end

def name_excluded?(name)
  EXCLUDE_NAMES_INDEX.has_key?(name) || EXCLUDE_NAME_REGEXP =~ name
end

def generate_basic_map
  result = {}
  (SCAN_FILES - EXCLUDE_FILES).each do |source_file|
    result[source_file] = extract_dependencies(source_file)
  end
  result
end

def gather_all_dependencies_recursively(source_file, basic_map, result)
  deps = basic_map[source_file]
  if deps
    deps.each do |dep|
      if !result[dep]
        result[dep] = true
        gather_all_dependencies_recursively(dep, basic_map, result)
      end
    end
  end
end

def generate_full_map_for(source_file, basic_map)
  gather_results = {}
  gather_all_dependencies_recursively(
    source_file, basic_map, gather_results)
  result = gather_results.keys
  result.sort!
  result
end

def generate_full_map(basic_map)
  result = {}
  basic_map.keys.sort.each do |source_file|
    result[source_file] = generate_full_map_for(source_file, basic_map)
  end
  result
end

result = generate_full_map(generate_basic_map)
puts "# Autogenerated by dev/index_cxx_dependencies.rb"
puts "CXX_DEPENDENCY_MAP ="
PP.pp(result, STDOUT, 1)
