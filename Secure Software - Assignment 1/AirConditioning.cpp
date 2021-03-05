#include "AirConditioning.h"
#include "View.h"


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
	View view;
	currentACState = state::on;
	view.printMessage("The air conditioning has been turned on.\n");
}
void AirConditioning::turnDeviceOff()
{
	View view;
	currentACState = state::off;
	view.printMessage("The air conditioning has been turned off.\n");
}