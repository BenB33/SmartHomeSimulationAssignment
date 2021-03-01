#pragma once
#include "Device.h"

#include <string>

class Light : public Device
{
private:
	std::string name = "Light";
	state currentLightState = state::off;

public:
	std::string getName() override;
	state getState() noexcept override;
	void turnDeviceOn() override;
	void turnDeviceOff() override;

	~Light() override = default;
};