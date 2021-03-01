#pragma once
#include "Device.h"

#include <string>

class Heating : public Device
{
private:
	std::string name = "Heating";
	int intensity = 0;
	state currentHeatingState = state::off;

public:

	std::string getName() override;
	state getState() noexcept override;
	void turnDeviceOn() override;
	void turnDeviceOff() override;
	void increaseIntensity();
	void decreaseIntensity();

	int getIntensity() noexcept override;
	void setIntensity(int newIntensity) override;

	~Heating() override = default;
};