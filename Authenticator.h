#pragma once

#include "AuthenticationInfo.h"
#include "User.h"
#include "ProofOfID.h"
#include "View.h"

#include <string>
#include <fstream>

class Authenticator
{
private:
	View view;

	std::string encryptDecrypt(std::string toEncrypt);

public:

	ProofOfID authenticateUser(User& user);
	void initaliseLoginInfo(User& user);
};