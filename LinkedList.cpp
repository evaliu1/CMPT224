
#include "LinkedList.h"
#include "pairWord.h"
#include "node.h"
#include <iostream>
#include <string>

using namespace std;


// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
LinkedList::LinkedList()
{
    head = new node;
    head -> next = NULL;
    length = 0;
}

// Inserts an item at the end of the list.
void LinkedList::insertItem( pairWord * newItem )
{
    pairWord temp = *newItem;
    node *newNode = new node;
	  newNode->data = temp;
	  newNode->next = head;
	  head = newNode;
}


// Searches for an item by its key.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
pairWord * LinkedList::getItem(pairWord myEnglish)
{
    node * p = head;
    node * q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p ->data == myEnglish))
			     return &p->data;
        q = p -> next;
    }
    return NULL;
}

// Returns the length of the list.
int LinkedList::getLength()
{
    return length;
}

node* LinkedList::getHead()
{
	return head;
}

// De-allocates list memory when the program terminates.
LinkedList::~LinkedList()
{
    node * p = head;
    node * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        if (q) delete p;
    }
}

/*ostream & operator<<(ostream & os, const LinkedList& rhs)
{
    LinkedList temp = rhs;
    node* p = temp.getHead();
    while(p->next != NULL)
    {
        cout<< p->data << endl;
    }
    return os;
}*/
