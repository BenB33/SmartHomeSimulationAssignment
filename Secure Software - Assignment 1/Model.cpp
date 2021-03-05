#include "Model.h"
#include "Controller.h"


Model::Model() noexcept
{
	retrieveData();
}


// Temperature Sensor getters and setters
int16_t Model::getTemp() const noexcept
{
	return tempSensor.getCurrentTemp();
}
void Model::setTemp(const int16_t newTemp) noexcept
{
	tempSensor.setCurrentTemp(newTemp);
}
int16_t Model::getMinTemp() const noexcept
{
	return tempSensor.getMinTemp();
}
int16_t Model::getMaxTemp() const noexcept
{
	return tempSensor.getMaxTemp();
}
void Model::setMinTemp(int16_t newMinTemp) noexcept
{
	tempSensor.setMinTemp(newMinTemp);
}
void Model::setMaxTemp(int16_t newMaxTemp) noexcept
{
	tempSensor.setMaxTemp(newMaxTemp);
}

// Light Sensor getters and setters
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

// Humidity Sensor getters and setters
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

// Sets the data inside of the model class to the data from the
// sensors.
void Model::retrieveData() noexcept
{
	temperature = tempSensor.getCurrentTemp();
	humidity = humiditySensor.getCurrentHumidity();
	luxLevel = lightSensor.getCurrentLux();
}