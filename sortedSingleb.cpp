#include "sortedSingle.h"

/**************************** part b ****************************************/

bool sortedSingle::insert(int item)
{
    node* temp = new (nothrow) node();
    node* current = headptr;
    node* prev = nullptr;

    if (temp == nullptr)
        return false;

    temp->theItem = item;

    if (headptr == nullptr)
    {
        headptr = temp;
        return true;
    }

    current = headptr;

    if (item <= current->theItem)    // insert if empty and to replace first node
    {
        temp->next = headptr;
        headptr = temp;
        return true;
    }

    while (current != nullptr && current->theItem < item) // find the right location to insert
    {
        prev = current;
        current = current->next;
    }

    if (prev != nullptr)
    {
        prev->next = temp;
        if (current != nullptr)
        {
            temp->next = current;
        }
    }

    return true;
}



void sortedSingle::print(ostream& out, string seperator)
{
    node* ptr = headptr;

    while (ptr != nullptr)
    {
        out << ptr->theItem;
        ptr = ptr->next;

        if (ptr != nullptr)
            out << seperator;
    }
}