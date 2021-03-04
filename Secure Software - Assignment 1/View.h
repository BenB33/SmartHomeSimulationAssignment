#pragma once
#include <string>
#include "Model.h"
#include "Choice.h"


class View
{
public:
	View() = default;

	void printMessage(std::string message) const;

	void printProgramHeader();
	void printLoginHeader();
	void printSensorDetailsHeader() const;
	void printViewDeviceHeader();
	void printHistoricDataHeader();
	void printChangeDeviceHeader(std::string deviceName);
	void printConfigureDeviceIntensityHeader();
	void printSensorConfigureMinMaxHeader();

	void printSensorList();
	void displaySensorData(uint16_t minute, int temp, uint16_t humid, uint16_t lux,
						   std::string lightState, std::string heatingState, std::string airconState, std::string dehumidState);

	void printDateDay();
	void printDateMonth();
	void printDateYear();
	void printHistoricData(uint16_t readingCount, std::string temperature, std::string luxLevel, std::string humidity);
	
	MainMenuChoice printMainMenu();
	DeviceMenuChoice printDeviceMenu();
	SensorMenuChoice printSensorMenu();
};