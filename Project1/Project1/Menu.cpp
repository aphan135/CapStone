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
    cout << "\n============= DONATION MENU =============\n\n";
	cout << "\t1. Add college \n"
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
	displayMenu();
	
	bool exit = false;
	while (!exit) {
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
			case 1: {
				string collegeCode, collegeName;
				cout << "Enter college code: ";
				cin >> collegeCode;
				cout << "Enter college name: ";
				cin.ignore();
				getline(cin, collegeName);
				manager.addCollege(collegeCode, collegeName);
				cout << "\n\t >>> College added.\n\n";
				system("Pause");
				displayMenu();
				break;
			}
			case 2: {
				string donorName, collegeCode;
				double amount;
				cout << "Enter donor name: ";
				cin.ignore();
				getline(cin, donorName);
				int newID = manager.addDonor(donorName);
				cout << "\n\t >>> New Donor ID: " << newID << endl;
				cout << "\nEnter college code: ";
				cin >> collegeCode;
				cout << "Enter donation amount: ";
				cin >> amount;
				manager.addDonation(donorName, collegeCode, amount);
				cout << "\n\t >>> Donation added.\n\n";
				system("Pause");
				displayMenu();
				break;
			}
			case 3:{				
				manager.printColleges();
				system("Pause");
				displayMenu();
				break;
			}

			case 4: {
				manager.printDonationsByCollege();
				system("Pause");
				displayMenu();
				break;
			}
			case 5: {
				manager.printDonationsByDonor();
				system("Pause");
				displayMenu();
				break;
			}
			case 6:{
				manager.printTotalsByCollege();
				system("Pause");
				displayMenu();
				break;
			}
			case 7:{
				manager.printTotalsByDonor();
				system("Pause");
				displayMenu();
				break;
			}
			case 8: {
				manager.printStatistics();
				system("Pause");
				displayMenu();
				break;
			}
			case 9: {
				manager.printHighestDonor();
				system("Pause");
				displayMenu();
				break;
			}
			case 10: {
				manager.printCollegeWithHighestTotal();
				system("Pause");
				displayMenu();
				break;
			}
			case 0:{
				cout << ">>>Logging out...\n\n";
				exit = true;
				break;
			default:
				cout << "Invalid choice. Please try again.\n";
			}
		}
	}
}
