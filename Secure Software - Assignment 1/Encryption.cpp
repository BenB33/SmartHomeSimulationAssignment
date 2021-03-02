#include "encryption.h"

// Encryption/Decryption function (XOR Encryption)
std::string Encryption::encryptDecrypt(const std::string& toEncrypt)
{
	// Key used for encrypting/decrypting
	char key = 'A';

	// The string being encrypted/decrypted
	std::string encryptedString = toEncrypt;

	// For loop, looping through the string one char at a time,
	// each pass, the specific char is being encrypted/decrypted
	for (uint16_t i = 0; i < toEncrypt.size(); i++)
	{
		encryptedString.at(i) = toEncrypt.at(i) ^ key;
	}

	// Returning the encrypted/decrypted string
	return encryptedString;
}