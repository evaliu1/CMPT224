/*
node.cpp
Implementation for the Linked list node

Eva Liu 301243938
Liam O'Shaughnessy 301283210
07/28/2016
*/
#include "node.h"
#include "pairWord.h"
#include <iostream>
#include <string>

using namespace std;

node::node()
{
	next = NULL;
}

node::node(const pairWord& theData)
{
	data = theData;
	next = NULL;
}

node::node(pairWord theData, node* theNextNode)
{
	data = theData;
	next = theNextNode;
}

node::~node()
{
}

pairWord node::getData()
{
	return data;
}

// end Node.cpp
