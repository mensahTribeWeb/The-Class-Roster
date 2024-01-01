#pragma once
// roster.h

#ifndef ROSTER_H
#define ROSTER_H


#include "student.h"
#include "degree.h"

class Roster {
private:
    static const int maxSize = 5;
    Student* classRosterArray[maxSize];
    int lastIndex;

public:
    Roster();
    void parseAndAddStudent(const std::string& studentData);
    void addStudent(Student* student);
    void printAllStudents();
};

#endif // ROSTER_H
