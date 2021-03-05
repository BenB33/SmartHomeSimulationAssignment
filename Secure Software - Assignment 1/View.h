#pragma once
#include <string>
#include "Model.h"
#include "Choice.h"


class View
{
public:
	View() = default;

	void printMessage(std::string message);
	

	void printProgramHeader();
	void printLoginHeader();
	void printViewDeviceHeader();
	void printChangeDeviceHeader(std::string deviceName);
	void printSensorConfigureMinMaxHeader();
	void printSensorDetailsHeader();
	void printHistoricDataHeader();

	MainMenuChoice printMainMenu();
	DeviceMenuChoice printDeviceMenu();
	SensorMenuChoice printSensorMenu();

	void printSensorList();
	void displaySensorData(uint16_t minute, int16_t temp, uint16_t humid, uint16_t lux,
		std::string lightState, std::string heatingState, std::string airconState, std::string dehumidState);

	void printHistoricData(uint16_t readingCount, std::string temperature, std::string luxLevel, std::string humidity);

	void printDateDay();
	void printDateMonth();
	void printDateYear();
};