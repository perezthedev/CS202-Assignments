// CS 202 Assignment #3

// **********************************************************************
//  Play a simplified craps game.

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class crapsType
{

public:
	// Constructor -> Initialize class variables.
	crapsType();

	// Function to read stake amount from player.
	//	Verifies range, re-prompts until correct input
	void	readStake();

	// Function to set the stake amount (from argument).
	void	setStake(int);

	// Function to return the current stake.
	int	getStake() const;

	// Function to get the current balance.
	int	getCurrentBalance() const;

	// Function to set the display flag.
	void	setDisplay(bool);

	// Play a single game of craps (simplified version).
	//	if display is true, calls displayGame()
	bool	playCraps(int);


private:
	void	displayRoll(int, int);		// Privtae function to display roll details
						//	including roll name

	int	originalStake;			// Original stake amount
	int	cashOnHand;			// Current cash amount
	bool	display;			// Dislpay game details
						//	true to display, false otherwise

	static	const	int	MINSTAKE = 50;
	static	const	int	MAXSTAKE = 10000;
	static	const	int	MINBET = 10;
	static	const	int	MAXBET = 1000;
};


