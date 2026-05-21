/*
    Cao, Aaron (Team Leader)
    Phan, Aaron
    Do, Adam

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#ifndef COLLEGELIST_H
#define COLLEGELIST_H

#include <string>
#include <map>

class CollegeList {
public:
    void addCollege(const std::string& code, const std::string& name);
    std::string getCollegeName(const std::string& code) const;
    const std::map<std::string, std::string>& getColleges() const;
    void printColleges() const;
private:
    std::map<std::string, std::string> colleges;
};
#endif
