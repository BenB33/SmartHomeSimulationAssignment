#include "Light.h"
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
	currentLightState = state::on;
	intensity = 50;
	//std::cout << "The light has been turned on.\nIntensity: " << intensity << std::endl;
}

void Light::turnDeviceOff()
{
	currentLightState = state::off;
	intensity = 0;
	//std::cout << "The light has been turned off." << std::endl;
}

int Light::getIntensity() noexcept
{
	return intensity;
}

void Light::setIntensity(int newIntensity)
{
	intensity = newIntensity;
}