//
//  Patient.h
//  EmergencyRoom
//
//  Created by Will Jameson on 4/21/24.
//

#ifndef Patient_h
#define Patient_h

#include <iostream>
using namespace std;

class Patient
{
private:
    string patientName;
    int priority;
    friend class Triage;
    
public:
    Patient()
    {
        priority = 0;
        patientName = "NAME";
    }
    Patient(string name, int patientPriority)
    {
        patientName = name;
        priority = patientPriority;
    }
    void setPriority(int patientPriority)
    {
        priority = patientPriority;
    }
    void setPatientName(string patient)
    {
        patientName = patient;
    }
    int getPriority() const
    {
        return priority;
    }
    string getPatientName() const
    {
        return patientName;
    }
    void viewPatientInfo()
    {
        cout << "Patient Name: " << getPatientName() << endl;
        cout << "Triage Value: " << getPriority() << endl;
    }
    friend bool operator<(const Patient& l, const Patient& r)
    {
        if (l.getPriority() < r.getPriority())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend bool operator>(const Patient l, const Patient r)
    {
        if (l.getPriority() > r.getPriority())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

  friend  ostream& operator<<(ostream& callout, Patient p)
    {
        
        callout << p.patientName << ", " << "Priority: " <<  p.priority <<  flush;
        
        return callout;

    }


};

#endif /* Patient_h */
