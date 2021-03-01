#pragma once
#include "Device.h"

#include <string>
#include <iostream>

class AirConditioning : public Device
{
private:
	std::string name = "Air Conditioning";
	int intensity = 0;
	state currentACState = state::on;

public:
	std::string getName() override;
	state getState() noexcept override;
	void turnDeviceOn() override;
	void turnDeviceOff() override;
	int getIntensity() noexcept override;
	void setIntensity(int newIntensity) override;

	~AirConditioning() override = default;
};