#pragma once
#include <string>

class HumiditySensor
{
private:
	std::string name = "Humidity Sensor";
	uint16_t currentHumidity = 50;
	uint16_t minHumidity = 0;
	uint16_t maxHumidity = 100;

public:
	std::string getName()const;
	uint16_t getCurrentHumidity() const noexcept;
	void setCurrentHumidity(uint16_t newCurrentTemp) noexcept;
	void configureHumiditySensor(uint16_t newMaxHumidity, uint16_t newMinHumidity) noexcept;

	uint16_t getMinHumidity() const noexcept;
	uint16_t getMaxHumidity() const noexcept;
	void setMinHumidity(uint16_t newMinHumidity) noexcept;
	void setMaxHumidity(uint16_t newMaxHumidity) noexcept;
};