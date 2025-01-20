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
 * ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.c is automatically generated from
 * ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.c.cxxcodebuilder,
 * using definitions from src/ruby_supportlib/phusion_passenger/nginx/config_options.rb.
 * Edits to ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.c will be lost.
 *
 * To update ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.c:
 *   rake nginx
 *
 * To force regeneration of ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.c:
 *   rm -f src/nginx_module/ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.c
 *   rake src/nginx_module/ConfigGeneral/AutoGeneratedManifestDefaultsInitialization.c
 */

#include "ManifestGeneration.h"

static void
set_manifest_autogenerated_global_conf_defaults(manifest_gen_ctx_t *ctx) {
    add_manifest_options_container_static_default_bool(ctx,
        ctx->global_config_container,
        "passenger_abort_on_startup_error",
        sizeof("passenger_abort_on_startup_error") - 1,
        0);

    add_manifest_options_container_static_default_uint(ctx,
        ctx->global_config_container,
        "passenger_log_level",
        sizeof("passenger_log_level") - 1,
        3);

    add_manifest_options_container_dynamic_default(ctx,
        ctx->global_config_container,
        "passenger_log_file",
        sizeof("passenger_log_file") - 1,
        "Nginx's global error log",
        sizeof("Nginx's global error log") - 1);

    add_manifest_options_container_static_default_bool(ctx,
        ctx->global_config_container,
        "passenger_disable_log_prefix",
        sizeof("passenger_disable_log_prefix") - 1,
        0);

    add_manifest_options_container_dynamic_default(ctx,
        ctx->global_config_container,
        "passenger_data_buffer_dir",
        sizeof("passenger_data_buffer_dir") - 1,
        "$TMPDIR, or if not given, /tmp",
        sizeof("$TMPDIR, or if not given, /tmp") - 1);

    add_manifest_options_container_static_default_uint(ctx,
        ctx->global_config_container,
        "passenger_socket_backlog",
        sizeof("passenger_socket_backlog") - 1,
        2048);

    add_manifest_options_container_dynamic_default(ctx,
        ctx->global_config_container,
        "passenger_core_file_descriptor_ulimit",
        sizeof("passenger_core_file_descriptor_ulimit") - 1,
        "The ulimits environment under which Nginx was started",
        sizeof("The ulimits environment under which Nginx was started") - 1);

    add_manifest_options_container_static_default_bool(ctx,
        ctx->global_config_container,
        "passenger_disable_security_update_check",
        sizeof("passenger_disable_security_update_check") - 1,
        0);

    add_manifest_options_container_static_default_bool(ctx,
        ctx->global_config_container,
        "passenger_disable_anonymous_telemetry",
        sizeof("passenger_disable_anonymous_telemetry") - 1,
        0);

    add_manifest_options_container_dynamic_default(ctx,
        ctx->global_config_container,
        "passenger_instance_registry_dir",
        sizeof("passenger_instance_registry_dir") - 1,
        "Either /var/run/passenger-instreg, $TMPDIR, or /tmp (see docs)",
        sizeof("Either /var/run/passenger-instreg, $TMPDIR, or /tmp (see docs)") - 1);

    add_manifest_options_container_dynamic_default(ctx,
        ctx->global_config_container,
        "passenger_spawn_dir",
        sizeof("passenger_spawn_dir") - 1,
        "Either $TMPDIR or /tmp",
        sizeof("Either $TMPDIR or /tmp") - 1);

    add_manifest_options_container_static_default_bool(ctx,
        ctx->global_config_container,
        "passenger_turbocaching",
        sizeof("passenger_turbocaching") - 1,
        1);

    add_manifest_options_container_static_default_bool(ctx,
        ctx->global_config_container,
        "passenger_user_switching",
        sizeof("passenger_user_switching") - 1,
        1);

    add_manifest_options_container_static_default_str(ctx,
        ctx->global_config_container,
        "passenger_default_user",
        sizeof("passenger_default_user") - 1,
        "nobody",
        sizeof("nobody") - 1);

    add_manifest_options_container_dynamic_default(ctx,
        ctx->global_config_container,
        "passenger_default_group",
        sizeof("passenger_default_group") - 1,
        "The primary group of passenger_default_user",
        sizeof("The primary group of passenger_default_user") - 1);

    add_manifest_options_container_static_default_uint(ctx,
        ctx->global_config_container,
        "passenger_max_pool_size",
        sizeof("passenger_max_pool_size") - 1,
        6);

    add_manifest_options_container_static_default_uint(ctx,
        ctx->global_config_container,
        "passenger_pool_idle_time",
        sizeof("passenger_pool_idle_time") - 1,
        300);

    add_manifest_options_container_static_default_uint(ctx,
        ctx->global_config_container,
        "passenger_response_buffer_high_watermark",
        sizeof("passenger_response_buffer_high_watermark") - 1,
        134217728);

    add_manifest_options_container_static_default_uint(ctx,
        ctx->global_config_container,
        "passenger_stat_throttle_rate",
        sizeof("passenger_stat_throttle_rate") - 1,
        10);

    add_manifest_options_container_static_default_bool(ctx,
        ctx->global_config_container,
        "passenger_show_version_in_header",
        sizeof("passenger_show_version_in_header") - 1,
        1);

    add_manifest_options_container_dynamic_default(ctx,
        ctx->global_config_container,
        "passenger_app_file_descriptor_ulimit",
        sizeof("passenger_app_file_descriptor_ulimit") - 1,
        "passenger_core_file_descriptor_ulimit",
        sizeof("passenger_core_file_descriptor_ulimit") - 1);

    add_manifest_options_container_static_default_uint(ctx,
        ctx->global_config_container,
        "passenger_max_instances_per_app",
        sizeof("passenger_max_instances_per_app") - 1,
        0);

}

static void
set_manifest_autogenerated_app_conf_defaults(manifest_gen_ctx_t *ctx, PsgJsonValue *options_container) {
    add_manifest_options_container_static_default_str(ctx,
        options_container,
        "passenger_ruby",
        sizeof("passenger_ruby") - 1,
        "ruby",
        sizeof("ruby") - 1);

    add_manifest_options_container_static_default_str(ctx,
        options_container,
        "passenger_python",
        sizeof("passenger_python") - 1,
        "python",
        sizeof("python") - 1);

    add_manifest_options_container_static_default_str(ctx,
        options_container,
        "passenger_nodejs",
        sizeof("passenger_nodejs") - 1,
        "node",
        sizeof("node") - 1);

    add_manifest_options_container_static_default_str(ctx,
        options_container,
        "passenger_app_env",
        sizeof("passenger_app_env") - 1,
        "production",
        sizeof("production") - 1);

    add_manifest_options_container_dynamic_default(ctx,
        options_container,
        "passenger_friendly_error_pages",
        sizeof("passenger_friendly_error_pages") - 1,
        "On if passenger_app_env is development, off otherwise",
        sizeof("On if passenger_app_env is development, off otherwise") - 1);

    add_manifest_options_container_static_default_uint(ctx,
        options_container,
        "passenger_min_instances",
        sizeof("passenger_min_instances") - 1,
        1);

    add_manifest_options_container_static_default_uint(ctx,
        options_container,
        "passenger_start_timeout",
        sizeof("passenger_start_timeout") - 1,
        90);

    add_manifest_options_container_dynamic_default(ctx,
        options_container,
        "passenger_user",
        sizeof("passenger_user") - 1,
        "See the user account sandboxing rules",
        sizeof("See the user account sandboxing rules") - 1);

    add_manifest_options_container_dynamic_default(ctx,
        options_container,
        "passenger_group",
        sizeof("passenger_group") - 1,
        "See the user account sandboxing rules",
        sizeof("See the user account sandboxing rules") - 1);

    add_manifest_options_container_dynamic_default(ctx,
        options_container,
        "passenger_app_group_name",
        sizeof("passenger_app_group_name") - 1,
        "passenger_app_root plus passenger_app_env",
        sizeof("passenger_app_root plus passenger_app_env") - 1);

    add_manifest_options_container_dynamic_default(ctx,
        options_container,
        "passenger_app_root",
        sizeof("passenger_app_root") - 1,
        "Parent directory of the associated Nginx virtual host's root directory",
        sizeof("Parent directory of the associated Nginx virtual host's root directory") - 1);

    add_manifest_options_container_static_default_bool(ctx,
        options_container,
        "passenger_debugger",
        sizeof("passenger_debugger") - 1,
        0);

    add_manifest_options_container_static_default_int(ctx,
        options_container,
        "passenger_max_preloader_idle_time",
        sizeof("passenger_max_preloader_idle_time") - 1,
        300);

    add_manifest_options_container_dynamic_default(ctx,
        options_container,
        "passenger_spawn_method",
        sizeof("passenger_spawn_method") - 1,
        "'smart' for Ruby apps, 'direct' for all other apps",
        sizeof("'smart' for Ruby apps, 'direct' for all other apps") - 1);

    add_manifest_options_container_static_default_str(ctx,
        options_container,
        "passenger_direct_instance_request_address",
        sizeof("passenger_direct_instance_request_address") - 1,
        "127.0.0.1",
        sizeof("127.0.0.1") - 1);

    add_manifest_options_container_static_default_bool(ctx,
        options_container,
        "passenger_load_shell_envvars",
        sizeof("passenger_load_shell_envvars") - 1,
        1);

    add_manifest_options_container_static_default_bool(ctx,
        options_container,
        "passenger_preload_bundler",
        sizeof("passenger_preload_bundler") - 1,
        0);

    add_manifest_options_container_static_default_uint(ctx,
        options_container,
        "passenger_max_request_queue_size",
        sizeof("passenger_max_request_queue_size") - 1,
        100);

    add_manifest_options_container_dynamic_default(ctx,
        options_container,
        "passenger_app_type",
        sizeof("passenger_app_type") - 1,
        "Autodetected",
        sizeof("Autodetected") - 1);

    add_manifest_options_container_dynamic_default(ctx,
        options_container,
        "passenger_startup_file",
        sizeof("passenger_startup_file") - 1,
        "Autodetected",
        sizeof("Autodetected") - 1);

    add_manifest_options_container_static_default_str(ctx,
        options_container,
        "passenger_restart_dir",
        sizeof("passenger_restart_dir") - 1,
        "tmp",
        sizeof("tmp") - 1);

    add_manifest_options_container_static_default_bool(ctx,
        options_container,
        "passenger_abort_websockets_on_process_shutdown",
        sizeof("passenger_abort_websockets_on_process_shutdown") - 1,
        1);

    add_manifest_options_container_static_default_int(ctx,
        options_container,
        "passenger_force_max_concurrent_requests_per_process",
        sizeof("passenger_force_max_concurrent_requests_per_process") - 1,
        -1);

    add_manifest_options_container_dynamic_default(ctx,
        options_container,
        "passenger_app_log_file",
        sizeof("passenger_app_log_file") - 1,
        "passenger_log_file",
        sizeof("passenger_log_file") - 1);

}

static void
set_manifest_autogenerated_loc_conf_defaults(manifest_gen_ctx_t *ctx, PsgJsonValue *options_container) {
    add_manifest_options_container_static_default_bool(ctx,
        options_container,
        "passenger_enabled",
        sizeof("passenger_enabled") - 1,
        0);

    add_manifest_options_container_static_default_uint(ctx,
        options_container,
        "passenger_max_requests",
        sizeof("passenger_max_requests") - 1,
        0);

    add_manifest_options_container_static_default_uint(ctx,
        options_container,
        "passenger_headers_hash_max_size",
        sizeof("passenger_headers_hash_max_size") - 1,
        512);

    add_manifest_options_container_static_default_uint(ctx,
        options_container,
        "passenger_headers_hash_bucket_size",
        sizeof("passenger_headers_hash_bucket_size") - 1,
        64);

    add_manifest_options_container_static_default_bool(ctx,
        options_container,
        "passenger_ignore_client_abort",
        sizeof("passenger_ignore_client_abort") - 1,
        0);

    add_manifest_options_container_static_default_bool(ctx,
        options_container,
        "passenger_buffer_response",
        sizeof("passenger_buffer_response") - 1,
        0);

    add_manifest_options_container_dynamic_default(ctx,
        options_container,
        "passenger_buffer_size",
        sizeof("passenger_buffer_size") - 1,
        "4k|8k",
        sizeof("4k|8k") - 1);

    add_manifest_options_container_dynamic_default(ctx,
        options_container,
        "passenger_buffers",
        sizeof("passenger_buffers") - 1,
        "8 4k|8k",
        sizeof("8 4k|8k") - 1);

    add_manifest_options_container_dynamic_default(ctx,
        options_container,
        "passenger_busy_buffers_size",
        sizeof("passenger_busy_buffers_size") - 1,
        "8k|16k",
        sizeof("8k|16k") - 1);

    add_manifest_options_container_static_default_bool(ctx,
        options_container,
        "passenger_request_buffering",
        sizeof("passenger_request_buffering") - 1,
        1);

    add_manifest_options_container_static_default_bool(ctx,
        options_container,
        "passenger_intercept_errors",
        sizeof("passenger_intercept_errors") - 1,
        0);

    add_manifest_options_container_static_default_int(ctx,
        options_container,
        "passenger_request_queue_overflow_status_code",
        sizeof("passenger_request_queue_overflow_status_code") - 1,
        503);

    add_manifest_options_container_static_default_int(ctx,
        options_container,
        "passenger_spawn_exception_status_code",
        sizeof("passenger_spawn_exception_status_code") - 1,
        500);

    add_manifest_options_container_static_default_bool(ctx,
        options_container,
        "passenger_buffer_upload",
        sizeof("passenger_buffer_upload") - 1,
        0);

    add_manifest_options_container_static_default_bool(ctx,
        options_container,
        "passenger_sticky_sessions",
        sizeof("passenger_sticky_sessions") - 1,
        0);

    add_manifest_options_container_static_default_str(ctx,
        options_container,
        "passenger_sticky_sessions_cookie_name",
        sizeof("passenger_sticky_sessions_cookie_name") - 1,
        "_passenger_route",
        sizeof("_passenger_route") - 1);

    add_manifest_options_container_static_default_str(ctx,
        options_container,
        "passenger_sticky_sessions_cookie_attributes",
        sizeof("passenger_sticky_sessions_cookie_attributes") - 1,
        "SameSite=Lax; Secure;",
        sizeof("SameSite=Lax; Secure;") - 1);

}

