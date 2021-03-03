#pragma once
#include <string>
#include "Model.h"
#include "Choice.h"
#include "Validation.h"


class View
{
private:
	Validation validation;

public:
	void printMessage(std::string message);

	void printProgramHeader();

	void printLoginHeader();

	void printSensorList();
	void printSensorDetailsHeader() const;
	void displaySensorData(int minute, int temp, int humid, int lux, 
						   std::string lightState, std::string heatingState, std::string airconState, std::string dehumidState);

	void printViewDeviceHeader();
	void printChangeDeviceHeader(std::string deviceName);
	void printConfigureDeviceIntensityHeader();

	void printDateDay();
	void printDateMonth();
	void printDateYear();
	void printHistoricData(uint16_t readingCount, std::string temperature, std::string luxLevel, std::string humidity);
	void printHistoricDataHeader();

	MainMenuChoice printMainMenu();
	DeviceMenuChoice deviceMenu();
	SensorMenuChoice sensorMenu();
};