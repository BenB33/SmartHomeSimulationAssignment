#include "HumiditySensor.h"

std::string HumiditySensor::getName() const
{
	return name;
}

int HumiditySensor::getCurrentHumidity() const
{
	return currentHumidity;
}

void HumiditySensor::setCurrentHumidity(int newCurrentHumidity)
{
	currentHumidity = newCurrentHumidity;
}

void HumiditySensor::configureHumiditySensor(int newMaxHumidity, int newMinHumidity)
{
	maxHumidity = newMaxHumidity;
	minHumidity = newMinHumidity;
}