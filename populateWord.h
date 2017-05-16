/*
populateWord.h
Get my dictionary words from txt file
Header file and Implementation of populateWord class

Eva Liu 301243938
Liam O'Shaughnessy 301283210
07/14/2016
*/

#include "pairWord.h"
#include "LinkedList.h"
#include "nodeBST.h"
#include <iostream>


class populateWord
{
private:
	static const int Max_n=1000;
	int elementCount;
	int size;
	LinkedList* expandArr;
	nodeBST* root;

public:
	// Default constructor
	populateWord();
	// Constructor
	populateWord(int myNum, LinkedList myDictrionary[]);
	// Destructor
	~populateWord();
	//My first data collection
	bool insertPair(const pairWord& onePair);
	//My second data Collection
	bool insertRoot(const pairWord & newElement);
	// Insert a new node into binary search tree
	bool insertNode(const pairWord & newElement);
	nodeBST* insertR(nodeBST* subTree, nodeBST* newNode);

	bool searchPairBST(pairWord myPair);
	int getSize() const;

	bool removeAll();
	// Search a specific pair of word from the chain hash table
	pairWord searchPair(pairWord onePair) const;
	nodeBST* getRoot();
	LinkedList* getArr();

	int getElementCount() const;
	void setElementCount(int num);
	int hashFunc(const pairWord& onePair) const;
	void inorderTraversal(nodeBST* myRoot);
};
