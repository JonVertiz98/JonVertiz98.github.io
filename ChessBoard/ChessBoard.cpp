// Jonathan Vertiz
// ITSE 1307
// Chess Board
// ChessBoard.cpp : Prints out a diagram of a chess board using arrays,

#include "stdafx.h"
#include <iostream>
using namespace std;

//Initilize the constant values of the board dimensions
const int intRows = 4;
const int intColumns = 8;

//Function that prints out the white space of the board
void printBoard(char aryBoard[][intColumns], const int intRows)
{
	for (int intRow = 0; intRow < intRows; intRow++)
	{
		for (int intColumn = 0; intColumn < intColumns; intColumn++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

//Function that prints out the array that holds the pawn location
void printPawn(char aryPawn[8])
{
	int intPawns = 8;
	for (int intPawn = 0; intPawn < 8; intPawn++)
	{
		aryPawn[intPawn] = 'p';
		cout << aryPawn[intPawn];
	}
	cout << endl;
}

//Function that prints out the array that holds the pawn location for the opposite side
void printUpperPawn(char aryUpperPawn[8])
{
	int intUpperPawns = 8;
	for (int intUpperPawn = 0; intUpperPawn < 8; intUpperPawn++)
	{
		aryUpperPawn[intUpperPawn] = 'P';
		cout << aryUpperPawn[intUpperPawn];
	}
	cout << endl;
}

//Function that prints out the array that holds the other piece locations
void printPiece()
{
	int intPiece = 0;
	char aryPiece[8] = { 'r','n','b','q','k','b','n','r' };
	for (int intPiece = 0; intPiece < 8; intPiece++)
	{
		cout << aryPiece[intPiece];
	}
	cout << endl;
}

//Function that prints out the array that holds the other piece locations for the opposite side
void printUpperPiece()
{
	int intUpperPiece = 0;
	char aryUpperPiece[8] = { 'R','N','B','Q','K','B','N','R' };
	for (int intUpperPiece = 0; intUpperPiece < 8; intUpperPiece++)
	{
		cout << aryUpperPiece[intUpperPiece];
	}
	cout << endl;
}

int main()
{
	//Initilize all the Arrays
	char arySeats[intRows][intColumns];
	char aryPawn[8];
	char aryUpperPawn[8];
	char aryPiece[8] = { 'r','n','b','q','k','b','n','r' };
	char aryUpperPiece[8] = { 'R','N','B','Q','K','B','N','R' };
	
	//Call all the functions into the main function
	printPiece();
	printPawn(aryPawn);
	printBoard(arySeats, intRows);
	printUpperPawn(aryUpperPawn);
	printUpperPiece();
    return 0;
}

