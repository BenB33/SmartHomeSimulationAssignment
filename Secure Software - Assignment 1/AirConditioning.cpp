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
	//std::cout << "The air conditioning has been turned on.\nIntensity: " << intensity << std::endl;
}
void AirConditioning::turnDeviceOff()
{
	currentACState = state::off;
	//std::cout << "The air conditioning has been turned off." << std::endl;
}