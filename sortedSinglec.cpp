#include "sortedSingle.h"
/**************************** part c ****************************************/

bool sortedSingle::remove(int item)
{
    node* ptr = headptr;
    node* prev = nullptr;

    while (ptr != nullptr)
    {
        if (ptr->theItem == item)
        {
            if (prev == nullptr)
                headptr = ptr->next;
            else
                prev->next = ptr->next;

            delete(ptr);
            return true;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    return false;
}



void sortedSingle::clear()
{
    node* ptr = headptr;
    node* next = nullptr;

    while (ptr != nullptr)
    {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }

    headptr = nullptr;
}