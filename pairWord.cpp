/*
pairWord.cpp
My Object -- pairWord, the data inside nodeBST
Implementation of pairWord class

Eva Liu 301243938
Liam O'Shaughnessy 301283210
07/14/2016
*/
#include "pairWord.h"
#include <iostream>
#include <string>

using namespace std;

// Default constructor

pairWord::pairWord()
{
	english = "";
	klingon = "";
}

// Constructor

pairWord::pairWord(string myEnglish)
{
    english = myEnglish;
    klingon = "";
}

pairWord::pairWord(string myEnglish, string myKlingon)
{
	english = myEnglish;
	klingon = myKlingon;
}

// Set my private variables
void pairWord::setPair(string myEnglish, string myKlingon)
{
	english = myEnglish;
	klingon = myKlingon;
}

// Get the english word when we know the klingon
string pairWord::getEnglish(string myKlingon) const
{
	if (klingon == myKlingon)
		return english;
	else
		return "";
}

// Get the klingon word when we know the english
string pairWord::getKlingon(string myEnglish) const
{
	if (myEnglish==english)
		return klingon;
	else
		return "";
}

string pairWord::returnEnglish() const
{
	return english;
}

string pairWord::returnKlingon() const
{
	return klingon;
}

// Overloaded Operators
// Description: Comparison (equality) operator. Compares "this" Profile object with "rhs" Profile object.
//              Returns true if both Profile objects have the same name.
bool pairWord::operator<(const pairWord& rhs)
{
    bool done = false;
    bool lessThan = true;
    int i =0;
    while (!done && english[i])
    {
        if (tolower(english[i]) < tolower(rhs.returnEnglish()[i]))
        {
            done = true;
            lessThan = true;
        }
        else if(tolower(english[i]) == tolower(rhs.returnEnglish()[i]))
        {
            done = false;
            i++;
        }

		else if ( (&english[i] != "") && (&rhs.returnEnglish()[i] == ""))
        {
            done = true;
            lessThan = true;
        }
        else
        {
            done = true;
            lessThan = false;
        }
    }
return lessThan;
} // end of operator<


  // Overloaded Operators==
  // Description: Comparison (equality) operator. Compares "this" Profile object with "rhs" Profile object.
  //              Returns true if both Profile objects have the same name.
bool pairWord::operator==(const pairWord& rhs)
{
	bool done = false;
    bool eq = true;
    int i =0;
    while (!done && english[i])
    {
        if (tolower(english[i]) == tolower(rhs.returnEnglish()[i]))
        {
            done = false;
            eq = true;
            i++;
        }
		else if ( (&english[i] != "") && (&rhs.returnEnglish()[i] == ""))
        {
            done = true;
            eq = true;
        }
        else
        {
            done = true;
            eq = false;
        }
    }
	return eq;
} // end of operator==


  // Overloaded Operators <
  // Description: Comparison (equality) operator. Compares "this" Profile object with "rhs" Profile object.
  //              Returns true if both Profile objects have the same name.
bool pairWord::operator>(const pairWord& rhs)
{
	bool done = false;
    bool greaterThan = true;
    int i =0;
    while (!done && english[i]) ///not sure if english[i] condition will work
    {
        if (tolower(english[i]) > tolower(rhs.returnEnglish()[i]))
        {
            done = true;
            greaterThan = true;
        }
        else if(tolower(english[i]) == tolower(rhs.returnEnglish()[i]))
        {
            done = false;
            i++;
        }

		else if ( (&english[i] != "") && (&rhs.returnEnglish()[i] == ""))
        {
            done = true;
            greaterThan = true;
        }
        else
        {
            done = true;
            greaterThan = false;
        }
    }
return greaterThan;
} // end of operator>

// Overloaded Operators <<
// Description: Print all the data inside pairWord
ostream & operator<<(ostream & os, const pairWord& rhs)
{
	cout<<rhs.returnEnglish()<<" : "<<rhs.returnKlingon();
    return os;
}
