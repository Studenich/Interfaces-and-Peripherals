#pragma once

#include <Windows.h>
#include <iostream>

class Battery
{
private:
public:
	unsigned char ACStatus;
	unsigned char BatteryLifePercent;
	unsigned char BatterySaver;
	unsigned int BatteryLifeTime;

	Battery();
	~Battery();
};

