#pragma once
#include <string>

class LightSensor
{
private:
	std::string name = "Light Sensor";
	uint16_t currentLux = 150;
	uint16_t minLux = 0;
	uint16_t maxLux = 3000;

public:
	std::string getName() const;
	uint16_t getCurrentLux() const noexcept;
	void setCurrentLux(uint16_t newCurrentLux) noexcept;
	void configureLightSensor(uint16_t newMaxLux, uint16_t newMinLux) noexcept;

	uint16_t getMinLux() const noexcept;
	uint16_t getMaxLux() const noexcept;

	void setMinLux(uint16_t newMinLux) noexcept;
	void setMaxLux(uint16_t newMaxLux) noexcept;
};
