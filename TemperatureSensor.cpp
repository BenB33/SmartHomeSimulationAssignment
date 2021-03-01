#include "TemperatureSensor.h"

std::string TemperatureSensor::getName() const
{
	return name;
}

int TemperatureSensor::getCurrentTemp() const
{
	return currentTemp;
}

void TemperatureSensor::setCurrentTemp(int newCurrentLux)
{
	currentTemp = newCurrentLux;
}

void TemperatureSensor::configureTempSensor(int newMaxTemp, int newMinTemp)
{
	maxTemp = newMaxTemp;
	minTemp = newMinTemp;
}