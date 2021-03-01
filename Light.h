#pragma once
#include "Device.h"

#include <string>

class Light : public Device
{
private:
	std::string name = "Light";
	int intensity = 0;
	state currentLightState = state::off;

public:
	std::string getName() override;
	state getState() noexcept override;
	void turnDeviceOn() override;
	void turnDeviceOff() override;

	int getIntensity() noexcept override;
	void setIntensity(int newIntensity) override;
	~Light() override = default;
};