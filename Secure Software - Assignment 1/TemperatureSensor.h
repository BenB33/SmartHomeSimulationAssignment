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
	int getCurrentTemp() const noexcept;
	void setCurrentTemp(int newCurrentTemp) noexcept;
	void configureTempSensor(int newMaxTemp, int newMinTemp) noexcept;

	int getMinTemp() const noexcept;
	int getMaxTemp() const noexcept;

	void setMinTemp(int newMinTemp) noexcept;
	void setMaxTemp(int newMaxTemp) noexcept;
};