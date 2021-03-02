#include "Light.h"
#include "View.h"
#include <iostream>

View view;

std::string Light::getName()
{
	return name;
}

state Light::getState() noexcept
{
	return currentLightState;
}

void Light::turnDeviceOn()
{
	currentLightState = state::on;
	std::cout << "The light has been turned on." << std::endl;
}

void Light::turnDeviceOff()
{
	currentLightState = state::off;
	std::cout << "The light has been turned off." << std::endl;
}