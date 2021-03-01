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
	const time_t currentTime = time(NULL);
	tm structuredTime{};
	localtime_s(&structuredTime, &currentTime);
	std::cout << "[" << std::put_time(&structuredTime, "%a %d %b %Y - %R]") << std::endl << std::endl;
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
	std::cout << "[4] Historic Data\n";
	std::cout << "[5] Exit\n\n";
	std::cout << "> ";

	menuSelection = Validation::integerValidation(5);
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
	std::cout << std::left << std::setfill(' ') << std::setw(13) << "[Heating]";
	std::cout << std::left << std::setfill(' ') << std::setw(13) << "[Air-Con]";
	std::cout << std::left << std::setfill(' ') << std::setw(15) << "[Lex Level]";
	std::cout << std::left << std::setfill(' ') << std::setw(13) << "[Light]";
	std::cout << std::left << std::setfill(' ') << std::setw(13) << "[Humid %]";
	std::cout << std::left << std::setfill(' ') << std::setw(13) << "[Dehumidifier]" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
}

void View::displaySensorData(int minute, int temp, int humid, int lux, std::string lightState, std::string heatingState, std::string airconState, std::string dehumidState)
{
	std::cout << std::left << std::setfill(' ') << std::setw(17) << minute;
	std::cout << std::left << std::setfill(' ') << std::setw(13) << temp;
	std::cout << std::left << std::setfill(' ') << std::setw(13) << heatingState;
	std::cout << std::left << std::setfill(' ') << std::setw(13) << airconState;
	std::cout << std::left << std::setfill(' ') << std::setw(15) << lux;
	std::cout << std::left << std::setfill(' ') << std::setw(13) << lightState;
	std::cout << std::left << std::setfill(' ') << std::setw(13) << humid;
	std::cout << std::left << std::setfill(' ') << std::setw(13) << dehumidState << std::endl;
}


void View::printDateDay()
{
	system("CLS");
	printProgramHeader();
	std::cout << "Please chose a day:\n";
	std::cout << "[1-31] Day\n";
	std::cout << "> ";
}

void View::printDateMonth()
{
	system("CLS");
	printProgramHeader();
	std::cout << "Please chose a month:\n";
	std::cout << "[1] January\n";
	std::cout << "[2] February\n";
	std::cout << "[3] March\n";
	std::cout << "[4] April\n";
	std::cout << "[5] May\n";
	std::cout << "[6] June\n";
	std::cout << "[7] July\n";
	std::cout << "[8] August\n";
	std::cout << "[9] September\n";
	std::cout << "[10] October\n";
	std::cout << "[11] November\n";
	std::cout << "[12] December\n";
	std::cout << "> ";
}

void View::printDateYear()
{
	system("CLS");
	printProgramHeader();
	std::cout << "Please chose a year:\n";
	std::cout << "[1] 2018\n";
	std::cout << "[2] 2019\n";
	std::cout << "[3] 2020\n";
	std::cout << "[4] 2021\n";
	std::cout << "> ";
}