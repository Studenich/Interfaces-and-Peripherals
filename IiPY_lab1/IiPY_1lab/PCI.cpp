#include "PCI.h"

using namespace std;

bool PCI::getDevicesInfo()
{
	int count = 0;
	char buff[512];

	HDEVINFO deviceInfo;
	SP_DEVINFO_DATA deviceInfoData;

	if (!getDeviceInfoHandler(deviceInfo)) {
		cout << "Error! Can't get access to device handler" << endl;
		return false;
	}

	deviceInfoData.cbSize = sizeof(deviceInfoData);

	while (SetupDiEnumDeviceInfo(deviceInfo, count, &deviceInfoData)) {

		cout << "Number " << count << endl;
		SetupDiGetDeviceRegistryProperty(deviceInfo, &deviceInfoData, SPDRP_DEVICEDESC, NULL, (BYTE*)buff, 512, NULL);
		cout << "Name - " << buff << endl;
		SetupDiGetDeviceRegistryProperty(deviceInfo, &deviceInfoData, SPDRP_HARDWAREID, NULL, (BYTE*)buff, 512, NULL);
		
		string str = buff;
		string vendorId = str.substr(str.find("VEN_") + 4, str.find("&DEV") - str.find("VEN_") - 4);
		string deviceId = str.substr(str.find("DEV_") + 4, str.find("&SUB") - str.find("DEV_") - 4);

		cout << "Vendor ID - " << vendorId << endl;
		cout << "Device ID - " << deviceId << endl << endl;
		count++;
	}

	return true;
}

bool PCI::getDeviceInfoHandler(HDEVINFO & infoHandler)
{
	return ((infoHandler = SetupDiGetClassDevs(NULL, "PCI", NULL, DIGCF_ALLCLASSES | DIGCF_PRESENT)) != INVALID_HANDLE_VALUE);
}

PCI::PCI()
{
}


PCI::~PCI()
{
}
