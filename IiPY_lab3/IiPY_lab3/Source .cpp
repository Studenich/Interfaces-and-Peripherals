#include <iostream>
#include <Windows.h>

#include "Battery.h"

using namespace std;

void showInfo(Battery battery) {
	cout << "AC line status:\t\t";
	switch (battery.ACStatus) {
		case 0: cout << "Offline" << endl; break;
		case 1: cout << "Online" << endl; break;
		default: cout << "Unknown status" << endl; break;
	}
	cout << "Life percent:\t\t" << (int)battery.BatteryLifePercent << endl;
	cout << "Saver status:\t\t";
	switch (battery.BatterySaver) {
		case 0: cout << "Off" << endl; break;
		case 1: cout << "On" << endl; break;
		default: cout << "Unknown status" << endl; break;
	}
	cout << "Battery life time:\t";
	cout << battery.BatteryLifeTime / 3600 << " h, ";
	cout << (battery.BatteryLifeTime - (battery.BatteryLifeTime / 3600)*3600)/60 << " min" << endl;
}

int main() {
	

	while (true) {
		Battery battery;
		showInfo(battery);
		Sleep(100);
		system("cls");
		battery.~Battery();
	}

	system("pause");

	return EXIT_SUCCESS;
}