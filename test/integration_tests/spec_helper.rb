source_root = File.expand_path(File.dirname(__FILE__) + "/../..")
Dir.chdir("#{source_root}/test")

require 'rubygems'
require 'json'
begin
  CONFIG = JSON.load(File.read('config.json'))
rescue Errno::ENOENT
  STDERR.puts "*** You do not have the file test/config.json. " <<
    "Please copy test/config.json.example to " <<
    "test/config.json, and edit it."
  exit 1
end

RSpec.configure do |config|
  config.expect_with(:rspec) do |c|
    c.syntax = [:should, :expect]
  end
end

$LOAD_PATH.unshift("#{source_root}/src/ruby_supportlib")
$LOAD_PATH.unshift("#{source_root}/test")

require 'phusion_passenger'
PhusionPassenger.locate_directories
require 'support/test_helper'

include TestHelper
