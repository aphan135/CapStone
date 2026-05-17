/*
    Cao, Aaron (Team Leader)
    Phan, Aaron
    Do, Adam

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "CollegeList.h"
#include <iostream>
#include <cctype>

using namespace std;

void CollegeList::addCollege(std::string code, const std::string& name) {
    for (char &c : code) {
        if (islower(c)) {
            c = toupper(c);
        }
	}
    colleges[code] = name;
}

std::string CollegeList::getCollegeName(const std::string& code) const {
    auto iter = colleges.find(code);
    if (iter != colleges.end()) {
        return iter->second;
    }
    return "";
}

void CollegeList::printColleges() const {
    for (auto iter = colleges.begin(); iter != colleges.end(); ++iter) {
        cout << "\t" << iter->first << " - " << iter->second << endl;
	}
    cout << endl;
}

const std::map<std::string, std::string>& CollegeList::getColleges() const {
    return colleges;
}