//
//  student.h
//  C867_PA
//
//  Created by Alex Gool on 6/2/21.
//

#ifndef student_h
#define student_h


#pragma once
#include "degree.h"
#include <string>
using std::string;

class Student {
private: //Attributes set to private because they are only accesed with methods
    string studentID, firstName, lastName, emailAddress;
    int age;
    int numberOfDays[3];
    DegreeProgram degree;

public:
    //structs
    Student(string sID, string fName, string lName, string eAddress, int aAge, int daysInCourse[], DegreeProgram degreeProgram); //true constructor
    Student(); //empty constructor
    ~Student(); //destructor
    
    //getters
    string GetID();
    string GetFirstName();
    string GetLastName();
    string GetEmailAddress();
    DegreeProgram GetDegreeProgram();
    int GetAge();
    int *GetNumberOfDays();
    
    //setters
    void SetID(string ID);
    void SetFirstName(string first);
    void SetLastName(string last);
    void SetEmailAddress(string email);
    void SetAge(int theAge);
    void SetNumberOfDays(int *daysInCourse);
    void SetDegreeProgram(DegreeProgram degreeProgram);
    void Print();
};



#endif /* student_hpp */



