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
 * ConfigGeneral/AutoGeneratedSetterFuncs.c is automatically generated from
 * ConfigGeneral/AutoGeneratedSetterFuncs.c.cxxcodebuilder,
 * using definitions from src/ruby_supportlib/phusion_passenger/nginx/config_options.rb.
 * Edits to ConfigGeneral/AutoGeneratedSetterFuncs.c will be lost.
 *
 * To update ConfigGeneral/AutoGeneratedSetterFuncs.c:
 *   rake nginx
 *
 * To force regeneration of ConfigGeneral/AutoGeneratedSetterFuncs.c:
 *   rm -f src/nginx_module/ConfigGeneral/AutoGeneratedSetterFuncs.c
 *   rake src/nginx_module/ConfigGeneral/AutoGeneratedSetterFuncs.c
 */

static void
record_main_conf_source_location(ngx_conf_t *cf, ngx_str_t *file, ngx_uint_t *line) {
    if (cf->conf_file == NULL) {
        file->data = (u_char *) NULL;
        file->len = 0;
        *line = 0;
    } else if (cf->conf_file->file.fd == NGX_INVALID_FILE) {
        file->data = (u_char *) "(command line)";
        file->len = sizeof("(command line)") - 1;
        *line = 0;
    } else {
        *file = cf->conf_file->file.name;
        *line = cf->conf_file->line;
    }
}

static void
record_loc_conf_source_location(ngx_conf_t *cf, passenger_loc_conf_t *pl_conf, ngx_str_t *file, ngx_uint_t *line) {
    pl_conf->cscf = ngx_http_conf_get_module_srv_conf(cf, ngx_http_core_module);
    pl_conf->clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
    if (cf->conf_file == NULL) {
        file->data = (u_char *) NULL;
        file->len = 0;
        *line = 0;
    } else if (cf->conf_file->file.fd == NGX_INVALID_FILE) {
        file->data = (u_char *) "(command line)";
        file->len = sizeof("(command line)") - 1;
        *line = 0;
    } else {
        *file = cf->conf_file->file.name;
        *line = cf->conf_file->line;
    }
}


static char *
passenger_conf_set_root(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.root_dir_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.root_dir_source_file,
        &passenger_conf->autogenerated.root_dir_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_ctl(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.ctl_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.ctl_source_file,
        &passenger_conf->autogenerated.ctl_source_line);

    return ngx_conf_set_keyval_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_abort_on_startup_error(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.abort_on_startup_error_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.abort_on_startup_error_source_file,
        &passenger_conf->autogenerated.abort_on_startup_error_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_dump_config_manifest(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.dump_config_manifest_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.dump_config_manifest_source_file,
        &passenger_conf->autogenerated.dump_config_manifest_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_log_level(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.log_level_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.log_level_source_file,
        &passenger_conf->autogenerated.log_level_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_log_file(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.log_file_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.log_file_source_file,
        &passenger_conf->autogenerated.log_file_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_disable_log_prefix(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.disable_log_prefix_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.disable_log_prefix_source_file,
        &passenger_conf->autogenerated.disable_log_prefix_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_file_descriptor_log_file(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.file_descriptor_log_file_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.file_descriptor_log_file_source_file,
        &passenger_conf->autogenerated.file_descriptor_log_file_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_data_buffer_dir(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.data_buffer_dir_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.data_buffer_dir_source_file,
        &passenger_conf->autogenerated.data_buffer_dir_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_socket_backlog(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.socket_backlog_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.socket_backlog_source_file,
        &passenger_conf->autogenerated.socket_backlog_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_core_file_descriptor_ulimit(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.core_file_descriptor_ulimit_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.core_file_descriptor_ulimit_source_file,
        &passenger_conf->autogenerated.core_file_descriptor_ulimit_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_disable_security_update_check(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.disable_security_update_check_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.disable_security_update_check_source_file,
        &passenger_conf->autogenerated.disable_security_update_check_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_security_update_check_proxy(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.security_update_check_proxy_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.security_update_check_proxy_source_file,
        &passenger_conf->autogenerated.security_update_check_proxy_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_disable_anonymous_telemetry(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.disable_anonymous_telemetry_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.disable_anonymous_telemetry_source_file,
        &passenger_conf->autogenerated.disable_anonymous_telemetry_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_anonymous_telemetry_proxy(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.anonymous_telemetry_proxy_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.anonymous_telemetry_proxy_source_file,
        &passenger_conf->autogenerated.anonymous_telemetry_proxy_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_pre_start(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.prestart_uris_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.prestart_uris_source_file,
        &passenger_conf->autogenerated.prestart_uris_source_line);

    return ngx_conf_set_str_array_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_instance_registry_dir(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.instance_registry_dir_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.instance_registry_dir_source_file,
        &passenger_conf->autogenerated.instance_registry_dir_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_spawn_dir(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.spawn_dir_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.spawn_dir_source_file,
        &passenger_conf->autogenerated.spawn_dir_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_turbocaching(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.turbocaching_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.turbocaching_source_file,
        &passenger_conf->autogenerated.turbocaching_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_old_routing(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.old_routing_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.old_routing_source_file,
        &passenger_conf->autogenerated.old_routing_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_user_switching(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.user_switching_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.user_switching_source_file,
        &passenger_conf->autogenerated.user_switching_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_default_user(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.default_user_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.default_user_source_file,
        &passenger_conf->autogenerated.default_user_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_default_group(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.default_group_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.default_group_source_file,
        &passenger_conf->autogenerated.default_group_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_max_pool_size(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.max_pool_size_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.max_pool_size_source_file,
        &passenger_conf->autogenerated.max_pool_size_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_pool_idle_time(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.pool_idle_time_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.pool_idle_time_source_file,
        &passenger_conf->autogenerated.pool_idle_time_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_response_buffer_high_watermark(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.response_buffer_high_watermark_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.response_buffer_high_watermark_source_file,
        &passenger_conf->autogenerated.response_buffer_high_watermark_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_stat_throttle_rate(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.stat_throttle_rate_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.stat_throttle_rate_source_file,
        &passenger_conf->autogenerated.stat_throttle_rate_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_show_version_in_header(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.show_version_in_header_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.show_version_in_header_source_file,
        &passenger_conf->autogenerated.show_version_in_header_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_app_file_descriptor_ulimit(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.app_file_descriptor_ulimit_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.app_file_descriptor_ulimit_source_file,
        &passenger_conf->autogenerated.app_file_descriptor_ulimit_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_max_instances_per_app(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_main_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.max_instances_per_app_explicitly_set = 1;
    record_main_conf_source_location(cf,
        &passenger_conf->autogenerated.max_instances_per_app_source_file,
        &passenger_conf->autogenerated.max_instances_per_app_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_ruby(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.ruby_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.ruby_source_file,
        &passenger_conf->autogenerated.ruby_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_python(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.python_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.python_source_file,
        &passenger_conf->autogenerated.python_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_nodejs(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.nodejs_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.nodejs_source_file,
        &passenger_conf->autogenerated.nodejs_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_meteor_app_settings(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.meteor_app_settings_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.meteor_app_settings_source_file,
        &passenger_conf->autogenerated.meteor_app_settings_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_app_env(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.environment_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.environment_source_file,
        &passenger_conf->autogenerated.environment_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_friendly_error_pages(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.friendly_error_pages_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.friendly_error_pages_source_file,
        &passenger_conf->autogenerated.friendly_error_pages_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_custom_error_page(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.custom_error_page_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.custom_error_page_source_file,
        &passenger_conf->autogenerated.custom_error_page_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_min_instances(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.min_instances_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.min_instances_source_file,
        &passenger_conf->autogenerated.min_instances_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_start_timeout(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.start_timeout_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.start_timeout_source_file,
        &passenger_conf->autogenerated.start_timeout_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_app_connect_timeout(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.app_connect_timeout_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.app_connect_timeout_source_file,
        &passenger_conf->autogenerated.app_connect_timeout_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_user(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.user_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.user_source_file,
        &passenger_conf->autogenerated.user_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_group(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.group_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.group_source_file,
        &passenger_conf->autogenerated.group_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_app_group_name(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.app_group_name_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.app_group_name_source_file,
        &passenger_conf->autogenerated.app_group_name_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_monitor_log_file(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.monitor_log_file_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.monitor_log_file_source_file,
        &passenger_conf->autogenerated.monitor_log_file_source_line);

    return ngx_conf_set_str_array_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_app_root(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.app_root_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.app_root_source_file,
        &passenger_conf->autogenerated.app_root_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_app_rights(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.app_rights_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.app_rights_source_file,
        &passenger_conf->autogenerated.app_rights_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_debugger(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.debugger_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.debugger_source_file,
        &passenger_conf->autogenerated.debugger_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_max_preloader_idle_time(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.max_preloader_idle_time_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.max_preloader_idle_time_source_file,
        &passenger_conf->autogenerated.max_preloader_idle_time_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_env_var(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.env_vars_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.env_vars_source_file,
        &passenger_conf->autogenerated.env_vars_source_line);

    return ngx_conf_set_keyval_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_spawn_method(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.spawn_method_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.spawn_method_source_file,
        &passenger_conf->autogenerated.spawn_method_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_direct_instance_request_address(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.direct_instance_request_address_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.direct_instance_request_address_source_file,
        &passenger_conf->autogenerated.direct_instance_request_address_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_load_shell_envvars(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.load_shell_envvars_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.load_shell_envvars_source_file,
        &passenger_conf->autogenerated.load_shell_envvars_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_preload_bundler(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.preload_bundler_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.preload_bundler_source_file,
        &passenger_conf->autogenerated.preload_bundler_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_max_request_queue_size(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.max_request_queue_size_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.max_request_queue_size_source_file,
        &passenger_conf->autogenerated.max_request_queue_size_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_app_type(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.app_type_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.app_type_source_file,
        &passenger_conf->autogenerated.app_type_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_startup_file(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.startup_file_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.startup_file_source_file,
        &passenger_conf->autogenerated.startup_file_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_app_start_command(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.app_start_command_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.app_start_command_source_file,
        &passenger_conf->autogenerated.app_start_command_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_restart_dir(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.restart_dir_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.restart_dir_source_file,
        &passenger_conf->autogenerated.restart_dir_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_abort_websockets_on_process_shutdown(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.abort_websockets_on_process_shutdown_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.abort_websockets_on_process_shutdown_source_file,
        &passenger_conf->autogenerated.abort_websockets_on_process_shutdown_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_force_max_concurrent_requests_per_process(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.force_max_concurrent_requests_per_process_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.force_max_concurrent_requests_per_process_source_file,
        &passenger_conf->autogenerated.force_max_concurrent_requests_per_process_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_max_requests(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.max_requests_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.max_requests_source_file,
        &passenger_conf->autogenerated.max_requests_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_base_uri(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.base_uris_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.base_uris_source_file,
        &passenger_conf->autogenerated.base_uris_source_line);

    return ngx_conf_set_str_array_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_document_root(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.document_root_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.document_root_source_file,
        &passenger_conf->autogenerated.document_root_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_set_header(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.headers_source_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.headers_source_source_file,
        &passenger_conf->autogenerated.headers_source_source_line);

    return ngx_conf_set_keyval_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_pass_header(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.upstream_config_pass_headers_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.upstream_config_pass_headers_source_file,
        &passenger_conf->autogenerated.upstream_config_pass_headers_source_line);

    return ngx_conf_set_str_array_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_headers_hash_max_size(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.headers_hash_max_size_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.headers_hash_max_size_source_file,
        &passenger_conf->autogenerated.headers_hash_max_size_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_headers_hash_bucket_size(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.headers_hash_bucket_size_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.headers_hash_bucket_size_source_file,
        &passenger_conf->autogenerated.headers_hash_bucket_size_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_ignore_client_abort(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.upstream_config_ignore_client_abort_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.upstream_config_ignore_client_abort_source_file,
        &passenger_conf->autogenerated.upstream_config_ignore_client_abort_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_read_timeout(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.upstream_config_read_timeout_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.upstream_config_read_timeout_source_file,
        &passenger_conf->autogenerated.upstream_config_read_timeout_source_line);

    return ngx_conf_set_msec_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_buffer_response(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.upstream_config_buffering_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.upstream_config_buffering_source_file,
        &passenger_conf->autogenerated.upstream_config_buffering_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_intercept_errors(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.upstream_config_intercept_errors_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.upstream_config_intercept_errors_source_file,
        &passenger_conf->autogenerated.upstream_config_intercept_errors_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_request_queue_overflow_status_code(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.request_queue_overflow_status_code_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.request_queue_overflow_status_code_source_file,
        &passenger_conf->autogenerated.request_queue_overflow_status_code_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_spawn_exception_status_code(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.spawn_exception_status_code_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.spawn_exception_status_code_source_file,
        &passenger_conf->autogenerated.spawn_exception_status_code_source_line);

    return ngx_conf_set_num_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_buffer_upload(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.buffer_upload_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.buffer_upload_source_file,
        &passenger_conf->autogenerated.buffer_upload_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_sticky_sessions(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.sticky_sessions_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.sticky_sessions_source_file,
        &passenger_conf->autogenerated.sticky_sessions_source_line);

    return ngx_conf_set_flag_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_sticky_sessions_cookie_name(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.sticky_sessions_cookie_name_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.sticky_sessions_cookie_name_source_file,
        &passenger_conf->autogenerated.sticky_sessions_cookie_name_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_sticky_sessions_cookie_attributes(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.sticky_sessions_cookie_attributes_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.sticky_sessions_cookie_attributes_source_file,
        &passenger_conf->autogenerated.sticky_sessions_cookie_attributes_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

static char *
passenger_conf_set_vary_turbocache_by_cookie(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {
    passenger_loc_conf_t *passenger_conf = conf;

    passenger_conf->autogenerated.vary_turbocache_by_cookie_explicitly_set = 1;
    record_loc_conf_source_location(cf, passenger_conf,
        &passenger_conf->autogenerated.vary_turbocache_by_cookie_source_file,
        &passenger_conf->autogenerated.vary_turbocache_by_cookie_source_line);

    return ngx_conf_set_str_slot(cf, cmd, conf);
}

