#pragma once
#include <string>

class User
{
private:
	std::string username;
	std::string proofOfID = "";

public:
	//User(std::string username);
	//~User();

	void setUsername();
	std::string getUsername() const;


	std::string getProofOfID();
	void setProofOfID(std::string proofToken);
};