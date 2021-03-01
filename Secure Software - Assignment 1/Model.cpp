#include "Model.h"
#include "Controller.h"


Model::Model() noexcept
{
	retrieveData();
}


// Temperature getter and setter
int Model::getTemp() const
{
	return tempSensor.getCurrentTemp();
}
void Model::setTemp(const int newTemp)
{
	tempSensor.setCurrentTemp(newTemp);
}

// Lux level (light) getter and setter
int Model::getLux() const
{
	return lightSensor.getCurrentLux();
}
void Model::setLux(const int newLux)
{
	lightSensor.setCurrentLux(newLux);
}

// Humidity Level getter and setter
int Model::getHumidity() const
{
	return humiditySensor.getCurrentHumidity();
}

void Model::setHumitity(const int newHumidity)
{
	humiditySensor.setCurrentHumidity(newHumidity);
}


// Sampling period getter and setter 
int Model::getSamplePeriod() const noexcept
{
	return samplePeriod;
}
void Model::setSamplePeriod(const int newSamplePeriod) noexcept
{
	samplePeriod = newSamplePeriod;
}

Controller controller;

// Device State Getters
state Model::getAirconState()
{
	// TODO: Get Device States
	
	return controller.devices.at(3)->getState();
}

// Device State Getters
state Model::getLightState()
{
	// TODO: Get Device States
	return controller.devices.at(0)->getState();
}

// Device State Getters
state Model::getHeatingState()
{
	// TODO: Get Device States
	return controller.devices.at(1)->getState();
}

// Device State Getters
state Model::getDehumidState()
{
	// TODO: Get Device States
	return controller.devices.at(2)->getState();
}


void Model::retrieveData()
{
	// Retrieve Data from File
	temperature = tempSensor.getCurrentTemp();
	humidity = humiditySensor.getCurrentHumidity();
	luxLevel = lightSensor.getCurrentLux();
}