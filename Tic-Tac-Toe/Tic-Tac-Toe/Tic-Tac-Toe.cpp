// Jonathan Vertiz
// ITSE 1307
// Tic-Tac-Toe
// Tic-Tac-Toe.cpp : Program is a simple Tic-Tac-Toe game.

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
//To do: Need to fix logic in deciding winner, counts all across board

//Initilize the constant values for the arrays to use
const int intRows = 3;
const int intColumns = 3;

void printBoard(char aryBoard[][intColumns], int intRows)
{
	//Function prints out the array that holds the board
	cout << "Column:\t0\t1\t2" << endl;
	for (int intRow = 0; intRow < intRows; intRow++)
	{
		cout << "Row " << (intRow);
		for (int intColumn = 0; intColumn < intColumns; intColumn++)
		{
			cout << "\t";
			cout << aryBoard[intRow][intColumn];
		}
		cout << endl;
	}
}

void clearBoard(char aryBoard[][intColumns], int intRows)
{
	//Function clears the board leaving it with an empty character 
	for (int intRow = 0; intRow < intRows; intRow++)
	{
		for (int intColumn = 0; intColumn < intColumns; intColumn++)
		{
			aryBoard[intRow][intColumn] = '-';
		}
	}
}

bool fillSpot(char aryBoard[][intColumns], int intRows, int intRow, int intColumn, char chrSymbol = 'X')
{
	//Bool function that fills a spot in the board with the players icon
	//Also prevents a player form placing ones piece on a taken spot
	if (aryBoard[intRow][intColumn] != '-')
	{
		return false;
	}
	aryBoard[intRow][intColumn] = chrSymbol;
	return true;
}

int getIntInput(string strMessage, int intMax = 3)
{
	//Function that allows for input in the next function with parameters that prevent bad numbers
	int intNumber = 0;
	do {
		cout << strMessage << " (0 - "
			<< intMax - 1 << "): ";
		cin >> intNumber;
	} while (intNumber < 0 || intNumber > intMax - 1);
	return intNumber;
}

void getPlayerInput(char aryBoard[][intColumns], int intRows)
{
	//Function applies the choice the player makes in where they want their piece to go
	static char chrSymbol = 'O';
	chrSymbol = (chrSymbol == 'O') ? 'X' : 'O';
	int intRow = 0;
	int intColumn = 0;

	do {
		cout << "Player " << chrSymbol << " Turn:" << endl;
		intRow = getIntInput("Please enter the row", intRows);
		intColumn = getIntInput("Please enter the column", intColumns);
	} while (!fillSpot(aryBoard, intRows, intRow, intColumn, chrSymbol));
}

bool isWinner(char aryBoard[][intColumns], int intRows, int intWinNumber = 3)
{
	//Scans the arrays and decides the winner
	char charCurrentSymbol = 'O';
	static int intCurrentSymbolCount = 0;

	for (int intRow = 0; intRow < intRows; intRow++)
	{
		intCurrentSymbolCount = 0;
		for (int intColumn = 0; intColumn < intColumns; intColumn++)
		{
			if (aryBoard[intRow][intColumn] == charCurrentSymbol)
			{
				intCurrentSymbolCount++;
				cout << "found " << intCurrentSymbolCount << ") "
					<< charCurrentSymbol << endl;
				if (intCurrentSymbolCount == 3)
				{
					return true;
				}
			}
		}
	}

	for (int intColumn = 0; intColumn < intColumns; intColumn++)
	{
		intCurrentSymbolCount = 0;
		for (int intRow = 0; intRow < intRows; intRow++)
		{
			if (aryBoard[intRow][intColumn] == charCurrentSymbol)
			{
				intCurrentSymbolCount++;
				cout << "found " << intCurrentSymbolCount << ") "
					<< charCurrentSymbol << endl;
				if (intCurrentSymbolCount == 3)
				{
					return true;
				}
			}
		}
	}

	/*charCurrentSymbol = 'X';
	intCurrentSymbolCount = 0;
	for (int intRow = 0; intRow < intRows; intRow++)
	{
		for (int intColumn = 0; intColumn < intColumns; intColumn++)
		{
			if (aryBoard[intRow][intColumn] == charCurrentSymbol)
			{
				intCurrentSymbolCount++;
				cout << "found " << intCurrentSymbolCount << ") "
					<< charCurrentSymbol << endl;
			}
		}
	}

	intCurrentSymbolCount = 0;
	for (int intColumn = 0; intColumn < intColumns; intColumn++)
	{
		for (int intRow = 0; intRow < intRows; intRow++)
		{
			if (aryBoard[intColumn][intRow] == charCurrentSymbol)
			{
				intCurrentSymbolCount++;
				cout << "found " << intCurrentSymbolCount << ") "
					<< charCurrentSymbol << endl;
			}
		}
	}*/

	if (intCurrentSymbolCount == intWinNumber)
	{
		return true;
	}


	return false;
}

int main()
{
	//main function that pulls all together
	char aryBoard[intRows][intColumns];
	clearBoard(aryBoard, intRows);
	printBoard(aryBoard, intRows);
	do {
		getPlayerInput(aryBoard, intRows);
		printBoard(aryBoard, intRows);
	} while (!isWinner(aryBoard, intRows));
	return 0;
}
