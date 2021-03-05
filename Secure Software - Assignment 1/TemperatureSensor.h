#pragma once
#include <string>

class TemperatureSensor
{
private:
	std::string name = "Temperature Sensor";
	int16_t currentTemp = 15;
	int16_t minTemp = -50;
	int16_t maxTemp = 100;

public:
	std::string getName() const;
	int16_t getCurrentTemp() const noexcept;
	void setCurrentTemp(int16_t newCurrentTemp) noexcept;
	void configureTempSensor(int16_t newMaxTemp, int16_t newMinTemp) noexcept;

	int16_t getMinTemp() const noexcept;
	int16_t getMaxTemp() const noexcept;

	void setMinTemp(int16_t newMinTemp) noexcept;
	void setMaxTemp(int16_t newMaxTemp) noexcept;
};