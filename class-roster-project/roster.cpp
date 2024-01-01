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
void Roster::printAll() {
    for (int i = 0; i < classRosterArray.size(); ++i) {
        std::cout << "Student " << classRosterArray[i]->getStudentID() << "\t"; 
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
    auto it = std::remove_if(classRosterArray.begin(), classRosterArray.end(),
        [studentID](const Student* student) {
            return student->getStudentID() == studentID;
        });

    if (it != classRosterArray.end()) {
        classRosterArray.erase(it, classRosterArray.end());
        std::cout << "Student with ID " << studentID << " removed." << std::endl;
    }
    else {
        std::cerr << "Error: Student with ID " << studentID << " not found." << std::endl;
    }
}

// Implement the printAverageDaysInCourse function
void Roster::printAverageDaysInCourse(const std::string& studentID) {
    // Find the student with the given studentID
    for (int i = 0; i < classRosterArray.size(); ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            // Calculate and print the average days in course
            int* daysInCourse = classRosterArray[i]->getDaysInCourse();
            double averageDays = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3.0;

            std::cout << "Average days in course for student " << studentID << ": " << averageDays << std::endl;
            return;
        }
    }

    // If studentID is not found, print an error message
    std::cerr << "Error: Student with ID " << studentID << " not found." << std::endl;
}


// Add the implementation of the printInvalidEmails function
void Roster::printInvalidEmails() {
    std::cout << "Invalid Email Addresses:" << std::endl;

    for (int i = 0; i < classRosterArray.size(); ++i) {
        std::string email = classRosterArray[i]->getEmail();

        // Check for invalid email format
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
            std::cout << email << std::endl;
        }
    }

    std::cout << std::endl;  
}

//Implement print By Dgree

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < classRosterArray.size(); ++i) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
            std::cout << std::endl;
        }
    }

    // Add an else statement to handle invalid degree
    if (degreeProgram != DegreeProgram::SECURITY && degreeProgram != DegreeProgram::NETWORK && degreeProgram != DegreeProgram::SOFTWARE) {
        std::cerr << "Error: Invalid Degree Program" << std::endl;
    }
}

// Function to get the size of the classRosterArray
int Roster::size() const {
    return classRosterArray.size();
}

Student* Roster::getStudentByID(int index) const {
    if (index >= 0 && index < classRosterArray.size()) {
        return classRosterArray[index];
    }
    return nullptr;  // Return nullptr if the index is out of bounds
}




