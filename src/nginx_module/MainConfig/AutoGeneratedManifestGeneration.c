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
 * MainConfig/AutoGeneratedManifestGeneration.c is automatically generated from
 * MainConfig/AutoGeneratedManifestGeneration.c.cxxcodebuilder,
 * using definitions from src/ruby_supportlib/phusion_passenger/nginx/config_options.rb.
 * Edits to MainConfig/AutoGeneratedManifestGeneration.c will be lost.
 *
 * To update MainConfig/AutoGeneratedManifestGeneration.c:
 *   rake nginx
 *
 * To force regeneration of MainConfig/AutoGeneratedManifestGeneration.c:
 *   rm -f src/nginx_module/MainConfig/AutoGeneratedManifestGeneration.c
 *   rake src/nginx_module/MainConfig/AutoGeneratedManifestGeneration.c
 */

#include "../ConfigGeneral/ManifestGeneration.h"

static void
generate_config_manifest_for_autogenerated_main_conf(manifest_gen_ctx_t *ctx, passenger_main_conf_t *conf) {
    PsgJsonValue *option_container, *hierarchy_member;

    if (conf->autogenerated.root_dir_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_root",
            sizeof("passenger_root") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.root_dir_source_file,
            conf->autogenerated.root_dir_source_line);
        psg_json_value_set_str(hierarchy_member, "value",
            (const char *) conf->autogenerated.root_dir.data,
            conf->autogenerated.root_dir.len);
    }
    if (conf->autogenerated.ctl_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_ctl",
            sizeof("passenger_ctl") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.ctl_source_file,
            conf->autogenerated.ctl_source_line);
        psg_json_value_set_str_keyval(hierarchy_member, "value",
            conf->autogenerated.ctl);
    }
    if (conf->autogenerated.abort_on_startup_error_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_abort_on_startup_error",
            sizeof("passenger_abort_on_startup_error") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.abort_on_startup_error_source_file,
            conf->autogenerated.abort_on_startup_error_source_line);
        psg_json_value_set_bool(hierarchy_member, "value",
            conf->autogenerated.abort_on_startup_error);
    }
    if (conf->autogenerated.dump_config_manifest_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_dump_config_manifest",
            sizeof("passenger_dump_config_manifest") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.dump_config_manifest_source_file,
            conf->autogenerated.dump_config_manifest_source_line);
        psg_json_value_set_str(hierarchy_member, "value",
            (const char *) conf->autogenerated.dump_config_manifest.data,
            conf->autogenerated.dump_config_manifest.len);
    }
    if (conf->autogenerated.log_level_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_log_level",
            sizeof("passenger_log_level") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.log_level_source_file,
            conf->autogenerated.log_level_source_line);
        psg_json_value_set_uint(hierarchy_member, "value",
            conf->autogenerated.log_level);
    }
    if (conf->autogenerated.log_file_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_log_file",
            sizeof("passenger_log_file") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.log_file_source_file,
            conf->autogenerated.log_file_source_line);
        psg_json_value_set_str(hierarchy_member, "value",
            (const char *) conf->autogenerated.log_file.data,
            conf->autogenerated.log_file.len);
    }
    if (conf->autogenerated.disable_log_prefix_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_disable_log_prefix",
            sizeof("passenger_disable_log_prefix") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.disable_log_prefix_source_file,
            conf->autogenerated.disable_log_prefix_source_line);
        psg_json_value_set_bool(hierarchy_member, "value",
            conf->autogenerated.disable_log_prefix);
    }
    if (conf->autogenerated.file_descriptor_log_file_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_file_descriptor_log_file",
            sizeof("passenger_file_descriptor_log_file") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.file_descriptor_log_file_source_file,
            conf->autogenerated.file_descriptor_log_file_source_line);
        psg_json_value_set_str(hierarchy_member, "value",
            (const char *) conf->autogenerated.file_descriptor_log_file.data,
            conf->autogenerated.file_descriptor_log_file.len);
    }
    if (conf->autogenerated.data_buffer_dir_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_data_buffer_dir",
            sizeof("passenger_data_buffer_dir") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.data_buffer_dir_source_file,
            conf->autogenerated.data_buffer_dir_source_line);
        psg_json_value_set_str(hierarchy_member, "value",
            (const char *) conf->autogenerated.data_buffer_dir.data,
            conf->autogenerated.data_buffer_dir.len);
    }
    if (conf->autogenerated.socket_backlog_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_socket_backlog",
            sizeof("passenger_socket_backlog") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.socket_backlog_source_file,
            conf->autogenerated.socket_backlog_source_line);
        psg_json_value_set_uint(hierarchy_member, "value",
            conf->autogenerated.socket_backlog);
    }
    if (conf->autogenerated.core_file_descriptor_ulimit_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_core_file_descriptor_ulimit",
            sizeof("passenger_core_file_descriptor_ulimit") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.core_file_descriptor_ulimit_source_file,
            conf->autogenerated.core_file_descriptor_ulimit_source_line);
        psg_json_value_set_uint(hierarchy_member, "value",
            conf->autogenerated.core_file_descriptor_ulimit);
    }
    if (conf->autogenerated.disable_security_update_check_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_disable_security_update_check",
            sizeof("passenger_disable_security_update_check") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.disable_security_update_check_source_file,
            conf->autogenerated.disable_security_update_check_source_line);
        psg_json_value_set_bool(hierarchy_member, "value",
            conf->autogenerated.disable_security_update_check);
    }
    if (conf->autogenerated.security_update_check_proxy_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_security_update_check_proxy",
            sizeof("passenger_security_update_check_proxy") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.security_update_check_proxy_source_file,
            conf->autogenerated.security_update_check_proxy_source_line);
        psg_json_value_set_str(hierarchy_member, "value",
            (const char *) conf->autogenerated.security_update_check_proxy.data,
            conf->autogenerated.security_update_check_proxy.len);
    }
    if (conf->autogenerated.disable_anonymous_telemetry_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_disable_anonymous_telemetry",
            sizeof("passenger_disable_anonymous_telemetry") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.disable_anonymous_telemetry_source_file,
            conf->autogenerated.disable_anonymous_telemetry_source_line);
        psg_json_value_set_bool(hierarchy_member, "value",
            conf->autogenerated.disable_anonymous_telemetry);
    }
    if (conf->autogenerated.anonymous_telemetry_proxy_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_anonymous_telemetry_proxy",
            sizeof("passenger_anonymous_telemetry_proxy") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.anonymous_telemetry_proxy_source_file,
            conf->autogenerated.anonymous_telemetry_proxy_source_line);
        psg_json_value_set_str(hierarchy_member, "value",
            (const char *) conf->autogenerated.anonymous_telemetry_proxy.data,
            conf->autogenerated.anonymous_telemetry_proxy.len);
    }
    if (conf->autogenerated.prestart_uris_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_pre_start",
            sizeof("passenger_pre_start") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.prestart_uris_source_file,
            conf->autogenerated.prestart_uris_source_line);
        psg_json_value_set_str_array(hierarchy_member, "value",
            conf->autogenerated.prestart_uris);
    }
    if (conf->autogenerated.instance_registry_dir_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_instance_registry_dir",
            sizeof("passenger_instance_registry_dir") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.instance_registry_dir_source_file,
            conf->autogenerated.instance_registry_dir_source_line);
        psg_json_value_set_str(hierarchy_member, "value",
            (const char *) conf->autogenerated.instance_registry_dir.data,
            conf->autogenerated.instance_registry_dir.len);
    }
    if (conf->autogenerated.spawn_dir_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_spawn_dir",
            sizeof("passenger_spawn_dir") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.spawn_dir_source_file,
            conf->autogenerated.spawn_dir_source_line);
        psg_json_value_set_str(hierarchy_member, "value",
            (const char *) conf->autogenerated.spawn_dir.data,
            conf->autogenerated.spawn_dir.len);
    }
    if (conf->autogenerated.turbocaching_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_turbocaching",
            sizeof("passenger_turbocaching") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.turbocaching_source_file,
            conf->autogenerated.turbocaching_source_line);
        psg_json_value_set_bool(hierarchy_member, "value",
            conf->autogenerated.turbocaching);
    }
    if (conf->autogenerated.old_routing_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_old_routing",
            sizeof("passenger_old_routing") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.old_routing_source_file,
            conf->autogenerated.old_routing_source_line);
        psg_json_value_set_bool(hierarchy_member, "value",
            conf->autogenerated.old_routing);
    }
    if (conf->autogenerated.user_switching_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_user_switching",
            sizeof("passenger_user_switching") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.user_switching_source_file,
            conf->autogenerated.user_switching_source_line);
        psg_json_value_set_bool(hierarchy_member, "value",
            conf->autogenerated.user_switching);
    }
    if (conf->autogenerated.default_user_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_default_user",
            sizeof("passenger_default_user") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.default_user_source_file,
            conf->autogenerated.default_user_source_line);
        psg_json_value_set_str(hierarchy_member, "value",
            (const char *) conf->autogenerated.default_user.data,
            conf->autogenerated.default_user.len);
    }
    if (conf->autogenerated.default_group_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_default_group",
            sizeof("passenger_default_group") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.default_group_source_file,
            conf->autogenerated.default_group_source_line);
        psg_json_value_set_str(hierarchy_member, "value",
            (const char *) conf->autogenerated.default_group.data,
            conf->autogenerated.default_group.len);
    }
    if (conf->autogenerated.max_pool_size_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_max_pool_size",
            sizeof("passenger_max_pool_size") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.max_pool_size_source_file,
            conf->autogenerated.max_pool_size_source_line);
        psg_json_value_set_uint(hierarchy_member, "value",
            conf->autogenerated.max_pool_size);
    }
    if (conf->autogenerated.pool_idle_time_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_pool_idle_time",
            sizeof("passenger_pool_idle_time") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.pool_idle_time_source_file,
            conf->autogenerated.pool_idle_time_source_line);
        psg_json_value_set_uint(hierarchy_member, "value",
            conf->autogenerated.pool_idle_time);
    }
    if (conf->autogenerated.response_buffer_high_watermark_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_response_buffer_high_watermark",
            sizeof("passenger_response_buffer_high_watermark") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.response_buffer_high_watermark_source_file,
            conf->autogenerated.response_buffer_high_watermark_source_line);
        psg_json_value_set_uint(hierarchy_member, "value",
            conf->autogenerated.response_buffer_high_watermark);
    }
    if (conf->autogenerated.stat_throttle_rate_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_stat_throttle_rate",
            sizeof("passenger_stat_throttle_rate") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.stat_throttle_rate_source_file,
            conf->autogenerated.stat_throttle_rate_source_line);
        psg_json_value_set_uint(hierarchy_member, "value",
            conf->autogenerated.stat_throttle_rate);
    }
    if (conf->autogenerated.show_version_in_header_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_show_version_in_header",
            sizeof("passenger_show_version_in_header") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.show_version_in_header_source_file,
            conf->autogenerated.show_version_in_header_source_line);
        psg_json_value_set_bool(hierarchy_member, "value",
            conf->autogenerated.show_version_in_header);
    }
    if (conf->autogenerated.app_file_descriptor_ulimit_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_app_file_descriptor_ulimit",
            sizeof("passenger_app_file_descriptor_ulimit") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.app_file_descriptor_ulimit_source_file,
            conf->autogenerated.app_file_descriptor_ulimit_source_line);
        psg_json_value_set_uint(hierarchy_member, "value",
            conf->autogenerated.app_file_descriptor_ulimit);
    }
    if (conf->autogenerated.max_instances_per_app_explicitly_set) {
        option_container = find_or_create_manifest_option_container(ctx,
            ctx->global_config_container,
            "passenger_max_instances_per_app",
            sizeof("passenger_max_instances_per_app") - 1);
        hierarchy_member = add_manifest_option_container_hierarchy_member(option_container,
            &conf->autogenerated.max_instances_per_app_source_file,
            conf->autogenerated.max_instances_per_app_source_line);
        psg_json_value_set_uint(hierarchy_member, "value",
            conf->autogenerated.max_instances_per_app);
    }

    /*
     * No autogenerated code for:
     * (none)
     */
}

