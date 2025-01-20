#  Phusion Passenger - https://www.phusionpassenger.com/
#  Copyright (c) 2010-2025 Asynchronous B.V.
#
#  "Passenger", "Phusion Passenger" and "Union Station" are registered
#  trademarks of Asynchronous B.V.
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in
#  all copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
#  THE SOFTWARE.

PhusionPassenger.require_passenger_lib 'platform_info'

module PhusionPassenger

  module PlatformInfo
    def self.curl_flags
      result = `(curl-config --cflags) 2>/dev/null`.strip
      if result.empty?
        return nil
      else
        version = `curl-config --vernum`.strip
        if version >= '070c01'
          # Curl >= 7.12.1 supports curl_easy_reset()
          result << " -DHAS_CURL_EASY_RESET"
        end
        return result
      end
    end
    memoize :curl_flags

    def self.curl_libs
      result = `(curl-config --libs) 2>/dev/null`.strip
      if os_name_simple == "macosx"
        result << ' -framework Foundation -framework SystemConfiguration'
      end
      if result.empty?
        return nil
      else
        return result
      end
    end
    memoize :curl_libs

    def self.curl_supports_ssl?
      features = `(curl-config --feature) 2>/dev/null`
      return features =~ /SSL/
    end
    memoize :curl_supports_ssl?
  end

end # module PhusionPassenger
