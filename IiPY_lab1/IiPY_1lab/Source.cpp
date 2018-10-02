#include <iostream> 
#include <windows.h>
#include "PCI.h"

int main() {
	setlocale(LC_ALL, "Russian");

	PCI::getDevicesInfo();

	system("pause");
	return 0;
}