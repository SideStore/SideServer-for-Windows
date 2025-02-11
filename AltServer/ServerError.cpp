#include "ServerError.hpp"

std::string UnderlyingErrorDomainErrorKey = "underlyingErrorDomain";
std::string UnderlyingErrorCodeErrorKey = "underlyingErrorCode";
std::string ProvisioningProfileBundleIDErrorKey = "bundleIdentifier";
std::string AppNameErrorKey = "appName";
std::string DeviceNameErrorKey = "deviceName";
std::string OperatingSystemNameErrorKey = "ALTOperatingSystemName";
std::string OperatingSystemVersionErrorKey = "ALTOperatingSystemVersion";

std::string NSFilePathErrorKey = "NSFilePath";

std::optional<std::string> ServerError::osVersion() const
{
	if (this->userInfo().count(OperatingSystemNameErrorKey) == 0 || this->userInfo().count(OperatingSystemVersionErrorKey) == 0)
	{
		return std::nullopt;
	}

	std::string osName = AnyStringValue(this->userInfo()[OperatingSystemNameErrorKey]);
	std::string versionString = AnyStringValue(this->userInfo()[OperatingSystemVersionErrorKey]);
	
	auto osVersion = osName + " " + versionString;
	return osVersion;
}