/*
 *  Phusion Passenger - https://www.phusionpassenger.com/
 *  Copyright (c) 2010-2025 Asynchronous B.V.
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
#ifndef _PASSENGER_APACHE2_MODULE_CONFIG_AUTOGENERATED_SETTER_FUNCS_CPP_
#define _PASSENGER_APACHE2_MODULE_CONFIG_AUTOGENERATED_SETTER_FUNCS_CPP_

#ifdef INTELLISENSE
	// These includes do nothing, but keep IntelliSense happy.
	#include <ap_config.h>
	#include <http_config.h>
	#include <http_log.h>
	#include "../Config.h"

	#ifdef APLOG_USE_MODULE
		extern "C" module AP_MODULE_DECLARE_DATA passenger_module;
		APLOG_USE_MODULE(passenger);
	#endif
#endif

namespace Passenger {
namespace Apache2Module {

/*
 * ConfigGeneral/AutoGeneratedSetterFuncs.cpp is automatically generated from
 * ConfigGeneral/AutoGeneratedSetterFuncs.cpp.cxxcodebuilder,
 * using definitions from src/ruby_supportlib/phusion_passenger/apache2/config_options.rb.
 * Edits to ConfigGeneral/AutoGeneratedSetterFuncs.cpp will be lost.
 *
 * To update ConfigGeneral/AutoGeneratedSetterFuncs.cpp:
 *   rake apache2
 *
 * To force regeneration of ConfigGeneral/AutoGeneratedSetterFuncs.cpp:
 *   rm -f src/apache2_module/ConfigGeneral/AutoGeneratedSetterFuncs.cpp
 *   rake src/apache2_module/ConfigGeneral/AutoGeneratedSetterFuncs.cpp
 */

static const char *
cmd_passenger_admin_panel_auth_type(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.adminPanelAuthTypeSourceFile = cmd->directive->filename;
	serverConfig.adminPanelAuthTypeSourceLine = cmd->directive->line_num;
	serverConfig.adminPanelAuthTypeExplicitlySet = true;
	serverConfig.adminPanelAuthType = arg;
	return NULL;
}

static const char *
cmd_passenger_admin_panel_password(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.adminPanelPasswordSourceFile = cmd->directive->filename;
	serverConfig.adminPanelPasswordSourceLine = cmd->directive->line_num;
	serverConfig.adminPanelPasswordExplicitlySet = true;
	serverConfig.adminPanelPassword = arg;
	return NULL;
}

static const char *
cmd_passenger_admin_panel_url(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.adminPanelUrlSourceFile = cmd->directive->filename;
	serverConfig.adminPanelUrlSourceLine = cmd->directive->line_num;
	serverConfig.adminPanelUrlExplicitlySet = true;
	serverConfig.adminPanelUrl = arg;
	return NULL;
}

static const char *
cmd_passenger_admin_panel_username(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.adminPanelUsernameSourceFile = cmd->directive->filename;
	serverConfig.adminPanelUsernameSourceLine = cmd->directive->line_num;
	serverConfig.adminPanelUsernameExplicitlySet = true;
	serverConfig.adminPanelUsername = arg;
	return NULL;
}

static const char *
cmd_passenger_allow_encoded_slashes(cmd_parms *cmd, void *pcfg, const char *arg) {
	DirConfig *config = (DirConfig *) pcfg;
	config->mAllowEncodedSlashesSourceFile = cmd->directive->filename;
	config->mAllowEncodedSlashesSourceLine = cmd->directive->line_num;
	config->mAllowEncodedSlashesExplicitlySet = true;
	config->mAllowEncodedSlashes =
		(arg != NULL) ?
		ENABLED :
		DISABLED;
	return NULL;
}

static const char *
cmd_passenger_analytics_log_group(cmd_parms *cmd, void *pcfg, const char *arg) {
	fprintf(stderr, "WARNING: The 'PassengerAnalyticsLogGroup' option is obsolete. Please remove this option from your configuration file.\n");
	fflush(stderr);
	return NULL;
}

static const char *
cmd_passenger_analytics_log_user(cmd_parms *cmd, void *pcfg, const char *arg) {
	fprintf(stderr, "WARNING: The 'PassengerAnalyticsLogUser' option is obsolete. Please remove this option from your configuration file.\n");
	fflush(stderr);
	return NULL;
}

static const char *
cmd_passenger_anonymous_telemetry_proxy(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.anonymousTelemetryProxySourceFile = cmd->directive->filename;
	serverConfig.anonymousTelemetryProxySourceLine = cmd->directive->line_num;
	serverConfig.anonymousTelemetryProxyExplicitlySet = true;
	serverConfig.anonymousTelemetryProxy = arg;
	return NULL;
}

static const char *
cmd_passenger_app_env(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mAppEnvSourceFile = cmd->directive->filename;
	config->mAppEnvSourceLine = cmd->directive->line_num;
	config->mAppEnvExplicitlySet = true;
	config->mAppEnv = arg;
	return NULL;
}

static const char *
cmd_passenger_app_group_name(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mAppGroupNameSourceFile = cmd->directive->filename;
	config->mAppGroupNameSourceLine = cmd->directive->line_num;
	config->mAppGroupNameExplicitlySet = true;
	config->mAppGroupName = arg;
	return NULL;
}

static const char *
cmd_passenger_app_root(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mAppRootSourceFile = cmd->directive->filename;
	config->mAppRootSourceLine = cmd->directive->line_num;
	config->mAppRootExplicitlySet = true;
	config->mAppRoot = arg;
	return NULL;
}

static const char *
cmd_passenger_app_start_command(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mAppStartCommandSourceFile = cmd->directive->filename;
	config->mAppStartCommandSourceLine = cmd->directive->line_num;
	config->mAppStartCommandExplicitlySet = true;
	config->mAppStartCommand = arg;
	return NULL;
}

static const char *
cmd_passenger_app_type(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mAppTypeSourceFile = cmd->directive->filename;
	config->mAppTypeSourceLine = cmd->directive->line_num;
	config->mAppTypeExplicitlySet = true;
	config->mAppType = arg;
	return NULL;
}

static const char *
cmd_passenger_buffer_response(cmd_parms *cmd, void *pcfg, const char *arg) {
	DirConfig *config = (DirConfig *) pcfg;
	config->mBufferResponseSourceFile = cmd->directive->filename;
	config->mBufferResponseSourceLine = cmd->directive->line_num;
	config->mBufferResponseExplicitlySet = true;
	config->mBufferResponse =
		(arg != NULL) ?
		ENABLED :
		DISABLED;
	return NULL;
}

static const char *
cmd_passenger_buffer_upload(cmd_parms *cmd, void *pcfg, const char *arg) {
	DirConfig *config = (DirConfig *) pcfg;
	config->mBufferUploadSourceFile = cmd->directive->filename;
	config->mBufferUploadSourceLine = cmd->directive->line_num;
	config->mBufferUploadExplicitlySet = true;
	config->mBufferUpload =
		(arg != NULL) ?
		ENABLED :
		DISABLED;
	return NULL;
}

static const char *
cmd_passenger_custom_error_page(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mCustomErrorPageSourceFile = cmd->directive->filename;
	config->mCustomErrorPageSourceLine = cmd->directive->line_num;
	config->mCustomErrorPageExplicitlySet = true;
	config->mCustomErrorPage = arg;
	return NULL;
}

static const char *
cmd_passenger_data_buffer_dir(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.dataBufferDirSourceFile = cmd->directive->filename;
	serverConfig.dataBufferDirSourceLine = cmd->directive->line_num;
	serverConfig.dataBufferDirExplicitlySet = true;
	serverConfig.dataBufferDir = arg;
	return NULL;
}

static const char *
cmd_passenger_default_group(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.defaultGroupSourceFile = cmd->directive->filename;
	serverConfig.defaultGroupSourceLine = cmd->directive->line_num;
	serverConfig.defaultGroupExplicitlySet = true;
	serverConfig.defaultGroup = arg;
	return NULL;
}

static const char *
cmd_passenger_default_ruby(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.defaultRubySourceFile = cmd->directive->filename;
	serverConfig.defaultRubySourceLine = cmd->directive->line_num;
	serverConfig.defaultRubyExplicitlySet = true;
	serverConfig.defaultRuby = arg;
	return NULL;
}

static const char *
cmd_passenger_default_user(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.defaultUserSourceFile = cmd->directive->filename;
	serverConfig.defaultUserSourceLine = cmd->directive->line_num;
	serverConfig.defaultUserExplicitlySet = true;
	serverConfig.defaultUser = arg;
	return NULL;
}

static const char *
cmd_passenger_direct_instance_request_address(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mDirectInstanceRequestAddressSourceFile = cmd->directive->filename;
	config->mDirectInstanceRequestAddressSourceLine = cmd->directive->line_num;
	config->mDirectInstanceRequestAddressExplicitlySet = true;
	config->mDirectInstanceRequestAddress = arg;
	return NULL;
}

static const char *
cmd_passenger_disable_anonymous_telemetry(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.disableAnonymousTelemetrySourceFile = cmd->directive->filename;
	serverConfig.disableAnonymousTelemetrySourceLine = cmd->directive->line_num;
	serverConfig.disableAnonymousTelemetryExplicitlySet = true;
	serverConfig.disableAnonymousTelemetry = arg != NULL;
	return NULL;
}

static const char *
cmd_passenger_disable_log_prefix(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.disableLogPrefixSourceFile = cmd->directive->filename;
	serverConfig.disableLogPrefixSourceLine = cmd->directive->line_num;
	serverConfig.disableLogPrefixExplicitlySet = true;
	serverConfig.disableLogPrefix = arg != NULL;
	return NULL;
}

static const char *
cmd_passenger_disable_security_update_check(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.disableSecurityUpdateCheckSourceFile = cmd->directive->filename;
	serverConfig.disableSecurityUpdateCheckSourceLine = cmd->directive->line_num;
	serverConfig.disableSecurityUpdateCheckExplicitlySet = true;
	serverConfig.disableSecurityUpdateCheck = arg != NULL;
	return NULL;
}

static const char *
cmd_passenger_dump_config_manifest(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.dumpConfigManifestSourceFile = cmd->directive->filename;
	serverConfig.dumpConfigManifestSourceLine = cmd->directive->line_num;
	serverConfig.dumpConfigManifestExplicitlySet = true;
	serverConfig.dumpConfigManifest = arg;
	return NULL;
}

static const char *
cmd_passenger_enabled(cmd_parms *cmd, void *pcfg, const char *arg) {
	DirConfig *config = (DirConfig *) pcfg;
	config->mEnabledSourceFile = cmd->directive->filename;
	config->mEnabledSourceLine = cmd->directive->line_num;
	config->mEnabledExplicitlySet = true;
	config->mEnabled =
		(arg != NULL) ?
		ENABLED :
		DISABLED;
	return NULL;
}

static const char *
cmd_passenger_error_override(cmd_parms *cmd, void *pcfg, const char *arg) {
	DirConfig *config = (DirConfig *) pcfg;
	config->mErrorOverrideSourceFile = cmd->directive->filename;
	config->mErrorOverrideSourceLine = cmd->directive->line_num;
	config->mErrorOverrideExplicitlySet = true;
	config->mErrorOverride =
		(arg != NULL) ?
		ENABLED :
		DISABLED;
	return NULL;
}

static const char *
cmd_passenger_file_descriptor_log_file(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.fileDescriptorLogFileSourceFile = cmd->directive->filename;
	serverConfig.fileDescriptorLogFileSourceLine = cmd->directive->line_num;
	serverConfig.fileDescriptorLogFileExplicitlySet = true;
	serverConfig.fileDescriptorLogFile = arg;
	return NULL;
}

static const char *
cmd_passenger_force_max_concurrent_requests_per_process(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mForceMaxConcurrentRequestsPerProcessSourceFile = cmd->directive->filename;
	config->mForceMaxConcurrentRequestsPerProcessSourceLine = cmd->directive->line_num;
	config->mForceMaxConcurrentRequestsPerProcessExplicitlySet = true;
	return setIntConfig(cmd, arg, config->mForceMaxConcurrentRequestsPerProcess);
}

static const char *
cmd_passenger_friendly_error_pages(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mFriendlyErrorPagesSourceFile = cmd->directive->filename;
	config->mFriendlyErrorPagesSourceLine = cmd->directive->line_num;
	config->mFriendlyErrorPagesExplicitlySet = true;
	config->mFriendlyErrorPages =
		(arg != NULL) ?
		ENABLED :
		DISABLED;
	return NULL;
}

static const char *
cmd_passenger_group(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mGroupSourceFile = cmd->directive->filename;
	config->mGroupSourceLine = cmd->directive->line_num;
	config->mGroupExplicitlySet = true;
	config->mGroup = arg;
	return NULL;
}

static const char *
cmd_passenger_high_performance(cmd_parms *cmd, void *pcfg, const char *arg) {
	DirConfig *config = (DirConfig *) pcfg;
	config->mHighPerformanceSourceFile = cmd->directive->filename;
	config->mHighPerformanceSourceLine = cmd->directive->line_num;
	config->mHighPerformanceExplicitlySet = true;
	config->mHighPerformance =
		(arg != NULL) ?
		ENABLED :
		DISABLED;
	return NULL;
}

static const char *
cmd_passenger_instance_registry_dir(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.instanceRegistryDirSourceFile = cmd->directive->filename;
	serverConfig.instanceRegistryDirSourceLine = cmd->directive->line_num;
	serverConfig.instanceRegistryDirExplicitlySet = true;
	serverConfig.instanceRegistryDir = arg;
	return NULL;
}

static const char *
cmd_passenger_load_shell_envvars(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mLoadShellEnvvarsSourceFile = cmd->directive->filename;
	config->mLoadShellEnvvarsSourceLine = cmd->directive->line_num;
	config->mLoadShellEnvvarsExplicitlySet = true;
	config->mLoadShellEnvvars =
		(arg != NULL) ?
		ENABLED :
		DISABLED;
	return NULL;
}

static const char *
cmd_passenger_log_file(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.logFileSourceFile = cmd->directive->filename;
	serverConfig.logFileSourceLine = cmd->directive->line_num;
	serverConfig.logFileExplicitlySet = true;
	serverConfig.logFile = arg;
	return NULL;
}

static const char *
cmd_passenger_log_level(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.logLevelSourceFile = cmd->directive->filename;
	serverConfig.logLevelSourceLine = cmd->directive->line_num;
	serverConfig.logLevelExplicitlySet = true;
	return setIntConfig(cmd, arg, serverConfig.logLevel, 0);
}

static const char *
cmd_passenger_lve_min_uid(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mLveMinUidSourceFile = cmd->directive->filename;
	config->mLveMinUidSourceLine = cmd->directive->line_num;
	config->mLveMinUidExplicitlySet = true;
	return setIntConfig(cmd, arg, config->mLveMinUid, 0);
}

static const char *
cmd_passenger_max_instances_per_app(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.maxInstancesPerAppSourceFile = cmd->directive->filename;
	serverConfig.maxInstancesPerAppSourceLine = cmd->directive->line_num;
	serverConfig.maxInstancesPerAppExplicitlySet = true;
	return setIntConfig(cmd, arg, serverConfig.maxInstancesPerApp, 0);
}

static const char *
cmd_passenger_max_pool_size(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.maxPoolSizeSourceFile = cmd->directive->filename;
	serverConfig.maxPoolSizeSourceLine = cmd->directive->line_num;
	serverConfig.maxPoolSizeExplicitlySet = true;
	return setIntConfig(cmd, arg, serverConfig.maxPoolSize, 1);
}

static const char *
cmd_passenger_max_preloader_idle_time(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mMaxPreloaderIdleTimeSourceFile = cmd->directive->filename;
	config->mMaxPreloaderIdleTimeSourceLine = cmd->directive->line_num;
	config->mMaxPreloaderIdleTimeExplicitlySet = true;
	return setIntConfig(cmd, arg, config->mMaxPreloaderIdleTime, 0);
}

static const char *
cmd_passenger_max_request_queue_size(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mMaxRequestQueueSizeSourceFile = cmd->directive->filename;
	config->mMaxRequestQueueSizeSourceLine = cmd->directive->line_num;
	config->mMaxRequestQueueSizeExplicitlySet = true;
	return setIntConfig(cmd, arg, config->mMaxRequestQueueSize, 0);
}

static const char *
cmd_passenger_max_requests(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mMaxRequestsSourceFile = cmd->directive->filename;
	config->mMaxRequestsSourceLine = cmd->directive->line_num;
	config->mMaxRequestsExplicitlySet = true;
	return setIntConfig(cmd, arg, config->mMaxRequests, 0);
}

static const char *
cmd_passenger_meteor_app_settings(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mMeteorAppSettingsSourceFile = cmd->directive->filename;
	config->mMeteorAppSettingsSourceLine = cmd->directive->line_num;
	config->mMeteorAppSettingsExplicitlySet = true;
	config->mMeteorAppSettings = arg;
	return NULL;
}

static const char *
cmd_passenger_min_instances(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mMinInstancesSourceFile = cmd->directive->filename;
	config->mMinInstancesSourceLine = cmd->directive->line_num;
	config->mMinInstancesExplicitlySet = true;
	return setIntConfig(cmd, arg, config->mMinInstances, 0);
}

static const char *
cmd_passenger_monitor_log_file(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mMonitorLogFileSourceFile = cmd->directive->filename;
	config->mMonitorLogFileSourceLine = cmd->directive->line_num;
	config->mMonitorLogFileExplicitlySet = true;
	config->mMonitorLogFile.insert(arg);
	return NULL;
}

static const char *
cmd_passenger_nodejs(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mNodejsSourceFile = cmd->directive->filename;
	config->mNodejsSourceLine = cmd->directive->line_num;
	config->mNodejsExplicitlySet = true;
	config->mNodejs = arg;
	return NULL;
}

static const char *
cmd_passenger_old_routing(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.oldRoutingSourceFile = cmd->directive->filename;
	serverConfig.oldRoutingSourceLine = cmd->directive->line_num;
	serverConfig.oldRoutingExplicitlySet = true;
	serverConfig.oldRouting = arg != NULL;
	return NULL;
}

static const char *
cmd_passenger_pool_idle_time(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.poolIdleTimeSourceFile = cmd->directive->filename;
	serverConfig.poolIdleTimeSourceLine = cmd->directive->line_num;
	serverConfig.poolIdleTimeExplicitlySet = true;
	return setIntConfig(cmd, arg, serverConfig.poolIdleTime, 0);
}

static const char *
cmd_passenger_pre_start(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.prestartURLsSourceFile = cmd->directive->filename;
	serverConfig.prestartURLsSourceLine = cmd->directive->line_num;
	serverConfig.prestartURLsExplicitlySet = true;
	serverConfig.prestartURLs.insert(arg);
	return NULL;
}

static const char *
cmd_passenger_preload_bundler(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mPreloadBundlerSourceFile = cmd->directive->filename;
	config->mPreloadBundlerSourceLine = cmd->directive->line_num;
	config->mPreloadBundlerExplicitlySet = true;
	config->mPreloadBundler =
		(arg != NULL) ?
		ENABLED :
		DISABLED;
	return NULL;
}

static const char *
cmd_passenger_python(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mPythonSourceFile = cmd->directive->filename;
	config->mPythonSourceLine = cmd->directive->line_num;
	config->mPythonExplicitlySet = true;
	config->mPython = arg;
	return NULL;
}

static const char *
cmd_passenger_response_buffer_high_watermark(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.responseBufferHighWatermarkSourceFile = cmd->directive->filename;
	serverConfig.responseBufferHighWatermarkSourceLine = cmd->directive->line_num;
	serverConfig.responseBufferHighWatermarkExplicitlySet = true;
	return setIntConfig(cmd, arg, serverConfig.responseBufferHighWatermark, 0);
}

static const char *
cmd_passenger_restart_dir(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mRestartDirSourceFile = cmd->directive->filename;
	config->mRestartDirSourceLine = cmd->directive->line_num;
	config->mRestartDirExplicitlySet = true;
	config->mRestartDir = arg;
	return NULL;
}

static const char *
cmd_passenger_root(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.rootSourceFile = cmd->directive->filename;
	serverConfig.rootSourceLine = cmd->directive->line_num;
	serverConfig.rootExplicitlySet = true;
	serverConfig.root = arg;
	return NULL;
}

static const char *
cmd_passenger_ruby(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mRubySourceFile = cmd->directive->filename;
	config->mRubySourceLine = cmd->directive->line_num;
	config->mRubyExplicitlySet = true;
	config->mRuby = arg;
	return NULL;
}

static const char *
cmd_passenger_security_update_check_proxy(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.securityUpdateCheckProxySourceFile = cmd->directive->filename;
	serverConfig.securityUpdateCheckProxySourceLine = cmd->directive->line_num;
	serverConfig.securityUpdateCheckProxyExplicitlySet = true;
	serverConfig.securityUpdateCheckProxy = arg;
	return NULL;
}

static const char *
cmd_passenger_show_version_in_header(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.showVersionInHeaderSourceFile = cmd->directive->filename;
	serverConfig.showVersionInHeaderSourceLine = cmd->directive->line_num;
	serverConfig.showVersionInHeaderExplicitlySet = true;
	serverConfig.showVersionInHeader = arg != NULL;
	return NULL;
}

static const char *
cmd_passenger_socket_backlog(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.socketBacklogSourceFile = cmd->directive->filename;
	serverConfig.socketBacklogSourceLine = cmd->directive->line_num;
	serverConfig.socketBacklogExplicitlySet = true;
	return setIntConfig(cmd, arg, serverConfig.socketBacklog, 0);
}

static const char *
cmd_passenger_spawn_dir(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.spawnDirSourceFile = cmd->directive->filename;
	serverConfig.spawnDirSourceLine = cmd->directive->line_num;
	serverConfig.spawnDirExplicitlySet = true;
	serverConfig.spawnDir = arg;
	return NULL;
}

static const char *
cmd_passenger_start_timeout(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mStartTimeoutSourceFile = cmd->directive->filename;
	config->mStartTimeoutSourceLine = cmd->directive->line_num;
	config->mStartTimeoutExplicitlySet = true;
	return setIntConfig(cmd, arg, config->mStartTimeout, 1);
}

static const char *
cmd_passenger_startup_file(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mStartupFileSourceFile = cmd->directive->filename;
	config->mStartupFileSourceLine = cmd->directive->line_num;
	config->mStartupFileExplicitlySet = true;
	config->mStartupFile = arg;
	return NULL;
}

static const char *
cmd_passenger_stat_throttle_rate(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.statThrottleRateSourceFile = cmd->directive->filename;
	serverConfig.statThrottleRateSourceLine = cmd->directive->line_num;
	serverConfig.statThrottleRateExplicitlySet = true;
	return setIntConfig(cmd, arg, serverConfig.statThrottleRate);
}

static const char *
cmd_passenger_sticky_sessions(cmd_parms *cmd, void *pcfg, const char *arg) {
	DirConfig *config = (DirConfig *) pcfg;
	config->mStickySessionsSourceFile = cmd->directive->filename;
	config->mStickySessionsSourceLine = cmd->directive->line_num;
	config->mStickySessionsExplicitlySet = true;
	config->mStickySessions =
		(arg != NULL) ?
		ENABLED :
		DISABLED;
	return NULL;
}

static const char *
cmd_passenger_sticky_sessions_cookie_attributes(cmd_parms *cmd, void *pcfg, const char *arg) {
	DirConfig *config = (DirConfig *) pcfg;
	config->mStickySessionsCookieAttributesSourceFile = cmd->directive->filename;
	config->mStickySessionsCookieAttributesSourceLine = cmd->directive->line_num;
	config->mStickySessionsCookieAttributesExplicitlySet = true;
	config->mStickySessionsCookieAttributes = arg;
	return NULL;
}

static const char *
cmd_passenger_sticky_sessions_cookie_name(cmd_parms *cmd, void *pcfg, const char *arg) {
	DirConfig *config = (DirConfig *) pcfg;
	config->mStickySessionsCookieNameSourceFile = cmd->directive->filename;
	config->mStickySessionsCookieNameSourceLine = cmd->directive->line_num;
	config->mStickySessionsCookieNameExplicitlySet = true;
	config->mStickySessionsCookieName = arg;
	return NULL;
}

static const char *
cmd_passenger_turbocaching(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.turbocachingSourceFile = cmd->directive->filename;
	serverConfig.turbocachingSourceLine = cmd->directive->line_num;
	serverConfig.turbocachingExplicitlySet = true;
	serverConfig.turbocaching = arg != NULL;
	return NULL;
}

static const char *
cmd_passenger_use_global_queue(cmd_parms *cmd, void *pcfg, const char *arg) {
	fprintf(stderr, "WARNING: The 'PassengerUseGlobalQueue' option is obsolete: global queueing is now always turned on. Please remove this option from your configuration file.\n");
	fflush(stderr);
	return NULL;
}

static const char *
cmd_passenger_user(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, NOT_IN_FILES);
	if (err != NULL) {
		return err;
	}

	DirConfig *config = (DirConfig *) pcfg;
	config->mUserSourceFile = cmd->directive->filename;
	config->mUserSourceLine = cmd->directive->line_num;
	config->mUserExplicitlySet = true;
	config->mUser = arg;
	return NULL;
}

static const char *
cmd_passenger_user_switching(cmd_parms *cmd, void *pcfg, const char *arg) {
	const char *err = ap_check_cmd_context(cmd, GLOBAL_ONLY);
	if (err != NULL) {
		ap_log_perror(APLOG_MARK, APLOG_STARTUP, 0, cmd->temp_pool,
			"WARNING: %s", err);
	}

	serverConfig.userSwitchingSourceFile = cmd->directive->filename;
	serverConfig.userSwitchingSourceLine = cmd->directive->line_num;
	serverConfig.userSwitchingExplicitlySet = true;
	serverConfig.userSwitching = arg != NULL;
	return NULL;
}

static const char *
cmd_rails_allow_mod_rewrite(cmd_parms *cmd, void *pcfg, const char *arg) {
	fprintf(stderr, "WARNING: The 'RailsAllowModRewrite' option is obsolete: Phusion Passenger(R) now fully supports mod_rewrite. Please remove this option from your configuration file.\n");
	fflush(stderr);
	return NULL;
}

static const char *
cmd_rails_framework_spawner_idle_time(cmd_parms *cmd, void *pcfg, const char *arg) {
	fprintf(stderr, "WARNING: The 'RailsFrameworkSpawnerIdleTime' option is obsolete. Please use 'PassengerMaxPreloaderIdleTime' instead.\n");
	fflush(stderr);
	return NULL;
}

static const char *
cmd_rails_spawn_server(cmd_parms *cmd, void *pcfg, const char *arg) {
	fprintf(stderr, "WARNING: The 'RailsSpawnServer' option is obsolete. Please specify 'PassengerRoot' instead. The correct value was given to you by 'passenger-install-apache2-module'.\n");
	fflush(stderr);
	return NULL;
}

static const char *
cmd_union_station_filter(cmd_parms *cmd, void *pcfg, const char *arg) {
	fprintf(stderr, "WARNING: The 'UnionStationFilter' option is obsolete. Please remove this option from your configuration file.\n");
	fflush(stderr);
	return NULL;
}

static const char *
cmd_union_station_gateway_address(cmd_parms *cmd, void *pcfg, const char *arg) {
	fprintf(stderr, "WARNING: The 'UnionStationGatewayAddress' option is obsolete. Please remove this option from your configuration file.\n");
	fflush(stderr);
	return NULL;
}

static const char *
cmd_union_station_gateway_cert(cmd_parms *cmd, void *pcfg, const char *arg) {
	fprintf(stderr, "WARNING: The 'UnionStationGatewayCert' option is obsolete. Please remove this option from your configuration file.\n");
	fflush(stderr);
	return NULL;
}

static const char *
cmd_union_station_gateway_port(cmd_parms *cmd, void *pcfg, const char *arg) {
	fprintf(stderr, "WARNING: The 'UnionStationGatewayPort' option is obsolete. Please remove this option from your configuration file.\n");
	fflush(stderr);
	return NULL;
}

static const char *
cmd_union_station_key(cmd_parms *cmd, void *pcfg, const char *arg) {
	fprintf(stderr, "WARNING: The 'UnionStationKey' option is obsolete. Please remove this option from your configuration file.\n");
	fflush(stderr);
	return NULL;
}

static const char *
cmd_union_station_proxy_address(cmd_parms *cmd, void *pcfg, const char *arg) {
	fprintf(stderr, "WARNING: The 'UnionStationProxyAddress' option is obsolete. Please remove this option from your configuration file.\n");
	fflush(stderr);
	return NULL;
}

static const char *
cmd_union_station_support(cmd_parms *cmd, void *pcfg, const char *arg) {
	fprintf(stderr, "WARNING: The 'UnionStationSupport' option is obsolete. Please remove this option from your configuration file.\n");
	fflush(stderr);
	return NULL;
}


} // namespace Apache2Module
} // namespace Passenger

#endif /* _PASSENGER_APACHE2_MODULE_CONFIG_AUTOGENERATED_SETTER_FUNCS_CPP_ */
