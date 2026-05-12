/*
    Cao, Aaron (Team Leader)
    Phan, Aaron
    Do, Adam

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include <iostream>
#include <iomanip>
#include "Donor.h"
#include "CollegeList.h"
#include "Donation.h"
#include "DonationList.h"
#include "DonationManager.h"
#include "FileLoader.h"

using namespace std;

int main()
{
    // Set precision for currency-related output
    cout << fixed << setprecision(2);

    cout << "===== PHASE 1: Testing Donor =====\n\n";

    // Test parameterized constructor + all accessors.
    Donor donor1("Alice Smith", 3000);
    Donor donor2("Bob Jones", 3001);
    cout << "Donor 1: " << donor1.getDonorName() << " (ID: " << donor1.getDonorID() << ")\n";
    cout << "Donor 2: " << donor2.getDonorName() << " (ID: " << donor2.getDonorID() << ")\n";

    // Test Donor::operator<.
    cout << "Is Donor 1 < Donor 2? " << (donor1 < donor2 ? "Yes" : "No") << endl;


    cout << "\n===== PHASE 2: Testing CollegeList =====\n\n";

    // Create CollegeList object.
    CollegeList myList;

    // Test CollegeList::addCollege.
    myList.addCollege("OCC", "Orange Coast College");
    myList.addCollege("GWC", "Golden West College");

    // Test CollegeList::getCollegeName with an existing college code.
    cout << "Code OCC: " << myList.getCollegeName("OCC") << endl;

    // Test CollegeList::printColleges.
    cout << "Printing Colleges:\n";
    myList.printColleges();

    // Test CollegeList::getColleges.
    const map<string, string>& collegeMap = myList.getColleges();
    cout << "Map contains " << collegeMap.size() << " colleges.\n";


    cout << "\n===== PHASE 3: Testing Donation =====\n\n";

    // Test parameterized constructor + all accessors.
    Donation don("Alice Smith", "OCC", 500.00);
    cout << "Donation: " << don.getDonorName() << " to "
        << don.getCollegeCode() << " amount: $" << don.getAmount() << endl;


    cout << "\n===== PHASE 4: Testing DonationList =====\n\n";

    // Create DonationList object.
    DonationList myDonations;

    // Test DonationList::getNumOfDonations on an empty list.
    cout << "Initial count: " << myDonations.getNumOfDonations() << endl;

    // Test DonationList::getFirst and DonationList::getLast on an empty list.
    cout << "First is null: " << (myDonations.getFirst() == nullptr ? "Yes" : "No") << endl;

    // Create and add a few Donation objects to the list.
    myDonations.addDonation(Donation("Alice Smith", "OCC", 100.0));
    myDonations.addDonation(Donation("Bob Jones", "GWC", 200.0));
    myDonations.addDonation(Donation("Charlie Brown", "OCC", 150.0));

    // Test DonationList::getNumOfDonations after adding donations.
    cout << "Count after adding: " << myDonations.getNumOfDonations() << endl;

    // Test DonationList::getFirst.
    // Print the data stored in the first node.
    DonationNode* firstNode = myDonations.getFirst();
    if (firstNode) {
        cout << "First Donation: " << firstNode->data.getDonorName() << " - " << firstNode->data.getAmount() << endl;
    }

    // Test DonationList::getLast.
    // Print the data stored in the last node.
    DonationNode* lastNode = myDonations.getLast();
    if (lastNode) {
        cout << "Last Donation: " << lastNode->data.getDonorName() << " - " << lastNode->data.getAmount() << endl;
    }

    // Traverse the DonationList manually using getFirst and next.
    // Print all donations in the list.
    cout << "Full Donation List:\n";
    DonationNode* current = myDonations.getFirst();
    while (current != nullptr) {
        cout << " - " << current->data.getDonorName() << ": $" << current->data.getAmount() << endl;
        current = current->next;
    }


    cout << "\n===== PHASE 5: Testing DonationManager with manual data =====\n\n";

    // Create DonationManager object.
    DonationManager manager;

    // Test DonationManager::addCollege by adding several colleges.
    manager.addCollege("CCC", "Coastline College");
    manager.addCollege("IVC", "Irvine Valley College");

    // Test DonationManager::printColleges.
    cout << "Colleges in Manager:\n";
    manager.printColleges();

    // Test DonationManager::addDonor by adding several donors.
    // Print the ID returned for each donor.
    cout << "Added Donor ID: " << manager.addDonor("Dave") << endl;
    cout << "Added Donor ID: " << manager.addDonor("Eve") << endl;

    // Test DonationManager::addDonation by adding several donations.
    manager.addDonation("Dave", "CCC", 1000.0);
    manager.addDonation("Eve", "IVC", 2000.0);
    manager.addDonation("Dave", "IVC", 500.0);

    // Test DonationManager::printDonationsByCollege.
    cout << "Donations by College:\n";
    manager.printDonationsByCollege();

    // Test DonationManager::printDonationsByDonor.
    cout << "\nDonations by Donor:\n";
    manager.printDonationsByDonor();

    // Test DonationManager::printTotalsByCollege.
    cout << "\nTotals by College:\n";
    manager.printTotalsByCollege();

    // Test DonationManager::printTotalsByDonor.
    cout << "\nTotals by Donor:\n";
    manager.printTotalsByDonor();

    // Test DonationManager::printStatistics.
    cout << "\nStatistics (Donors, Colleges, Donations):\n";
    manager.printStatistics();

    // Test DonationManager::printHighestDonor.
    cout << "\nHighest Donor:\n";
    manager.printHighestDonor();

    // Test DonationManager::printCollegeWithHighestTotal.
    cout << "\nCollege with Highest Total:\n";
    manager.printCollegeWithHighestTotal();


    cout << "\n===== PHASE 6: Testing FileLoader with colleges.csv and donations.csv =====\n\n";

    // Create DonationManager object.
    DonationManager fileManager;

    // Test loadCollegesFromFile.
    loadCollegesFromFile("colleges.csv", fileManager);

    // After calling loadCollegesFromFile, test DonationManager::printColleges.
    fileManager.printColleges();

    // Test loadDonationsFromFile.
    loadDonationsFromFile("donations.csv", fileManager);

    // After calling loadDonationsFromFile, test all report functions:
    cout << "\n--- Reports for File Data ---\n";
    cout << "Donations by College:\n";
    fileManager.printDonationsByCollege();

    cout << "\nDonations by Donor:\n";
    fileManager.printDonationsByDonor();

    cout << "\nTotals by College:\n";
    fileManager.printTotalsByCollege();

    cout << "\nTotals by Donor:\n";
    fileManager.printTotalsByDonor();

    cout << "\nStatistics:\n";
    fileManager.printStatistics();

    cout << "\nHighest Donor:\n";
    fileManager.printHighestDonor();

    cout << "\nCollege with Highest Total:\n";
    fileManager.printCollegeWithHighestTotal();


    cout << "\n===== All tests completed. =====\n";

    cout << endl;
    system("Pause");
    return 0;
}
