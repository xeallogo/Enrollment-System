//
//  student.cpp
//  C867_PA
//
//  Created by Alex Gool on 6/2/21.
//

#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using std::string;
using std::endl;
using std::cout;

string Student::GetID() {
    return studentID;
}

string Student::GetFirstName() {
    return firstName;
}

string Student::GetLastName() {
    return lastName;
}

string Student::GetEmailAddress() {
    return emailAddress;
}

DegreeProgram Student::GetDegreeProgram() {
    return degree;
}

int Student::GetAge() {
    return age;
}

int*  Student::GetNumberOfDays() {
    return numberOfDays;
}

void Student::SetID(string ID) {
    studentID = ID;
}

void Student::SetFirstName(string first) {
    firstName = first;
}

void Student::SetLastName(string last) {
    lastName = last;
}

void Student::SetEmailAddress(string email) {
    emailAddress = email;
}

void Student::SetAge(int theAge) {
    age = theAge;
}

void Student::SetNumberOfDays(int *daysInCourse) {
    numberOfDays[0] = daysInCourse[0];
    numberOfDays[1] = daysInCourse[1];
    numberOfDays[2] = daysInCourse[2];
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    degree = degreeProgram;
}

void Student::Print() {
    if (studentID == "Deleted") {
        return;
    }// if student is deleted, then print function is ended
    cout << studentID << '\t';
    cout << "First Name: " << firstName << '\t';
    cout << "Last Name: " << lastName << '\t';
    cout << "Age: " << age << '\t';
    cout << "Days In Course: " << "{" << numberOfDays[0] <<" ," <<numberOfDays[1]<< " ,"<< numberOfDays[2]<< "}"<< '\t';
    cout << "Degree Program: " << degreeStrings[degree] << '\t';
    cout << endl;
}

Student::Student(string sID, string fName, string lName, string eAddress, int aAge, int daysInCourse[], DegreeProgram degreeProgram) { //true constructor
    studentID = sID;
    firstName = fName;
    lastName = lName;
    emailAddress = eAddress;
    age = aAge;
    numberOfDays[0] = daysInCourse[0];
    numberOfDays[1] = daysInCourse[1];
    numberOfDays[2] = daysInCourse[2];
    degree = degreeProgram;
}

Student::Student() { //empty constructor
    studentID = "";
    firstName = "";
    lastName = "";
    emailAddress = "";
    age = 0;
    numberOfDays[0] = 0;
    numberOfDays[1] = 0;
    numberOfDays[2] = 0;
    degree = SOFTWARE; //SOFTWARE is default value
}

Student::~Student() {
}
