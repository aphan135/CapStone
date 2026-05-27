/*
    Cao, Aaron (Team Leader)
    Phan, Aaron
    Do, Adam

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "DonationManager.h"

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int DonationManager::addDonor(const string& donorName)
{
    for (const auto& donor : donors)
    {
        if (donor.getDonorName() == donorName)
        {
            return donor.getDonorID();
        }
    }

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
void DonationManager::addDonation(const int donorID, const std::string& collegeCode, double amount)
{
    auto iter = donors.begin();
    std::string donorName = "";

    while (iter != donors.end())
    {
        if (iter->getDonorID() == donorID)
        {
            donorName = iter->getDonorName();
        }
        iter++;
    }
    Donation donorPerson(donorName, collegeCode, amount);
    donations.addDonation(donorPerson);

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
        bool found = false;
        while (current != nullptr)
        {
            if (current->data.getCollegeCode() == pair.first)
            {
                cout << "\t    " << current->data.getDonorName() << " | Amount: $"
                    << current->data.getAmount() << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found)
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
            << "\t    " << colleges.getCollegeName(current->data.getCollegeCode()) << " (" << current->data.getCollegeCode() << ")" << endl
            << "\t    Amount: $" << current->data.getAmount() << endl;
        current = current->next;
    }
}

void DonationManager::printTotalsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();

    for (const auto& pair : collegeMap)
    {
        cout << "\t" << pair.first << " - " << pair.second
            << "\n\t    Total donation amount: $" << getCollegeTotal(pair.first) << endl;
    }
}

void DonationManager::printTotalsByDonor() const
{
    for (const auto& donor : donors)
    {
        cout << "\t(ID " << donor.getDonorID() << ") "
            << donor.getDonorName() << " | $"
            << getDonorTotal(donor.getDonorName()) << endl;
    }
}

void DonationManager::printStatistics() const
{
    cout << "\tNumber of donors: " << donors.size() << "\n"
        << "\tNumber of colleges: " << colleges.getColleges().size() << "\n"
        << "\tNumber of donations: " << donations.getNumOfDonations() << endl;
}

void DonationManager::printHighestDonor() const
{
    double highestAmount = 0;

    for (const auto& donor : donors)
    {
        double total = getDonorTotal(donor.getDonorName());
        if (total > highestAmount)
        {
            highestAmount = total;
        }
    }

    vector<string> highestDonors;
    highestDonors.reserve(donors.size());

    for (const auto& donor : donors)
    {
        if (getDonorTotal(donor.getDonorName()) == highestAmount)
        {
            highestDonors.push_back(donor.getDonorName());
        }
    }

    cout << "\tHighest donor(s):" << endl;
    for (const auto& name : highestDonors)
    {
        cout << "\t    " << name << endl;
    }
    cout << "\t    Highest amount donated: $"
        << highestAmount << endl;
}

void DonationManager::printCollegeWithHighestTotal() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    double highestTotal = 0;

    vector<string> highestColleges;
    highestColleges.reserve(collegeMap.size());

    for (const auto& pair : collegeMap)
    {
        double total = getCollegeTotal(pair.first);
        if (total > highestTotal)
        {
            highestTotal = total;
            highestColleges.clear();
            highestColleges.push_back(pair.second + " (" + pair.first + ")");
        }
        else if (total == highestTotal)
        {
            highestColleges.push_back(pair.second + " (" + pair.first + ")");
        }
    }

    cout << "\tCollege(s) with highest total donation:" << endl;
    for (const auto& college : highestColleges)
    {
        cout << "\t    " << college << endl;
    }
    cout << "\t    Highest total received: $"
        << highestTotal << "\n";
}

double DonationManager::getDonorTotal(const string& donorName) const
{
    DonationNode* current = donations.getFirst();
    double total = 0;
    while (current != nullptr) {
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
