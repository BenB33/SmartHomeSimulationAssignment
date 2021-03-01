#pragma once
#include "Device.h"

#include <string>

class Dehumidifier : public Device
{
private:
	std::string name = "Dehumidifier";
	state currentDehumidifierState = state::off;

public:
	std::string getName() override;
	state getState() noexcept override;
	void turnDeviceOn() override;
	void turnDeviceOff() override;

	~Dehumidifier() override = default;
};