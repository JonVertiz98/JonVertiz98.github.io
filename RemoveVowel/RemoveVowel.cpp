// Jonathan Vertiz
// ITSE 1307
// Removing Vowels
// RemoveVowel.cpp : Program asks the user to input a string and removes the vowels from it.

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//Function that declares characters that are vowels
bool isVowel(char chrLetter)
{
	switch (toupper(chrLetter))
	{
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'Y':
			return true;
	}
	return false;
}

//Function that substrings vowels
string removeVowels(string strRemoveVowels)
{
	char* removeSubstring = new char[strRemoveVowels.size() + 1];

	int intRemove = 0;
	for (int intCount = 0; intCount < strRemoveVowels.size(); intCount++)
	{
		if (!isVowel(strRemoveVowels[intCount]))
		{
			removeSubstring[intRemove] = strRemoveVowels[intCount];

			intRemove++;
		}

	}

	removeSubstring[intRemove] = '\0';

	return removeSubstring;
}

int main()

{
	//Prompts the user to enter the string to be substringed and outputs the string to the user
	string strRemove = "";
	removeVowels("");
	cout << "Enter string: ";
	getline(cin, strRemove);
	cout << removeVowels(strRemove) << endl;
    return 0;
}

