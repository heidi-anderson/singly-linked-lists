#include "sortedSingle.h"

sortedSingle::sortedSingle()
{
    headptr = nullptr;
}



sortedSingle::~sortedSingle()
{
    node* ptr;

    for (ptr = headptr; headptr; ptr = headptr)
    {
        headptr = headptr->next;
        delete ptr;
    }
}



bool sortedSingle::empty()
{
    if (size() == 0)
        return true;
    else
        return false;
}



bool sortedSingle::find(int item)
{
    node* ptr = headptr;

    while (ptr != nullptr)
    {
        if (ptr->theItem == item)
            return true;
        ptr = ptr->next;
    }

    return false;
}



int sortedSingle::size()
{
    node* ptr = headptr;
    int count = 0;

    while (ptr != nullptr)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}



int sortedSingle::retrievePosition(int item)
{
    node* ptr = headptr;
    int pos = 1;

    while (ptr != nullptr)
    {
        if (ptr->theItem == item)
            return pos;
        pos++;
        ptr = ptr->next;
    }

    return 0;
}