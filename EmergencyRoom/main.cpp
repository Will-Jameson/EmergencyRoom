//
//  main.cpp
//  EmergencyRoom
//
//  Created by Will Jameson on 4/20/24.
//


#include <iostream>
#include "Patient.h"
#include "Triage.h"


using namespace std;

void testERProgram()
{
    Triage er;
    
    er.addPatient("Mary", 9);
    er.addPatient("Bob", 5);
    er.addPatient("Max", 1);
    er.addPatient("Julio", 3);
    er.addPatient("Stacy", 7);
    er.addPatient("Paul", 4);
    er.addPatient("Reiko", 2);
    er.addPatient("Jennifer", 6);
    er.addPatient("Julio", 3);
    er.addPatient("Stacy", 7);
    er.addPatient("Chang", 5);
    
    cout << er.getNextName() << " will see the doctor now. \n";
    er.removeRoot();
    cout << er.getNextName() << " will see the doctor now. \n";
    er.removeRoot();
    cout << er.getNextName() << " will see the doctor now. \n";
    er.removeRoot();
    cout << er.waitlistSize() << endl;
    
}

int main()
{
    
    testERProgram();

}

