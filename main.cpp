//
//  main.cpp
//  C867_PA
//
//  Created by Alex Gool on 6/2/21.
//

#include <iostream>
#include "student.h"
#include "roster.h"
#include <string>

using std::endl;
using std::string;
using std::cout;



int main() {
    cout << "C867: Scripting and Programming - Applications\n";
    cout << "Programming Language: C++\n";
    cout << "WGU Student ID: #002762910\n";
    cout << "Alex Gool\n\n";

    Roster classRoster;
    classRoster.parseAdd();
    classRoster.PrintAll();
    classRoster.PrintInvalidEmails();

    // For loop that prints a student's avg days in the 3 courses by ID
    for (int x = 0; x < 5; x++) {
        Student student = classRoster.getStudent(x);  //use defined method to retrieve student since the attributes are private
        classRoster.PrintAverageDaysInCourse(student.GetID());
        cout << endl;
    }
    cout << endl;

    classRoster.PrintByDegreeProgram(SOFTWARE);
    classRoster.Remove("A3");
    classRoster.PrintAll();
    classRoster.Remove("A3"); //Displays message that student with specific ID A3 was not found
}


