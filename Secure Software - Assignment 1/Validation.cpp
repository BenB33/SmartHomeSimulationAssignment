#include <iostream>
#include <gsl.h>

#include "Validation.h"


uint16_t Validation::unsignedIntegerValidation(uint16_t limit)
{
    uint16_t input = 0;
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > limit)
    {
        if (input < 1 || input > limit) std::cout << "Please enter a value no larger than " << limit << " and no smaller than 1.\n> ";
        else std::cout << "ERROR: Input is not valid. Please enter a valid input.\n> "; // Informs user of invalid input

        std::cin.clear(); // Clears the cin failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores the invalid input

        std::cin >> input; // Requests new input from the user
    }

    std::cin.clear(); // Clears the cin failbit
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores the invalid input

    return input;
}

int Validation::signedIntegerValidation()
{
    int input = 0;
    std::cin >> input;

    while (!std::cin.good())
    {
        std::cout << "ERROR: Input is not valid. Please enter a valid input.\n> ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cin >> input;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return input;
}


uint16_t Validation::unsignedSecureAddition(uint16_t ui_a, uint16_t ui_b) 
{
    if (std::numeric_limits<uint16_t>::max() - ui_a < ui_b) throw "ERROR: Unsigned int wrap.\n";
    else return gsl::narrow_cast<uint16_t>(ui_a + ui_b);
}


uint16_t Validation::unsignedSecureSubtraction(uint16_t ui_a, uint16_t ui_b) 
{
    if (ui_a < ui_b) throw "ERROR: Unsigned int wrap.\n";
    const uint16_t returnValue = gsl::narrow_cast<uint16_t>(ui_a - ui_b);
    return returnValue;
}


int Validation::signedSecureSubtraction(int si_a, int si_b) 
{
    if ((si_b > 0 && si_a < std::numeric_limits<int>::max() + si_b) || 
        (si_b < 0 && si_a > std::numeric_limits<int>::max() + si_b)) throw "\nERROR: Signed Integer Overflow.\n";
    else return si_a - si_b;
}


int Validation::signedSecureAddition(int si_a, int si_b)
{
    if (((si_b > 0) && (si_a > (std::numeric_limits<int>::max() - si_b))) || 
        ((si_b < 0) && (si_a < (std::numeric_limits<int>::max() - si_b)))) throw "\nERROR: Signed Integer Overflow.\n";
    else return si_a + si_b;
}
