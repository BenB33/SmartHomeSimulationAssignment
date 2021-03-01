#pragma once
#include "Device.h"

#include <string>
#include <iostream>

class AirConditioning : public Device
{
private:
	std::string name = "Air Conditioning";
	int intensity = 0;
	state currentACState = state::off;

public:
	std::string getName() override;
	state getState() noexcept override;
	void turnDeviceOn() noexcept override;
	void turnDeviceOff() noexcept  override;
	int getIntensity() noexcept override;
	void setIntensity(int newIntensity) noexcept override;

	~AirConditioning() override = default;
};