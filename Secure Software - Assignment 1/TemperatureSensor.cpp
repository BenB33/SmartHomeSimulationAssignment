#include "TemperatureSensor.h"

std::string TemperatureSensor::getName() const
{
	return name;
}

int TemperatureSensor::getCurrentTemp() const noexcept
{
	return currentTemp;
}

void TemperatureSensor::setCurrentTemp(int newCurrentLux) noexcept
{
	currentTemp = newCurrentLux;
}

void TemperatureSensor::configureTempSensor(int newMaxTemp, int newMinTemp) noexcept
{
	maxTemp = newMaxTemp;
	minTemp = newMinTemp;
}

int TemperatureSensor::getMinTemp() const noexcept
{
	return minTemp;
}

int TemperatureSensor::getMaxTemp() const noexcept
{
	return maxTemp;
}

void TemperatureSensor::setMinTemp(int newMinTemp) noexcept
{
	minTemp = newMinTemp;
}
void TemperatureSensor::setMaxTemp(int newMaxTemp) noexcept
{
	maxTemp = newMaxTemp;
}