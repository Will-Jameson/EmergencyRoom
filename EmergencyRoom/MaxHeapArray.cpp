//
//  MaxHeapArray.cpp
//  EmergencyRoom
//
//  Created by Will Jameson on 4/21/24.
//

#include <stdio.h>
#include "MaxHeapArray.h"
using namespace std;

template<class ItemType>
MaxHeapArray<ItemType>::MaxHeapArray()
{
    itemCount = 0;
    maxItems = 50;
}

template<class ItemType>
MaxHeapArray<ItemType>::MaxHeapArray(const ItemType anArray[], const int numItems) : itemCount(numItems), maxItems(numItems*2)
{
}
// Write all the heap functions
// implement them into the triage class using inheritance
// make patient a friend of triage so patient info can be directly accessed from the triage list

