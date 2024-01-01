#pragma once
// roster.h

#ifndef ROSTER_H
#define ROSTER_H


#include "student.h"
#include "degree.h"
#include <vector>

class Roster {
private:
    std::vector<Student*> classRosterArray;
    int lastIndex;

public:
    Roster();
    void parseAndAddStudent( std::string& studentData);
    void addStudent(Student* student);
    // Update the declaration of printAllStudents to match the new requirements I have been using this for testing
    void printAll();

    // Function to add a student with individual parameters
    void add(
        const std::string& studentID,
        const std::string& firstName,
        const std::string& lastName,
        const std::string& emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram
    );

    // Function to remove a student by student ID
    void remove(const std::string& studentID);
};

#endif // ROSTER_H
