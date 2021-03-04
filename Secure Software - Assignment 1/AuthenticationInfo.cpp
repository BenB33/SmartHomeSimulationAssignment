#include "AuthenticationInfo.h"
#include "Encryption.h"

#include <iostream>
#include <fstream>
#include <sstream>




AuthenticationInfo::AuthenticationInfo()
{
	// Initialize an ifstream with exceptions
	std::ifstream readFile("userList.txt", std::ios::in);
	readFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	// If the file is able to be open
	if (readFile.is_open())
	{
		std::string temp;
		std::string userInfo;
		try
		{
			while (readFile.peek() != std::char_traits<char>::eof())
			{
				std::getline(readFile, temp);
				userInfo = Encryption::encryptDecrypt(temp);
				
				std::stringstream stream(userInfo);

				std::string username;
				stream >> username;
				std::string password;
				stream >> password;

				Users.insert({ username, password });
			}
		}
		catch (std::exception ex)
		{
			std::cerr << "ERROR: " << ex.what() << std::endl;
		}
	}
}


// Determines whether the user logging in 
bool AuthenticationInfo::isValidUser(std::string username, std::string password)
{
	bool isUserValid = false;

	std::map<std::string, std::string>::iterator it;
	it = Users.find(username);

	if (it != Users.end()) if (!(it->second.compare(password))) isUserValid = true;
	return isUserValid;
}