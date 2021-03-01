#pragma once
#include <string>

class LightSensor
{
private:
	std::string name = "Light Sensor";
	int currentLux = 150;
	int minLux = 0;
	int maxLux = 3000;

public:
	std::string getName() const;
	int getCurrentLux() const;
	void setCurrentLux(int newCurrentLux);
	void configureLightSensor(int newMaxLux, int newMinLux);
};
