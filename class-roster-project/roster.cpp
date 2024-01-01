// roster.cpp

#include <iostream>
#include <sstream>
#include "roster.h"
#include "degree.h"
#include "student.h"  

using namespace std;

Roster::Roster() {
    lastIndex = 0;
}

void Roster::parseAndAddStudent(const std::string& studentData) {
    std::istringstream stream(studentData);

    std::string studentID, firstName, lastName, email;
    int age, daysInCourse1, daysInCourse2, daysInCourse3;
    DegreeProgram degreeProgram;

    std::getline(stream, studentID, ',');
    std::getline(stream, firstName, ',');
    std::getline(stream, lastName, ',');
    std::getline(stream, email, ',');
    stream >> age;
    stream.ignore();  // Ignore the comma after age
    stream >> daysInCourse1 >> daysInCourse2 >> daysInCourse3;
    stream.ignore();  // Ignore the comma after daysInCourse3
    std::string degreeProgramStr;
    std::getline(stream, degreeProgramStr);

    // Convert the string representation of DegreeProgram to enum
    if (degreeProgramStr == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (degreeProgramStr == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (degreeProgramStr == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;
    }
    else {
        degreeProgram = DegreeProgram::SOFTWARE;
    }

    // Create a new Student object and add it to classRosterArray
    Student* newStudent = new Student(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    addStudent(newStudent);
}

void Roster::addStudent(Student* student) {
    if (lastIndex < maxSize) {
        classRosterArray[lastIndex++] = student;
    }
    else {
        std::cerr << "Error: Roster is full, cannot add more students." << std::endl;
        throw std::out_of_range("Error: Roster is full, cannot add more students.");
    }
}

// Function to print all students in the roster
void Roster::printAllStudents() {
    for (int i = 0; i < lastIndex; ++i) {
        std::cout << "Student " << i + 1 << ":" << std::endl;
        classRosterArray[i]->print();  // Assuming you have a print function in the Student class
        std::cout << std::endl;
    }
}
