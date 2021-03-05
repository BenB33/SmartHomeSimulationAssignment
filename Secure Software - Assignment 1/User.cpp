#include "User.h"

#include <iostream>

// Getter and Setter for Username
std::string User::getUsername() const
{
	return username;
}
void User::setUsername(std::string passedUsername)
{
	username = passedUsername;
}

// Getter and Setter for ProofOfID
std::string User::getProofOfID()
{
	return proofOfID;
}
void User::setProofOfID(std::string proofToken)
{
	proofOfID = proofToken;
}

