/*
nodeBST.cpp
Implementation for the BST node

Eva Liu 301243938
Liam O'Shaughnessy 301283210
07/28/2016
*/

#include <string>
#include <iostream>
#include "pairWord.h"
#include "nodeBST.h"

using namespace std;

// Default constructor
nodeBST::nodeBST()
{
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}

// Constructor

nodeBST::nodeBST(pairWord myData, nodeBST* left, nodeBST* right)
{
	data = myData;
	leftChildPtr = left;
	rightChildPtr = right;
}

// Destructor

nodeBST::~nodeBST()    //LEAVE IT EMPTY FOR NOW, CHANGE IT LATER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
}


nodeBST* nodeBST::getLeft() const
{
	return leftChildPtr;
}


nodeBST* nodeBST::getRight() const
{
	return rightChildPtr;
}


pairWord nodeBST::getData() const
{
	return data;
}


void nodeBST::setLeft(nodeBST* myLeft)
{
	leftChildPtr = myLeft;
}


void nodeBST::setRight(nodeBST* myRight)
{
	rightChildPtr = myRight;
}


bool nodeBST::isLeaf(nodeBST* myNode) const
{
	if (myNode->leftChildPtr == NULL && myNode->rightChildPtr == NULL)
		return true;
	else
		return false;
}
