/*
    Cao, Aaron (Team Leader)
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
	return donorID;
}

bool Donor::operator<(const Donor& otherDonor) const 
{
	return donorID < otherDonor.donorID;
}
