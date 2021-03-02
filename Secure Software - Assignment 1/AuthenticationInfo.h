#pragma once
#include <map>
#include <string>

#include "User.h"

class AuthenticationInfo
{
private:
	std::map<std::string, std::string> Users;

public:
	AuthenticationInfo();

	bool isValidUser(std::string username, std::string password);
};