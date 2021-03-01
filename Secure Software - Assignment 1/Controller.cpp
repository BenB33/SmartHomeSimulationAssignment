#include "Controller.h"
#include "Device.h"


//#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <random>
#include <fstream>


Controller::Controller()
{

}

void Controller::launch()
{
	// Load logger
	std::cout << "[LOG] Load Logger\n\n";
	

	// Initialize Users
	std::cout << "[LOG] Initiate Users\n\n";
	

	// Initiate Light sensor
	std::cout << "[LOG] Initiate Light Sensor\n\n";


	// Initiate Temperature Sensor
	std::cout << "[LOG] Initiate Temp Sensor\n\n";


	// Initiate Humidity Sensor
	std::cout << "[LOG] Initiate Humidity Sensor\n\n";
	

	// Start-up complete
	std::cout << "[LOG] Start-up Complete!!\n\n";
	


	// Display Menus
	menuSystem();
}


void Controller::runAutonomously()
{
	// Complete read data first
}

void Controller::menuSystem()
{
	MainMenuChoice mainChoice = MainMenuChoice::Login;
	//DeviceMenuChoice deviceChoice = DeviceMenuChoice::View_Device_Status;
	//SensorMenuChoice sensorChoice = SensorMenuChoice::Read_Light_Sensor_Data;

	while (mainChoice != MainMenuChoice::Exit)
	{
		//MainMenuChoice mainChoice = MainMenuChoice::Login;
		DeviceMenuChoice deviceChoice = DeviceMenuChoice::View_Device_Status;
		SensorMenuChoice sensorChoice = SensorMenuChoice::View_Sensor_List;

		mainChoice = view.printMainMenu();

		switch (mainChoice)
		{
		case MainMenuChoice::Login:
			// TODO: Login System
			login();
			backMenu();
			break;
		case MainMenuChoice::Device_Menu:
			// Device Menu

			while (deviceChoice != DeviceMenuChoice::Back)
			{
				deviceChoice = view.deviceMenu();

				switch (deviceChoice)
				{
				case DeviceMenuChoice::View_Device_Status:
					// View Device Status


					if ((!proof.getProofID().empty()) && (proof.getProofID() == user.getProofOfID()))
					{
						viewDeviceStatus();
					}
					else
					{
						view.printMessage("You are not authorised to access this content.");
						backMenu();
					}


					break; 
				case DeviceMenuChoice::Change_Device_Status:
					// Change Device Status
					changeDeviceStatus();
					break;
				case DeviceMenuChoice::Back:
					// Back

					break;
				}
			}
			break;

		case MainMenuChoice::Sensor_Menu:
			// Sensor Menu

			sensorChoice = view.sensorMenu();

			switch (sensorChoice)
			{
			case SensorMenuChoice::View_Sensor_List:
				// View Sensor List

				// TODO: Sensor List

				break;
			case SensorMenuChoice::Read_Sensor_Data:
				// Read Sensor Data
				readSensorData(inputSampleSize());
				backMenu();
				break;
			case SensorMenuChoice::Back:
				// Back
				break;
			}
			break;

		case MainMenuChoice::Historic_Data:
			// Historic Data
			checkHistoricData();
			break;
		case MainMenuChoice::Exit:
			break;
		}
	}
}




void Controller::login()
{
	system("CLS");
	view.printProgramHeader();
	// If user is already logged in, display message
	if (isLoggedIn == true) view.printMessage("Already logged in as " + user.getUsername() + ".\n\n"); 

	while (!isLoggedIn)
	{
		view.printMessage("Enter your username: ");
		user.setUsername();

		proof = auth.authenticateUser(user);

		if (proof.getProofID() == "")
		{
			system("CLS");
			view.printMessage("Login credentials incorrect. Please try again...");
		}
		else
		{
			isLoggedIn = true;
			view.printMessage("Successfully logged in!");
			view.printMessage(user.getProofOfID());
		}
	}
}

void Controller::backMenu()
{
	int menuSelection = 0;
	view.printMessage("\n[9] Back...\n> ");
	while (menuSelection != 9)
	{
		menuSelection = validation.integerValidation(9);
	}
}

int Controller::inputSampleSize()
{
	uint16_t sampleSize;
	view.printMessage("Input required sample size.\n> ");
	sampleSize = validation.integerValidation(std::numeric_limits<uint16_t>::max());

	return sampleSize;
}


/*
	Device Functions
*/

void Controller::viewDeviceStatus()
{
	system("CLS");
	view.printProgramHeader();
	view.printMessage("As a " + user.getUsername() + " you are authorised to access this content\n\n");
	view.printViewDeviceHeader();

	// TODO: Get device status'
	for (int i = 0; i < devices.size(); i++)
	{
		view.printMessage("[" + std::to_string(i + 1) + "] ");
		view.printMessage(devices.at(i)->getName());
		view.printMessage(" = " + (stateString.at(devices.at(i)->getState())));
	}

	backMenu();
}


void Controller::changeDeviceStatus()
{
	system("CLS");
	view.printProgramHeader();
	view.printChangeDeviceHeader("a Device");

	for(int i = 0; i < devices.size(); i++)
	{
		view.printMessage("[" + std::to_string(i + 1) + "] ");
		view.printMessage(devices.at(i)->getName() + "\n");
	}

	view.printMessage("\n> ");

	int menuSelection = 0;
	menuSelection = validation.integerValidation(4);
	menuSelection--;

	// Toggle device status depending on the current state
	if (devices.at(menuSelection)->getState() == state::on) devices.at(menuSelection)->turnDeviceOff();
	else if (devices.at(menuSelection)->getState() == state::off) devices.at(menuSelection)->turnDeviceOn();

	// TODO: Change Device Status

	backMenu();
}


void Controller::configureDeviceState()
{
	// Configuring Light Device
	if (model.getLux() > 100 /*&& model.getLightState() == state::on*/) devices.at(0)->turnDeviceOff();
	else if (model.getLux() <= 100 /*&& model.getLightState() == state::off*/) devices.at(0)->turnDeviceOn();


	// Configuring Heating/Aircon
	if (model.getTemp() > 15 /*&& model.getHeatingState() == state::on*/) devices.at(1)->turnDeviceOff();
	else if (model.getTemp() <= 15 /*&& model.getHeatingState() == state::off*/) devices.at(1)->turnDeviceOn();

	if (model.getTemp() > 20 /*&& model.getAirconState() == state::off*/) devices.at(3)->turnDeviceOn();
	else if (model.getTemp() <= 20 /*&& model.getAirconState() == state::on*/) devices.at(3)->turnDeviceOff();


	// Configuring Dehumidifier
	if (model.getHumidity() > 65 /*&& model.getDehumidState() == state::off*/) devices.at(2)->turnDeviceOn();
	else if (model.getHumidity() <= 65 /*&& model.getDehumidState() == state::on*/) devices.at(2)->turnDeviceOff();
}


void Controller::deviceManipulation()
{
	// Light
	if (devices.at(0)->getState() == state::on)
	{
		model.setLux(model.getLux() + 10);
	}
	else if (devices.at(0)->getState() == state::off)
	{
		model.setLux(model.getLux() - 10);
	}

	// Heating
	if (devices.at(1)->getState() == state::on)
	{
		model.setTemp(model.getTemp() + 2);
	}
	else
	{
		model.setTemp(model.getTemp() - 2);
	}

	// Dehumidifier
	if (devices.at(2)->getState() == state::on)
	{
		model.setHumitity(model.getHumidity() + 5);
	}
	else
	{
		model.setHumitity(model.getHumidity() - 5);
	}

	// Air Con
	if (devices.at(3)->getState() == state::on)
	{
		model.setTemp(model.getTemp() - 3);
	}
	else
	{
		model.setTemp(model.getTemp() + 3);
	}
}



/*
	Sensor Functions
*/

void Controller::viewSensorList()
{

}

void Controller::readSensorData(int sampleSize)
{
	int time = 0;

	system("CLS");
	view.printProgramHeader();
	view.printSensorDetailsHeader(model);

	std::default_random_engine gen;
	std::normal_distribution<float> tempDistribution(model.getTemp(),4.0);
	std::normal_distribution<float> luxDistribution(model.getLux(),40.0);
	std::normal_distribution<float> humidDistribution(model.getHumidity(),20.0);

	for (int i = 0; i < sampleSize; i++)
	{
		time = i * 10; // Time is in 10 minute intervals

		model.setTemp(tempDistribution(gen));
		model.setLux(luxDistribution(gen));
		model.setHumitity(humidDistribution(gen));

		deviceManipulation(); // Changes the environment (Temp, etc) depending on device state (If heating is on, will gradually get hotter)
		configureDeviceState(); // Checks if sensor data is in certain bounds, then changes device status when needed

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		view.displaySensorData(time, model.getTemp(), model.getHumidity(), model.getLux(), stateString.at(devices.at(0)->getState()), stateString.at(devices.at(1)->getState()), stateString.at(devices.at(3)->getState()), stateString.at(devices.at(2)->getState()));
	}
}


/*
	Historic Data Functions
*/

void Controller::checkHistoricData()
{
	uint16_t dateDay;
	view.printDateDay();
	dateDay = validation.integerValidation(31);

	uint16_t dateMonth;
	view.printDateMonth();
	dateMonth = validation.integerValidation(12);

	uint16_t dateYear;
	view.printDateYear();
	dateYear = validation.integerValidation(4);

	switch (dateYear)
	{
	case 1:
		dateYear = 2018;
		break;
	case 2:
		dateYear = 2019;
		break;
	case 3:
		dateYear = 2020;
		break;
	case 4:
		dateYear = 2021;
		break;
	}

	std::string fullDate = std::to_string(dateDay) + "/" + std::to_string(dateMonth) + "/" + std::to_string(dateYear);

	system("CLS");
	view.printProgramHeader();
	view.printMessage("Date: " + fullDate + "\n");
	view.printHistoricDataHeader();

	std::ifstream readFile("historicData.txt", std::ios::in);
	if (readFile.is_open())
	{
		std::string temp;
		uint16_t readingCount = 0;
		bool foundAReading = false;

		while (readFile)
		{
			// Works for now, try and fix
			readFile >> temp;

			// Check if fullDate is anywhere in the file
			if (temp == fullDate)
			{
				// At least one reading has been found
				foundAReading = true;

				// Keeping count of the readings that were found
				readingCount++;

				// Save the data in memory
				std::string temperature;
				std::string luxLevel;
				std::string humidity;
				readFile >> temperature;
				readFile >> luxLevel;
				readFile >> humidity;

				view.printHistoricData(readingCount, temperature, luxLevel, humidity);
			}
			else
			{
				// Skipping the line
				std::getline(readFile, temp);
			}
		}

		if (foundAReading == false)
		{
			view.printMessage("No readings for the specified date.\n");
		}
	}
	else
	{
		view.printMessage("ERROR: Cannot open file.");
	}

	backMenu();
}

