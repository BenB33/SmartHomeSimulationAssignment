#include "AirConditioning.h"

std::string AirConditioning::getName()
{
	return name;
}
state AirConditioning::getState() noexcept
{
	return currentACState;
}
void AirConditioning::turnDeviceOn()
{
	currentACState = state::on;
	intensity = 50;
	//std::cout << "The air conditioning has been turned on.\nIntensity: " << intensity << std::endl;
}
void AirConditioning::turnDeviceOff()
{
	currentACState = state::off;
	intensity = 0;
	//std::cout << "The air conditioning has been turned off." << std::endl;
}

int AirConditioning::getIntensity() noexcept
{
	return intensity;
}

void AirConditioning::setIntensity(int newIntensity)
{
	intensity = newIntensity;
}