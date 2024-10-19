// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// October 18, 2024

#include "student.h"

#include <string>
#include <list>
#include <fstream>
#include <exception>
#include <sstream>

// constructor
Student::Student() {
    uID = "default id";
    name = "default name";
    major = "default major";
}

// parameterized constructor
Student::Student(const std::string& id, const std::string& name, const std::string& major) {
    uID = id;
    this->name = name;
    this->major = major;
}

// getters
std::string Student::getID() const {
    return uID;
}

std::string Student::getName() const {
    return name;
}

std::string Student::getMajor() const {
    return major;
}

// setters
void Student::setID(const std::string& id) {
    uID = id;
}

void Student::setName(const std::string& name) {
    this->name = name;
}

void Student::setMajor(const std::string& major) {
    this->major = major;
}

// operator ==
bool Student::operator==(const Student& other) const {
    return uID == other.uID && name == other.name && major == other.major;
}

// creates student list from file and returns it
std::list<Student> Student::readStudfromFile() const {
    std::ifstream file;

    // return empty array if file does not exist
    try {
        file.open("studentsList.txt");
    } catch (std::exception& e) {
        return {};
    }

    // create return list
    std::string line;
    std::list<Student> student_list;

    // get lines
    while (std::getline(file, line)) {
        std::istringstream line_stream(line);

        // get id, name, and major
        std::string id, name, major;
        line_stream >> id >> name >> major;

        // add student to list
        student_list.push_back(Student(id, name, major));
    }

    file.close();
    return student_list;
}
