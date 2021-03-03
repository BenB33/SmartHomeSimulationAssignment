#include "Controller.h"
#include "Choice.h"
#include "Device.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <random>
#include <fstream>
#include <sstream>


void Controller::launch()
{
	// Display Menus
	menuSystem();
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
			break;
		case MainMenuChoice::Device_Menu:

			// Device Menu
			while (deviceChoice != DeviceMenuChoice::Back)
			{
				// Device Menu Choice 
				deviceChoice = view.deviceMenu();

				switch (deviceChoice)
				{
				case DeviceMenuChoice::View_Device_Status:

					// View Device Status - Requires admin, student or guest account logged in
					if ((!proof.getProofID().empty()))
					{
						if (user.getUsername() == "admin" || user.getUsername() == "student" || user.getUsername() == "guest") viewDeviceStatus();
						else
						{
							view.printMessage("\n\nYou are not authorised to access this content.");
							backMenu();
						}
					}
					else
					{
						view.printMessage("\n\nYou are not logged in.");
						backMenu();
					}
					break; 
				case DeviceMenuChoice::Change_Device_Status:

					// Change Device Status - Requires admin account logged in
					if ((!proof.getProofID().empty()))
					{
						if (user.getUsername() == "admin") changeDeviceStatus();
						else
						{
							view.printMessage("\n\nYou are not authorised to access this content.");
							backMenu();
						}
					}
					else
					{
						view.printMessage("\n\nYou are not logged in.");
						backMenu();
					}
					break;
				case DeviceMenuChoice::Back:
					// Back
					break;
				}
			}
			break;
		case MainMenuChoice::Sensor_Menu:

			while (sensorChoice != SensorMenuChoice::Back)
			{
				sensorChoice = view.sensorMenu();

				switch (sensorChoice)
				{
				case SensorMenuChoice::View_Sensor_List:
				
					// View Sensor List
					if ((!proof.getProofID().empty()))
					{
						if (user.getUsername() == "admin" || user.getUsername() == "student" || user.getUsername() == "guest") viewSensorList();
						else
						{
							view.printMessage("\n\nYou are not authorised to access this content.");
							backMenu();
						}
					}
					else
					{
						view.printMessage("\n\nYou are not logged in.");
						backMenu();
					}
					break;
				case SensorMenuChoice::Read_Sensor_Data:

					// Read Sensor Data
					if ((!proof.getProofID().empty()))
					{
						if (user.getUsername() == "admin" || user.getUsername() == "student") readSensorData(inputSampleSize());
						else
						{
							view.printMessage("\n\nYou are not authorised to access this content.");
							backMenu();
						}
					}
					else
					{
						view.printMessage("\n\nYou are not logged in.");
						backMenu();
					}
					break;
				case SensorMenuChoice::Back:
					// Back
					break;
				}
			}
			break;

		case MainMenuChoice::Historic_Data:

			// Historic Data
			if ((!proof.getProofID().empty()))
			{
				if (user.getUsername() == "admin" || user.getUsername() == "student") checkHistoricData();
				else
				{
					view.printMessage("\n\nYou are not authorised to access this content.");
					backMenu();
				}
			}
			else
			{
				view.printMessage("\n\nYou are not logged in.");
				backMenu();
			}
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
	if (isLoggedIn == true)
	{
		view.printMessage("Already logged in as " + user.getUsername() + ".\n\n");
		view.printMessage("[1] Logout\n[2] Back...\n>");
		uint16_t logoutMenuIndex = 0;

		logoutMenuIndex = validation.integerValidation(2);

		switch (logoutMenuIndex)
		{
		case 1:
			 // Logout
			user.setProofOfID("");
			user.setUsername("");
			isLoggedIn = false;
			view.printMessage("\n\nLogged out successfully.\n");
			backMenu();
		case 2:
			// Back...
			return;
		default:
			break;
		}
	}

	while (!isLoggedIn)
	{
		view.printLoginHeader();
		view.printMessage("Enter your username\n> ");
		std::string username;
		std::cin >> username;
		user.setUsername(username);

		proof = auth.authenticateUser(user);

		if (proof.getProofID() == "")
		{
			system("CLS");
			view.printMessage("\nLogin Error\n-----------\n\nLogin credentials incorrect. Please try again...\n\n");
		}
		else
		{
			isLoggedIn = true;
			backMenu();
		}
	}
}


void Controller::backMenu()
{
	int menuSelection = 0;
	view.printMessage("\n[9] Back...\n> ");
	while (menuSelection != 9) menuSelection = validation.integerValidation(9);
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
	for (uint16_t i = 0; i < devices.size(); i++)
	{
		view.printMessage("[" + std::to_string(i + 1) + "] ");
		view.printMessage(devices.at(i)->getName());
		view.printMessage(" = " + (stateString.at(devices.at(i)->getState())) + "\n");
	}

	backMenu();
}


void Controller::changeDeviceStatus()
{
	system("CLS");
	view.printProgramHeader();
	view.printChangeDeviceHeader("a Device");

	for(uint16_t i = 0; i < devices.size(); i++)
	{
		view.printMessage("[" + std::to_string(i + 1) + "] ");
		view.printMessage(devices.at(i)->getName() + "\n");
	}

	view.printMessage("\n> ");

	uint16_t menuSelection = 0;
	menuSelection = validation.integerValidation(4);

	// Secure subtraction function which makes integer wrap impossible.
	menuSelection = validation.secureSubtract(menuSelection, 1);

	// Toggle device status depending on the current state
	if (devices.at(menuSelection)->getState() == state::on) devices.at(menuSelection)->turnDeviceOff();
	else if (devices.at(menuSelection)->getState() == state::off) devices.at(menuSelection)->turnDeviceOn();

	backMenu();
}


void Controller::configureDeviceState()
{
	// Configuring Light Device
	if (model.getLux() > 150 && devices.at(0)->getState() == state::on) devices.at(0)->turnDeviceOff();
	else if (model.getLux() < 80 && devices.at(0)->getState() == state::off) devices.at(0)->turnDeviceOn();


	// Configuring Heating/Aircon
	if (model.getTemp() > 20 && devices.at(1)->getState() == state::on) devices.at(1)->turnDeviceOff();
	else if (model.getTemp() < 10 && devices.at(1)->getState() == state::off) devices.at(1)->turnDeviceOn();

	if (model.getTemp() > 25 && devices.at(3)->getState() == state::off) devices.at(3)->turnDeviceOn();
	else if (model.getTemp() < 20 && devices.at(3)->getState() == state::on) devices.at(3)->turnDeviceOff();


	// Configuring Dehumidifier
	if (model.getHumidity() > 65 && devices.at(2)->getState() == state::off) devices.at(2)->turnDeviceOn();
	else if (model.getHumidity() < 50 && devices.at(2)->getState() == state::on) devices.at(2)->turnDeviceOff();
}


void Controller::deviceManipulation()
{
	// Light
	if (devices.at(0)->getState() == state::on) model.setLux(validation.secureAddition(model.getLux(), 5));
	else model.setLux(validation.secureSubtract(model.getLux(), 5));
	
	// Heating
	if (devices.at(1)->getState() == state::on) model.setTemp(validation.secureAddition(model.getTemp(), 1));
	else model.setTemp(validation.secureSubtract(model.getTemp(), 1));
	

	// Dehumidifier
	if (devices.at(2)->getState() == state::on) model.setHumitity(validation.secureAddition(model.getHumidity(), 3));
	else model.setHumitity(validation.secureSubtract(model.getHumidity(), 3));

	// Air Con
	if (devices.at(3)->getState() == state::on) model.setTemp(validation.secureSubtract(model.getTemp(), 1));
	else model.setTemp(validation.secureAddition(model.getTemp(), 1));
}



/*
	Sensor Functions
*/

void Controller::viewSensorList()
{
	view.printSensorList();
	backMenu();
}

void Controller::readSensorData(int sampleSize)
{
	int time = 0;

	system("CLS");
	view.printProgramHeader();
	view.printSensorDetailsHeader();

	std::default_random_engine gen;
	std::normal_distribution<float> tempDistribution(static_cast<float>(model.getTemp()),6.0f);
	std::normal_distribution<float> luxDistribution(static_cast<float>(model.getLux()),50.0f);
	std::normal_distribution<float> humidDistribution(static_cast<float>(model.getHumidity()),20.0f);

	for (int i = 0; i < sampleSize; i++)
	{
		time = i * 10; // Time is in 10 minute intervals

		model.setTemp(static_cast<int>(tempDistribution(gen)));
		model.setLux(static_cast<int>(luxDistribution(gen)));
		model.setHumitity(static_cast<int>(humidDistribution(gen)));

		deviceManipulation(); // Changes the environment (Temp, etc) depending on device state (If heating is on, will gradually get hotter)
		configureDeviceState(); // Checks if sensor data is in certain bounds, then changes device status when needed

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		view.displaySensorData(time, model.getTemp(), model.getHumidity(), model.getLux(), stateString.at(devices.at(0)->getState()), stateString.at(devices.at(1)->getState()), stateString.at(devices.at(3)->getState()), stateString.at(devices.at(2)->getState()));
	}

	backMenu();
}


/*
	Historic Data Functions
*/

void Controller::checkHistoricData()
{
	// User input for day
	uint16_t dateDay;
	view.printDateDay();
	dateDay = validation.integerValidation(31);

	// User input for month
	uint16_t dateMonth;
	view.printDateMonth();
	dateMonth = validation.integerValidation(12);

	// User input for year
	uint16_t dateYear;
	view.printDateYear();
	dateYear = validation.integerValidation(4);

	// Converting year selection index into actual year string
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
	default:
		break;
	}

	// Formatting the date
	std::string fullDate = std::to_string(dateDay) + "/" + std::to_string(dateMonth) + "/" + std::to_string(dateYear);

	// Preparing the screen to fit program theme
	system("CLS");
	view.printProgramHeader();
	view.printMessage("Date: " + fullDate + "\n");
	view.printHistoricDataHeader();

	// Initializing ifstream with exceptions
	std::ifstream readFile("historicData.txt", std::ios::in);
	readFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	

	if (readFile.is_open())
	{
		// Create a temp string, count integer, and reading found boolean
		std::string temp;
		uint16_t readingCount = 0;
		bool foundAReading = false;

		// Try catch block to handle exceptions
		try 
		{
			// While the next character in the input sequence isn't the end of file, run while loop
			while (readFile.peek() != EOF)
			{
				// getline grabs the date from the file
				std::getline(readFile, temp);

				// string stream created to allow operations on the lines pulled from file
				std::stringstream stream(temp);

				// Date string created, and date is pulled from string stream
				std::string date;
				stream >> date;

				// Check if the fullDate is anywhere in the file
				if (date == fullDate)
				{
					// At least one reading has been found
					foundAReading = true;

					// Keeping count of the readings that were found to later print to console
					readingCount++;

					// Save the data from string stream to memory
					std::string temperature;
					std::string luxLevel;
					std::string humidity;
					stream >> temperature;
					stream >> luxLevel;
					stream >> humidity;

					// Pass each of the data values to print to console using view class
					view.printHistoricData(readingCount, temperature, luxLevel, humidity);
				}
			}
			// If foundAReading boolean is false, then no readings were found for the date the user
			// provided, print message to screen
			if (foundAReading == false) view.printMessage("No readings for the specified date.\n");
		} 
		catch (std::exception ex) 
		{
			std::cerr << "ERROR: " << ex.what() << std::endl;
		}
	}
	else view.printMessage("ERROR: Cannot open file.");


	backMenu();
}

