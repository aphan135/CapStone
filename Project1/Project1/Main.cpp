/*
    Cao, Aaron (Team Leader)
    Phan, Aaron
    Do, Adam

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "DonationManager.h"
#include "FileLoader.h"
#include "Menu.h"

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    
    // Set precision for currency-related output
    cout << fixed << setprecision(2);

    DonationManager manager;

	loadCollegesFromFile("colleges.csv", manager);
	loadDonationsFromFile("donations.csv", manager);

    processUserChoices(manager);
    
    cout << endl;
	system("pause");
    return 0;
}
