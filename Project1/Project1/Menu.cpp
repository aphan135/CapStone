/*
    Cao, Aaron (Team Leader)
    Phan, Aaron
    Do, Adam

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "Menu.h"
#include "DonationManager.h"

#include <iostream>
#include <string>

using namespace std;


// Definition of function displayMenu
// Your code here…
void displayMenu() {
    cout << "\n============= DONATION MENU =============\n\n"
	 << "\t1. Add college \n"
	 << "\t2. Add donation \n"
	 << "\t3. Print colleges \n"
	 << "\t4. Print donations by college \n"
	 << "\t5. Print donations by donor \n"
	 << "\t6. Print totals by college \n"
	 << "\t7. Print totals by donor \n"
	 << "\t8. Print statistics \n"
	 << "\t9. Print highest donor \n"
	 << "\t10. Print highest-funded college \n"
	 << "\t0. Exit \n\n";
}

// Definition of function processUserChoices
// Your code here...
void processUserChoices(DonationManager& manager) {	
	bool exit = false;
	displayMenu();
	while (!exit)
	{
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;
		if (choice == 1) 
		{
			string collegeCode, collegeName;

			cout << "Enter college code: ";
			cin >> collegeCode;

			cout << "Enter college name: ";
			cin.ignore();
			getline(cin, collegeName);

			manager.addCollege(collegeCode, collegeName);
			cout << "\n\t >>> College added.\n\n";
		}
		else if (choice == 2) 
		{
			string donorName, collegeCode;
			double amount;

			cout << "Enter new donor name: ";
			cin.ignore();
			getline(cin, donorName);

			int newID = manager.addDonor(donorName);

			cout << "\n\t >>> New donor ID: " << newID << endl;
			cout << "\nEnter college code: ";
			cin >> collegeCode;

			cout << "Enter donation amount: ";
			cin >> amount;

			manager.addDonation(donorName, collegeCode, amount);
			cout << "\n\t >>> Donation added.\n\n";

		}
		else if (choice == 3) 
		{
			manager.printColleges();
			cout << endl;
		}
		else if (choice == 4) 
		{
			manager.printDonationsByCollege();
			cout << endl;
		}
		else if (choice == 5) 
		{
			manager.printDonationsByDonor();
			cout << endl;
		}
		else if (choice == 6) 
		{
			manager.printTotalsByCollege();
			cout << endl;
		}
		else if (choice == 7) 
		{
			manager.printTotalsByDonor();
			cout << endl;
		}
		else if (choice == 8) 
		{
			manager.printStatistics();
			cout << endl;
		}
		else if (choice == 9) 
		{
			manager.printHighestDonor();
			cout << endl;
		}
		else if (choice == 10) 
		{
			manager.printCollegeWithHighestTotal();
			cout << endl;
		}
		else if (choice == 0)
		{
			cout << "\t>>>Logging out..." << endl;
			exit = true;
			break;
		}
		else 
		{
			cout << "Invalid choice. Please try again.\n";
		}
		system("pause");
		displayMenu();
	}
}
