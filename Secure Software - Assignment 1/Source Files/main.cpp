#include <iostream>
#include <map>

#include "User.h"

int integerInputValidaiton(int menuSize)
{
    int input = 0;
    std::cin >> input;

    while (!std::cin.good() || input < 0 || input > menuSize)
    {
        std::cout << "ERROR: Input is not valid. Please enter a valid input." << std::endl << "> "; // Informs user of invalid input

        std::cin.clear(); // Clears the cin failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores the invalid input

        std::cin >> input; // Requests new input from the user
    }

    std::cin.clear(); // Clears the cin failbit
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores the invalid input

    return input;
}



void mainMenu()
{
    int menuSelection = 0;

    while (menuSelection == 0)
    {
        std::cout << "Please selection an option: " << std::endl << std::endl;

        std::cout << "[1] Device Status'" << std::endl;
        std::cout << "[2] Login" << std::endl;
        std::cout << "[3] Change Device Status" << std::endl;
        std::cout << "[4] Exit..." << std::endl << std::endl << "> ";

        menuSelection = integerInputValidaiton(4); // Passing 4 to integerInputValidation to limit menu selection size
    }

    switch (menuSelection)
    {
    case 1:
        system("CLS");
        std::cout << "Device Status'";
        break;
    case 2:
        system("CLS");
        std::cout << "Login";
        break;
    case 3:
        system("CLS");
        std::cout << "Change Device Status";
        break;
    case 4:
        system("CLS");
        std::cout << "Exit...";
        break;
    }
}


int main()
{
    

    mainMenu();


}
