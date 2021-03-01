#pragma once

#include "Light.h"
#include "Heating.h"
#include "AirConditioning.h"
#include "Dehumidifier.h"

#include <vector>
#include "View.h"
#include "State.h"

#include "Authenticator.h"
#include "Validation.h"

class Controller
{
private:
	// TEMP	
	Model model;
	View view;

	Validation validation;

	User user;
	ProofOfID proof;
	Authenticator auth;
	bool isLoggedIn = false;

	//std::vector<std::shared_ptr<Device>> devices = { std::make_shared<Light>(), std::make_shared<Heating>(), std::make_shared<Dehumidifier>(), std::make_shared<AirConditioning>() };
	//std::vector<Device*> devices = { new Light, new Heating, new Dehumidifier, new AirConditioning };

public:
	std::vector<std::shared_ptr<Device>> devices = { std::make_shared<Light>(), std::make_shared<Heating>(), std::make_shared<Dehumidifier>(), std::make_shared<AirConditioning>() };

	Controller();

	void runAutonomously();

	void launch();
	void menuSystem();
	void backMenu();

	void viewDeviceStatus();
	void changeDeviceStatus();
	void configureDeviceIntensity();
	void configureDevices();

	void viewSensorList();
	void readSensorData(); // Use a controlActuator() method to check bounds of sensor data and toggle device states


	int inputSampleSize();

	void login();
};