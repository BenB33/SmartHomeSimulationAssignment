#pragma once
#include <string>

class HumiditySensor
{
private:
	std::string name = "Humidity Sensor";
	int currentHumidity = 50;
	int minHumidity = 0;
	int maxHumidity = 100;

public:
	std::string getName()const;
	int getCurrentHumidity() const;
	void setCurrentHumidity(int newCurrentTemp);
	void configureHumiditySensor(int newMaxHumidity, int newMinHumidity);
};