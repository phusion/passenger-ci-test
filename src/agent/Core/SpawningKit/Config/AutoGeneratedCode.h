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
 * SpawningKit/Config/AutoGeneratedCode.h is automatically generated from
 * SpawningKit/Config/AutoGeneratedCode.h.cxxcodebuilder by the build system.
 * It uses the comment hints from SpawningKit/Config.h.
 *
 * To force regenerating this file:
 *   rm -f src/agent/Core/SpawningKit/Config/AutoGeneratedCode.h
 *   rake src/agent/Core/SpawningKit/Config/AutoGeneratedCode.h
 */

inline void
Passenger::SpawningKit::Config::internStrings() {
	size_t totalSize = 0;
	size_t tmpSize;
	char *newStorage, *pos, *end;

	/*
	 * Calculated required storage size
	 */
	totalSize += appGroupName.size() + 1;
	totalSize += appRoot.size() + 1;
	totalSize += startCommand.size() + 1;
	totalSize += startupFile.size() + 1;
	totalSize += processTitle.size() + 1;
	totalSize += appType.size() + 1;
	totalSize += appEnv.size() + 1;
	totalSize += spawnMethod.size() + 1;
	totalSize += bindAddress.size() + 1;
	totalSize += baseURI.size() + 1;
	totalSize += user.size() + 1;
	totalSize += group.size() + 1;
	{
		StringKeyTable<StaticString>::ConstIterator it(environmentVariables);
		while (*it != NULL) {
			totalSize += it.getValue().size() + 1;
			it.next();
		}
	}
	totalSize += logFile.size() + 1;
	totalSize += apiKey.size() + 1;
	totalSize += groupUuid.size() + 1;

	/*
	 * Allocate new storage
	 */
	newStorage = pos = new char[totalSize];
	end = newStorage + totalSize;

	/*
	 * Fill new storage
	 */
	pos = appendData(pos, end, appGroupName);
	pos = appendData(pos, end, "\0", 1);
	pos = appendData(pos, end, appRoot);
	pos = appendData(pos, end, "\0", 1);
	pos = appendData(pos, end, startCommand);
	pos = appendData(pos, end, "\0", 1);
	pos = appendData(pos, end, startupFile);
	pos = appendData(pos, end, "\0", 1);
	pos = appendData(pos, end, processTitle);
	pos = appendData(pos, end, "\0", 1);
	pos = appendData(pos, end, appType);
	pos = appendData(pos, end, "\0", 1);
	pos = appendData(pos, end, appEnv);
	pos = appendData(pos, end, "\0", 1);
	pos = appendData(pos, end, spawnMethod);
	pos = appendData(pos, end, "\0", 1);
	pos = appendData(pos, end, bindAddress);
	pos = appendData(pos, end, "\0", 1);
	pos = appendData(pos, end, baseURI);
	pos = appendData(pos, end, "\0", 1);
	pos = appendData(pos, end, user);
	pos = appendData(pos, end, "\0", 1);
	pos = appendData(pos, end, group);
	pos = appendData(pos, end, "\0", 1);
	{
		StringKeyTable<StaticString>::Iterator it(environmentVariables);
		while (*it != NULL) {
			pos = appendData(pos, end, it.getValue());
			pos = appendData(pos, end, "\0", 1);
			it.next();
		}
	}
	pos = appendData(pos, end, logFile);
	pos = appendData(pos, end, "\0", 1);
	pos = appendData(pos, end, apiKey);
	pos = appendData(pos, end, "\0", 1);
	pos = appendData(pos, end, groupUuid);
	pos = appendData(pos, end, "\0", 1);

	/*
	 * Move over pointers to new storage
	 */
	pos = newStorage;
	tmpSize = appGroupName.size();
	appGroupName = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	tmpSize = appRoot.size();
	appRoot = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	tmpSize = startCommand.size();
	startCommand = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	tmpSize = startupFile.size();
	startupFile = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	tmpSize = processTitle.size();
	processTitle = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	tmpSize = appType.size();
	appType = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	tmpSize = appEnv.size();
	appEnv = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	tmpSize = spawnMethod.size();
	spawnMethod = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	tmpSize = bindAddress.size();
	bindAddress = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	tmpSize = baseURI.size();
	baseURI = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	tmpSize = user.size();
	user = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	tmpSize = group.size();
	group = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	{
		StringKeyTable<StaticString>::Iterator it(environmentVariables);
		while (*it != NULL) {
			tmpSize = it.getValue().size();
			it.getValue() = StaticString(pos, tmpSize);
			pos += tmpSize + 1;
			it.next();
		}
	}

	tmpSize = logFile.size();
	logFile = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	tmpSize = apiKey.size();
	apiKey = StaticString(pos, tmpSize);
	pos += tmpSize + 1;

	tmpSize = groupUuid.size();
	groupUuid = StaticString(pos, tmpSize);
	pos += tmpSize + 1;


	/*
	 * Commit current storage
	 */
	storage.reset(newStorage);
}

inline bool
Passenger::SpawningKit::Config::validate(vector<StaticString> &errors) const {
	bool ok = true;
	const Config &config = *this;

	if (OXT_UNLIKELY(appGroupName.empty())) {
		ok = false;
		errors.push_back(P_STATIC_STRING("app_group_name may not be empty"));
	}
	if (OXT_UNLIKELY(appRoot.empty())) {
		ok = false;
		errors.push_back(P_STATIC_STRING("app_root may not be empty"));
	}
	if (OXT_UNLIKELY(startCommand.empty())) {
		ok = false;
		errors.push_back(P_STATIC_STRING("start_command may not be empty"));
	}
	if (!config.genericApp && config.startsUsingWrapper && OXT_UNLIKELY(startupFile.empty())) {
		ok = false;
		errors.push_back(P_STATIC_STRING("startup_file may not be empty"));
	}
	if (OXT_UNLIKELY(appType.empty())) {
		ok = false;
		errors.push_back(P_STATIC_STRING("app_type may not be empty"));
	}
	if (OXT_UNLIKELY(appEnv.empty())) {
		ok = false;
		errors.push_back(P_STATIC_STRING("app_env may not be empty"));
	}
	if (OXT_UNLIKELY(spawnMethod.empty())) {
		ok = false;
		errors.push_back(P_STATIC_STRING("spawn_method may not be empty"));
	}
	if (OXT_UNLIKELY(bindAddress.empty())) {
		ok = false;
		errors.push_back(P_STATIC_STRING("bind_address may not be empty"));
	}
	if (OXT_UNLIKELY(baseURI.empty())) {
		ok = false;
		errors.push_back(P_STATIC_STRING("base_uri may not be empty"));
	}
	if (OXT_UNLIKELY(user.empty())) {
		ok = false;
		errors.push_back(P_STATIC_STRING("user may not be empty"));
	}
	if (OXT_UNLIKELY(group.empty())) {
		ok = false;
		errors.push_back(P_STATIC_STRING("group may not be empty"));
	}
	if (OXT_UNLIKELY(!(config.startTimeoutMsec > 0))) {
		ok = false;
		errors.push_back(P_STATIC_STRING("start_timeout_msec does not satisfy requirement: "
			"config.startTimeoutMsec > 0"));
	}

	/*
	 * Excluded:
	 *
	 * logLevel
	 * genericApp
	 * startsUsingWrapper
	 * wrapperSuppliedByThirdParty
	 * findFreePort
	 * preloadBundler
	 * loadShellEnvvars
	 * debugWorkDir
	 * processTitle
	 * environmentVariables
	 * logFile
	 * apiKey
	 * groupUuid
	 * lveMinUid
	 * fileDescriptorUlimit
	 */

	return ok;
}

inline Json::Value
Passenger::SpawningKit::Config::getConfidentialFieldsToPassToApp() const {
	Json::Value doc;
	const Config &config = *this;

	doc["app_group_name"] = appGroupName.toString();
	doc["app_root"] = appRoot.toString();
	doc["log_level"] = logLevel;
	doc["generic_app"] = genericApp;
	if (!config.genericApp) {
		doc["starts_using_wrapper"] = startsUsingWrapper;
	}
	if (!config.genericApp && config.startsUsingWrapper) {
		doc["wrapper_supplied_by_third_party"] = wrapperSuppliedByThirdParty;
	}
	if (config.appType == "ruby") {
		doc["preload_bundler"] = preloadBundler;
	}
	doc["load_shell_envvars"] = loadShellEnvvars;
	doc["start_command"] = startCommand.toString();
	if (!config.genericApp && config.startsUsingWrapper) {
		doc["startup_file"] = startupFile.toString();
	}
	if (!config.processTitle.empty()) {
		doc["process_title"] = processTitle.toString();
	}
	doc["app_type"] = appType.toString();
	doc["app_env"] = appEnv.toString();
	doc["spawn_method"] = spawnMethod.toString();
	doc["bind_address"] = bindAddress.toString();
	doc["base_uri"] = baseURI.toString();
	doc["user"] = user.toString();
	doc["group"] = group.toString();
	doc["environment_variables"] = tableToJson(environmentVariables);
	doc["log_file"] = logFile.toString();
	if (!config.apiKey.empty()) {
		doc["api_key"] = apiKey.toString();
	}
	if (!config.groupUuid.empty()) {
		doc["group_uuid"] = groupUuid.toString();
	}
	if (config.fileDescriptorUlimit > 0) {
		doc["file_descriptor_ulimit"] = fileDescriptorUlimit;
	}

	/*
	 * Excluded:
	 *
	 * findFreePort
	 * debugWorkDir
	 * lveMinUid
	 * startTimeoutMsec
	 */

	return doc;
}

inline Json::Value
Passenger::SpawningKit::Config::getNonConfidentialFieldsToPassToApp() const {
	Json::Value doc;
	const Config &config = *this;

	doc["app_group_name"] = appGroupName.toString();
	doc["app_root"] = appRoot.toString();
	doc["log_level"] = logLevel;
	doc["generic_app"] = genericApp;
	if (!config.genericApp) {
		doc["starts_using_wrapper"] = startsUsingWrapper;
	}
	if (!config.genericApp && config.startsUsingWrapper) {
		doc["wrapper_supplied_by_third_party"] = wrapperSuppliedByThirdParty;
	}
	if (config.appType == "ruby") {
		doc["preload_bundler"] = preloadBundler;
	}
	doc["load_shell_envvars"] = loadShellEnvvars;
	doc["start_command"] = startCommand.toString();
	if (!config.genericApp && config.startsUsingWrapper) {
		doc["startup_file"] = startupFile.toString();
	}
	if (!config.processTitle.empty()) {
		doc["process_title"] = processTitle.toString();
	}
	doc["app_type"] = appType.toString();
	doc["app_env"] = appEnv.toString();
	doc["spawn_method"] = spawnMethod.toString();
	doc["bind_address"] = bindAddress.toString();
	doc["base_uri"] = baseURI.toString();
	doc["user"] = user.toString();
	doc["group"] = group.toString();
	doc["environment_variables"] = "<SECRET>";
	doc["log_file"] = logFile.toString();
	if (!config.apiKey.empty()) {
		doc["api_key"] = "<SECRET>";
	}
	if (!config.groupUuid.empty()) {
		doc["group_uuid"] = "<SECRET>";
	}
	if (config.fileDescriptorUlimit > 0) {
		doc["file_descriptor_ulimit"] = fileDescriptorUlimit;
	}

	/*
	 * Excluded:
	 *
	 * findFreePort
	 * debugWorkDir
	 * lveMinUid
	 * startTimeoutMsec
	 */

	return doc;
}

