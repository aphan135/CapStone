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

using namespace std;

void CollegeList::addCollege(const std::string& code, const std::string& name) {
    colleges[code] = name;
}

std::string CollegeList::getCollegeName(const std::string& code) const {
    const auto it = colleges.find(code);
    if (it != colleges.end()) {
        return it->second;
    }
    return "";
}

void CollegeList::printColleges() const {
    for (const auto& [code, name] : colleges) {
        std::cout << code << " " << name << std::endl;
    }
}

const std::map<std::string, std::string>& CollegeList::getColleges() const {
    return colleges;
}