/*
 *  Phusion Passenger - https://www.phusionpassenger.com/
 *  Copyright (c) 2017-2025 Asynchronous B.V.
 *
 *  "Passenger", "Phusion Passenger" and "Union Station" are registered
 *  trademarks of Asynchronous B.V.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

/*
 * ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.cpp is automatically generated from
 * ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.cpp.cxxcodebuilder,
 * using ConfigGeneral/AutoGeneratedManifestDefaultsInitialization from src/ruby_supportlib/phusion_passenger/apache2/config_options.rb.
 * Edits to ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.cpp will be lost.
 *
 * To update ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.cpp:
 *   rake apache2
 *
 * To force regeneration of ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.cpp:
 *   rm -f src/apache2_module/ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.cpp
 *   rake src/apache2_module/ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.cpp
 */

#include "ManifestGeneration.h"

namespace Passenger {
namespace Apache2Module {


void
ConfigManifestGenerator::autoGenerated_setGlobalConfigDefaults() {
	Json::Value &globalConfigContainer = manifest["global_configuration"];

	addOptionsContainerDynamicDefault(
		globalConfigContainer,
		"PassengerDataBufferDir",
		P_STATIC_STRING("$TMPDIR, or if not given, /tmp"));

	addOptionsContainerDynamicDefault(
		globalConfigContainer,
		"PassengerDefaultGroup",
		P_STATIC_STRING("The primary group of PassengerDefaultUser"));

	addOptionsContainerStaticDefaultStr(
		globalConfigContainer,
		"PassengerDefaultRuby",
		DEFAULT_RUBY);

	addOptionsContainerStaticDefaultStr(
		globalConfigContainer,
		"PassengerDefaultUser",
		PASSENGER_DEFAULT_USER);

	addOptionsContainerStaticDefaultBool(
		globalConfigContainer,
		"PassengerDisableAnonymousTelemetry",
		false);

	addOptionsContainerStaticDefaultBool(
		globalConfigContainer,
		"PassengerDisableLogPrefix",
		false);

	addOptionsContainerStaticDefaultBool(
		globalConfigContainer,
		"PassengerDisableSecurityUpdateCheck",
		false);

	addOptionsContainerDynamicDefault(
		globalConfigContainer,
		"PassengerInstanceRegistryDir",
		P_STATIC_STRING("Either /var/run/passenger-instreg, $TMPDIR, or /tmp (see docs)"));

	addOptionsContainerDynamicDefault(
		globalConfigContainer,
		"PassengerLogFile",
		P_STATIC_STRING("Apache's global error log"));

	addOptionsContainerStaticDefaultInt(
		globalConfigContainer,
		"PassengerLogLevel",
		DEFAULT_LOG_LEVEL);

	addOptionsContainerStaticDefaultInt(
		globalConfigContainer,
		"PassengerMaxInstancesPerApp",
		0);

	addOptionsContainerStaticDefaultInt(
		globalConfigContainer,
		"PassengerMaxPoolSize",
		DEFAULT_MAX_POOL_SIZE);

	addOptionsContainerStaticDefaultBool(
		globalConfigContainer,
		"PassengerOldRouting",
		false);

	addOptionsContainerStaticDefaultInt(
		globalConfigContainer,
		"PassengerPoolIdleTime",
		DEFAULT_POOL_IDLE_TIME);

	addOptionsContainerStaticDefaultInt(
		globalConfigContainer,
		"PassengerResponseBufferHighWatermark",
		DEFAULT_RESPONSE_BUFFER_HIGH_WATERMARK);

	addOptionsContainerStaticDefaultBool(
		globalConfigContainer,
		"PassengerShowVersionInHeader",
		true);

	addOptionsContainerStaticDefaultInt(
		globalConfigContainer,
		"PassengerSocketBacklog",
		DEFAULT_SOCKET_BACKLOG);

	addOptionsContainerDynamicDefault(
		globalConfigContainer,
		"PassengerSpawnDir",
		P_STATIC_STRING("Either $TMPDIR or /tmp"));

	addOptionsContainerStaticDefaultInt(
		globalConfigContainer,
		"PassengerStatThrottleRate",
		DEFAULT_STAT_THROTTLE_RATE);

	addOptionsContainerStaticDefaultBool(
		globalConfigContainer,
		"PassengerTurbocaching",
		true);

	addOptionsContainerStaticDefaultBool(
		globalConfigContainer,
		"PassengerUserSwitching",
		true);

}

void
ConfigManifestGenerator::autoGenerated_setAppConfigDefaults() {
	Json::Value &defaultAppConfigContainer = manifest["default_application_configuration"];

	addOptionsContainerStaticDefaultInt(
		defaultAppConfigContainer,
		"PassengerAppConnectTimeout",
		DEFAULT_CONNECT_TIMEOUT);

	addOptionsContainerStaticDefaultStr(
		defaultAppConfigContainer,
		"PassengerAppEnv",
		P_STATIC_STRING("production"));

	addOptionsContainerDynamicDefault(
		defaultAppConfigContainer,
		"PassengerAppGroupName",
		P_STATIC_STRING("PassengerAppRoot plus PassengerAppEnv"));

	addOptionsContainerDynamicDefault(
		defaultAppConfigContainer,
		"PassengerAppLogFile",
		P_STATIC_STRING("PassengerLogFile"));

	addOptionsContainerDynamicDefault(
		defaultAppConfigContainer,
		"PassengerAppRoot",
		P_STATIC_STRING("Parent directory of the associated Apache virtual host's root directory"));

	addOptionsContainerDynamicDefault(
		defaultAppConfigContainer,
		"PassengerAppType",
		P_STATIC_STRING("Autodetected"));

	addOptionsContainerStaticDefaultStr(
		defaultAppConfigContainer,
		"PassengerDirectInstanceRequestAddress",
		P_STATIC_STRING("127.0.0.1"));

	addOptionsContainerStaticDefaultInt(
		defaultAppConfigContainer,
		"PassengerForceMaxConcurrentRequestsPerProcess",
		-1);

	addOptionsContainerDynamicDefault(
		defaultAppConfigContainer,
		"PassengerFriendlyErrorPages",
		P_STATIC_STRING("On if PassengerAppEnv is development, off otherwise"));

	addOptionsContainerDynamicDefault(
		defaultAppConfigContainer,
		"PassengerGroup",
		P_STATIC_STRING("See the user account sandboxing rules"));

	addOptionsContainerStaticDefaultBool(
		defaultAppConfigContainer,
		"PassengerLoadShellEnvvars",
		true);

	addOptionsContainerStaticDefaultInt(
		defaultAppConfigContainer,
		"PassengerLveMinUid",
		DEFAULT_LVE_MIN_UID);

	addOptionsContainerStaticDefaultInt(
		defaultAppConfigContainer,
		"PassengerMaxPreloaderIdleTime",
		DEFAULT_MAX_PRELOADER_IDLE_TIME);

	addOptionsContainerStaticDefaultInt(
		defaultAppConfigContainer,
		"PassengerMaxRequestQueueSize",
		DEFAULT_MAX_REQUEST_QUEUE_SIZE);

	addOptionsContainerStaticDefaultInt(
		defaultAppConfigContainer,
		"PassengerMaxRequests",
		0);

	addOptionsContainerStaticDefaultInt(
		defaultAppConfigContainer,
		"PassengerMinInstances",
		1);

	addOptionsContainerStaticDefaultStr(
		defaultAppConfigContainer,
		"PassengerNodejs",
		DEFAULT_NODEJS);

	addOptionsContainerStaticDefaultBool(
		defaultAppConfigContainer,
		"PassengerPreloadBundler",
		false);

	addOptionsContainerStaticDefaultStr(
		defaultAppConfigContainer,
		"PassengerPython",
		DEFAULT_PYTHON);

	addOptionsContainerStaticDefaultStr(
		defaultAppConfigContainer,
		"PassengerRestartDir",
		P_STATIC_STRING("tmp"));

	addOptionsContainerStaticDefaultStr(
		defaultAppConfigContainer,
		"PassengerRuby",
		StaticString());

	addOptionsContainerDynamicDefault(
		defaultAppConfigContainer,
		"PassengerSpawnMethod",
		P_STATIC_STRING("'smart' for Ruby apps, 'direct' for all other apps"));

	addOptionsContainerStaticDefaultInt(
		defaultAppConfigContainer,
		"PassengerStartTimeout",
		DEFAULT_START_TIMEOUT / 1000);

	addOptionsContainerDynamicDefault(
		defaultAppConfigContainer,
		"PassengerStartupFile",
		P_STATIC_STRING("Autodetected"));

	addOptionsContainerDynamicDefault(
		defaultAppConfigContainer,
		"PassengerUser",
		P_STATIC_STRING("See the user account sandboxing rules"));

}

void
ConfigManifestGenerator::autoGenerated_setLocationConfigDefaults() {
	Json::Value &defaultLocConfigContainer = manifest["default_location_configuration"];

	addOptionsContainerStaticDefaultBool(
		defaultLocConfigContainer,
		"PassengerAllowEncodedSlashes",
		false);

	addOptionsContainerStaticDefaultBool(
		defaultLocConfigContainer,
		"PassengerBufferResponse",
		false);

	addOptionsContainerStaticDefaultBool(
		defaultLocConfigContainer,
		"PassengerBufferUpload",
		true);

	addOptionsContainerStaticDefaultBool(
		defaultLocConfigContainer,
		"PassengerEnabled",
		true);

	addOptionsContainerStaticDefaultBool(
		defaultLocConfigContainer,
		"PassengerErrorOverride",
		false);

	addOptionsContainerStaticDefaultBool(
		defaultLocConfigContainer,
		"PassengerHighPerformance",
		false);

	addOptionsContainerStaticDefaultBool(
		defaultLocConfigContainer,
		"PassengerStickySessions",
		false);

	addOptionsContainerStaticDefaultStr(
		defaultLocConfigContainer,
		"PassengerStickySessionsCookieAttributes",
		DEFAULT_STICKY_SESSIONS_COOKIE_ATTRIBUTES);

	addOptionsContainerStaticDefaultStr(
		defaultLocConfigContainer,
		"PassengerStickySessionsCookieName",
		DEFAULT_STICKY_SESSIONS_COOKIE_NAME);

}



} // namespace Apache2Module
} // namespace Passenger
