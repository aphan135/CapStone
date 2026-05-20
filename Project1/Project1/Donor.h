/*
	Cao, Aaron (Team Leader)
	Phan, Aaron
	Do, Adam

	Spring 2026
	CS A250 - C++ 2

	College Donations
*/

#ifndef DONOR_H
#define DONOR_H

#include <string>

class Donor {
public:
	Donor(const std::string& aDonorName, int aDonorID)
		: donorName(aDonorName), donorID(aDonorID) {}

	std::string getDonorName() const;
	int getDonorID() const;

	bool operator<(const Donor& other) const;
private:
	std::string donorName;
	int donorID;
};

#endif
