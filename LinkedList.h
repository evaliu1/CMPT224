#ifndef LinkedList_h
#define LinkedList_h

#include "node.h"
#include "pairWord.h"
#include <iostream>
#include <string>
using namespace std;


class LinkedList
{
private:
    // Head is a reference to a list of data nodes.
    node* head;

    // Length is the number of data nodes.
    int length;

public:
    // Constructs the empty linked list object.
    // Creates the head node and sets length to zero.
    LinkedList();

    // Inserts an item at the end of the list.
    void insertItem(pairWord* newItem );

    // Searches for an item by its key.
    // Returns a reference to first match.
    // Returns a NULL pointer if no match is found.
    pairWord* getItem(pairWord myEnglish);

    // Returns the length of the list.
    int getLength();
	  node* getHead();

    // De-allocates list memory when the program terminates.
    ~LinkedList();
    //friend ostream & operator<<(ostream & os, const LinkedList& rhs);
};

#endif
