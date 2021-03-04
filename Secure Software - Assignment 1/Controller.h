#pragma once

#include "AirConditioning.h"
#include "Authenticator.h"
#include "Dehumidifier.h"
#include "Heating.h"
#include "Light.h"
#include "Validation.h"

#include <vector>
#include "State.h"
#include "View.h"


class Controller
{
private:
	Authenticator auth;
	Model model;
	ProofOfID proof;
	User user;
	Validation validation;
	View view;
	
	bool isLoggedIn = false;

	const std::vector<std::shared_ptr<Device>> devices = { std::make_shared<Light>(), std::make_shared<Heating>(), std::make_shared<Dehumidifier>(), std::make_shared<AirConditioning>() };

public:

	Controller() = default;
	Controller(const Controller&) = delete;
	Controller& operator=(const Controller&) = delete;

	void launch();
	void menuSystem();
	void backMenu();
	void login();

	void viewDeviceStatus();
	void changeDeviceStatus();
	void configureDeviceState();
	void deviceManipulation();

	void viewSensorList();
	void readSensorData(uint16_t sampleSize);
	void configureSensorMinMax();


	void checkHistoricData();

	uint16_t inputSampleSize();


};