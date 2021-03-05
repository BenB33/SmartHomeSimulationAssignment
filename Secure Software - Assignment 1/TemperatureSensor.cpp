#include "TemperatureSensor.h"

std::string TemperatureSensor::getName() const
{
	return name;
}

int16_t TemperatureSensor::getCurrentTemp() const noexcept
{
	return currentTemp;
}

void TemperatureSensor::setCurrentTemp(int16_t newCurrentTemp) noexcept
{
	currentTemp = newCurrentTemp;
}

void TemperatureSensor::configureTempSensor(int16_t newMaxTemp, int16_t newMinTemp) noexcept
{
	maxTemp = newMaxTemp;
	minTemp = newMinTemp;
}

int16_t TemperatureSensor::getMinTemp() const noexcept
{
	return minTemp;
}

int16_t TemperatureSensor::getMaxTemp() const noexcept
{
	return maxTemp;
}

void TemperatureSensor::setMinTemp(int16_t newMinTemp) noexcept
{
	minTemp = newMinTemp;
}
void TemperatureSensor::setMaxTemp(int16_t newMaxTemp) noexcept
{
	maxTemp = newMaxTemp;
}