#include "Model.h"
#include "Controller.h"


Model::Model()
{
	retrieveData();
}


// Temperature getter and setter
int Model::getTemp() const noexcept
{
	return tempSensor.getCurrentTemp();
}
void Model::setTemp(const int newTemp) noexcept
{
	tempSensor.setCurrentTemp(newTemp);
}
int Model::getMinTemp() const noexcept
{
	return tempSensor.getMinTemp();
}
int Model::getMaxTemp() const noexcept
{
	return tempSensor.getMaxTemp();
}
void Model::setMinTemp(int newMinTemp) noexcept
{
	tempSensor.setMinTemp(newMinTemp);
}
void Model::setMaxTemp(int newMaxTemp) noexcept
{
	tempSensor.setMaxTemp(newMaxTemp);
}

// Lux level (light) getter and setter
uint16_t Model::getLux() const noexcept
{
	return lightSensor.getCurrentLux();
}
void Model::setLux(const uint16_t newLux) noexcept
{
	lightSensor.setCurrentLux(newLux);
}
uint16_t Model::getMinLux() const noexcept
{
	return lightSensor.getMinLux();
}
uint16_t Model::getMaxLux() const noexcept
{
	return lightSensor.getMaxLux();
}
void Model::setMinLux(uint16_t newMinLux) noexcept
{
	lightSensor.setMinLux(newMinLux);
}
void Model::setMaxLux(uint16_t newMaxLux) noexcept
{
	lightSensor.setMaxLux(newMaxLux);
}

// Humidity Level getter and setter
uint16_t Model::getHumidity() const noexcept
{
	return humiditySensor.getCurrentHumidity();
}
void Model::setHumidity(const uint16_t newHumidity) noexcept
{
	humiditySensor.setCurrentHumidity(newHumidity);
}
uint16_t Model::getMinHumidity() const noexcept
{
	return humiditySensor.getMinHumidity();
}
uint16_t Model::getMaxHumidity() const noexcept
{
	return humiditySensor.getMaxHumidity();
}
void Model::setMinHumidity(uint16_t newMinHumidity) noexcept
{
	humiditySensor.setMinHumidity(newMinHumidity);
}
void Model::setMaxHumidity(uint16_t newMaxHumidity) noexcept
{
	humiditySensor.setMaxHumidity(newMaxHumidity);
}


void Model::retrieveData() noexcept
{
	// Retrieve Data from File
	temperature = tempSensor.getCurrentTemp();
	humidity = humiditySensor.getCurrentHumidity();
	luxLevel = lightSensor.getCurrentLux();
}