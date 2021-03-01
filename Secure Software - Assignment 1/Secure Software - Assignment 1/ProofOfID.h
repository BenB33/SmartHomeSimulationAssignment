#pragma once

#include <string>

class ProofOfID
{
private:
	std::string proofID;

public:
	ProofOfID() = default;
	ProofOfID(std::string);

	std::string getProofID();
	void setProofID(std::string);
};