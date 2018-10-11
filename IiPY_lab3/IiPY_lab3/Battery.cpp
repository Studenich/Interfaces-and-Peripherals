#include "Battery.h"

Battery::Battery()
{
	SYSTEM_POWER_STATUS batteryState;

	if (!GetSystemPowerStatus(&batteryState)) {
		std::cout << GetLastError() << std::endl;
		exit(-1);
	}

	ACStatus = (char)batteryState.ACLineStatus;
	BatteryLifePercent = (char)batteryState.BatteryLifePercent;
	BatterySaver = (char)batteryState.SystemStatusFlag;
	BatteryLifeTime = (int)batteryState.BatteryLifeTime;
}


Battery::~Battery()
{
	ACStatus = 0;
	BatteryLifePercent = 0;
	BatterySaver = 0;
}
