#include "ProofOfID.h"

#include <iostream>

// Constructor
ProofOfID::ProofOfID(std::string newIDProof) : proofID(newIDProof) {};


// Getter and setter for proof of ID
std::string ProofOfID::getProofID()
{
	return proofID;
}
void ProofOfID::setProofID(std::string newIDProof)
{
	proofID = newIDProof;
}

