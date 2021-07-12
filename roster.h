//
//  roster.h
//  C867_PA
//
//  Created by Alex Gool on 6/2/21.
//

#ifndef roster_h
#define roster_h

#pragma once
#include "student.h"
#include "degree.h"
#include <string>

using std::string;

class Roster {
public:
    void parseAdd();
    void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void Remove(string studentID);
    void PrintAll();
    void PrintAverageDaysInCourse(string studentID);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(DegreeProgram degreeProgram);
    Roster();
    ~Roster();
    
    //Getter to retrieve student;
    Student getStudent(int index);

private:
    Student* classRosterArray[5]; // array of pointers created to hold the data from studentData
    int lastIndex = -1; 
    const int numOfStudents = 5;
};


#endif /* roster_h */
