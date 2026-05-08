#ifndef COLLEGELIST_H
#define COLLEGELIST_H

#include <map>
#include <string>

class CollegeList {
public:
    void addCollege(const std::string& code, const std::string& name);
    std::string getCollegeName(const std::string& code) const;
    void printColleges() const;
    const std::map<std::string, std::string>& getColleges() const;
private:
    std::map<std::string, std::string> colleges;
};
#endif