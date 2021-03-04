#include "LightSensor.h"

std::string LightSensor::getName() const
{
	return name;
}

uint16_t LightSensor::getCurrentLux() const noexcept
{
	return currentLux;
}

void LightSensor::setCurrentLux(uint16_t newCurrentLux) noexcept
{
	currentLux = newCurrentLux;
}

void LightSensor::configureLightSensor(uint16_t newMaxLux, uint16_t newMinLux) noexcept
{
	maxLux = newMaxLux;
	minLux = newMinLux;
}

uint16_t LightSensor::getMinLux() const noexcept
{
	return minLux;
}

uint16_t LightSensor::getMaxLux() const noexcept
{
	return maxLux;
}

void LightSensor::setMinLux(uint16_t newMinLux) noexcept
{
	minLux = newMinLux;
}
void LightSensor::setMaxLux(uint16_t newMaxLux) noexcept
{
	maxLux = newMaxLux;
}