//
//  roster.cpp
//  C867_PA
//
//  Created by Alex Gool on 6/2/21.
//
#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <string>
#include <vector>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stringstream;


const string studentData[5] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Alex,Gool,agool1@wgu.edu,23,4,10,10,SOFTWARE"};

void Roster::parseAdd() {
    for (int x = 0; x < numOfStudents; x++) {
        vector<string> vector;    //empty vector
        string row = studentData[x];  //array to store the datarow from studentData
        stringstream s_stream(row);  //input stream of the (row in studentData) using stringStream
        while (s_stream.good()) {
            string item;
            getline(s_stream, item, ','); //use commas as delimiter
            vector.push_back(item);  //item is added to vector
        }
        DegreeProgram degree = SECURITY; // SECURITY is default
        if (vector.at(8).back() == 'E') { //Check to see if degree is SOFTWARE
            degree = SOFTWARE;
        }
        if (vector.at(8).back() == 'K') { //Check to see if degree is NETWORK
            degree = NETWORK;
        }
        //students added to vector by calling add function within parseAdd function to satisfy project requirements
        Add(vector.at(0), vector.at(1), vector.at(2), vector.at(3), stoi(vector.at(4)), stoi(vector.at(5)), stoi(vector.at(6)), stoi(vector.at(7)), degree);
    }
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int days[3] = {daysInCourse1,daysInCourse2,daysInCourse3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
}

void Roster::Remove(string studentID) { //This method changes ID to deleted
    for (int x = 0; x <= lastIndex; x++) {
        if (classRosterArray[x]->GetID() == studentID) {
            cout << "Student " << classRosterArray[x]->GetID() <<" has been deleted!" << endl;
            classRosterArray[x]->SetID("Deleted");
            return;
        }
    }
    cout << "A student with ID "<< studentID << " was not found!" << endl;
}

//displays tab-separated student list and iterates through all students in student list and calls print function for every student
void Roster::PrintAll() {
    for (int x = 0; x <= lastIndex; x++) {
        classRosterArray[x]->Print();
    }
    cout << endl;
}

void Roster::PrintAverageDaysInCourse(string studentID) {
    bool studentExists = false; //false is default
    //iterate through classRosterArray and use getter to compare studentID
    for (int x = 0; x <= lastIndex; x++) {
        if (classRosterArray[x]->GetID() == studentID) {
            studentExists = true; //Set foundStudent to true if student is found
            int* numberofDays = classRosterArray[x]->GetNumberOfDays();
            int average = (numberofDays[0] + numberofDays[1] + numberofDays[2])/3;
            cout << "Student " << classRosterArray[x]->GetID() <<  "'s average number of days in three courses is " << average;
            //display avg number of days in 3 classes
        }
    }
    if (studentExists == false) {
        cout << "Student not found!"; //error displayed if student not found
    }
}

//verifies student emails and prints invalid emails to user
void Roster::PrintInvalidEmails() {
    for (int x = 0; x <= lastIndex; x++) {
        string email = classRosterArray[x]->GetEmailAddress();
        if (email.find("@") != string::npos && email.find(".") != string::npos && email.find(" ") == string::npos){
            //if email is vali we do nothing
            //if email is valid if input satifies all the conditions, then
            //valid email must have an "@", ".", no spaces
       } else { //Print invalid emails
            cout << "Student " << classRosterArray[x]->GetID() <<  " has an invalid email. " << classRosterArray[x]->GetEmailAddress();
            cout << endl;
        }
    }
    cout << endl;
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
    string deg = "SECURITY"; //SECURITY is default
    if (degreeProgram == SOFTWARE) {
        deg = "SOFTWARE";
    }
    else if(degreeProgram == NETWORK) {
        deg = "NETWORK";
    }
    cout << "Students with degree " << deg << " are listed below" << endl;
    for (int x = 0; x <= lastIndex; x++) {
        if (classRosterArray[x]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[x]->Print(); //for the specified degree, calls print function for every student
        }
    }
    cout << endl;
}

Roster::Roster() { // classRosteArray set to nullptr
    for (int x = 0; x <= lastIndex; x++) {
        classRosterArray[x] = nullptr;
    }
}

//destructor
Roster::~Roster() {
    // delete *classRosterArray;
    for (int x = 0; x <= lastIndex; x++) {
       delete classRosterArray[x];
    }
    // each student object in roster is deleted, releasing the memory
    //Thus, we do not have to call destructor in main method
}

Student Roster::getStudent(int index) {
    return *classRosterArray[index];
}

