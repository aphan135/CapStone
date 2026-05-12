/*
    Cao, Aaron (Team Leader)
    Phan, Aaron
    Do, Adam

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#ifndef DONATIONMANAGER_H
#define DONATIONMANAGER_H

#include "Donor.h"
#include "CollegeList.h"
#include "DonationList.h"

#include <string>
#include <set>
#include <map>

const int START_ID = 3000;

class DonationManager
{
public:
    DonationManager() : nextDonorID(START_ID) {}

    int addDonor(const std::string& donorName);
    void addCollege(const std::string& collegeCode, const std::string& collegeName);
    void addDonation(const std::string& donorName, const std::string& collegeCode, double amount);

    void printColleges() const;
    void printDonationsByCollege() const;
    void printDonationsByDonor() const;
    void printTotalsByCollege() const;
    void printTotalsByDonor() const;
    void printStatistics() const;
    void printHighestDonor() const;
    void printCollegeWithHighestTotal() const;

private:
    std::set<Donor> donors;
    CollegeList colleges;
    DonationList donations;
    int nextDonorID;

	// Helper functions
    double getDonorTotal(const std::string& donorName) const;
    double getCollegeTotal(const std::string& collegeCode) const;
	
};

#endif
