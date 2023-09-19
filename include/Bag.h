
// Purpose: To create a second version of the bag class, replacing the vector class with the list class made in module 3 part 1

#ifndef BAG_H
#define BAG_H



#pragma once
#include <iostream>
#include "List.h"


template <typename Thing>
class Bag //create an empty bag
{
public:
	{
		bagContents = List<Thing>();
	}
    void insert(Thing aThing)
    {
        bagContents.push_back(aThing);
        bagSize++;
    }
    Thing& pop()
    {
        Thing aThing;
        if (bagContents.size() > 0)
		{
            aThing = bagContents(bagSize);
            bagSize--;
		}
        else
        {
            std:: cerr << "Can't pop out of an empty bag" << std::endl;
        }
        return aThing;
    }
    int size()
	{
		return bagSize;
	}
    int count (Thing aThing)
	{
		int bagCount = 0;
		for (int i = 0; i < bagSize; i++)
		{
			if (bagContents[i] == aThing)
			{
				bagCount++;
			}
		}
		return bagCount;
	}
private:
List<Thing> bagContents;
	int bagSize = 0;
};


#endif // !BAG_H