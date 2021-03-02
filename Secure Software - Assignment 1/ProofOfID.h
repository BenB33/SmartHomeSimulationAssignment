#pragma once

#include <string>

class ProofOfID
{
private:
	std::string proofID;

public:
	// Constructors for Proof of ID
	ProofOfID() = default;
	ProofOfID(std::string);

	// Getter and setter for proof of ID
	std::string getProofID();
	void setProofID(std::string);
};