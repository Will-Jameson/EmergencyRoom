//
//  Triage.cpp
//  EmergencyRoom
//
//  Created by Will Jameson on 4/21/24.
//

#include <stdio.h>
#include "Triage.h"
#include <iostream>
Triage::Triage()
{
    //content
    numPatients = 0;
    list = new Patient[maxRoomCapacity];
}
Triage::Triage(Triage &copyTriage)
{
    numPatients = copyTriage.numPatients;
    
    list = new Patient[copyTriage.numPatients];
    for (int i = 0; i < numPatients; i++)
    {
        list[i] = copyTriage.list[i];
    }
}
void Triage::viewNext()
{
    if (numPatients == 0)
    {
        cout << "Emergency Room is Empty" << endl;
    }
    else
    {
        list[0].viewPatientInfo();
    }
}
Patient Triage::getNext()
{
    return list[0];
}
string Triage::getNextName()
{
    return list[0].patientName;
}
//bool Triage::addPatient()
//{
//    Patient newPatient;
//    cout << "Enter patient Name: ";
//    getline(cin, newPatient.patientName);
//    cout << endl;
//    cout << "How bad is it, from 1 - 10? ";
//    cin >> newPatient.priority;
//    
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    //clear input buffer.  problem from using cin and getline together. ignore() will ignore every character under the numeric limit of <streamsize> maximum, or until the delimiter \n
//    
//    cout << endl;
//    
//    if (numPatients >= maxRoomCapacity)
//    {
//        cout << "Emergency room is Full" << endl;
//        return false;
//    }
//    else
//    {
//        
//        list[numPatients] = newPatient;
//        
//        int pos = numPatients;
//        numPatients++;
//        bool added = false; //condition to continue trickling up
//            while ((pos > 0) && (!added))
//            {
//                int parentIndex = (pos-1)/2;
//                if (list[pos] > list[parentIndex])
//                {
//
//                    swap(list[pos], list[parentIndex]);
//                    // switch parent and child
//                    pos = parentIndex;
//                    // update pos to parent position
//                }
//                else // the patient is in place
//                {
//                    added = true;
//                }
//            }
//        }
//        return true; //added
//}
//

bool Triage::addPatient(string name, int priority)
{
    if (numPatients > maxRoomCapacity)
    {
        cout << "Emergency Room is full" << endl;
        return false;
    }
    else
    {
        Patient newPatient(name, priority);
        list[numPatients] = newPatient;
        
        int pos = numPatients;
        bool added = false; //condition to continue trickling up
            while ((pos > 0) && (!added))
            {
                int parentIndex = (pos-1)/2;
                if (list[pos] > list[parentIndex])
                {

                    swap(list[pos], list[parentIndex]); // switch parent and child
                    pos = parentIndex; // update pos to parent position
                }
                else // the patient is in place
                {
                    added = true;
                }
            }
        numPatients++;
        }
        return true; //added
}


bool Triage::heapRebuild(int rootIndex, int patientCount)
{
    bool rebuilt = false;
    if ((rootIndex * 2 + 1) < patientCount)
    {
        int largeChildIndex = 2*rootIndex+1;
        
        if ((rootIndex*2 + 2) < patientCount)
        {
            int rightChildIndex = rootIndex*2 + 2;
            if (list[rightChildIndex] > list[largeChildIndex])
            {
                largeChildIndex = rightChildIndex;
            }
        }
    if (list[rootIndex] < list[largeChildIndex])
    {
        swap(list[rootIndex], list[largeChildIndex]);
//                rebuilt = true;
                
        rebuilt = heapRebuild(largeChildIndex, patientCount);
        
        rebuilt = true;
    }
            
        }
    return rebuilt;
}

bool Triage::removeRoot()
{
    if (numPatients == 0)
    {
        cout << "Triage is empty" << endl;
        return false;
    }

    else
    {
        list[0] = list[numPatients - 1];
        numPatients--;
        heapRebuild(0, numPatients);
        
        return true;
    }
    
}
bool Triage::clearList()
{
    delete [] list;
    numPatients = 0;
    return 0;
}

void Triage::displayArray()
{
    cout << "[ ";
    for (int i = 0; i < numPatients; i++)
    {
    
        cout << list[i].getPriority() << " ";
    }
    cout << "]" << endl;
}
void Triage::displayPatientList()
{
    Triage* erCopy = new Triage(*this);
    
    
    while (erCopy->waitlistSize())
    {
        cout << erCopy->getNext();
        cout << endl;
        erCopy->removeRoot();
    }
    delete erCopy;
}
