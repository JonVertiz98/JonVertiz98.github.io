// Jonathan Vertiz
// ITSE 1307
// Card Project
// MaoCardGame.cpp : Program is a card game of Mao

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Player.h"
using namespace std;

void playGame()
{
	//Initilize all the values we'll need and add in all the class files
	Player objPlayerOne = Player();
	Player objPlayerTwo = Player();
	Deck objDeck = Deck();
	DiscardPile objDiscard = DiscardPile();
	int intCardChoice1 = 0;
	int intCardChoice2 = 0;
	char chrChoice = ' ';

	objDeck.shuffle();	//Shuffles the deck at the beginning of the game
	objPlayerOne.inputBet();  //Asks player one to input their bet
	objPlayerTwo.inputBet();  //Asks player two to input their bet

	//Initilizes the deck and plants the cards in each players hands
	for (int intCards = 0; intCards < 7; intCards++)
	{
		objPlayerOne.addCardToHand(objDeck.getCard());
		objPlayerTwo.addCardToHand(objDeck.getCard());
	}

	objPlayerOne.printHand(); //Displays the array of cards in Player Ones hand
	cout << "Player One, choose base card: "; //Asks Player One to choose the starting card
	cin >> intCardChoice1;

	//Code that checks if the played card is applicable
	Card cardPlayerDiscard = objPlayerOne.removeCardFromHand(intCardChoice1);
	if (objDiscard.checkValidCard(cardPlayerDiscard))
	{
		objDiscard.addCard(cardPlayerDiscard); //If so, it's used as the played card
	}
	else
	{
		objPlayerOne.addCardToHand(cardPlayerDiscard); //If not, the player has to put it back in their deck 
		objPlayerOne.addCardToHand(objDeck.getCard()); //plus an extra card
	}

	//Card played is now the card at the top of the deck
	cout << "Card in play is: " << objDiscard.getTopCard().toString() << endl;
	cout << endl;

	//Do-While loop
	do {
		//Prints out the array of Player Twos' cards
		objPlayerTwo.printHand();

		cout << "Card in play is: " << objDiscard.getTopCard().toString() << endl; //Displays the current card at top of deck
		cout << endl;
		cout << "Player Two, select your playing card: "; //Prompts Player Two to play their card
		cin >> intCardChoice2;
		cout << endl;

		//Same logic as before but with Player Two
		//If applicable then card at top of deck is updated to Player Twos played card
		cardPlayerDiscard = objPlayerTwo.removeCardFromHand(intCardChoice2);
		if (objDiscard.checkValidCard(cardPlayerDiscard))
		{
			objDiscard.addCard(cardPlayerDiscard);
		}
		else
		{
			objPlayerTwo.addCardToHand(cardPlayerDiscard);
			objPlayerTwo.addCardToHand(objDeck.getCard());
		}

		//Prints out Player Ones' hand again for their turn
		objPlayerOne.printHand();

		//Shows updated top card
		cout << "Card in play is: " << objDiscard.getTopCard().toString() << endl;
		cout << endl;

		//Prompts Player One to select their card
		cout << "Player one, select your playing card: ";
		cin >> intCardChoice1;
		cout << endl;

		//Same logic as before
		cardPlayerDiscard = objPlayerOne.removeCardFromHand(intCardChoice1);
		if (objDiscard.checkValidCard(cardPlayerDiscard))
		{
			objDiscard.addCard(cardPlayerDiscard);
		}
		else
		{
			objPlayerOne.addCardToHand(cardPlayerDiscard);
			objPlayerOne.addCardToHand(objDeck.getCard());
		}

		//Updated top card if Player Ones card was applicable
		cout << "Card in play is: " << objDiscard.getTopCard().toString() << endl;
		cout << endl;

		//If statement: if Player One loses all their cards
		if (objPlayerOne.getNumberOfCards() == 0)
		{
			//Displays who won
			cout << "Player one won" << endl;
			objPlayerOne.wonBet();	//Player wins the bet and is added to their money
			objPlayerTwo.lostBet(); //Losing Player loses bet and is penilized 
			objPlayerOne.printHand(); //Prints out empty hand to show they won the money
			cout << "-----" << endl;
			objPlayerTwo.printHand(); //Prints out losing hand to show how much they had
			cout << "Do you want a rematch?(Y/N):  "; //Asks if a rematch is in order
			cin >> chrChoice;
			
			//If statement: If a rematch is in order
			if (chrChoice == 'Y')
			{
				//Displays rematch is happening
				cout << "Rematch..." << endl;
				cout << endl;

				objPlayerOne.clearHand(); //Clears Players hands for a fresh start
				objPlayerTwo.clearHand();

				objDeck.shuffle(); //Shuffles deck
				objPlayerOne.inputBet(); //Asks for Player Ones bet
				objPlayerTwo.inputBet(); //Asks for Player Twos bet

										 //Adds a fresh set of cards to each hand
				for (int intCards = 0; intCards < 7; intCards++)
				{
					objPlayerOne.addCardToHand(objDeck.getCard());
					objPlayerTwo.addCardToHand(objDeck.getCard());
				}

				//Asks Player One two choose top card again
				objPlayerOne.printHand();
				cout << "Player One, choose base card: ";
				cin >> intCardChoice1;

				//Checks if applicable, sets top card always in this case
				cardPlayerDiscard = objPlayerOne.removeCardFromHand(intCardChoice1);
				if (objDiscard.checkValidCard(cardPlayerDiscard))
				{
					objDiscard.addCard(cardPlayerDiscard);
				}
				else
				{
					objPlayerOne.addCardToHand(cardPlayerDiscard);
					objPlayerOne.addCardToHand(objDeck.getCard());
				}

				//Displays updated top card and loops back through the game
				cout << "Card in play is: " << objDiscard.getTopCard().toString() << endl;
				cout << endl;
			}
			else //Else statement: If player does not want a rematch then the game is ended
			{
				break;
			}
		}
		else if (objPlayerTwo.getNumberOfCards() == 0) //Else: if Player Two loses all their cards
		{
			//Displays who won
			cout << "Player two won" << endl;
			objPlayerTwo.wonBet(); //Player wins the bet and is added to their money
			objPlayerOne.lostBet(); //Losing Player loses bet and is penilized 
			objPlayerTwo.printHand(); //Prints out empty hand to show they won the money
			cout << "-----" << endl;
			objPlayerOne.printHand();  //Prints out losing hand to show how much they had
			cout << "Do you want a rematch?(Y/N):  "; //Asks if a rematch is in order
			cin >> chrChoice;

			//If statement: If a rematch is in order
			if (chrChoice == 'Y')
			{
				//Displays rematch is happening
				cout << "Rematch..." << endl;
				cout << endl;

				objPlayerOne.clearHand(); //Clears Players hands for a fresh start
				objPlayerTwo.clearHand();

				objDeck.shuffle(); //Shuffles deck
				objPlayerOne.inputBet(); //Asks for Player Ones bet
				objPlayerTwo.inputBet(); //Asks for Player Twos bet

										 //Adds a fresh set of cards to each hand
				for (int intCards = 0; intCards < 7; intCards++)
				{
					objPlayerOne.addCardToHand(objDeck.getCard());
					objPlayerTwo.addCardToHand(objDeck.getCard());
				}

				//Asks Player One two choose top card again
				objPlayerOne.printHand();
				cout << "Player One, choose base card: ";
				cin >> intCardChoice1;

				//Checks if applicable, sets top card always in this case
				Card cardPlayerDiscard = objPlayerOne.removeCardFromHand(intCardChoice1);
				if (objDiscard.checkValidCard(cardPlayerDiscard))
				{
					objDiscard.addCard(cardPlayerDiscard);
				}
				else
				{
					objPlayerOne.addCardToHand(cardPlayerDiscard);
					objPlayerOne.addCardToHand(objDeck.getCard());
				}

				//Displays updated top card and loops back through the game
				cout << "Card in play is: " << objDiscard.getTopCard().toString() << endl;
				cout << endl;
			}
			else //Else statement: If player does not want a rematch then the game is ended
			{
				break;
			}
		}
		
		
	} while (toupper(chrChoice) != 'N'); //Do all above code while prompt for rematch is not No
}

	//Main function that executed the code
	int main()
	{
		srand(time(0)); //Setup the randomness at the beginning of the program
		const int INTNUMBEROFDECKS = 3;	//Total amount of decks is up to 3, 1 for each 2 players
		const int INTPLAYERHANDSIZE = 7; // Initial starting amount of cards is always 7
		const int INTMAXPLAYERS = 6; //Max amount of players is 6
		int intNumberOfPlayers = 2; //Number of players for this program is 2

		playGame(); //Plays the game

		cout << "Thank you for playing."; //When done, we thank you

		return 0;
	}