#pragma once
#include "Device.h"

#include <string>
#include <iostream>

class AirConditioning : public Device
{
private:
	std::string name = "Air Conditioning";
	state currentACState = state::off;

public:
	std::string getName() override;
	state getState() noexcept override;
	void turnDeviceOn() override;
	void turnDeviceOff() override;

	~AirConditioning() override = default;
};