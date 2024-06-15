//
//  MaxHeapArray.h
//  EmergencyRoom
//
//  Created by Will Jameson on 4/21/24.
//

#ifndef MaxHeapArray_h
#define MaxHeapArray_h

using namespace std;

template<class ItemType>
class MaxHeapArray
{
private:
    int itemCount;
    int maxItems;
    
    int getLeftChildIndex(const int nodeIndex) const;
    int getRightChildIndex(int nodeIndex) const;
    int getParentIndex(int nodeIndex) const;
    bool isLeaf(int nodeIndex) const;
    void heapRebuild(int nodeIndex);
    
    void heapCreate();
    
public:
    MaxHeapArray();
    MaxHeapArray(const ItemType anArray[], const int listSize);
    virtual ~MaxHeapArray();
    
    bool isEmpty();
    int getHeight();
    int getSize();
    bool addPatient();
    ItemType peekTop();
    bool removeTop();
    bool clearRoom();
    
};
#endif /* MaxHeapArray_h */
