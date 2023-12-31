#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h" //enums

class Student {

private:
    // Member variables
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string email;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    // Constructors
    Student(); // Default constructor
    Student(std::string studentID, std::string firstName, std::string lastName, std::string email,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

};

#endif // STUDENT_H