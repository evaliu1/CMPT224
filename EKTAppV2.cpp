/*
EKTAppV2.cpp
Implementation of English--Klingon translation

Eva Liu 301243938
Liam O'Shaughnessy 301283210
07/28/2016
*/

#include "pairWord.h"
#include "populateWord.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;
void populate(populateWord* Dictionary);
void display(populateWord* Dictionary);
void read(populateWord* Dictionary, populateWord* engWord);

// Main funciton
// Description: Get Dictionary data from data file and read word from command line
// Postcondition: Two BST, one is sorted dictionary, the other one is sorted input word after translation, creates two data collection, one is hash table, the other one is BST.
int main(int argc, char *argv[])
{
	populateWord* Dictionary = new populateWord;
	populateWord* engWord = new populateWord;
	populate(Dictionary);
	read(Dictionary, engWord);

    // Loop through each argument and print its number and value
  if (argc == 2)
  {
  	string s(argv[1]);
  	if (s=="display")
  	{
  		display(Dictionary);
  	}
  }
  return 0;
}


// Populate the words inside data file
// Description: Read line and then write into pairWord
// Precondition: data file is not empty
// Postcondition: One BST, sorted dictionary data
void populate(populateWord* Dictionary)
{
	const int MAX_L = 50;
	string* englishWord = new string[MAX_L] ; ///Do these need to be pointers?
	string* klingonWord = new string[MAX_L] ;

    //char* filename = "dataFile.txt"; ///Not sure if this is why we get errors
	ifstream myfile;
	myfile.open("dataFile.txt");
	string line;

	//Insert into my first data collection
	if (myfile.is_open())
	{
		while (getline (myfile,line) )
		{
		    int i = 0;
		    string token[2];
		    istringstream ss(line);
		     while (getline(ss,token[i],':'))
            {
                i++;
            }
        pairWord myPair(token[0],token[1]);

			  //cout << line << '\n';
        if (Dictionary->getRoot()==NULL )
        {
            Dictionary->insertRoot(myPair);
        }
        else
        {
						Dictionary->insertNode(myPair);
        }
		}
		myfile.close();
	}
	else cout << "Unable to open file";


    //char* filename = "dataFile.txt"; ///Not sure if this is why we get errors
	ifstream myfile2;
	myfile2.open("dataFile.txt");
	string line2;

	//Insert into my second data collection
	if (myfile2.is_open())
	{
		while ( getline (myfile2,line2) )
		{
		    int i = 0;
		    string token[2];
		    istringstream ss(line2);
		     while (getline(ss,token[i],':'))
        {
                i++;
        }
        pairWord myPair(token[0],token[1]);
				Dictionary->insertPair(myPair);
		}
		myfile.close();
	}

	int arrLength = 0;
	arrLength  = Dictionary->getSize();
}

//Read word from the cin
//Description: Search the inputs words in the hash table, O(1)
//Precondition: We have two data collection for the dictionary, one is BST, the other is hash table
//Postcondition: Make another BST for the inputs
void read(populateWord* Dictionary, populateWord* engWord)
{
    string aWord = "";
    pairWord myPair;
    cout << "Reading from cin:" << endl;
	 while(getline(cin, aWord))
	 {
				pairWord noKling = pairWord(aWord);
				//Use hash table to search the pairWord, so the time efficiency is O(1)
				myPair = Dictionary->searchPair(noKling);
				if (aWord == "")
				cout<<"Empty inputs"<<endl;
				else if (myPair.returnEnglish() == "")
				{
					cout<<aWord<<": <not found>"<<endl;
				}
				else
				{
							if(engWord->getRoot() == NULL)
								engWord->insertRoot(myPair);
							else
								engWord->insertNode(myPair);
				}
				cout <<endl;
				cout <<"Here is all the inputs and translation, searched by chain hash table: "<<endl;
				engWord->inorderTraversal(engWord->getRoot());
	}
}



void display(populateWord* Dictionary)
{
	cout<<endl;
	cout<<"Here is my sorted BST for the dictionary: "<<endl;
	Dictionary->inorderTraversal(Dictionary->getRoot());
}
