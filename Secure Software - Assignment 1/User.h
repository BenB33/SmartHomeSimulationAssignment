#pragma once
#include <string>

class User
{
private:
	std::string username;
	std::string proofOfID;

public:

	// Getter and setter for username
	void setUsername(std::string username);
	std::string getUsername() const;

	// Getter and setter for proof of ID
	std::string getProofOfID();
	void setProofOfID(std::string proofToken);
};