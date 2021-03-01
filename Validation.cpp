#include <iostream>

#include "Validation.h"

uint16_t Validation::integerValidation(uint16_t limit)
{
    uint16_t input = 0;
    std::cin >> input;

    while (!std::cin.good() || input < 0 || input > limit)
    {
        if (input < 0 || input > limit)
        {
            std::cout << "Please enter a value no larger than " << limit << " and no smaller than 0.\n> ";
        }
        else
        {
            std::cout << "ERROR: Input is not valid. Please enter a valid input.\n> "; // Informs user of invalid input
        }

        std::cin.clear(); // Clears the cin failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores the invalid input

        std::cin >> input; // Requests new input from the user
    }

    std::cin.clear(); // Clears the cin failbit
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores the invalid input

    return input;
}

std::string Validation::stringValidation()
{
    return "piss";
}