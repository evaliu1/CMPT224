/*
node.h
Header file for the Linked list node

Eva Liu 301243938
Liam O'Shaughnessy 301283210
07/28/2016
*/


// #pragma once is shorthand for the 2 #include guards we've seen before:
// #ifndef _NODE and #define _NODE
#pragma once

#include <cstddef>  // defines NULL
#include "pairWord.h"


class node
{
public:
	// Public attributes - Why are the attributes public?
	pairWord data;   // The data in the node
	node* next;   // Pointer to next node

	// Constructors and destructor
	node();
	node(const pairWord& theData);
	node(pairWord theData, node* theNextNode);
	~node();
	pairWord getData();

}; // end Node
