#include <iostream>

#ifndef DEGREE_H
#define DEGREE_H

using namespace std;

enum DegreeProgram {
	SECURITY,
	NETWORK,
	SOFTWARE
};

// Function declaration
std::string degreeProgramToString(DegreeProgram degreeProgram);

#endif