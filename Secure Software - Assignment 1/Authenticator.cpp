#include "Authenticator.h"
#include "Encryption.h"
#include "View.h"

#include <iostream>
#include <sstream>
#include <fstream>

ProofOfID Authenticator::authenticateUser(User& user)
{
	AuthenticationInfo info;
	Encryption encrypt;
	ProofOfID proofOfID;
	View view;

	// Grabbing the username from the user class object
	std::string username = user.getUsername();
	std::string password;
	std::string token;

	// User inputs their password
	view.printMessage("\nEnter your password\n> ");
	std::cin >> password;

	// Calls function isValidUser from the AuthenticationInfo class,
	// and passes the username and password. Either returns true or false
	// depending on whether the user is valid or not.
	if (info.isValidUser(username, password))
	{
		// If the user is valid, the user is logged in successfully.
		view.printMessage("\nLogged in successfully.\nWelcome ");
		view.printMessage(user.getUsername() + "!\n");

		// The token is encrypted using the username and password,
		// and then passed to token string.
		token = encrypt.encryptDecrypt(username + " " + password);

		// proofOfID object set using token.
		// user set proofOfID using token.
		proofOfID = ProofOfID(token);
		user.setProofOfID(token);
	}

	// Return the proof of ID.
	return proofOfID;
}