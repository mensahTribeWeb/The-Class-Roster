// roster.cpp

#include <iostream>
#include <sstream>
#include "roster.h"
#include "degree.h"
#include "student.h"  

using namespace std;

Roster::Roster() {
    
}

void Roster::addStudent(Student* student) {
    classRosterArray.push_back(student);
}

void Roster::parseAndAddStudent( std::string& studentData) {
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


// Function to print all students in the roster
void Roster::printAllStudents() {
    for (int i = 0; i < classRosterArray.size(); ++i) {
        std::cout << "Student " << i + 1 << ":" << std::endl;
        classRosterArray[i]->print(); 
        std::cout << std::endl;
    }
}

void Roster::add(
    const std::string& studentID,
    const std::string& firstName,
    const std::string& lastName,
    const std::string& emailAddress,
    int age,
    int daysInCourse1,
    int daysInCourse2,
    int daysInCourse3,
    DegreeProgram degreeProgram
) {
    Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    addStudent(newStudent);
}

//implement the remove function

void Roster::remove(const std::string& studentID) {
    bool studentRemoved = false;

    for (auto it = classRosterArray.begin(); it != classRosterArray.end(); ++it) {
        if ((*it)->getStudentID() == studentID) {
            it = classRosterArray.erase(it);  // Remove the student from the vector
            --it;  // Adjust the iterator as erase shifts elements
            studentRemoved = true;
            break;  // No need to continue searching once the student is found
        }
    }

    if (!studentRemoved) {
        std::cerr << "Error: Student with ID " << studentID << " not found." << std::endl;
    }
}

