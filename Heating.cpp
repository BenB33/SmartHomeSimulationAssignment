#include "Heating.h"
#include <iostream>


std::string Heating::getName()
{
	return name;
}

state Heating::getState() noexcept
{
	return currentHeatingState;
}

void Heating::turnDeviceOn()
{
	currentHeatingState = state::on;
	intensity = 50;
	//std::cout << "The heating has been turned on.\nIntensity: " << intensity << std::endl;
}

void Heating::turnDeviceOff()
{
	currentHeatingState = state::off;
	intensity = 0;
	//std::cout << "The heating has been turned off." << std::endl;
}

void Heating::increaseIntensity()
{
	intensity = intensity + 10;
	std::cout << "The heating has been turned up by 10.\nIntensity: " << intensity << std::endl;
}
void Heating::decreaseIntensity()
{
	intensity = intensity - 10;
	std::cout << "The heating has been turned down by 10.\nIntensity: " << intensity << std::endl;
}

int Heating::getIntensity() noexcept
{
	return intensity;
}

void Heating::setIntensity(int newIntensity)
{
	intensity = newIntensity;
}