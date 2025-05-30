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
 * MainConfig/AutoGeneratedCreateFunction.c is automatically generated from
 * MainConfig/AutoGeneratedCreateFunction.c.cxxcodebuilder,
 * using definitions from src/ruby_supportlib/phusion_passenger/nginx/config_options.rb.
 * Edits to MainConfig/AutoGeneratedCreateFunction.c will be lost.
 *
 * To update MainConfig/AutoGeneratedCreateFunction.c:
 *   rake nginx
 *
 * To force regeneration of MainConfig/AutoGeneratedCreateFunction.c:
 *   rm -f src/nginx_module/MainConfig/AutoGeneratedCreateFunction.c
 *   rake src/nginx_module/MainConfig/AutoGeneratedCreateFunction.c
 */

void
passenger_create_autogenerated_main_conf(passenger_autogenerated_main_conf_t *conf) {
    conf->root_dir.data = NULL;
    conf->root_dir.len  = 0;
    conf->ctl = NULL;
    conf->abort_on_startup_error = NGX_CONF_UNSET;
    conf->dump_config_manifest.data = NULL;
    conf->dump_config_manifest.len  = 0;
    conf->log_level = NGX_CONF_UNSET_UINT;
    conf->log_file.data = NULL;
    conf->log_file.len  = 0;
    conf->disable_log_prefix = NGX_CONF_UNSET;
    conf->file_descriptor_log_file.data = NULL;
    conf->file_descriptor_log_file.len  = 0;
    conf->data_buffer_dir.data = NULL;
    conf->data_buffer_dir.len  = 0;
    conf->socket_backlog = NGX_CONF_UNSET_UINT;
    conf->core_file_descriptor_ulimit = NGX_CONF_UNSET_UINT;
    conf->disable_security_update_check = NGX_CONF_UNSET;
    conf->security_update_check_proxy.data = NULL;
    conf->security_update_check_proxy.len  = 0;
    conf->disable_anonymous_telemetry = NGX_CONF_UNSET;
    conf->anonymous_telemetry_proxy.data = NULL;
    conf->anonymous_telemetry_proxy.len  = 0;
    conf->prestart_uris = NGX_CONF_UNSET_PTR;
    conf->instance_registry_dir.data = NULL;
    conf->instance_registry_dir.len  = 0;
    conf->spawn_dir.data = NULL;
    conf->spawn_dir.len  = 0;
    conf->turbocaching = NGX_CONF_UNSET;
    conf->old_routing = NGX_CONF_UNSET;
    conf->user_switching = NGX_CONF_UNSET;
    conf->default_user.data = NULL;
    conf->default_user.len  = 0;
    conf->default_group.data = NULL;
    conf->default_group.len  = 0;
    conf->max_pool_size = NGX_CONF_UNSET_UINT;
    conf->pool_idle_time = NGX_CONF_UNSET_UINT;
    conf->response_buffer_high_watermark = NGX_CONF_UNSET_UINT;
    conf->stat_throttle_rate = NGX_CONF_UNSET_UINT;
    conf->show_version_in_header = NGX_CONF_UNSET;
    conf->app_file_descriptor_ulimit = NGX_CONF_UNSET_UINT;
    conf->max_instances_per_app = NGX_CONF_UNSET_UINT;

    conf->root_dir_source_file.data = NULL;
    conf->root_dir_source_file.len = 0;
    conf->root_dir_source_line = 0;
    conf->root_dir_explicitly_set = 0;
    conf->ctl_source_file.data = NULL;
    conf->ctl_source_file.len = 0;
    conf->ctl_source_line = 0;
    conf->ctl_explicitly_set = 0;
    conf->abort_on_startup_error_source_file.data = NULL;
    conf->abort_on_startup_error_source_file.len = 0;
    conf->abort_on_startup_error_source_line = 0;
    conf->abort_on_startup_error_explicitly_set = 0;
    conf->dump_config_manifest_source_file.data = NULL;
    conf->dump_config_manifest_source_file.len = 0;
    conf->dump_config_manifest_source_line = 0;
    conf->dump_config_manifest_explicitly_set = 0;
    conf->log_level_source_file.data = NULL;
    conf->log_level_source_file.len = 0;
    conf->log_level_source_line = 0;
    conf->log_level_explicitly_set = 0;
    conf->log_file_source_file.data = NULL;
    conf->log_file_source_file.len = 0;
    conf->log_file_source_line = 0;
    conf->log_file_explicitly_set = 0;
    conf->disable_log_prefix_source_file.data = NULL;
    conf->disable_log_prefix_source_file.len = 0;
    conf->disable_log_prefix_source_line = 0;
    conf->disable_log_prefix_explicitly_set = 0;
    conf->file_descriptor_log_file_source_file.data = NULL;
    conf->file_descriptor_log_file_source_file.len = 0;
    conf->file_descriptor_log_file_source_line = 0;
    conf->file_descriptor_log_file_explicitly_set = 0;
    conf->data_buffer_dir_source_file.data = NULL;
    conf->data_buffer_dir_source_file.len = 0;
    conf->data_buffer_dir_source_line = 0;
    conf->data_buffer_dir_explicitly_set = 0;
    conf->socket_backlog_source_file.data = NULL;
    conf->socket_backlog_source_file.len = 0;
    conf->socket_backlog_source_line = 0;
    conf->socket_backlog_explicitly_set = 0;
    conf->core_file_descriptor_ulimit_source_file.data = NULL;
    conf->core_file_descriptor_ulimit_source_file.len = 0;
    conf->core_file_descriptor_ulimit_source_line = 0;
    conf->core_file_descriptor_ulimit_explicitly_set = 0;
    conf->disable_security_update_check_source_file.data = NULL;
    conf->disable_security_update_check_source_file.len = 0;
    conf->disable_security_update_check_source_line = 0;
    conf->disable_security_update_check_explicitly_set = 0;
    conf->security_update_check_proxy_source_file.data = NULL;
    conf->security_update_check_proxy_source_file.len = 0;
    conf->security_update_check_proxy_source_line = 0;
    conf->security_update_check_proxy_explicitly_set = 0;
    conf->disable_anonymous_telemetry_source_file.data = NULL;
    conf->disable_anonymous_telemetry_source_file.len = 0;
    conf->disable_anonymous_telemetry_source_line = 0;
    conf->disable_anonymous_telemetry_explicitly_set = 0;
    conf->anonymous_telemetry_proxy_source_file.data = NULL;
    conf->anonymous_telemetry_proxy_source_file.len = 0;
    conf->anonymous_telemetry_proxy_source_line = 0;
    conf->anonymous_telemetry_proxy_explicitly_set = 0;
    conf->prestart_uris_source_file.data = NULL;
    conf->prestart_uris_source_file.len = 0;
    conf->prestart_uris_source_line = 0;
    conf->prestart_uris_explicitly_set = 0;
    conf->instance_registry_dir_source_file.data = NULL;
    conf->instance_registry_dir_source_file.len = 0;
    conf->instance_registry_dir_source_line = 0;
    conf->instance_registry_dir_explicitly_set = 0;
    conf->spawn_dir_source_file.data = NULL;
    conf->spawn_dir_source_file.len = 0;
    conf->spawn_dir_source_line = 0;
    conf->spawn_dir_explicitly_set = 0;
    conf->turbocaching_source_file.data = NULL;
    conf->turbocaching_source_file.len = 0;
    conf->turbocaching_source_line = 0;
    conf->turbocaching_explicitly_set = 0;
    conf->old_routing_source_file.data = NULL;
    conf->old_routing_source_file.len = 0;
    conf->old_routing_source_line = 0;
    conf->old_routing_explicitly_set = 0;
    conf->user_switching_source_file.data = NULL;
    conf->user_switching_source_file.len = 0;
    conf->user_switching_source_line = 0;
    conf->user_switching_explicitly_set = 0;
    conf->default_user_source_file.data = NULL;
    conf->default_user_source_file.len = 0;
    conf->default_user_source_line = 0;
    conf->default_user_explicitly_set = 0;
    conf->default_group_source_file.data = NULL;
    conf->default_group_source_file.len = 0;
    conf->default_group_source_line = 0;
    conf->default_group_explicitly_set = 0;
    conf->max_pool_size_source_file.data = NULL;
    conf->max_pool_size_source_file.len = 0;
    conf->max_pool_size_source_line = 0;
    conf->max_pool_size_explicitly_set = 0;
    conf->pool_idle_time_source_file.data = NULL;
    conf->pool_idle_time_source_file.len = 0;
    conf->pool_idle_time_source_line = 0;
    conf->pool_idle_time_explicitly_set = 0;
    conf->response_buffer_high_watermark_source_file.data = NULL;
    conf->response_buffer_high_watermark_source_file.len = 0;
    conf->response_buffer_high_watermark_source_line = 0;
    conf->response_buffer_high_watermark_explicitly_set = 0;
    conf->stat_throttle_rate_source_file.data = NULL;
    conf->stat_throttle_rate_source_file.len = 0;
    conf->stat_throttle_rate_source_line = 0;
    conf->stat_throttle_rate_explicitly_set = 0;
    conf->show_version_in_header_source_file.data = NULL;
    conf->show_version_in_header_source_file.len = 0;
    conf->show_version_in_header_source_line = 0;
    conf->show_version_in_header_explicitly_set = 0;
    conf->app_file_descriptor_ulimit_source_file.data = NULL;
    conf->app_file_descriptor_ulimit_source_file.len = 0;
    conf->app_file_descriptor_ulimit_source_line = 0;
    conf->app_file_descriptor_ulimit_explicitly_set = 0;
    conf->max_instances_per_app_source_file.data = NULL;
    conf->max_instances_per_app_source_file.len = 0;
    conf->max_instances_per_app_source_line = 0;
    conf->max_instances_per_app_explicitly_set = 0;
}

