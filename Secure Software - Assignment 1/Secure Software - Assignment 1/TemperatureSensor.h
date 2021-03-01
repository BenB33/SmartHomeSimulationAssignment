#pragma once
#include <string>

class TemperatureSensor
{
private:
	std::string name = "Temperature Sensor";
	int currentTemp = 15;
	int minTemp = -50;
	int maxTemp = 100;

public:
	std::string getName() const;
	int getCurrentTemp() const;
	void setCurrentTemp(int newCurrentTemp);
	void configureTempSensor(int newMaxTemp, int newMinTemp);
};