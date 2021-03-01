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
	intensity = 50;
	//std::cout << "The dehumidifier has been turned on.\nIntensity: " << intensity << std::endl;
}

void Dehumidifier::turnDeviceOff()
{
	currentDehumidifierState = state::off;
	intensity = 0;
	//std::cout << "The dehumidifier has been turned off." << std::endl;
}

int Dehumidifier::getIntensity() noexcept
{
	return intensity;
}

void Dehumidifier::setIntensity(int newIntensity)
{
	intensity = newIntensity;
}