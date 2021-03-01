#include "Controller.h"
#include "Device.h"


//#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <random>


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
				case DeviceMenuChoice::Configure_Device_Intensity:
					// Configure Device Intensity
					configureDeviceIntensity();
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
				

				break;
			case SensorMenuChoice::Read_Sensor_Data:
				// Read Sensor Data
				readSensorData();
				backMenu();
				break;
			case SensorMenuChoice::Back:
				// Back


				break;
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
	int sampleSize;
	view.printMessage("Input required sample size.\n> ");
	std::cin >> sampleSize;

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
		view.printMessage(" = " + stateString.at(devices.at(i)->getState()));
		//if (devices.at(i)->getState() == state::on) view.printMessage(" = On");
		//else if (devices.at(i)->getState() == state::off) view.printMessage(" = Off");
		view.printMessage(" - Intensity: " + std::to_string(devices.at(i)->getIntensity()) + "\n");
	}
	

	backMenu();
}


void Controller::changeDeviceStatus()
{
	system("CLS");
	view.printProgramHeader();
	view.printChangeDeviceHeader("a Device");

	// TODO: Print Device List
	for(int i = 0; i < devices.size(); i++)
	{
		view.printMessage("[" + std::to_string(i + 1) + "] ");
		view.printMessage(devices.at(i)->getName() + "\n");
	}

	std::cout << std::endl;

	int menuSelection = 0;
	menuSelection = validation.integerValidation(4);
	menuSelection--;

	// Toggle device status depending on the current state
	if (devices.at(menuSelection)->getState() == state::on) devices.at(menuSelection)->turnDeviceOff();
	else if (devices.at(menuSelection)->getState() == state::off) devices.at(menuSelection)->turnDeviceOn();

	// TODO: Change Device Status

	backMenu();
}


void Controller::configureDeviceIntensity()
{
	system("CLS");
	view.printProgramHeader();
	view.printConfigureDeviceIntensityHeader();

	// TODO: Configure Device Intensity
	for (int i = 0; i < devices.size(); i++)
	{
		view.printMessage("[" + std::to_string(i + 1) + "] ");
		view.printMessage(devices.at(i)->getName() + "\n");
	}

	std::cout << std::endl;

	int menuSelection = 0;
	menuSelection = validation.integerValidation(4);
	menuSelection--;

	if (devices.at(menuSelection)->getState() == state::on)
	{
		view.printMessage("Enter new intensity for the " + devices.at(menuSelection)->getName() + "\n> ");
		int newIntensity = 0;
		newIntensity = validation.integerValidation(100);

		devices.at(menuSelection)->setIntensity(newIntensity);

		view.printMessage("\nIntensity has been updated successfully.\n\n");
	}
	else if (devices.at(menuSelection)->getState() == state::off)
	{
		view.printMessage("Cannot change intensity for " + devices.at(menuSelection)->getName() + " as it is turned off.\n\n");
	}


	backMenu();
}


void Controller::configureDevices()
{
	// Configuring Light Device
	if (model.getLux() > 100 /*&& model.getLightState() == state::on*/)
	{
		devices.at(0)->turnDeviceOff();
	}
	else if (model.getLux() <= 100 /*&& model.getLightState() == state::off*/)
	{
		devices.at(0)->turnDeviceOn();
	}


	// Configuring Heating/Aircon
	if (model.getTemp() > 15 /*&& model.getHeatingState() == state::on*/)
	{
		devices.at(1)->turnDeviceOff();
	}
	else if (model.getTemp() <= 15 /*&& model.getHeatingState() == state::off*/)
	{
		devices.at(1)->turnDeviceOn();
	}

	if (model.getTemp() > 20 /*&& model.getAirconState() == state::off*/)
	{
		devices.at(3)->turnDeviceOn();
	}
	else if (model.getTemp() <= 20 /*&& model.getAirconState() == state::on*/)
	{
		devices.at(3)->turnDeviceOff();
	}


	// Configuring Dehumidifier
	if (model.getHumidity() > 65 /*&& model.getDehumidState() == state::off*/)
	{
		devices.at(2)->turnDeviceOn();
	}
	else if (model.getHumidity() <= 65 /*&& model.getDehumidState() == state::on*/)
	{
		devices.at(2)->turnDeviceOff();
	}
}



/*
	Sensor Functions
*/

void Controller::viewSensorList()
{

}

void Controller::readSensorData()
{
	int time = 0;
	const int sampleSize = inputSampleSize();

	system("CLS");
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

		configureDevices(); // Checks if sensor data is in certain bounds, then changes device status when needed

		// deviceManipulation(); // When a device is turned on, it will manipulate the environment and, for example, make it colder

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		view.displaySensorData(time, model.getTemp(), model.getHumidity(), model.getLux(), stateString.at(devices.at(0)->getState()), stateString.at(devices.at(1)->getState()), stateString.at(devices.at(2)->getState()), stateString.at(devices.at(3)->getState()));
	}
}
