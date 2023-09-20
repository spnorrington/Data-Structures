// File: Mid-term Exam- Programming Question #1.h
// 
// 
// 
// Programming Question #1 Here's a another variation on the theme of lists:   self-adjusting list.    Define a new template subclass of the List<> class named SelfAdjustingList<>  that adds one new method to the subclass: 

//   T* find(TitemToFind);
//Make the find() method do a linear search for the argument in the list.If it finds the item, move it to the front of the list and then return a pointer to that item that is now in the front of the list.

//(NOTE: this is a rather common trick used to improve the search times on large lists.Over the time, the items you most often search for will be moved towards the front of the list)


#pragma once
#include "List.h"
template <typename T>
class SelfAdjustingList : public List<T> 
{
private:
    typename SelfAdjustingList<T>::iterator findInList(T data) 
    {
        typename SelfAdjustingList<T>::iterator placeInList = this->begin();
        typename SelfAdjustingList<T>::iterator endOfList = this->end();
        bool found = false;
        while (!found && placeInList != endOfList) 
        {
            if (*placeInList == data) 
            {
                found = true;
            }
            placeInList++;
        }
        return placeInList;
    }
public:
    typename SelfAdjustingList<T>::iterator findIt(T data) 
    {
        typename SelfAdjustingList<T>::iterator whereFound = findInList(data);
        if (whereFound != this->end()) 
        {
            T& temp = *whereFound;
            this->erase(whereFound);
            this->push_front(temp);
        }
        return whereFound;
    }
};