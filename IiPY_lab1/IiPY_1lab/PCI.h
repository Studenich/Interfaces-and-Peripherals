#pragma once
#include <iostream> 
#include <windows.h> 
#include <setupapi.h> 
#include <string> 

#pragma comment(lib, "setupapi.lib" ) 

class PCI
{
public:
	static bool getDevicesInfo();
	static bool getDeviceInfoHandler(HDEVINFO &infoHandler);

	PCI();
	~PCI();
};

