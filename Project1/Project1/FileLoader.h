/*
	Cao, Aaron (Team Leader)
	Phan, Aaron
	Do, Adam

	Spring 2026
	CS A250 - C++ 2

	College Donations
*/

#ifndef FILELOADER_H
#define FILELOADER_H

#include "DonationManager.h"

#include <string>

void loadCollegesFromFile(const std::string& fileName, 
    DonationManager& manager);
void loadDonationsFromFile(const std::string& fileName,
    DonationManager& manager);

#endif