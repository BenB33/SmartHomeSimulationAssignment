#include <iostream>
#include <iomanip>
#include <ctime>

#include "Validation.h"
#include "View.h"



void View::printMessage(std::string message)
{
	std::cout << message;
}


/*
	Print Headers
*/
void View::printProgramHeader()
{
	const time_t currentTime = time(NULL);
	tm structuredTime{};
	localtime_s(&structuredTime, &currentTime);
	std::cout << "[" << std::put_time(&structuredTime, "%a %d %b %Y - %R]") << std::endl << std::endl;
}
void View::printLoginHeader()
{
	std::cout << "Login\n-----\n\n";
}
void View::printViewDeviceHeader()
{
	std::cout << "View Device Status'\n-------------------\n\n";
}
void View::printChangeDeviceHeader(std::string deviceName)
{
	std::cout << "Change " << deviceName << "'s Status." << std::endl << "-------------------------\n\n";
}
void View::printSensorConfigureMinMaxHeader()
{
	std::cout << "Configure Sensor Min/Max\n-----------------------\n\n";
}
void View::printSensorDetailsHeader()
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
void View::printHistoricDataHeader()
{
	std::cout << "------------------------------------------------------------------\n";
	std::cout << std::left << std::setfill(' ') << std::setw(17) << "[Reading]";
	std::cout << std::left << std::setfill(' ') << std::setw(17) << "[Temerature]";
	std::cout << std::left << std::setfill(' ') << std::setw(17) << "[Lex Level]";
	std::cout << std::left << std::setfill(' ') << std::setw(17) << "[Humidity]" << std::endl;
	std::cout << "------------------------------------------------------------------\n";
}

/*
	Print Menus
*/
MainMenuChoice View::printMainMenu()
{
	Validation validation;
	system("CLS");
	printProgramHeader();
	std::cout << "Autonomous Smart Home System\n----------------------------\n\n";
	std::cout << "[1] Login/Logout\n";
	std::cout << "[2] Device Menu\n";
	std::cout << "[3] Sensor Menu\n";
	std::cout << "[4] Historic Data\n";
	std::cout << "[5] Exit\n\n";
	std::cout << "> ";


	uint16_t mainMenuSelection = 0;
	mainMenuSelection = validation.unsignedIntegerValidation(5);
	mainMenuSelection = validation.unsignedSecureSubtraction(mainMenuSelection, 1);
	return static_cast<MainMenuChoice>(mainMenuSelection);
}
DeviceMenuChoice View::printDeviceMenu()
{
	Validation validation;
	system("CLS");
	printProgramHeader();
	std::cout << "Device Menu\n-----------\n\n";
	std::cout << "[1] View Device Status'\n";
	std::cout << "[2] Change Device Status Manually\n";
	std::cout << "[3] Back...\n\n";
	std::cout << "> ";

	uint16_t deviceMenuSelection = 0;
	deviceMenuSelection = validation.unsignedIntegerValidation(3);
	deviceMenuSelection = validation.unsignedSecureSubtraction(deviceMenuSelection, 1);
	return static_cast<DeviceMenuChoice>(deviceMenuSelection);
}
SensorMenuChoice View::printSensorMenu()
{
	Validation validation;
	system("CLS");
	printProgramHeader();
	std::cout << "Sensor Menu\n-----------\n\n";
	std::cout << "[1] View Sensor List\n";
	std::cout << "[2] Read Sensor Data\n";
	std::cout << "[3] Configure Sensor MinMax\n";
	std::cout << "[4] Back...\n\n";
	std::cout << "> ";

	uint16_t sensorMenuSelection = 0;
	sensorMenuSelection = validation.unsignedIntegerValidation(4);
	sensorMenuSelection = validation.unsignedSecureSubtraction(sensorMenuSelection, 1);
	return static_cast<SensorMenuChoice>(sensorMenuSelection);
}



/*
	Sensors
*/
void View::printSensorList()
{
	system("CLS");
	printProgramHeader();
	std::cout << "Sensor List\n" << "-----------\n\n";
	std::cout << "[1] Light Sensor\n";
	std::cout << "[2] Temperature Sensor\n";
	std::cout << "[3] Humidity Sensor\n";
}
void View::displaySensorData(uint16_t minute, int16_t temp, uint16_t humid, uint16_t lux, 
								std::string lightState, std::string heatingState, std::string airconState, std::string dehumidState)
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

/*
	Historic Data
*/
void View::printHistoricData(uint16_t readingCount, std::string temperature, std::string luxLevel, std::string humidity)
{
	std::cout << std::left << std::setfill(' ') << std::setw(4) << " ";
	std::cout << std::left << std::setfill(' ') << std::setw(17) << readingCount;
	std::cout << std::left << std::setfill(' ') << std::setw(17) << temperature;
	std::cout << std::left << std::setfill(' ') << std::setw(17) << luxLevel;
	std::cout << std::left << std::setfill(' ') << std::setw(17) << humidity << std::endl;
}

/*
	Print Date
*/
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