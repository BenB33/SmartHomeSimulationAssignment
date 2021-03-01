#include "ProofOfID.h"

#include <iostream>

std::string ProofOfID::getProofID()
{
	return proofID;
}

void ProofOfID::setProofID(std::string newIDProof)
{
	proofID = newIDProof;
}

ProofOfID::ProofOfID(std::string newIDProof) : proofID(newIDProof) {};