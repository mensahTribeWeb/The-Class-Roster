// student.cpp

#include <iostream>
#include "student.h"
#include "degree.h"

// Default constructor
Student::Student() {
    // Initialize variables with default values
    studentID = "";
    firstName = "";
    lastName = "";
    email = "";
    age = 0;
    daysInCourse[0] = 0;
    daysInCourse[1] = 0;
    daysInCourse[2] = 0;
    degreeProgram = DegreeProgram::SOFTWARE; // Default value
}

// Parameterized constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string email,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    // Set member variables with provided values
    setStudentID(studentID);
    setFirstName(firstName);
    setLastName(lastName);
    setEmail(email);
    setAge(age);
    setDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);
    setDegreeProgram(degreeProgram);
}

// Accessors (getters)
std::string Student::getStudentID() const {
    return studentID;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getEmail() const {
    return email;
}

int Student::getAge() const {
    return age;
}

int* Student::getDaysInCourse() {
    return daysInCourse;
}

DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

// Mutators (setters)
void Student::setStudentID(std::string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Student::setEmail(std::string email) {
    this->email = email;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

// Function to convert DegreeProgram enum to string
std::string degreeProgramToString(DegreeProgram degreeProgram) {
    switch (degreeProgram) {
    case DegreeProgram::SECURITY:
        return "Security";
    case DegreeProgram::NETWORK:
        return "Network";
    case DegreeProgram::SOFTWARE:
        return "Software";
    default:
        return "Unknown";
    }
}

// Print function implementation
void Student::print() const {
    std::cout << "Student ID: " << studentID << "\t"
        << "First Name: " << firstName << "\t"
        << "Last Name: " << lastName << "\t"
        << "Email: " << email << "\t"
        << "Age: " << age << "\t"
        << "Days in Course: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t"
        << "Degree Program: " << degreeProgramToString(degreeProgram) << std::endl; 

}
