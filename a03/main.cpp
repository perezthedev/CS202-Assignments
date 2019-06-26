//  CS 202
//  Provided Main Program
//  Assignment #3 - Craps Game

//	C++ program to implement a virtual craps game.

// ************************************************************************************

#include <cstdlib>
#include <iostream>
#include <string>

#include "crapsType.h"

using namespace std;

void showSummary(crapsType myGame, int w, int l, int r, string title);


// ************************************************************************************

int main()
{

// ----------
//  General initializations

	string	bars = "---------------------------";

	cout << bars << endl;
	cout << "CS 202 Assignment #3" << endl;
	cout << "Craps Game Simulation." << endl;
	cout << endl;

// ----------
//  Start initial game.

//  Game strategy:
//	- bet 100 each bet.
//	- if run out of money, quit
//	- if stake is quadrupled, quit

	crapsType	gameA;
	int	wins=0, losses=0, rounds=0;
	int	myBet = 100, balance;
	string	gameAtitle = "Game Example A (w/display)";

	cout << bars << endl;
	cout << gameAtitle << endl << endl;

	gameA.readStake();
	gameA.setDisplay(true);

	while(true) {
		cout << bars << endl;
		if (gameA.playCraps(myBet))
			wins++;
		else
			losses++;

		rounds++;
		balance = gameA.getCurrentBalance();
		cout << "Current Balance: $" << balance << endl;

		if (balance <= myBet)
			break;

		if (balance >= (gameA.getStake()*4))
			break;
	}

	showSummary(gameA, wins, losses, rounds, gameAtitle);


// ----------
//  Start two more games.
//  For simplicity on these games:
//	- set stake directly (no need to read from user)
//	- do not display each game status (i.e., set display to false)

//  Game 1 Strategy:
//	- set stake to 1000, and set bet 100
//		if win, increase bet by 10
//		if lose, set bet back to 100
//	- if run out of money, quit
//	- if stake is doubled, quit

	crapsType	game1;
	int	wins1=0, losses1=0, rounds1=0;
	int	myBet1 = 100, balance1;
	bool	stat;

	game1.setStake(1);			// note, invalid
	game1.setStake(1000);
	game1.setDisplay(false);
	
	stat = game1.playCraps(5);		// note, invalid
// SOMEWHERE HERE!!!
	while(true) {
		stat = game1.playCraps(myBet1);
		if (stat)
			wins1++;
		else
			losses1++;

		if (stat)
			myBet1 += 10;
		else
			myBet1 = 100;

		rounds1++;
		balance1 = game1.getCurrentBalance();

		if (balance1 <= myBet1)
			break;

		if (balance1 >= (game1.getStake()*4))
			break;
	}

	showSummary(game1, wins1, losses1, rounds1, "Game Example 1 (wo/display)");

// ----------
//  Game 2 Strategy:
//	- players choice.
//	Challenge: find a winning strategy.  :-)





// ----------
//  Done...

	return 0;

}


// ************************************************************************************
//  Simple function to display game summary.

void showSummary(crapsType myGame, int w, int l, int r, string title)
{
	string	stars = "************************************************";
	string	spc = "   ";

	cout << endl << stars << endl;

	cout << "Game Results:" << endl;
	cout << spc << "Game Title: " << title << endl;
	cout << spc << "Wins = " << w << endl;
	cout << spc << "Losses = " << l << endl;
	cout << spc << "Rounds = " << r << endl;
	cout << spc << "Original Stake:  $" << myGame.getStake() << ".00" << endl;
	cout << spc << "Final Balance:  $" << myGame.getCurrentBalance() << ".00" << endl;

	if (myGame.getCurrentBalance() > myGame.getStake())
		cout << spc << "Winner!!" << endl;
	else
		cout << spc << "Loser." << endl;

	cout << stars << endl << endl;

}

