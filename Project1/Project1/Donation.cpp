/*
	Cao, Aaron (Team Leader)
	Phan, Aaron
	Do, Adam

	Spring 2026
	CS A250 - C++ 2

	College Donations
*/

#include "Donation.h"

#include <string>
using namespace std;

std::string Donation::getDonorName() const {
	return donorName;
}
std::string Donation::getCollegeCode() const {
	return collegeCode;
}
double Donation::getAmount() const {
	return amount;
}