#include "Authenticator.h"

#include <iostream>

std::string Authenticator::encryptDecrypt(std::string toEncrypt)
{
	// TODO: Add encryption - XOR Encryption
	// To decrypt, encrypy again

	char key = 'A';
	std::string encryptedString = toEncrypt;
	for (uint16_t i = 0; i < toEncrypt.size(); i++)
	{
		encryptedString.at(i) = toEncrypt.at(i) ^ key;
	}
	return encryptedString;
}

ProofOfID Authenticator::authenticateUser(User& user)
{
	AuthenticationInfo info;
	ProofOfID proofOfID;

	std::string username = user.getUsername();
	std::string password;
	std::string token;

	view.printMessage("\nEnter your password\n> ");
	std::cin >> password;

	if (info.isValidUser(username, password))
	{
		view.printMessage("\nLogged in successfully.\nWelcome ");
		view.printMessage(user.getUsername() + "!\n");

		token = encryptDecrypt(username + password);
		proofOfID = ProofOfID(token);
		user.setProofOfID(token);
	}
	else
	{
		view.printMessage("Invalid login credentials. Please try again!");
	}

	return proofOfID;
}




void Authenticator::initaliseLoginInfo(User& user)
{
	// get this shit working
	//char buffer[20];
	//std::string username;
	//std::string password;

	//try
	//{
	//	std::ifstream fileRead("userInfo.txt");

	//	fileRead.exceptions(std::ifstream::eofbit || std::ifstream::failbit || std::ifstream::badbit);

	//	if (fileRead.is_open())
	//	{
	//		while (!fileRead.eof())
	//		{
	//			fileRead.getline(buffer, 20);
	//			username = encryptDecrypt(buffer);
	//			fileRead.getline(buffer, 20);
	//			password = encryptDecrypt(buffer);

	//			Users.insert(std::pair<std::string, std::string>(username, password));
	//		}
	//	}
	//}
	//catch (std::exception e)
	//{

	//}



}