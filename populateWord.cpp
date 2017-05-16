/*
populateWord.cpp
Get my dictionary words from txt file
Header file and Implementation of populateWord class

Eva Liu 301243938
Liam O'Shaughnessy 301283210
07/27/2016
*/

#include "pairWord.h"
#include "populateWord.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

//Default constructor
populateWord::populateWord()
{
	elementCount = 0;
	expandArr = new LinkedList[Max_n];
	size = 0;
}

// Constructor
populateWord::populateWord(int myNum, LinkedList myDictrionary[])
{
	elementCount = myNum;
	expandArr = myDictrionary;
	size = sizeof(myDictrionary);
}

// Destructor
populateWord::~populateWord()
{
	elementCount = 0;
}

//Get the number of pair words we have in the dictionary
int populateWord::getElementCount() const
{
	return elementCount;
}

//Set my element Count
void populateWord::setElementCount(int num)
{
	elementCount = num;
}


//Insert one new pair into chain hash table
bool populateWord::insertPair(const pairWord& onePair)
{
	pairWord* temp = new pairWord(onePair.returnEnglish(),onePair.returnKlingon());
	bool myValue = false;
	int key = hashFunc(onePair);

	expandArr[key].insertItem(temp);
	size = size+1;
	myValue = true;
	return myValue;
}



//Insert my words into one other data colletion
bool populateWord::insertRoot(const pairWord& newElement)
{
    bool myValue=false;
    nodeBST* newRoot = new nodeBST(newElement, NULL,NULL);
    root= newRoot;
    elementCount++;
    return myValue;
}



// Insert a new node into binary search tree
bool populateWord::insertNode(const pairWord& newElement)
{
	bool myValue = false;
	//cout<<"Element being inserted   "<<newElement<<endl;
	if (searchPairBST(newElement)!= true)
	{
		nodeBST* newNode = new nodeBST(newElement, NULL, NULL);
		root = insertR(root, newNode);
		elementCount++;
		myValue = true;
  }
	return myValue;
}


nodeBST* populateWord::insertR(nodeBST* subTree, nodeBST* newNode)
{
	if (subTree == NULL)
		return newNode;
	else
	{
		if ((subTree->getData()) > (newNode->getData()))
			subTree -> setLeft(insertR(subTree->getLeft(), newNode));
		else
			subTree->setRight(insertR(subTree->getRight(), newNode));
		return subTree;
	}
}



nodeBST* populateWord::getRoot()
{
	return root;
}

LinkedList* populateWord::getArr()
{
	return expandArr;
}

int populateWord::getSize() const
{
	return size;
}


//Remove all the elements
bool populateWord::removeAll()
{
	elementCount = 0;
}


// Search a specific pair of word from the BST
bool populateWord::searchPairBST(pairWord myPair)
{
	nodeBST* temp = root;
	while (temp != NULL)
	{
		if (temp->getData() == myPair)
            break;
		if (myPair > temp->getData())
            temp = temp->getRight();
		else
		{
			if (myPair < temp->getData())
          temp = temp->getLeft();
		}
	}
	if (temp == NULL)
    return false;
	if (temp->getData() == myPair)
		return true;
}



// Search a specific pair of word from the chain hash table
pairWord populateWord::searchPair(pairWord onePair) const
{
	int myKey = hashFunc(onePair);
	int myLength = expandArr[myKey].getLength();

	node *myhead = expandArr[myKey].getHead();
	while (myhead != NULL)
	{
		if (myhead->getData() == onePair)
			return myhead->getData();
		else
			myhead = myhead->next;
	}
	if (myhead == NULL)
	{
		pairWord newPair("","");
		return newPair;
	}
}



int populateWord::hashFunc(const pairWord& onePair) const
{
	int accum = 0;
	string myStr = onePair.returnEnglish();

	const int sizeOfS = myStr.size();
	const char * bytes = myStr.c_str();
	for(int i =0; i < sizeOfS; i++)
	{
		accum+= bytes[i];
	}
	accum  = accum%sizeOfS;
	return accum;
}

//Display the whole dictionary in O(n) by ascending order
void populateWord::inorderTraversal(nodeBST* myRoot)
{
    if( root == NULL ) //
		cout<<"Empty"<<endl;

    if(myRoot != NULL)
    {
        inorderTraversal(myRoot->getLeft());
        cout<< myRoot->getData()<<endl;
        inorderTraversal(myRoot->getRight());
    }
}
