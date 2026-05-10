/*
    Cao, Aaron (team leader)
    Phan, Aaron
    Do, Adam

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "DonationList.h"

using namespace std;

DonationList::DonationList()
    : first(nullptr), last(nullptr), numOfDonations(0) {
}

int DonationList::addDonation(const Donation& donation) {
    DonationNode* newNode = new DonationNode(donation);

    if (first == nullptr) {
        first = newNode;
        last = newNode;
    }
    else {
        last->next = newNode;
        last = newNode;
    }

    numOfDonations = numOfDonations + 1;
    return numOfDonations;
}

int DonationList::getNumOfDonations() const {
    return numOfDonations;
}

DonationNode* DonationList::getFirst() const {
    return first;
}

DonationNode* DonationList::getLast() const {
    return last;
}

DonationList::~DonationList() {
    DonationNode* current = first;

    while (current != nullptr) {
        DonationNode* temp = current;
        current = current->next;
        delete temp;
    }

    first = nullptr;
    last = nullptr;
    numOfDonations = 0;
}
