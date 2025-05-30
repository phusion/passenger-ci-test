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

#ifdef INTELLISENSE
	// These includes do nothing, but keep IntelliSense happy.
	#include <ap_config.h>
	#include "../Config.h"
#endif

/*
 * DirConfig/AutoGeneratedMergeFunction.cpp is automatically generated from DirConfig/AutoGeneratedMergeFunction.cpp.cxxcodebuilder,
 * using definitions from src/ruby_supportlib/phusion_passenger/apache2/config_options.rb.
 * Edits to DirConfig/AutoGeneratedMergeFunction.cpp will be lost.
 *
 * To update DirConfig/AutoGeneratedMergeFunction.cpp:
 *   rake apache2
 *
 * To force regeneration of DirConfig/AutoGeneratedMergeFunction.cpp:
 *   rm -f src/apache2_module/DirConfig/AutoGeneratedMergeFunction.cpp
 *   rake src/apache2_module/DirConfig/AutoGeneratedMergeFunction.cpp
 */

namespace Passenger {
namespace Apache2Module {

static void
mergeDirConfig_autoGenerated(DirConfig *config, DirConfig *base, DirConfig *add) {
	config->mAllowEncodedSlashes =
		(add->mAllowEncodedSlashes != Apache2Module::UNSET)
		? add->mAllowEncodedSlashes
		: base->mAllowEncodedSlashes;
	config->mAppConnectTimeout =
		(add->mAppConnectTimeout != UNSET_INT_VALUE)
		? add->mAppConnectTimeout
		: base->mAppConnectTimeout;
	config->mAppEnv =
		(!add->mAppEnv.empty())
		? add->mAppEnv
		: base->mAppEnv;
	config->mAppGroupName =
		(!add->mAppGroupName.empty())
		? add->mAppGroupName
		: base->mAppGroupName;
	config->mAppLogFile =
		(!add->mAppLogFile.empty())
		? add->mAppLogFile
		: base->mAppLogFile;
	config->mAppRoot =
		(!add->mAppRoot.empty())
		? add->mAppRoot
		: base->mAppRoot;
	config->mAppStartCommand =
		(!add->mAppStartCommand.empty())
		? add->mAppStartCommand
		: base->mAppStartCommand;
	config->mAppType =
		(!add->mAppType.empty())
		? add->mAppType
		: base->mAppType;
	config->mBaseURIs =
		(!add->mBaseURIs.empty())
		? add->mBaseURIs
		: base->mBaseURIs;
	config->mBufferResponse =
		(add->mBufferResponse != Apache2Module::UNSET)
		? add->mBufferResponse
		: base->mBufferResponse;
	config->mBufferUpload =
		(add->mBufferUpload != Apache2Module::UNSET)
		? add->mBufferUpload
		: base->mBufferUpload;
	config->mCustomErrorPage =
		(!add->mCustomErrorPage.empty())
		? add->mCustomErrorPage
		: base->mCustomErrorPage;
	config->mDirectInstanceRequestAddress =
		(!add->mDirectInstanceRequestAddress.empty())
		? add->mDirectInstanceRequestAddress
		: base->mDirectInstanceRequestAddress;
	config->mEnabled =
		(add->mEnabled != Apache2Module::UNSET)
		? add->mEnabled
		: base->mEnabled;
	config->mErrorOverride =
		(add->mErrorOverride != Apache2Module::UNSET)
		? add->mErrorOverride
		: base->mErrorOverride;
	config->mForceMaxConcurrentRequestsPerProcess =
		(add->mForceMaxConcurrentRequestsPerProcess != UNSET_INT_VALUE)
		? add->mForceMaxConcurrentRequestsPerProcess
		: base->mForceMaxConcurrentRequestsPerProcess;
	config->mFriendlyErrorPages =
		(add->mFriendlyErrorPages != Apache2Module::UNSET)
		? add->mFriendlyErrorPages
		: base->mFriendlyErrorPages;
	config->mGroup =
		(!add->mGroup.empty())
		? add->mGroup
		: base->mGroup;
	config->mHighPerformance =
		(add->mHighPerformance != Apache2Module::UNSET)
		? add->mHighPerformance
		: base->mHighPerformance;
	config->mLoadShellEnvvars =
		(add->mLoadShellEnvvars != Apache2Module::UNSET)
		? add->mLoadShellEnvvars
		: base->mLoadShellEnvvars;
	config->mLveMinUid =
		(add->mLveMinUid != UNSET_INT_VALUE)
		? add->mLveMinUid
		: base->mLveMinUid;
	config->mMaxPreloaderIdleTime =
		(add->mMaxPreloaderIdleTime != UNSET_INT_VALUE)
		? add->mMaxPreloaderIdleTime
		: base->mMaxPreloaderIdleTime;
	config->mMaxRequestQueueSize =
		(add->mMaxRequestQueueSize != UNSET_INT_VALUE)
		? add->mMaxRequestQueueSize
		: base->mMaxRequestQueueSize;
	config->mMaxRequests =
		(add->mMaxRequests != UNSET_INT_VALUE)
		? add->mMaxRequests
		: base->mMaxRequests;
	config->mMeteorAppSettings =
		(!add->mMeteorAppSettings.empty())
		? add->mMeteorAppSettings
		: base->mMeteorAppSettings;
	config->mMinInstances =
		(add->mMinInstances != UNSET_INT_VALUE)
		? add->mMinInstances
		: base->mMinInstances;
	config->mMonitorLogFile =
		(!add->mMonitorLogFile.empty())
		? add->mMonitorLogFile
		: base->mMonitorLogFile;
	config->mNodejs =
		(!add->mNodejs.empty())
		? add->mNodejs
		: base->mNodejs;
	config->mPreloadBundler =
		(add->mPreloadBundler != Apache2Module::UNSET)
		? add->mPreloadBundler
		: base->mPreloadBundler;
	config->mPython =
		(!add->mPython.empty())
		? add->mPython
		: base->mPython;
	config->mRestartDir =
		(!add->mRestartDir.empty())
		? add->mRestartDir
		: base->mRestartDir;
	config->mRuby =
		(!add->mRuby.empty())
		? add->mRuby
		: base->mRuby;
	config->mSpawnMethod =
		(!add->mSpawnMethod.empty())
		? add->mSpawnMethod
		: base->mSpawnMethod;
	config->mStartTimeout =
		(add->mStartTimeout != UNSET_INT_VALUE)
		? add->mStartTimeout
		: base->mStartTimeout;
	config->mStartupFile =
		(!add->mStartupFile.empty())
		? add->mStartupFile
		: base->mStartupFile;
	config->mStickySessions =
		(add->mStickySessions != Apache2Module::UNSET)
		? add->mStickySessions
		: base->mStickySessions;
	config->mStickySessionsCookieAttributes =
		(!add->mStickySessionsCookieAttributes.empty())
		? add->mStickySessionsCookieAttributes
		: base->mStickySessionsCookieAttributes;
	config->mStickySessionsCookieName =
		(!add->mStickySessionsCookieName.empty())
		? add->mStickySessionsCookieName
		: base->mStickySessionsCookieName;
	config->mUser =
		(!add->mUser.empty())
		? add->mUser
		: base->mUser;

	config->mAllowEncodedSlashesSourceFile = add->mAllowEncodedSlashesSourceFile;
	config->mAppConnectTimeoutSourceFile = add->mAppConnectTimeoutSourceFile;
	config->mAppEnvSourceFile = add->mAppEnvSourceFile;
	config->mAppGroupNameSourceFile = add->mAppGroupNameSourceFile;
	config->mAppLogFileSourceFile = add->mAppLogFileSourceFile;
	config->mAppRootSourceFile = add->mAppRootSourceFile;
	config->mAppStartCommandSourceFile = add->mAppStartCommandSourceFile;
	config->mAppTypeSourceFile = add->mAppTypeSourceFile;
	config->mBaseURIsSourceFile = add->mBaseURIsSourceFile;
	config->mBufferResponseSourceFile = add->mBufferResponseSourceFile;
	config->mBufferUploadSourceFile = add->mBufferUploadSourceFile;
	config->mCustomErrorPageSourceFile = add->mCustomErrorPageSourceFile;
	config->mDirectInstanceRequestAddressSourceFile = add->mDirectInstanceRequestAddressSourceFile;
	config->mEnabledSourceFile = add->mEnabledSourceFile;
	config->mErrorOverrideSourceFile = add->mErrorOverrideSourceFile;
	config->mForceMaxConcurrentRequestsPerProcessSourceFile = add->mForceMaxConcurrentRequestsPerProcessSourceFile;
	config->mFriendlyErrorPagesSourceFile = add->mFriendlyErrorPagesSourceFile;
	config->mGroupSourceFile = add->mGroupSourceFile;
	config->mHighPerformanceSourceFile = add->mHighPerformanceSourceFile;
	config->mLoadShellEnvvarsSourceFile = add->mLoadShellEnvvarsSourceFile;
	config->mLveMinUidSourceFile = add->mLveMinUidSourceFile;
	config->mMaxPreloaderIdleTimeSourceFile = add->mMaxPreloaderIdleTimeSourceFile;
	config->mMaxRequestQueueSizeSourceFile = add->mMaxRequestQueueSizeSourceFile;
	config->mMaxRequestsSourceFile = add->mMaxRequestsSourceFile;
	config->mMeteorAppSettingsSourceFile = add->mMeteorAppSettingsSourceFile;
	config->mMinInstancesSourceFile = add->mMinInstancesSourceFile;
	config->mMonitorLogFileSourceFile = add->mMonitorLogFileSourceFile;
	config->mNodejsSourceFile = add->mNodejsSourceFile;
	config->mPreloadBundlerSourceFile = add->mPreloadBundlerSourceFile;
	config->mPythonSourceFile = add->mPythonSourceFile;
	config->mRestartDirSourceFile = add->mRestartDirSourceFile;
	config->mRubySourceFile = add->mRubySourceFile;
	config->mSpawnMethodSourceFile = add->mSpawnMethodSourceFile;
	config->mStartTimeoutSourceFile = add->mStartTimeoutSourceFile;
	config->mStartupFileSourceFile = add->mStartupFileSourceFile;
	config->mStickySessionsSourceFile = add->mStickySessionsSourceFile;
	config->mStickySessionsCookieAttributesSourceFile = add->mStickySessionsCookieAttributesSourceFile;
	config->mStickySessionsCookieNameSourceFile = add->mStickySessionsCookieNameSourceFile;
	config->mUserSourceFile = add->mUserSourceFile;

	config->mAllowEncodedSlashesSourceLine = add->mAllowEncodedSlashesSourceLine;
	config->mAppConnectTimeoutSourceLine = add->mAppConnectTimeoutSourceLine;
	config->mAppEnvSourceLine = add->mAppEnvSourceLine;
	config->mAppGroupNameSourceLine = add->mAppGroupNameSourceLine;
	config->mAppLogFileSourceLine = add->mAppLogFileSourceLine;
	config->mAppRootSourceLine = add->mAppRootSourceLine;
	config->mAppStartCommandSourceLine = add->mAppStartCommandSourceLine;
	config->mAppTypeSourceLine = add->mAppTypeSourceLine;
	config->mBaseURIsSourceLine = add->mBaseURIsSourceLine;
	config->mBufferResponseSourceLine = add->mBufferResponseSourceLine;
	config->mBufferUploadSourceLine = add->mBufferUploadSourceLine;
	config->mCustomErrorPageSourceLine = add->mCustomErrorPageSourceLine;
	config->mDirectInstanceRequestAddressSourceLine = add->mDirectInstanceRequestAddressSourceLine;
	config->mEnabledSourceLine = add->mEnabledSourceLine;
	config->mErrorOverrideSourceLine = add->mErrorOverrideSourceLine;
	config->mForceMaxConcurrentRequestsPerProcessSourceLine = add->mForceMaxConcurrentRequestsPerProcessSourceLine;
	config->mFriendlyErrorPagesSourceLine = add->mFriendlyErrorPagesSourceLine;
	config->mGroupSourceLine = add->mGroupSourceLine;
	config->mHighPerformanceSourceLine = add->mHighPerformanceSourceLine;
	config->mLoadShellEnvvarsSourceLine = add->mLoadShellEnvvarsSourceLine;
	config->mLveMinUidSourceLine = add->mLveMinUidSourceLine;
	config->mMaxPreloaderIdleTimeSourceLine = add->mMaxPreloaderIdleTimeSourceLine;
	config->mMaxRequestQueueSizeSourceLine = add->mMaxRequestQueueSizeSourceLine;
	config->mMaxRequestsSourceLine = add->mMaxRequestsSourceLine;
	config->mMeteorAppSettingsSourceLine = add->mMeteorAppSettingsSourceLine;
	config->mMinInstancesSourceLine = add->mMinInstancesSourceLine;
	config->mMonitorLogFileSourceLine = add->mMonitorLogFileSourceLine;
	config->mNodejsSourceLine = add->mNodejsSourceLine;
	config->mPreloadBundlerSourceLine = add->mPreloadBundlerSourceLine;
	config->mPythonSourceLine = add->mPythonSourceLine;
	config->mRestartDirSourceLine = add->mRestartDirSourceLine;
	config->mRubySourceLine = add->mRubySourceLine;
	config->mSpawnMethodSourceLine = add->mSpawnMethodSourceLine;
	config->mStartTimeoutSourceLine = add->mStartTimeoutSourceLine;
	config->mStartupFileSourceLine = add->mStartupFileSourceLine;
	config->mStickySessionsSourceLine = add->mStickySessionsSourceLine;
	config->mStickySessionsCookieAttributesSourceLine = add->mStickySessionsCookieAttributesSourceLine;
	config->mStickySessionsCookieNameSourceLine = add->mStickySessionsCookieNameSourceLine;
	config->mUserSourceLine = add->mUserSourceLine;

	config->mAllowEncodedSlashesExplicitlySet = add->mAllowEncodedSlashesExplicitlySet;
	config->mAppConnectTimeoutExplicitlySet = add->mAppConnectTimeoutExplicitlySet;
	config->mAppEnvExplicitlySet = add->mAppEnvExplicitlySet;
	config->mAppGroupNameExplicitlySet = add->mAppGroupNameExplicitlySet;
	config->mAppLogFileExplicitlySet = add->mAppLogFileExplicitlySet;
	config->mAppRootExplicitlySet = add->mAppRootExplicitlySet;
	config->mAppStartCommandExplicitlySet = add->mAppStartCommandExplicitlySet;
	config->mAppTypeExplicitlySet = add->mAppTypeExplicitlySet;
	config->mBaseURIsExplicitlySet = add->mBaseURIsExplicitlySet;
	config->mBufferResponseExplicitlySet = add->mBufferResponseExplicitlySet;
	config->mBufferUploadExplicitlySet = add->mBufferUploadExplicitlySet;
	config->mCustomErrorPageExplicitlySet = add->mCustomErrorPageExplicitlySet;
	config->mDirectInstanceRequestAddressExplicitlySet = add->mDirectInstanceRequestAddressExplicitlySet;
	config->mEnabledExplicitlySet = add->mEnabledExplicitlySet;
	config->mErrorOverrideExplicitlySet = add->mErrorOverrideExplicitlySet;
	config->mForceMaxConcurrentRequestsPerProcessExplicitlySet = add->mForceMaxConcurrentRequestsPerProcessExplicitlySet;
	config->mFriendlyErrorPagesExplicitlySet = add->mFriendlyErrorPagesExplicitlySet;
	config->mGroupExplicitlySet = add->mGroupExplicitlySet;
	config->mHighPerformanceExplicitlySet = add->mHighPerformanceExplicitlySet;
	config->mLoadShellEnvvarsExplicitlySet = add->mLoadShellEnvvarsExplicitlySet;
	config->mLveMinUidExplicitlySet = add->mLveMinUidExplicitlySet;
	config->mMaxPreloaderIdleTimeExplicitlySet = add->mMaxPreloaderIdleTimeExplicitlySet;
	config->mMaxRequestQueueSizeExplicitlySet = add->mMaxRequestQueueSizeExplicitlySet;
	config->mMaxRequestsExplicitlySet = add->mMaxRequestsExplicitlySet;
	config->mMeteorAppSettingsExplicitlySet = add->mMeteorAppSettingsExplicitlySet;
	config->mMinInstancesExplicitlySet = add->mMinInstancesExplicitlySet;
	config->mMonitorLogFileExplicitlySet = add->mMonitorLogFileExplicitlySet;
	config->mNodejsExplicitlySet = add->mNodejsExplicitlySet;
	config->mPreloadBundlerExplicitlySet = add->mPreloadBundlerExplicitlySet;
	config->mPythonExplicitlySet = add->mPythonExplicitlySet;
	config->mRestartDirExplicitlySet = add->mRestartDirExplicitlySet;
	config->mRubyExplicitlySet = add->mRubyExplicitlySet;
	config->mSpawnMethodExplicitlySet = add->mSpawnMethodExplicitlySet;
	config->mStartTimeoutExplicitlySet = add->mStartTimeoutExplicitlySet;
	config->mStartupFileExplicitlySet = add->mStartupFileExplicitlySet;
	config->mStickySessionsExplicitlySet = add->mStickySessionsExplicitlySet;
	config->mStickySessionsCookieAttributesExplicitlySet = add->mStickySessionsCookieAttributesExplicitlySet;
	config->mStickySessionsCookieNameExplicitlySet = add->mStickySessionsCookieNameExplicitlySet;
	config->mUserExplicitlySet = add->mUserExplicitlySet;
}


} // namespace Apache2Module
} // namespace Passenger
