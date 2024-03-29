#include "Heating.h"
#include "View.h"
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
	std::cout << "The heating has been turned on." << std::endl;
}

void Heating::turnDeviceOff()
{
	currentHeatingState = state::off;
	std::cout << "The heating has been turned off." << std::endl;
}