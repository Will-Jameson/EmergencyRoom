//
//  Triage.h
//  EmergencyRoom
//
//  Created by Will Jameson on 4/21/24.
//

#ifndef Triage_h
#define Triage_h

#include <iostream>
#include "Patient.h"
#include "PrecondViolatedExcep.h"

using namespace std;
class Triage
{
private:
    
    int numPatients;
    static const int maxRoomCapacity = 20;
    Patient *list;
    friend class Patient;
    
public:
    Triage();
    Triage(Triage &copyTriage);
    ~Triage() {delete [] list; }
    bool isEmpty() const {return numPatients==0;}
    int waitlistSize()  {return numPatients;}
    void viewNext();
    Patient getNext();
    string getNextName();
    bool addPatient();
    bool addPatient(string patName, int priority);
    bool removeRoot();
    bool heapRebuild(int rootIndex, int patientCount);
    bool clearList();
    void displayPatientList();
    void displayArray();
    friend ostream& operator<<(ostream& callout, Patient &p);
    
};



#endif /* Triage_h */
