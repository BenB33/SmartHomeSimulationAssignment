#include "AuthenticationInfo.h"

#include <iostream>
#include <fstream>


AuthenticationInfo::AuthenticationInfo()
{
	// TODO: Grab these from a file (Encrypted)
	Users.insert(std::pair<std::string, std::string>("admin", "admin"));
	Users.insert(std::pair<std::string, std::string>("student", "student"));
	Users.insert(std::pair<std::string, std::string>("guest", "guest"));
}


void AuthenticationInfo::initaliseLoginInfo()
{
	// Figure out how to bring info from file while encrypting/decrypting it
}

bool AuthenticationInfo::isValidUser(std::string username, std::string password)
{
	bool isUserValid = false;

	std::map<std::string, std::string>::iterator it;
	it = Users.find(username);

	if (it != Users.end())
	{
		if (!(it->second.compare(password)))
		{
			isUserValid = true;
		}
	}
	return isUserValid;
}