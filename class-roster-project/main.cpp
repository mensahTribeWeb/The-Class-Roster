#include <iostream>
#include "student.h" 
#include "roster.h" 
#include "degree.h"
#include <string>
#include <array>

 int main() {
    
     // Print out personal information
     std::cout << "Course Title: C867 - SCRIPTING AND PROGRAMMING - APPLICATIONS" << std::endl;
     std::cout << "Programming Language: C++" << std::endl;
     std::cout << "WGU Student ID: 010195113" << std::endl;
     std::cout << "Author: Nick Mensah" << std::endl;

     // Create an instance of the Roster class
    Roster* classRoster = new Roster();

    // Add each student to classRoster
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Nicholas,Mensah,nmensa2@wqu.edu,39,30, 60, 90,SOFTWARE"
    };


    for (int i = 0; i < 5; i++) {
        std::string data = studentData[i];  
        classRoster->parseAndAddStudent(data);
    }

    // Print all students
    std::cout << "\nPrint All Students:" << std::endl;
    classRoster->printAll();

    // Print invalid emails
    std::cout << "\nPrint Invalid Emails:" << std::endl;
    classRoster->printInvalidEmails();

    // Loop through classRosterArray and print average days in course for each student
    std::cout << "\nPrint Average Days in Course:" << std::endl;
    for (int i = 0; i < classRoster->size(); ++i) {
        Student* currentStudent = classRoster->getStudentByID(i);
        if (currentStudent) {
            classRoster->printAverageDaysInCourse(currentStudent->getStudentID());
        }
    }

    // Print by degree program (e.g., SOFTWARE)
    std::cout << "\nPrint By Degree Program (SOFTWARE):" << std::endl;
    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);

    // Remove student A3
    std::cout << "\nRemove Student A3:" << std::endl;
    classRoster->remove("A3");

    // Print all students after removal
    std::cout << "\nPrint All Students:" << std::endl;
    classRoster->printAll();

    // Attempt to remove student A3 again
    std::cout << "\nRemove Student A3 Again:" << std::endl;
    classRoster->remove("A3");

    //destructor
    classRoster->~Roster();
    delete classRoster;

    return 0;
}



#ifndef CLASS_ROSTER_H
#define CLASS_ROSTER_H

#endif // Class_Roster