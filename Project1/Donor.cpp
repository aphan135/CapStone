/*
	Cao, Aaron (team leader)
	Phan, Aaron
	Do, Adam

	Spring 2026
	CS A250 - C++ 2

	College Donations
*/

#include "Donor.h"

using namespace std;

string Donor::getDonorName() const 
{
	return donorName;
}

int Donor::getDonorID() const 
{
	return donorId;
}

bool Donor::operator<(const Donor& other) const 
{
	return donorId < other.donorId;
}
