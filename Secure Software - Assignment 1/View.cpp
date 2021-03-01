#include <iostream>
#include <iomanip>
#include <ctime>

#include "View.h"
#include "Validation.h"


void View::printMessage(std::string message)
{
	std::cout << message;
}


void View::printProgramHeader()
{
	time_t currentTime = time(NULL);
	char displayTime[26];
	ctime_s(displayTime, sizeof displayTime, &currentTime);
	std::cout << displayTime << std::endl << std::endl;
}

MainMenuChoice View::printMainMenu()
{
	system("CLS");
	int menuSelection = 0;
	printProgramHeader();
	std::cout << "Autonomous Smart Home System\n----------------------------\n\n";
	std::cout << "[1] Login\n";
	std::cout << "[2] Device Menu\n";
	std::cout << "[3] Sensor Menu\n";
	std::cout << "[4] Exit\n\n";
	std::cout << "> ";

	menuSelection = Validation::integerValidation(4);
	menuSelection--;

	return static_cast<MainMenuChoice>(menuSelection);
}

DeviceMenuChoice View::deviceMenu()
{
	system("CLS");
	int menuSelection = 0;
	printProgramHeader();
	std::cout << "Device Menu\n-----------\n\n";
	std::cout << "[1] View Device Status'\n";
	std::cout << "[2] Change Device Status'\n";
	std::cout << "[3] Configure Device Intensity\n";
	std::cout << "[4] Back...\n\n";
	std::cout << "> ";

	menuSelection = Validation::integerValidation(4);
	menuSelection--;

	return static_cast<DeviceMenuChoice>(menuSelection);
}

SensorMenuChoice View::sensorMenu()
{
	system("CLS");
	int menuSelection = 0;
	printProgramHeader();
	std::cout << "Sensor Menu\n-----------\n\n";
	std::cout << "[1] View Sensor List\n";
	std::cout << "[2] Read Sensor Data\n";
	std::cout << "[3] Back...\n\n";
	std::cout << "> ";

	menuSelection = Validation::integerValidation(3);
	menuSelection--;

	return static_cast<SensorMenuChoice>(menuSelection);
}

void View::printViewDeviceHeader()
{
	printMessage("View Device Status'\n-------------------\n\n");
}


void View::printChangeDeviceHeader(std::string deviceName)
{
	std::cout << "Change " << deviceName << "'s Status." << std::endl << "-------------------------\n\n";
}


void View::printConfigureDeviceIntensityHeader()
{
	printMessage("Configure Device Intensity\n--------------------------\n\n");
}


void View::printSensorDetailsHeader(const Model& model) const
{
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
	std::cout << std::left << std::setfill(' ') << std::setw(13) << "[Minute]";
	std::cout << std::left << std::setfill(' ') << std::setw(13) << "[Temp \370C]";
	std::cout << std::left << std::setfill(' ') << std::setw(13) << "[Humid %]";
	std::cout << std::left << std::setfill(' ') << std::setw(15) << "[Lex Level]";
	std::cout << std::left << std::setfill(' ') << std::setw(13) << "[Light]";
	std::cout << std::left << std::setfill(' ') << std::setw(13) << "[Heating]";
	std::cout << std::left << std::setfill(' ') << std::setw(13) << "[Air-Con]";
	std::cout << std::left << std::setfill(' ') << std::setw(13) << "[Dehumidifier]" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
}

void View::displaySensorData(int minute, int temp, int humid, int lux, std::string lightState, std::string heatingState, std::string airconState, std::string dehumidState)
{
	std::cout << std::left << std::setfill(' ') << std::setw(17) << minute;
	std::cout << std::left << std::setfill(' ') << std::setw(13) << temp;
	std::cout << std::left << std::setfill(' ') << std::setw(13) << humid;
	std::cout << std::left << std::setfill(' ') << std::setw(15) << lux;
	std::cout << std::left << std::setfill(' ') << std::setw(13) << lightState;
	std::cout << std::left << std::setfill(' ') << std::setw(13) << heatingState;
	std::cout << std::left << std::setfill(' ') << std::setw(13) << airconState;
	std::cout << std::left << std::setfill(' ') << std::setw(13) << dehumidState << std::endl;
}