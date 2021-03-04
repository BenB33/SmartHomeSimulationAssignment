#pragma once
#include <string>

#include "TemperatureSensor.h"
#include "LightSensor.h"
#include "HumiditySensor.h"
#include "state.h"

class Model
{
private:
	TemperatureSensor tempSensor;
	LightSensor	lightSensor;
	HumiditySensor humiditySensor;

	int temperature = 0;	// Temperature used for heating
	uint16_t luxLevel = 0;	// Lux used for lights
	uint16_t humidity = 0; // Humitity used for...

public:
	Model();

	// Temp Sensor
	int getTemp() const noexcept;
	void setTemp(const int newTemp) noexcept;
	int getMinTemp() const noexcept;
	int getMaxTemp() const noexcept;
	void setMinTemp(int newMinTemp) noexcept;
	void setMaxTemp(int newMaxTemp) noexcept;

	// Light Sensor
	uint16_t getLux() const noexcept;
	void setLux(const uint16_t newLux) noexcept;
	uint16_t getMinLux() const noexcept;
	uint16_t getMaxLux() const noexcept;
	void setMinLux(uint16_t newMinLux) noexcept;
	void setMaxLux(uint16_t newMaxLux) noexcept;

	// Humidity Sensor
	uint16_t getHumidity() const noexcept;
	void setHumidity(const uint16_t newHumidity) noexcept;
	uint16_t getMinHumidity() const noexcept;
	uint16_t getMaxHumidity() const noexcept;
	void setMinHumidity(uint16_t newMinHumidity) noexcept;
	void setMaxHumidity(uint16_t newMaxHumidity) noexcept;

	void retrieveData() noexcept;
};