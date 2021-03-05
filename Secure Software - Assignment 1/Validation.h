#pragma once
#include <string>

class Validation
{
public:
	static uint16_t unsignedIntegerValidation(uint16_t limit);
    static int signedIntegerValidation();
    uint16_t unsignedSecureAddition(uint16_t ui_a, uint16_t ui_b);
    uint16_t unsignedSecureSubtraction(uint16_t ui_a, uint16_t ui_b);

    int64_t signedSecureSubtraction(int64_t si_a, int64_t si_b);
    int64_t signedSecureAddition(int64_t si_a, int64_t si_b);
};
