// Jonathan Vertiz
// ITSE 1307
// Airline Seating
// AirlineSeating.cpp : Claims a seat in an airline through user input.

#include "stdafx.h"
#include <iostream>
using namespace std;

//Create constant integeres to be universally used
const int intRows = 12;
const int intColumns = 6;

//Function that prints out the array of the seats, refreshes in main after every update from other functions
void printSeats(char arySeats[][intColumns], const int intRows)
{
	for (int intRow = 0; intRow < intRows; intRow++) 
	{
		cout << "Row" << (intRow + 1);
		for (int intColumn = 0; intColumn < intColumns; intColumn++) 
		{
			cout << "\t";
			cout << arySeats[intRow][intColumn];
		}
		cout << endl;
	}
}

//Function that empties the seats arrau and dislays them to the user
void emptySeats(char arySeats[][intColumns], const int intRows) 
{
	cout << "Available seats on the airline: " << endl;
	cout << endl;

	for (int intRow = 0; intRow < intRows; intRow++) 
	{
		for (int intColumn = 0; intColumn < intColumns; intColumn++) 
		{
			arySeats[intRow][intColumn] = '-';
		}
	}
}

//Funtion that has the user claim a seat through keyboard input
void claimSeats(char arySeats[][intColumns], const int intRows)
{
	int intRow = 0;
	int intColumn = 0;

	cout << "Which row do you want? (0-11): ";
	cin >> intRow;
	cout << "Which Column? (0-5): ";
	cin >> intColumn;

	arySeats[intRow][intColumn] = 'X';
}

//Main function that throws everything into practice
int main()
{
	char arySeats[intRows][intColumns];
	emptySeats(arySeats, intRows);
	printSeats(arySeats, intRows);
	claimSeats(arySeats, intRows);
	printSeats(arySeats, intRows);
    return 0;
}

