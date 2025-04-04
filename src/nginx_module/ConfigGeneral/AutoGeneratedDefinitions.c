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

/*
 * ConfigGeneral/AutoGeneratedDefinitions.c is automatically generated from
 * ConfigGeneral/AutoGeneratedDefinitions.c.cxxcodebuilder,
 * using definitions from src/ruby_supportlib/phusion_passenger/nginx/config_options.rb.
 * Edits to ConfigGeneral/AutoGeneratedDefinitions.c will be lost.
 *
 * To update ConfigGeneral/AutoGeneratedDefinitions.c:
 *   rake nginx
 *
 * To force regeneration of ConfigGeneral/AutoGeneratedDefinitions.c:
 *   rm -f src/nginx_module/ConfigGeneral/AutoGeneratedDefinitions.c
 *   rake src/nginx_module/ConfigGeneral/AutoGeneratedDefinitions.c
 */

{
    ngx_string("passenger_root"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_root,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.root_dir),
    NULL
},
{
    ngx_string("passenger_ctl"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE2,
    passenger_conf_set_ctl,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.ctl),
    NULL
},
{
    ngx_string("passenger_abort_on_startup_error"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_FLAG,
    passenger_conf_set_abort_on_startup_error,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.abort_on_startup_error),
    NULL
},
{
    ngx_string("passenger_dump_config_manifest"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_dump_config_manifest,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.dump_config_manifest),
    NULL
},
{
    ngx_string("passenger_log_level"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_log_level,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.log_level),
    NULL
},
{
    ngx_string("passenger_log_file"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_log_file,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.log_file),
    NULL
},
{
    ngx_string("passenger_disable_log_prefix"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_FLAG,
    passenger_conf_set_disable_log_prefix,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.disable_log_prefix),
    NULL
},
{
    ngx_string("passenger_file_descriptor_log_file"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_file_descriptor_log_file,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.file_descriptor_log_file),
    NULL
},
{
    ngx_string("passenger_data_buffer_dir"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_data_buffer_dir,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.data_buffer_dir),
    NULL
},
{
    ngx_string("passenger_socket_backlog"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_socket_backlog,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.socket_backlog),
    NULL
},
{
    ngx_string("passenger_core_file_descriptor_ulimit"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_core_file_descriptor_ulimit,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.core_file_descriptor_ulimit),
    NULL
},
{
    ngx_string("passenger_disable_security_update_check"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_FLAG,
    passenger_conf_set_disable_security_update_check,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.disable_security_update_check),
    NULL
},
{
    ngx_string("passenger_security_update_check_proxy"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_security_update_check_proxy,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.security_update_check_proxy),
    NULL
},
{
    ngx_string("passenger_disable_anonymous_telemetry"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_FLAG,
    passenger_conf_set_disable_anonymous_telemetry,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.disable_anonymous_telemetry),
    NULL
},
{
    ngx_string("passenger_anonymous_telemetry_proxy"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_anonymous_telemetry_proxy,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.anonymous_telemetry_proxy),
    NULL
},
{
    ngx_string("passenger_pre_start"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_pre_start,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.prestart_uris),
    NULL
},
{
    ngx_string("passenger_instance_registry_dir"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_instance_registry_dir,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.instance_registry_dir),
    NULL
},
{
    ngx_string("passenger_spawn_dir"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_spawn_dir,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.spawn_dir),
    NULL
},
{
    ngx_string("passenger_turbocaching"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_FLAG,
    passenger_conf_set_turbocaching,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.turbocaching),
    NULL
},
{
    ngx_string("passenger_old_routing"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_FLAG,
    passenger_conf_set_old_routing,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.old_routing),
    NULL
},
{
    ngx_string("passenger_user_switching"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_FLAG,
    passenger_conf_set_user_switching,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.user_switching),
    NULL
},
{
    ngx_string("passenger_default_user"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_default_user,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.default_user),
    NULL
},
{
    ngx_string("passenger_default_group"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_default_group,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.default_group),
    NULL
},
{
    ngx_string("passenger_max_pool_size"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_max_pool_size,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.max_pool_size),
    NULL
},
{
    ngx_string("passenger_pool_idle_time"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_pool_idle_time,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.pool_idle_time),
    NULL
},
{
    ngx_string("passenger_response_buffer_high_watermark"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_response_buffer_high_watermark,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.response_buffer_high_watermark),
    NULL
},
{
    ngx_string("passenger_stat_throttle_rate"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_stat_throttle_rate,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.stat_throttle_rate),
    NULL
},
{
    ngx_string("passenger_show_version_in_header"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_FLAG,
    passenger_conf_set_show_version_in_header,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.show_version_in_header),
    NULL
},
{
    ngx_string("passenger_app_file_descriptor_ulimit"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_app_file_descriptor_ulimit,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.app_file_descriptor_ulimit),
    NULL
},
{
    ngx_string("passenger_max_instances_per_app"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_max_instances_per_app,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.max_instances_per_app),
    NULL
},
{
    ngx_string("passenger_ruby"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_ruby,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.ruby),
    NULL
},
{
    ngx_string("passenger_python"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_python,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.python),
    NULL
},
{
    ngx_string("passenger_nodejs"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_nodejs,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.nodejs),
    NULL
},
{
    ngx_string("passenger_meteor_app_settings"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_meteor_app_settings,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.meteor_app_settings),
    NULL
},
{
    ngx_string("passenger_app_env"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_app_env,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.environment),
    NULL
},
{
    ngx_string("passenger_friendly_error_pages"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_conf_set_friendly_error_pages,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.friendly_error_pages),
    NULL
},
{
    ngx_string("passenger_custom_error_page"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_custom_error_page,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.custom_error_page),
    NULL
},
{
    ngx_string("passenger_min_instances"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_min_instances,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.min_instances),
    NULL
},
{
    ngx_string("passenger_start_timeout"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_start_timeout,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.start_timeout),
    NULL
},
{
    ngx_string("passenger_app_connect_timeout"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_app_connect_timeout,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.app_connect_timeout),
    NULL
},
{
    ngx_string("passenger_user"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_user,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.user),
    NULL
},
{
    ngx_string("passenger_group"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_group,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.group),
    NULL
},
{
    ngx_string("passenger_app_group_name"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_app_group_name,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.app_group_name),
    NULL
},
{
    ngx_string("passenger_monitor_log_file"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_monitor_log_file,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.monitor_log_file),
    NULL
},
{
    ngx_string("passenger_app_root"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_app_root,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.app_root),
    NULL
},
{
    ngx_string("passenger_app_rights"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_app_rights,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.app_rights),
    NULL
},
{
    ngx_string("passenger_debugger"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_conf_set_debugger,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.debugger),
    NULL
},
{
    ngx_string("passenger_max_preloader_idle_time"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_max_preloader_idle_time,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.max_preloader_idle_time),
    NULL
},
{
    ngx_string("passenger_env_var"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE2,
    passenger_conf_set_env_var,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.env_vars),
    NULL
},
{
    ngx_string("passenger_spawn_method"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_spawn_method,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.spawn_method),
    NULL
},
{
    ngx_string("passenger_direct_instance_request_address"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_direct_instance_request_address,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.direct_instance_request_address),
    NULL
},
{
    ngx_string("passenger_load_shell_envvars"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_conf_set_load_shell_envvars,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.load_shell_envvars),
    NULL
},
{
    ngx_string("passenger_preload_bundler"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_conf_set_preload_bundler,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.preload_bundler),
    NULL
},
{
    ngx_string("passenger_max_request_queue_size"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_max_request_queue_size,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.max_request_queue_size),
    NULL
},
{
    ngx_string("passenger_app_type"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_app_type,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.app_type),
    NULL
},
{
    ngx_string("passenger_startup_file"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_startup_file,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.startup_file),
    NULL
},
{
    ngx_string("passenger_app_start_command"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_app_start_command,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.app_start_command),
    NULL
},
{
    ngx_string("passenger_restart_dir"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_restart_dir,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.restart_dir),
    NULL
},
{
    ngx_string("passenger_abort_websockets_on_process_shutdown"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_conf_set_abort_websockets_on_process_shutdown,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.abort_websockets_on_process_shutdown),
    NULL
},
{
    ngx_string("passenger_force_max_concurrent_requests_per_process"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_force_max_concurrent_requests_per_process,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.force_max_concurrent_requests_per_process),
    NULL
},
{
    ngx_string("passenger_enabled"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_enabled,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.enabled),
    NULL
},
{
    ngx_string("passenger_max_requests"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_max_requests,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.max_requests),
    NULL
},
{
    ngx_string("passenger_base_uri"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_base_uri,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.base_uris),
    NULL
},
{
    ngx_string("passenger_document_root"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_document_root,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.document_root),
    NULL
},
{
    ngx_string("passenger_temp_path"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    ngx_conf_set_path_slot,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, upstream_config.temp_path),
    NULL
},
{
    ngx_string("passenger_ignore_headers"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_1MORE,
    ngx_conf_set_bitmask_slot,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, upstream_config.ignore_headers),
    &ngx_http_upstream_ignore_headers_masks
},
{
    ngx_string("passenger_set_header"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE2,
    passenger_conf_set_set_header,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.headers_source),
    NULL
},
{
    ngx_string("passenger_pass_header"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_pass_header,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, upstream_config.pass_headers),
    NULL
},
{
    ngx_string("passenger_headers_hash_max_size"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_headers_hash_max_size,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.headers_hash_max_size),
    NULL
},
{
    ngx_string("passenger_headers_hash_bucket_size"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_headers_hash_bucket_size,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.headers_hash_bucket_size),
    NULL
},
{
    ngx_string("passenger_ignore_client_abort"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_conf_set_ignore_client_abort,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, upstream_config.ignore_client_abort),
    NULL
},
{
    ngx_string("passenger_read_timeout"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_read_timeout,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, upstream_config.read_timeout),
    NULL
},
{
    ngx_string("passenger_buffer_response"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_conf_set_buffer_response,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, upstream_config.buffering),
    NULL
},
{
    ngx_string("passenger_buffer_size"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    ngx_conf_set_size_slot,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, upstream_config.buffer_size),
    NULL
},
{
    ngx_string("passenger_buffers"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE2,
    ngx_conf_set_bufs_slot,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, upstream_config.bufs),
    NULL
},
{
    ngx_string("passenger_busy_buffers_size"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    ngx_conf_set_size_slot,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, upstream_config.busy_buffers_size_conf),
    NULL
},
{
    ngx_string("passenger_request_buffering"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_conf_set_request_buffering,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, upstream_config.request_buffering),
    NULL
},
{
    ngx_string("passenger_intercept_errors"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_conf_set_intercept_errors,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, upstream_config.intercept_errors),
    NULL
},
{
    ngx_string("passenger_request_queue_overflow_status_code"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_request_queue_overflow_status_code,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.request_queue_overflow_status_code),
    NULL
},
{
    ngx_string("passenger_spawn_exception_status_code"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_spawn_exception_status_code,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.spawn_exception_status_code),
    NULL
},
{
    ngx_string("passenger_buffer_upload"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_conf_set_buffer_upload,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.buffer_upload),
    NULL
},
{
    ngx_string("passenger_sticky_sessions"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_conf_set_sticky_sessions,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.sticky_sessions),
    NULL
},
{
    ngx_string("passenger_sticky_sessions_cookie_name"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_sticky_sessions_cookie_name,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.sticky_sessions_cookie_name),
    NULL
},
{
    ngx_string("passenger_sticky_sessions_cookie_attributes"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_sticky_sessions_cookie_attributes,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.sticky_sessions_cookie_attributes),
    NULL
},
{
    ngx_string("passenger_vary_turbocache_by_cookie"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_vary_turbocache_by_cookie,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.vary_turbocache_by_cookie),
    NULL
},
{
    ngx_string("passenger_fly_with"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_enterprise_only,
    NGX_HTTP_MAIN_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("passenger_max_instances"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_enterprise_only,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("passenger_memory_limit"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_enterprise_only,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("passenger_concurrency_model"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_enterprise_only,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("passenger_thread_count"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_enterprise_only,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("passenger_rolling_restarts"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_enterprise_only,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("passenger_resist_deployment_errors"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_enterprise_only,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("passenger_max_request_time"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_enterprise_only,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("passenger_max_request_queue_time"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_enterprise_only,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("passenger_app_log_file"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_enterprise_only,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.app_log_file),
    NULL
},
{
    ngx_string("passenger_debug_log_file"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_log_file,
    NGX_HTTP_MAIN_CONF_OFFSET,
    offsetof(passenger_main_conf_t, autogenerated.log_file),
    NULL
},
{
    ngx_string("rails_spawn_method"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_spawn_method,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.spawn_method),
    NULL
},
{
    ngx_string("rails_env"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_app_env,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.environment),
    NULL
},
{
    ngx_string("rack_env"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_app_env,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.environment),
    NULL
},
{
    ngx_string("rails_app_spawner_idle_time"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_conf_set_max_preloader_idle_time,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(passenger_loc_conf_t, autogenerated.max_preloader_idle_time),
    NULL
},
{
    ngx_string("rails_framework_spawner_idle_time"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    rails_framework_spawner_idle_time,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("passenger_use_global_queue"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_use_global_queue,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("passenger_analytics_log_user"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_obsolete_directive,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("passenger_analytics_log_group"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_obsolete_directive,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("union_station_gateway_address"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_obsolete_directive,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("union_station_gateway_port"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_obsolete_directive,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("union_station_gateway_cert"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_obsolete_directive,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("union_station_proxy_address"),
    NGX_HTTP_MAIN_CONF | NGX_CONF_TAKE1,
    passenger_obsolete_directive,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("union_station_key"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_obsolete_directive,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("union_station_support"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_FLAG,
    passenger_obsolete_directive,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
{
    ngx_string("union_station_filter"),
    NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LIF_CONF | NGX_CONF_TAKE1,
    passenger_obsolete_directive,
    NGX_HTTP_LOC_CONF_OFFSET,
    0,
    NULL
},
