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
#include <gsl.h>

void Controller::launch()
{
	// Display Menus
	menuSystem();
}

// Menu System that handles all of the menus
void Controller::menuSystem()
{
	// mainChoice is initialized
	MainMenuChoice mainChoice = MainMenuChoice::Login;

	while (mainChoice != MainMenuChoice::Exit)
	{
		// deviceChoice and sensorChoice is initialized
		DeviceMenuChoice deviceChoice = DeviceMenuChoice::View_Device_Status;
		SensorMenuChoice sensorChoice = SensorMenuChoice::View_Sensor_List;

		// Call printMainMenu that returns a menu choice to menuChoice.
		// This is then used for the menu switch case below.
		mainChoice = view.printMainMenu();

		switch (mainChoice)
		{
		case MainMenuChoice::Login:
			
			// Login
			login();
			break;
		case MainMenuChoice::Device_Menu:

			// Device Menu
			while (deviceChoice != DeviceMenuChoice::Back)
			{

				// Device Menu Choice 
				deviceChoice = view.printDeviceMenu();

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
				sensorChoice = view.printSensorMenu();

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

				case SensorMenuChoice::Configure_Sensor_MinMax:

					// Configure Min and Max of Sensors
					configureSensorMinMax();
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

		logoutMenuIndex = validation.unsignedIntegerValidation(2);

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
	while (menuSelection != 9) menuSelection = validation.unsignedIntegerValidation(9);
}

uint16_t Controller::inputSampleSize()
{
	uint16_t sampleSize;
	view.printMessage("Input required sample size.\n> ");
	sampleSize = validation.unsignedIntegerValidation(std::numeric_limits<uint16_t>::max());

	return sampleSize;
}


/*
	Device Functions
*/

void Controller::viewDeviceStatus()
{
	system("CLS");
	view.printProgramHeader();
	view.printViewDeviceHeader();

	// For loop that loops once for each device in the devices vector
	// It prints each device and their status (on/off)
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

	// For loop that prints the device names in a list
	for(uint16_t i = 0; i < devices.size(); i++)
	{
		view.printMessage("[" + std::to_string(i + 1) + "] ");
		view.printMessage(devices.at(i)->getName() + "\n");
	}

	// Valid user input to choose the device
	view.printMessage("\n> ");
	uint16_t deviceSelection = 0;
	deviceSelection = validation.unsignedIntegerValidation(4);

	// Secure subtraction function which makes integer wrap impossible.
	deviceSelection = validation.unsignedSecureSubtraction(deviceSelection, 1);

	// Toggle device status depending on the current state
	if (devices.at(deviceSelection)->getState() == state::on) devices.at(deviceSelection)->turnDeviceOff();
	else if (devices.at(deviceSelection)->getState() == state::off) devices.at(deviceSelection)->turnDeviceOn();

	backMenu();
}


void Controller::configureDeviceState()
{
	// Configuring Light Device if light level is more than 150 and less than 80
	if (model.getLux() > 150 && devices.at(0)->getState() == state::on) devices.at(0)->turnDeviceOff();
	else if (model.getLux() < 80 && devices.at(0)->getState() == state::off) devices.at(0)->turnDeviceOn();

	// Configuring Heating if temperature is more than 20 degrees and less than 10 degrees
	if (model.getTemp() > 20 && devices.at(1)->getState() == state::on) devices.at(1)->turnDeviceOff();
	else if (model.getTemp() < 10 && devices.at(1)->getState() == state::off) devices.at(1)->turnDeviceOn();

	// Configuring Aircon if temperature is more than 25 degrees and less than 20 degrees
	if (model.getTemp() > 25 && devices.at(3)->getState() == state::off) devices.at(3)->turnDeviceOn();
	else if (model.getTemp() < 20 && devices.at(3)->getState() == state::on) devices.at(3)->turnDeviceOff();

	// Configuring Dehumidifier if humidity is more than 70% and less than 45%
	if (model.getHumidity() > 70 && devices.at(2)->getState() == state::off) devices.at(2)->turnDeviceOn();
	else if (model.getHumidity() < 45 && devices.at(2)->getState() == state::on) devices.at(2)->turnDeviceOff();
}


void Controller::sensorDataManipulation()
{
	// Lux level is reduced by 5 if the light is off, but increased by 5 if the light is on. 
	if (devices.at(0)->getState() == state::on) model.setLux(validation.unsignedSecureAddition(model.getLux(), 5));
	else model.setLux(validation.unsignedSecureSubtraction(model.getLux(), 5));
	
	// Temperature is reduced by 1 if the heating is off, but increased by 1 if the heating on.
	if (devices.at(1)->getState() == state::on) model.setTemp(validation.signedSecureAddition(model.getTemp(), 1));
	else model.setTemp(validation.signedSecureSubtraction(model.getTemp(), 1));
	
	// Humidity is reduced by 3 if the dehumidifier is on, but increased by 3 if the dehumidifier is off.
	if (devices.at(2)->getState() == state::on) model.setHumidity(validation.unsignedSecureSubtraction(model.getHumidity(), 3));
	else model.setHumidity(validation.unsignedSecureAddition(model.getHumidity(), 3));

	// Temperature is reduced by 1 if the aircon is on, but increased by 1 if the aircon is off.
	if (devices.at(3)->getState() == state::on) model.setTemp(validation.signedSecureSubtraction(model.getTemp(), 1));
	else model.setTemp(validation.signedSecureAddition(model.getTemp(), 1));
}



/*
	Sensor Functions
*/

void Controller::viewSensorList()
{
	view.printSensorList();
	backMenu();
}

void Controller::readSensorData(uint16_t sampleSize)
{
	uint16_t time = 0;

	system("CLS");
	view.printProgramHeader();
	view.printSensorDetailsHeader();

	// Default Random Engine is initialized
	std::default_random_engine gen;
	// Three seperate normal distribution variables are initialized with accurate data,
	// for each of the 3 variables. Static casts are used to ensure no type mismatch.
	std::normal_distribution<float> tempDistribution(static_cast<float>(model.getTemp()),6.0f);
	std::normal_distribution<float> luxDistribution(static_cast<float>(model.getLux()),50.0f);
	std::normal_distribution<float> humidDistribution(static_cast<float>(model.getHumidity()),20.0f);

	// For loop that loops the amount chosen by the user (sampleSize)
	for (uint16_t i = 0; i < sampleSize; i++)
	{
		time = i * gsl::narrow_cast<uint16_t>(10); // Time is in 10 minute intervals

		// Temp Lux and Humidity is set to an accurate random number using
		// default random engine and normal distribution initialized above
		model.setTemp(static_cast<uint16_t>(tempDistribution(gen)));
		model.setLux(static_cast<uint16_t>(luxDistribution(gen)));
		model.setHumidity(static_cast<uint16_t>(humidDistribution(gen)));

		sensorDataManipulation(); // Changes the environment (Temp, etc) depending on device state (If heating is on, will gradually get hotter)
		configureDeviceState(); // Checks if sensor data is in certain bounds, then changes device status when needed

		// Thread sleeps for 1 second between each data point, this is to
		// simulate the data being gathered.
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		// Data is printed to the console
		view.displaySensorData(time, model.getTemp(), model.getHumidity(), model.getLux(), stateString.at(devices.at(0)->getState()), stateString.at(devices.at(1)->getState()), stateString.at(devices.at(3)->getState()), stateString.at(devices.at(2)->getState()));
	}
	backMenu();
}


void Controller::configureSensorMinMax()
{
	system("CLS");
	view.printProgramHeader();
	view.printSensorConfigureMinMaxHeader();
	view.printMessage("[1] Light Sensor\n[2] Temperature Sensor\n[3] Humidity Sensor\n\n> ");

	// Sensor is selected by the user to configure via secure input
	uint16_t sensorSelection = 0;
	while (sensorSelection == 0)
	{
		sensorSelection = validation.unsignedIntegerValidation(3);
		switch (sensorSelection)
		{
		case 1:
			// Light Sensor
			{
				view.printMessage("\nCurrent Light Sensor Min = " + std::to_string(model.getMinLux()));
				view.printMessage("\nCurrent Light Sensor Max = " + std::to_string(model.getMaxLux()));

				view.printMessage("\n\nPlease enter new Light Min \n> ");
				model.setMinLux(validation.unsignedIntegerValidation(3000));
				view.printMessage("\nPlease enter new Light Max\n> ");

				// Check to ensure the maxLux is larger than the previously set minLux
				uint16_t newMaxLux = validation.unsignedIntegerValidation(3000);
				while (newMaxLux < model.getMinLux())
				{
					view.printMessage("The max lux level you entered is lower than the current min lux level.\nPlease enter a valid max lux level:\n> ");
					newMaxLux = validation.unsignedIntegerValidation(3000);
				}
				model.setMaxLux(newMaxLux);
				backMenu();
				break;
			}

		case 2:
			// Temp Sensor
			{
				view.printMessage("\nCurrent Temperature Sensor Min = " + std::to_string(model.getMinTemp()));
				view.printMessage("\nCurrent Temperature Sensor Max = " + std::to_string(model.getMaxTemp()));

				view.printMessage("\n\nPlease enter new Temperature Min \n> ");
				model.setMinTemp(validation.signedIntegerValidation());
				view.printMessage("\nPlease enter new Temperature Max\n> ");

				// Check to ensure the maxTemp is larger than the previously set minTemp
				int newMaxTemp = validation.signedIntegerValidation();
				while (newMaxTemp < model.getMinTemp())
				{
					view.printMessage("The max temperature you entered is lower than the current min temp.\nPlease enter a valid max temp:\n> ");
					newMaxTemp = validation.signedIntegerValidation();
				}
				model.setMaxTemp(newMaxTemp);
				backMenu();
				break;
			}

		case 3:
			// Humidity Sensor
			{
				view.printMessage("\nCurrent Humidity Sensor Min = " + std::to_string(model.getMinHumidity()));
				view.printMessage("\nCurrent Humidity Sensor Max = " + std::to_string(model.getMaxHumidity()));

				view.printMessage("\n\nPlease enter new Humidity Min \n> ");
				model.setMinHumidity(validation.unsignedIntegerValidation(100));
				view.printMessage("\nPlease enter new Humidity Max\n> ");

				// Check to ensure the maxHumidity is larger than the previously set minHumidity
				uint16_t newMaxHumidity = validation.unsignedIntegerValidation(100);
				while (newMaxHumidity < model.getMinHumidity())
				{
					view.printMessage("The max humidity you entered is lower than the current min humidity.\nPlease enter a valid max humidity:\n> ");
					newMaxHumidity = validation.unsignedIntegerValidation(100);
				}
				model.setMaxHumidity(newMaxHumidity);
				backMenu();
				break;
			}
		default:
			break;
		}
	}
}


/*
	Historic Data Functions
*/

void Controller::checkHistoricData()
{
	// User input for day
	uint16_t dateDay;
	view.printDateDay();
	dateDay = validation.unsignedIntegerValidation(31);

	// User input for month
	uint16_t dateMonth;
	view.printDateMonth();
	dateMonth = validation.unsignedIntegerValidation(12);

	// User input for year
	uint16_t dateYear;
	view.printDateYear();
	dateYear = validation.unsignedIntegerValidation(4);

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