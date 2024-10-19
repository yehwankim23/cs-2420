// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// October 18, 2024

#pragma once

#include <string>
#include <list>

// student class
class Student {
private:
    // instance variables
    std::string uID;
    std::string name;
    std::string major;

public:
    // default constructor
    Student();

    // parameterized constructor
    Student(const std::string& id, const std::string& name, const std::string& major);

    // getters
    std::string getID() const;
    std::string getName() const;
    std::string getMajor() const;

    // setters
    void setID(const std::string& id);
    void setName(const std::string& name);
    void setMajor(const std::string& major);

    // operator ==
    bool operator==(const Student& other) const;

    // creates student list from file and returns it
    std::list<Student> readStudfromFile() const;
};
