// Jonathan Vertiz
// ITSE 1307
// Time Conversion Revisit
// TimeConversion.cpp : Program that will take in and convert the time

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
//Further logic needs to be applied before this program is complete
//Function that takes in the users input on the time of day and hours
int getIntHours(int intHours, char chrTimeofDay)
{
	cout << "Enter the hour: ";
	cin >> intHours;
	cout << "AM or PM: ";
	cin >> chrTimeofDay;
	return intHours;
}

//Decides if converting 12 to 24 hours or vice versa
void time12or24(char chrChoice)
{
	int intHours = 0;
	char chrTimeofDay = '-';

	cout << "Are you converting 12 to 24 ('A') " << endl 
		<< "Are you converting 24 o 12 ('B') ";
	cin >> chrChoice;

	switch (chrChoice)
	{
		case 'A':
			if (intHours < 10)
			{
				cout << "0" << intHours;
			}
			if (chrTimeofDay == 'PM')
			{
				cout << intHours * 12;
			}
			break;
		case 'B':
			cout << intHours - 12;
	}
}

int main()
{
	getIntHours(0, '-');
	time12or24('-');
    return 0;
}

