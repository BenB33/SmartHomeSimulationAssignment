#pragma once
#include "Device.h"

#include <string>

class Dehumidifier : public Device
{
private:
	std::string name = "Dehumidifier";
	int intensity = 0;
	state currentDehumidifierState = state::off;

public:
	std::string getName() override;
	state getState() noexcept override;
	void turnDeviceOn() override;
	void turnDeviceOff() override;

	int getIntensity() noexcept override;
	void setIntensity(int newIntensity) override;

	~Dehumidifier() override = default;
};