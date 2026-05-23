/* Cao, Aaron (Team Leader) 
   Phan, Aaron 
   Do, Adam 
   Spring 2026 
   CS A250 - C++ 2 
   College Donations */

#include "DonationManager.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

int DonationManager::addDonor(const string& donorName)
{
    Donor donorPerson(donorName, nextDonorID);
    donors.insert(donorPerson);
    nextDonorID = nextDonorID + 1;
    return donorPerson.getDonorID();
}

void DonationManager::addCollege(const string& collegeCode, const string& collegeName)
{
    colleges.addCollege(collegeCode, collegeName);
}

void DonationManager::addDonation(const string& donorName, const string& collegeCode, double amount)
{
    int donorID = addDonor(donorName);
    Donation donorPerson(donorName, collegeCode, amount);
    donations.addDonation(donorPerson);
}

void DonationManager::addDonation(int donorID, const string& collegeCode, double amount)
{
    auto iter = donors.begin();
    string donorName = " ";
    bool found = false;

    while (iter != donors.end() && !found)
    {
        if (iter->getDonorID() == donorID)
        {
            donorName = iter->getDonorName();
            found = true;
        }
        else
        {
            iter++;
        }
    }

    if (found)
    {
        Donation donorPerson(donorName, collegeCode, amount);
        donations.addDonation(donorPerson);
    }
}

void DonationManager::printColleges() const
{
    const auto& collegeMap = colleges.getColleges();
    for (const auto& pair : collegeMap)
    {
        cout << "\t" << pair.first << " - " << pair.second << endl;
    }
}

void DonationManager::printDonationsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    for (const auto& pair : collegeMap)
    {
        cout << "\t" << pair.first << " - " << pair.second << endl;
        const DonationNode* current = donations.getFirst();
        bool hasDonation = false;

        while (current != nullptr)
        {
            if (current->data.getCollegeCode() == pair.first)
            {
                cout << "\t    " << current->data.getDonorName() << " | Amount: $" << current->data.getAmount() << endl;
                hasDonation = true;
            }
            current = current->next;
        }

        if (!hasDonation)
        {
            cout << "\t    (no donation)" << endl;
        }
    }
}

void DonationManager::printDonationsByDonor() const
{
    DonationNode* current = donations.getFirst();
    while (current != nullptr)
    {
        std::string donorName = current->data.getDonorName();
        int donorId = -1;

        for (const auto& donor : donors)
        {
            if (donor.getDonorName() == donorName)
            {
                donorId = donor.getDonorID();
                break;
            }
        }

        cout << "\tID " << donorId << " - " << donorName << endl
             << "\t\t" << colleges.getCollegeName(current->data.getCollegeCode()) << " (" << current->data.getCollegeCode() << ")" << endl
             << "\t\tAmount: $" << current->data.getAmount() << endl;
        current = current->next;
    }
}

void DonationManager::printTotalsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    for (const auto& pair : collegeMap)
    {
        cout << "\t" << pair.first << " - " << pair.second << "\n\t    Total donation amount: $" << getCollegeTotal(pair.first) << endl;
    }
}

void DonationManager::printTotalsByDonor() const
{
    for (const auto& donor : donors)
    {
        cout << "\t(ID " << donor.getDonorID() << ") " << donor.getDonorName() << " | $" << getDonorTotal(donor.getDonorName()) << endl;
    }
}

void DonationManager::printStatistics() const
{
    cout << "\tNumber of donors: " << donors.size() << "\n"
         << "\tNumber of colleges: " << colleges.getColleges().size() << "\n"
         << "\tNumber of donations: " << donations.getNumOfDonations() << "\n";
}

void DonationManager::printHighestDonor() const
{
    double bestAmount = -1.0;
    std::vector<std::string> highestDonors;
    highestDonors.reserve(donors.size());

    for (const auto& donor : donors)
    {
        double total = getDonorTotal(donor.getDonorName());
        if (total > bestAmount)
        {
            bestAmount = total;
            highestDonors.clear();
            highestDonors.push_back(donor.getDonorName());
        }
        else if (total == bestAmount && bestAmount > 0)
        {
            highestDonors.push_back(donor.getDonorName());
        }
    }

    cout << "\tHighest donor(s):\n";
    for (const auto& donor : highestDonors)
    {
        cout << "\t    " << donor << "\n";
    }
    cout << "\t    Highest amount donated: $" << bestAmount << endl;
}

void DonationManager::printCollegeWithHighestTotal() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    vector<string> highestColleges;
    highestColleges.reserve(collegeMap.size());
    double bestAmount = -1.0;

    for (const auto& pair : collegeMap)
    {
        double total = getCollegeTotal(pair.first);
        if (total > bestAmount)
        {
            bestAmount = total;
            highestColleges.clear();
            highestColleges.push_back(pair.first);
        }
        else if (total == bestAmount && bestAmount > 0)
        {
            highestColleges.push_back(pair.first);
        }
    }

    cout << "\tCollege(s) with highest total donation:\n";
    for (const auto& collegeCode : highestColleges)
    {
        cout << "\t    " << colleges.getCollegeName(collegeCode) << " (" << collegeCode << ")" << endl;
    }
    cout << "\t    Highest total received: $" << bestAmount << endl;
}

double DonationManager::getDonorTotal(const string& donorName) const
{
    DonationNode* current = donations.getFirst();
    double total = 0;

    while (current != nullptr)
    {
        if (current->data.getDonorName() == donorName)
        {
            total = total + current->data.getAmount();
        }
        current = current->next;
    }
    return total;
}

double DonationManager::getCollegeTotal(const string& collegeCode) const
{
    DonationNode* current = donations.getFirst();
    double total = 0;

    while (current != nullptr)
    {
        if (current->data.getCollegeCode() == collegeCode)
        {
            total = total + current->data.getAmount();
        }
        current = current->next;
    }
    return total;
}
