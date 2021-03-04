#include "Light.h"
#include "View.h"
#include <iostream>

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
	const View view;
	currentLightState = state::on;
	view.printMessage("The light has been turned on.\n");
}

void Light::turnDeviceOff()
{
	const View view;
	currentLightState = state::off;
	view.printMessage("The light has been turned off.\n");
}