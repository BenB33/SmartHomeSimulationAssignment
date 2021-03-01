#include "User.h"

#include <iostream>

//User::User(std::string newUser)
//{
//	username = newUser;
//
//	Trust t;
//	trustLevel = t.getTrustLevel(username);
//}
//
//User::~User()
//{
//	username = "guest";
//	trustLevel = TrustLevel::low;
//}


// Getter and Setter for Username
std::string User::getUsername() const
{
	return username;
}
void User::setUsername()
{
	std::cin >> username;
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

