#pragma once
#include "State.h"

#include <string>

class Device
{
public:
	virtual std::string getName() = 0;
	virtual state getState() = 0;
	virtual void turnDeviceOn() = 0;
	virtual void turnDeviceOff() = 0;
	virtual ~Device() = default;
};