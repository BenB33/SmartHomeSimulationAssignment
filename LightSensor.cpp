#include "LightSensor.h"

std::string LightSensor::getName() const
{
	return name;
}

int LightSensor::getCurrentLux() const
{
	return currentLux;
}

void LightSensor::setCurrentLux(int newCurrentLux)
{
	currentLux = newCurrentLux;
}

void LightSensor::configureLightSensor(int newMaxLux, int newMinLux)
{
	maxLux = newMaxLux;
	minLux = newMinLux;
}