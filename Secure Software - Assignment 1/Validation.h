#pragma once
#include <string>

class Validation
{
public:
	static uint16_t unsignedIntegerValidation(uint16_t limit);
    static int signedIntegerValidation();
    uint16_t unsignedSecureAddition(uint16_t ui_a, uint16_t ui_b);
    uint16_t unsignedSecureSubtraction(uint16_t ui_a, uint16_t ui_b);

    int signedSecureSubtraction(int si_a, int si_b);
    int signedSecureAddition(int si_a, int si_b);
};
