#include "HumiditySensor.h"

std::string HumiditySensor::getName() const
{
	return name;
}

uint16_t HumiditySensor::getCurrentHumidity() const noexcept
{
	return currentHumidity;
}

void HumiditySensor::setCurrentHumidity(uint16_t newCurrentHumidity) noexcept
{
	currentHumidity = newCurrentHumidity;
}

void HumiditySensor::configureHumiditySensor(uint16_t newMaxHumidity, uint16_t newMinHumidity) noexcept
{
	maxHumidity = newMaxHumidity;
	minHumidity = newMinHumidity;
}

uint16_t HumiditySensor::getMinHumidity() const noexcept
{
	return minHumidity;
}

uint16_t HumiditySensor::getMaxHumidity() const noexcept
{
	return maxHumidity;
}

void HumiditySensor::setMinHumidity(uint16_t newMinHumidity) noexcept
{
	minHumidity = newMinHumidity;
}
void HumiditySensor::setMaxHumidity(uint16_t newMaxHumidity) noexcept
{
	maxHumidity = newMaxHumidity;
}