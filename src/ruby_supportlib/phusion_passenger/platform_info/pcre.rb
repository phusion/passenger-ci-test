#  Phusion Passenger - https://www.phusionpassenger.com/
#  Copyright (c) 2021-2025 Asynchronous B.V.
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
PhusionPassenger.require_passenger_lib 'platform_info/operating_system'

module PhusionPassenger

  module PlatformInfo
    def self.pcre_extra_cflags
      cflags = ""
      if PlatformInfo.os_name_simple == "macosx"
        brew_path = "#{`/usr/bin/env -P /usr/local/bin:/opt/homebrew/bin brew --prefix pcre2`.strip}/include"
        if File.exist?(brew_path)
          # Use the one from Homebrew.
          cflags = "-I#{brew_path}"
        else
          # Use the one from Macports.
          cflags = "-I/opt/local/include"
        end
      end
      return "#{cflags} -DPCRE2_CODE_UNIT_WIDTH=8"
    end
    memoize :pcre_extra_cflags

    def self.pcre_extra_ldflags
      if PlatformInfo.os_name_simple == "macosx"
        brew_path = "#{`/usr/bin/env -P /usr/local/bin:/opt/homebrew/bin brew --prefix pcre2`.strip}/lib"
        if File.exist?(brew_path)
          # Use the one from Homebrew.
          "-L#{brew_path}"
        else
          # Use the one from Macports.
          "-L/opt/local/lib"
        end
      else
        ""
      end
    end
    memoize :pcre_extra_ldflags
  end

end # module PhusionPassenger
