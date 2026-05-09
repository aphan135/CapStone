/*
   Phan, Aaron (team leader?)
    Cao, Aaron
    Do, Adam

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "DonationManager.h"
#include <iostream>

using namespace std;

int DonationManager::addDonor(const string& donorName) {
    Donor donorPerson(donorName, nextDonorID);
    donors.insert(donorPerson);
    nextDonorID = nextDonorID + 1;
    return donorPerson.getDonorID();
}

void DonationManager::addCollege(const string& collegeCode, const string& collegeName) {
    colleges.addCollege(collegeCode, collegeName);
}

void DonationManager::addDonation(const string& donorName, const string& collegeCode, double amount) {
    addDonor(donorName);
    Donation donorPerson(donorName, collegeCode, amount);
    donations.addDonation(donorPerson);
}

void DonationManager::printColleges() const {
    colleges.printColleges();
}

void DonationManager::printDonationsByCollege() const {
    const map<string, string>& collegeMap = colleges.getColleges();

    for (const auto& pair : collegeMap) {
        double total = getCollegeTotal(pair.first);
        cout << pair.first << " " << total << endl;
    }
}

void DonationManager::printDonationsByDonor() const {
    DonationNode* current = donations.getFirst();

    while (current != nullptr) {
        cout << "Donor Name: " << current->data.getDonorName() 
            << endl << "College Code: " << current->data.getCollegeCode() 
            << endl << "Amount: " << current->data.getAmount() << endl;
        current = current->next;
    }
}

void DonationManager::printTotalsByCollege() const {
    const map<string, string>& collegeMap = colleges.getColleges();

    for (const auto& pair : collegeMap) {
        cout << pair.first << " " << getCollegeTotal(pair.first) << endl;
    }
}

void DonationManager::printTotalsByDonor() const {
    for (const auto& donor : donors) {
        cout << donor.getDonorName() << " "
            << getDonorTotal(donor.getDonorName()) << endl;
    }
}

void DonationManager::printStatistics() const {
    cout << donors.size() << endl;
    cout << colleges.getColleges().size() << endl;
    cout << donations.getNumOfDonations() << endl;
}

void DonationManager::printHighestDonor() const {
    string bestName = "";
    double bestAmount = -1;

    for (const auto& donor : donors) {
        double total = getDonorTotal(donor.getDonorName());
        if (total > bestAmount) {
            bestAmount = total;
            bestName = donor.getDonorName();
        }
    }

    cout << bestName << " " << bestAmount << endl;
}

void DonationManager::printCollegeWithHighestTotal() const {
    const map<string, string>& collegeMap = colleges.getColleges();

    string bestCollege = "";
    double bestAmount = -1;

    for (const auto& pair : collegeMap) {
        double total = getCollegeTotal(pair.first);
        if (total > bestAmount) {
            bestAmount = total;
            bestCollege = pair.first;
        }
    }

    cout << bestCollege << " " << bestAmount << endl;
}

double DonationManager::getDonorTotal(const string& donorName) const {
    DonationNode* current = donations.getFirst();

    while (current != nullptr) {
        if (current->data.getDonorName() == donorName) {
            return current->data.getAmount();
        }
        current = current->next;
    }

    return 0;
}

double DonationManager::getCollegeTotal(const string& collegeCode) const {
    DonationNode* current = donations.getFirst();
    double total = 0;

    while (current != nullptr) {
        if (current->data.getCollegeCode() == collegeCode) {
            total = total + current->data.getAmount();
        }
        current = current->next;
    }

    return total;
}
