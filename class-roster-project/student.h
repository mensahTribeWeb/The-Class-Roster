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

    // Accessors (getters)
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmail() const;
    int getAge() const;
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram() const;

    // Mutators (setters)
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmail(std::string email);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // Print function
    void print() const;
};

#endif // STUDENT_H