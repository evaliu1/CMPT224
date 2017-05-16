/*
pairWord.h
My Object -- pairWord, the data inside nodeBST
header file of pairWord class

Eva Liu 301243938
Liam O'Shaughnessy 301283210
07/14/2016
*/

#pragma once
#ifndef PAIRWORD_H_INCLUDED
#define PAIRWORD_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;


class pairWord
{
private:
	string english;
	string klingon;
public:

	pairWord();
	pairWord(string myEnglish);
	pairWord(string myEnglish, string myKlingon);
	// Get the english word when we know the klingon
	string getEnglish(string myKlingon) const;
	// Get the klingon word when we know the english
	string getKlingon(string myEnglish) const;

	string returnEnglish() const;
	string returnKlingon() const;

	// Set my private variable
	void setPair(string myEnglish, string myKlingon);

	bool operator<(const pairWord& rhs);
	bool operator>(const pairWord& rhs);
	bool operator==(const pairWord& rhs);
	friend ostream & operator<<(ostream & os, const pairWord& rhs);
};

#endif // PAIRWORD_H_INCLUDED
