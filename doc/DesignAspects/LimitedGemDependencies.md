# Limited gem dependencies

## Context

- We provide native packages (APT/YUM) for Passenger.
- Passenger has a bunch of tools (e.g. `bin/passenger-status`, `helper-scripts/backtrace-sanitizer.rb`, `helper-scripts/prespawn`) that are written in Ruby. When Passenger is natively packaged, we ensure that these tools run in the "system" Ruby.
- On Debian-based systems, the OS package repositories may supply multiple Ruby versions. So our native packaging can't assume a single Ruby version.

This raises the question of how to deal with Passenger's own gem dependencies. An analysis of possible strategies and their implications/tradeoffs:

1. If the OS package repositories supply dependent gems, then our native packages can depend on those directly.

   Drawbacks:

    - Limited selection of gems.

2. We package the gem dependencies ourselves. In addition, any dependency with native extensions must be packaged separately, once for each Ruby version installable through the native OS package repositories.

   Drawbacks:

    - More work for us.

3. We vendor the gem dependencies within the native packages. In addition, any dependency with native extensions must be vendored separately, once for each Ruby version installable through the native OS package repositories.

## Decision

We pick strategy 1.

## Consequences

- Any gems that the written-in-Ruby tools depend on, must either be available through OS repositories, or must be a Ruby standard library gem.
  - All such dependencies must be specified in the Passenger gemspec.
- Development-related Passenger Ruby code can depend on any gem, since they're not included in native packages.
  - All such dependencies must be specified in the Passenger Gemfile.

## See also

- [No gem activation during Ruby loader initialization](NoGemActivationDuringRubyLoaderInitialization.md)
- System Ruby runner (only used in Debian packages): `packaging/debian/debian_specs/passenger/passenger_system_ruby.c.erb`
