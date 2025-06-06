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
 * LocationConfig/AutoGenereatedCreateFunction.c is automatically generated from
 * LocationConfig/AutoGenereatedCreateFunction.c.cxxcodebuilder,
 * using definitions from src/ruby_supportlib/phusion_passenger/nginx/config_options.rb.
 * Edits to LocationConfig/AutoGenereatedCreateFunction.c will be lost.
 *
 * To update LocationConfig/AutoGenereatedCreateFunction.c:
 *   rake nginx
 *
 * To force regeneration of LocationConfig/AutoGenereatedCreateFunction.c:
 *   rm -f src/nginx_module/LocationConfig/AutoGenereatedCreateFunction.c
 *   rake src/nginx_module/LocationConfig/AutoGenereatedCreateFunction.c
 */

static void
passenger_create_autogenerated_loc_conf(passenger_autogenerated_loc_conf_t  *conf) {
    conf->ruby.data = NULL;
    conf->ruby.len  = 0;
    conf->python.data = NULL;
    conf->python.len  = 0;
    conf->nodejs.data = NULL;
    conf->nodejs.len  = 0;
    conf->meteor_app_settings.data = NULL;
    conf->meteor_app_settings.len  = 0;
    conf->environment.data = NULL;
    conf->environment.len  = 0;
    conf->friendly_error_pages = NGX_CONF_UNSET;
    conf->custom_error_page.data = NULL;
    conf->custom_error_page.len  = 0;
    conf->min_instances = NGX_CONF_UNSET_UINT;
    conf->start_timeout = NGX_CONF_UNSET_UINT;
    conf->app_connect_timeout = NGX_CONF_UNSET_UINT;
    conf->user.data = NULL;
    conf->user.len  = 0;
    conf->group.data = NULL;
    conf->group.len  = 0;
    conf->app_group_name.data = NULL;
    conf->app_group_name.len  = 0;
    conf->monitor_log_file = NGX_CONF_UNSET_PTR;
    conf->app_root.data = NULL;
    conf->app_root.len  = 0;
    conf->app_rights.data = NULL;
    conf->app_rights.len  = 0;
    conf->debugger = NGX_CONF_UNSET;
    conf->max_preloader_idle_time = NGX_CONF_UNSET;
    conf->env_vars = NULL;
    conf->spawn_method.data = NULL;
    conf->spawn_method.len  = 0;
    conf->direct_instance_request_address.data = NULL;
    conf->direct_instance_request_address.len  = 0;
    conf->load_shell_envvars = NGX_CONF_UNSET;
    conf->preload_bundler = NGX_CONF_UNSET;
    conf->max_request_queue_size = NGX_CONF_UNSET_UINT;
    conf->app_type.data = NULL;
    conf->app_type.len  = 0;
    conf->startup_file.data = NULL;
    conf->startup_file.len  = 0;
    conf->app_start_command.data = NULL;
    conf->app_start_command.len  = 0;
    conf->restart_dir.data = NULL;
    conf->restart_dir.len  = 0;
    conf->abort_websockets_on_process_shutdown = NGX_CONF_UNSET;
    conf->force_max_concurrent_requests_per_process = NGX_CONF_UNSET;
    conf->enabled = NGX_CONF_UNSET;
    conf->max_requests = NGX_CONF_UNSET_UINT;
    conf->base_uris = NGX_CONF_UNSET_PTR;
    conf->document_root.data = NULL;
    conf->document_root.len  = 0;
    conf->headers_hash_max_size = NGX_CONF_UNSET_UINT;
    conf->headers_hash_bucket_size = NGX_CONF_UNSET_UINT;
    conf->request_queue_overflow_status_code = NGX_CONF_UNSET;
    conf->spawn_exception_status_code = NGX_CONF_UNSET;
    conf->buffer_upload = NGX_CONF_UNSET;
    conf->sticky_sessions = NGX_CONF_UNSET;
    conf->sticky_sessions_cookie_name.data = NULL;
    conf->sticky_sessions_cookie_name.len  = 0;
    conf->sticky_sessions_cookie_attributes.data = NULL;
    conf->sticky_sessions_cookie_attributes.len  = 0;
    conf->vary_turbocache_by_cookie.data = NULL;
    conf->vary_turbocache_by_cookie.len  = 0;
    conf->app_log_file.data = NULL;
    conf->app_log_file.len  = 0;

    conf->ruby_source_file.data = NULL;
    conf->ruby_source_file.len = 0;
    conf->ruby_source_line = 0;
    conf->ruby_explicitly_set = 0;
    conf->python_source_file.data = NULL;
    conf->python_source_file.len = 0;
    conf->python_source_line = 0;
    conf->python_explicitly_set = 0;
    conf->nodejs_source_file.data = NULL;
    conf->nodejs_source_file.len = 0;
    conf->nodejs_source_line = 0;
    conf->nodejs_explicitly_set = 0;
    conf->meteor_app_settings_source_file.data = NULL;
    conf->meteor_app_settings_source_file.len = 0;
    conf->meteor_app_settings_source_line = 0;
    conf->meteor_app_settings_explicitly_set = 0;
    conf->environment_source_file.data = NULL;
    conf->environment_source_file.len = 0;
    conf->environment_source_line = 0;
    conf->environment_explicitly_set = 0;
    conf->friendly_error_pages_source_file.data = NULL;
    conf->friendly_error_pages_source_file.len = 0;
    conf->friendly_error_pages_source_line = 0;
    conf->friendly_error_pages_explicitly_set = 0;
    conf->custom_error_page_source_file.data = NULL;
    conf->custom_error_page_source_file.len = 0;
    conf->custom_error_page_source_line = 0;
    conf->custom_error_page_explicitly_set = 0;
    conf->min_instances_source_file.data = NULL;
    conf->min_instances_source_file.len = 0;
    conf->min_instances_source_line = 0;
    conf->min_instances_explicitly_set = 0;
    conf->start_timeout_source_file.data = NULL;
    conf->start_timeout_source_file.len = 0;
    conf->start_timeout_source_line = 0;
    conf->start_timeout_explicitly_set = 0;
    conf->app_connect_timeout_source_file.data = NULL;
    conf->app_connect_timeout_source_file.len = 0;
    conf->app_connect_timeout_source_line = 0;
    conf->app_connect_timeout_explicitly_set = 0;
    conf->user_source_file.data = NULL;
    conf->user_source_file.len = 0;
    conf->user_source_line = 0;
    conf->user_explicitly_set = 0;
    conf->group_source_file.data = NULL;
    conf->group_source_file.len = 0;
    conf->group_source_line = 0;
    conf->group_explicitly_set = 0;
    conf->app_group_name_source_file.data = NULL;
    conf->app_group_name_source_file.len = 0;
    conf->app_group_name_source_line = 0;
    conf->app_group_name_explicitly_set = 0;
    conf->monitor_log_file_source_file.data = NULL;
    conf->monitor_log_file_source_file.len = 0;
    conf->monitor_log_file_source_line = 0;
    conf->monitor_log_file_explicitly_set = 0;
    conf->app_root_source_file.data = NULL;
    conf->app_root_source_file.len = 0;
    conf->app_root_source_line = 0;
    conf->app_root_explicitly_set = 0;
    conf->app_rights_source_file.data = NULL;
    conf->app_rights_source_file.len = 0;
    conf->app_rights_source_line = 0;
    conf->app_rights_explicitly_set = 0;
    conf->debugger_source_file.data = NULL;
    conf->debugger_source_file.len = 0;
    conf->debugger_source_line = 0;
    conf->debugger_explicitly_set = 0;
    conf->max_preloader_idle_time_source_file.data = NULL;
    conf->max_preloader_idle_time_source_file.len = 0;
    conf->max_preloader_idle_time_source_line = 0;
    conf->max_preloader_idle_time_explicitly_set = 0;
    conf->env_vars_source_file.data = NULL;
    conf->env_vars_source_file.len = 0;
    conf->env_vars_source_line = 0;
    conf->env_vars_explicitly_set = 0;
    conf->spawn_method_source_file.data = NULL;
    conf->spawn_method_source_file.len = 0;
    conf->spawn_method_source_line = 0;
    conf->spawn_method_explicitly_set = 0;
    conf->direct_instance_request_address_source_file.data = NULL;
    conf->direct_instance_request_address_source_file.len = 0;
    conf->direct_instance_request_address_source_line = 0;
    conf->direct_instance_request_address_explicitly_set = 0;
    conf->load_shell_envvars_source_file.data = NULL;
    conf->load_shell_envvars_source_file.len = 0;
    conf->load_shell_envvars_source_line = 0;
    conf->load_shell_envvars_explicitly_set = 0;
    conf->preload_bundler_source_file.data = NULL;
    conf->preload_bundler_source_file.len = 0;
    conf->preload_bundler_source_line = 0;
    conf->preload_bundler_explicitly_set = 0;
    conf->max_request_queue_size_source_file.data = NULL;
    conf->max_request_queue_size_source_file.len = 0;
    conf->max_request_queue_size_source_line = 0;
    conf->max_request_queue_size_explicitly_set = 0;
    conf->app_type_source_file.data = NULL;
    conf->app_type_source_file.len = 0;
    conf->app_type_source_line = 0;
    conf->app_type_explicitly_set = 0;
    conf->startup_file_source_file.data = NULL;
    conf->startup_file_source_file.len = 0;
    conf->startup_file_source_line = 0;
    conf->startup_file_explicitly_set = 0;
    conf->app_start_command_source_file.data = NULL;
    conf->app_start_command_source_file.len = 0;
    conf->app_start_command_source_line = 0;
    conf->app_start_command_explicitly_set = 0;
    conf->restart_dir_source_file.data = NULL;
    conf->restart_dir_source_file.len = 0;
    conf->restart_dir_source_line = 0;
    conf->restart_dir_explicitly_set = 0;
    conf->abort_websockets_on_process_shutdown_source_file.data = NULL;
    conf->abort_websockets_on_process_shutdown_source_file.len = 0;
    conf->abort_websockets_on_process_shutdown_source_line = 0;
    conf->abort_websockets_on_process_shutdown_explicitly_set = 0;
    conf->force_max_concurrent_requests_per_process_source_file.data = NULL;
    conf->force_max_concurrent_requests_per_process_source_file.len = 0;
    conf->force_max_concurrent_requests_per_process_source_line = 0;
    conf->force_max_concurrent_requests_per_process_explicitly_set = 0;
    conf->enabled_source_file.data = NULL;
    conf->enabled_source_file.len = 0;
    conf->enabled_source_line = 0;
    conf->enabled_explicitly_set = 0;
    conf->max_requests_source_file.data = NULL;
    conf->max_requests_source_file.len = 0;
    conf->max_requests_source_line = 0;
    conf->max_requests_explicitly_set = 0;
    conf->base_uris_source_file.data = NULL;
    conf->base_uris_source_file.len = 0;
    conf->base_uris_source_line = 0;
    conf->base_uris_explicitly_set = 0;
    conf->document_root_source_file.data = NULL;
    conf->document_root_source_file.len = 0;
    conf->document_root_source_line = 0;
    conf->document_root_explicitly_set = 0;
    conf->upstream_config_temp_path_source_file.data = NULL;
    conf->upstream_config_temp_path_source_file.len = 0;
    conf->upstream_config_temp_path_source_line = 0;
    conf->upstream_config_temp_path_explicitly_set = 0;
    conf->upstream_config_ignore_headers_source_file.data = NULL;
    conf->upstream_config_ignore_headers_source_file.len = 0;
    conf->upstream_config_ignore_headers_source_line = 0;
    conf->upstream_config_ignore_headers_explicitly_set = 0;
    conf->headers_source_source_file.data = NULL;
    conf->headers_source_source_file.len = 0;
    conf->headers_source_source_line = 0;
    conf->headers_source_explicitly_set = 0;
    conf->upstream_config_pass_headers_source_file.data = NULL;
    conf->upstream_config_pass_headers_source_file.len = 0;
    conf->upstream_config_pass_headers_source_line = 0;
    conf->upstream_config_pass_headers_explicitly_set = 0;
    conf->headers_hash_max_size_source_file.data = NULL;
    conf->headers_hash_max_size_source_file.len = 0;
    conf->headers_hash_max_size_source_line = 0;
    conf->headers_hash_max_size_explicitly_set = 0;
    conf->headers_hash_bucket_size_source_file.data = NULL;
    conf->headers_hash_bucket_size_source_file.len = 0;
    conf->headers_hash_bucket_size_source_line = 0;
    conf->headers_hash_bucket_size_explicitly_set = 0;
    conf->upstream_config_ignore_client_abort_source_file.data = NULL;
    conf->upstream_config_ignore_client_abort_source_file.len = 0;
    conf->upstream_config_ignore_client_abort_source_line = 0;
    conf->upstream_config_ignore_client_abort_explicitly_set = 0;
    conf->upstream_config_read_timeout_source_file.data = NULL;
    conf->upstream_config_read_timeout_source_file.len = 0;
    conf->upstream_config_read_timeout_source_line = 0;
    conf->upstream_config_read_timeout_explicitly_set = 0;
    conf->upstream_config_buffering_source_file.data = NULL;
    conf->upstream_config_buffering_source_file.len = 0;
    conf->upstream_config_buffering_source_line = 0;
    conf->upstream_config_buffering_explicitly_set = 0;
    conf->upstream_config_buffer_size_source_file.data = NULL;
    conf->upstream_config_buffer_size_source_file.len = 0;
    conf->upstream_config_buffer_size_source_line = 0;
    conf->upstream_config_buffer_size_explicitly_set = 0;
    conf->upstream_config_bufs_source_file.data = NULL;
    conf->upstream_config_bufs_source_file.len = 0;
    conf->upstream_config_bufs_source_line = 0;
    conf->upstream_config_bufs_explicitly_set = 0;
    conf->upstream_config_busy_buffers_size_conf_source_file.data = NULL;
    conf->upstream_config_busy_buffers_size_conf_source_file.len = 0;
    conf->upstream_config_busy_buffers_size_conf_source_line = 0;
    conf->upstream_config_busy_buffers_size_conf_explicitly_set = 0;
    conf->upstream_config_request_buffering_source_file.data = NULL;
    conf->upstream_config_request_buffering_source_file.len = 0;
    conf->upstream_config_request_buffering_source_line = 0;
    conf->upstream_config_request_buffering_explicitly_set = 0;
    conf->upstream_config_intercept_errors_source_file.data = NULL;
    conf->upstream_config_intercept_errors_source_file.len = 0;
    conf->upstream_config_intercept_errors_source_line = 0;
    conf->upstream_config_intercept_errors_explicitly_set = 0;
    conf->request_queue_overflow_status_code_source_file.data = NULL;
    conf->request_queue_overflow_status_code_source_file.len = 0;
    conf->request_queue_overflow_status_code_source_line = 0;
    conf->request_queue_overflow_status_code_explicitly_set = 0;
    conf->spawn_exception_status_code_source_file.data = NULL;
    conf->spawn_exception_status_code_source_file.len = 0;
    conf->spawn_exception_status_code_source_line = 0;
    conf->spawn_exception_status_code_explicitly_set = 0;
    conf->buffer_upload_source_file.data = NULL;
    conf->buffer_upload_source_file.len = 0;
    conf->buffer_upload_source_line = 0;
    conf->buffer_upload_explicitly_set = 0;
    conf->sticky_sessions_source_file.data = NULL;
    conf->sticky_sessions_source_file.len = 0;
    conf->sticky_sessions_source_line = 0;
    conf->sticky_sessions_explicitly_set = 0;
    conf->sticky_sessions_cookie_name_source_file.data = NULL;
    conf->sticky_sessions_cookie_name_source_file.len = 0;
    conf->sticky_sessions_cookie_name_source_line = 0;
    conf->sticky_sessions_cookie_name_explicitly_set = 0;
    conf->sticky_sessions_cookie_attributes_source_file.data = NULL;
    conf->sticky_sessions_cookie_attributes_source_file.len = 0;
    conf->sticky_sessions_cookie_attributes_source_line = 0;
    conf->sticky_sessions_cookie_attributes_explicitly_set = 0;
    conf->vary_turbocache_by_cookie_source_file.data = NULL;
    conf->vary_turbocache_by_cookie_source_file.len = 0;
    conf->vary_turbocache_by_cookie_source_line = 0;
    conf->vary_turbocache_by_cookie_explicitly_set = 0;
    conf->app_log_file_source_file.data = NULL;
    conf->app_log_file_source_file.len = 0;
    conf->app_log_file_source_line = 0;
    conf->app_log_file_explicitly_set = 0;
}

