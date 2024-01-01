#include <iostream>
#include "student.h" 
#include "roster.h" 
#include <string>
#include <array>

int main() {
    
/**
 Course Title: C867 - SCRIPTING AND PROGRAMMING - APPLICATIONS
 TOOLS: Cpp
 IDE: VISUAL STUDIO
 STUDENT ID: 010195113
 AUTHOR: NICK MENSAH
*/

// A.  Modify the “studentData Table” to include your personal information as the last item.
    
const std::string studentData[] = {
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Nicholas,Mensah,nmensa2@wqu.edu,39,30, 60, 90,SOFTWARE"
};


Roster* classRoster = new Roster();
for (int i = 0; i < 5; i++) {
    std::string data = studentData[i];  
    classRoster->parseAndAddStudent(data);
}

// Add a new student using the add function
classRoster->add("A6", "Jane", "Doe", "jane.doe@email.com", 25, 35, 40, 30, DegreeProgram::SOFTWARE);


classRoster->printAllStudents();

delete classRoster;

return 0;
}


#ifndef CLASS_ROSTER_H
#define CLASS_ROSTER_H

#endif // Class_Roster