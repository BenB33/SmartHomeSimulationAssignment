#pragma once
#include "Device.h"

#include <string>

class Heating : public Device
{
private:
	std::string name = "Heating";
	state currentHeatingState = state::off;

public:

	std::string getName() override;
	state getState() noexcept override;
	void turnDeviceOn() override;
	void turnDeviceOff() override;

	~Heating() override = default;
};