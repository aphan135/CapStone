/*
	Cao, Aaron (Team Leader)
	Phan, Aaron
	Do, Adam

	Spring 2026
	CS A250 - C++ 2

	College Donations
*/

#include "FileLoader.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void loadCollegesFromFile(const string& fileName, 
    DonationManager& manager)
{
    ifstream inFile(fileName);

    if (inFile)
    {
        string line;
        while (getline(inFile, line))
        {
            if (line.empty())
            {
                continue;
            }

            const size_t comma = line.find(',');
            if (comma != string::npos)
            {
                const string code = line.substr(0, comma);
                const string name = line.substr(comma + 1);
                manager.addCollege(code, name);
            }
        }

        inFile.close();
        cout << "=> College data loaded...\n";
    }
    else
    {
        cerr << "=> Could not open colleges.csv." << endl;
    }
}

void loadDonationsFromFile(const string& fileName, 
    DonationManager& manager)
{
    ifstream inFile(fileName);

    if (inFile)
    {
        string line;
        while (getline(inFile, line))
        {
            if (line.empty())
            {
                continue;
            }

            istringstream iss(line);
            string donorName;
            string collegeCode;
            string amountStr;

            getline(iss, donorName, ',');
            getline(iss, collegeCode, ',');
            getline(iss, amountStr, ',');

            if (!donorName.empty() 
                && !collegeCode.empty()
                && !amountStr.empty())
            {
                const double CONST_AMOUNT = stod(amountStr);
                manager.addDonation(donorName, collegeCode, CONST_AMOUNT);
            }
        }

        inFile.close();
        cout << "=> Donation data loaded...\n";
    }
    else
    {
        cerr << "=> Could not open donations.csv." << endl;
    }
}
