#pragma once

#include <string>

#include "AuthenticationInfo.h"
#include "ProofOfID.h"
#include "User.h"

class Authenticator
{
public:
	// Authenticate user given the username and password, 
	// returns the proofOfID encrypted token.
	ProofOfID authenticateUser(User& user);
};