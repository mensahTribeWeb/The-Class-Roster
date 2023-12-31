#include <iostream>
#include "student.h"

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