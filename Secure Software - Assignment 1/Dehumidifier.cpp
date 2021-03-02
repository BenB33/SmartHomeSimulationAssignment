#include "Dehumidifier.h"

#include <iostream>

std::string Dehumidifier::getName()
{
	return name;
}

state Dehumidifier::getState() noexcept
{
	return currentDehumidifierState;
}

void Dehumidifier::turnDeviceOn()
{
	currentDehumidifierState = state::on;
	std::cout << "The dehumidifier has been turned on." << std::endl;
}

void Dehumidifier::turnDeviceOff()
{
	currentDehumidifierState = state::off;
	std::cout << "The dehumidifier has been turned off." << std::endl;
}