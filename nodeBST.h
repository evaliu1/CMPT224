/*
nodeBST.h
Header file for the BST node

Eva Liu 301243938
Liam O'Shaughnessy 301283210
07/28/2016
*/

#include "pairWord.h"
#include <iostream>
using namespace std;

class nodeBST
{
private:
	nodeBST* leftChildPtr;
	nodeBST* rightChildPtr;
	pairWord data;

public:
	// Default constructor
	nodeBST();
	// Parameterize constructor
	nodeBST(pairWord myData, nodeBST* left, nodeBST* right);
	// Destructor
	~nodeBST();

	nodeBST* getLeft() const;
	nodeBST* getRight() const;
	pairWord getData() const;
	void setLeft(nodeBST* myLeft);
	void setRight(nodeBST* myRight);
	bool isLeaf(nodeBST* myNode) const;
};
