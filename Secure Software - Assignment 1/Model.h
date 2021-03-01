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
	int luxLevel = 0;	// Lux used for lights
	int humidity = 0; // Humitity used for...

	int samplePeriod = 500;

public:
	Model();

	// Temp Sensor
	int getTemp() const;
	void setTemp(const int newTemp);

	// Light Sensor
	int getLux() const;
	void setLux(const int newLux);

	// Humidity Sensor
	int getHumidity() const;
	void setHumitity(const int newHumidity);

	// Sample Period
	int getSamplePeriod() const noexcept;
	void setSamplePeriod(const int newSamplePeriod) noexcept;

	void retrieveData();
};