#include <iostream>
#include "crapsType.h"

using namespace std;

crapsType::crapsType()
{
	originalStake = 0;
	cashOnHand = 0;
	display = true;
}

void crapsType::readStake()
{
	bool flag = true;
	do{
		cout << "Enter your stake: ";
		cin >> originalStake;
		if(originalStake < MINSTAKE || originalStake > MAXSTAKE)
		{
			cout << "Error - invalid entry, must be between ";
			cout << MINSTAKE << " and " << MAXSTAKE << endl;
			cout << "Please re-enter." << endl;
		}
		else
		{
			flag = false;
			cashOnHand = originalStake;
		}
	}while(flag);
	
}

void crapsType::setStake(int amount)
{
	//bool flag = true;
	//do{
		if(amount < MINSTAKE || amount > MAXSTAKE)
		{
			cout << "Error - invalid stake amount." << endl;
		}
		else
		{
			//flag = false;
			originalStake = amount;
			cashOnHand = originalStake;
		}
	//}while(flag);
}

int crapsType::getStake() const
{
		return originalStake;
}

int crapsType::getCurrentBalance() const
{
		return cashOnHand;
}

void crapsType::setDisplay(bool x)
{
		display = x;
}

bool crapsType::playCraps(int yourBet)
{
	
	if(yourBet < MINBET || yourBet > MAXBET)
	{
		cout << "Error - invalid bet amount." << endl;
		return 0;
	}
	else
	{
		if(display)
		{

			int die1 = rand() % 6 + 1;
			int die2 = rand() % 6 + 1;
			int die_total = die1 + die2;
			displayRoll(die1, die2);

			
			if (die_total == 7 || die_total == 11)
			{
				{
					cashOnHand = cashOnHand + yourBet;
					return 1;
				}
			}
			
			else if (die_total == 2 || die_total == 3 || die_total == 12)
			{
				cashOnHand = cashOnHand - yourBet;
				return 0;
			}
			
			else if((die_total == 4) || (die_total == 5) || (die_total == 6) ||
					(die_total == 8) || (die_total == 9) || (die_total == 10))
			{
				int point_num = die_total;

				die1 = rand() % 6 + 1;
				die2 = rand() % 6 + 1;
				die_total = die1 + die2;
				
				displayRoll(die1, die2);
				
				if(die_total == 7)
				{
					if(die_total == point_num)
					{
						cashOnHand = cashOnHand - yourBet;
						return 0;
					}
				}
				else if(die_total == point_num)
				{
						cashOnHand = cashOnHand + yourBet;
						return 1;
				}
			}
		}
			
		else
		{
			int die1 = rand() % 6 + 1;
			int die2 = rand() % 6 + 1;
			int die_total = die1 + die2;
			
			if (die_total == 7 || die_total == 11)
			{
				{
					cashOnHand = cashOnHand + yourBet;
					return 1;
				}
			}
			
			else if (die_total == 2 || die_total == 3 || die_total == 12)
			{
				cashOnHand = cashOnHand - yourBet;
				return 0;
			}
			
			else if((die_total == 4) || (die_total == 5) || (die_total == 6) ||
					(die_total == 8) || (die_total == 9) || (die_total == 10))
			{
				int point_num = die_total;

				die1 = rand() % 6 + 1;
				die2 = rand() % 6 + 1;
				die_total = die1 + die2;
				
				if(die_total == 7)
				{
					if(die_total == point_num)
					{
						cashOnHand = cashOnHand - yourBet;
						return 0;
					}
				}
				else if(die_total == point_num)
				{
						cashOnHand = cashOnHand + yourBet;
						return 1;
				}
			}

		}
	}
	return 0;
}
void crapsType::displayRoll(int die1, int die2)
{
		int die_total = die1 + die2;
		if (die_total == 7 || die_total == 11)
	{
		if(die_total == 7)
		{
				cout << "Die 1: " << die1;
				cout << " Die 2: " << die2;
				cout << " Sum: " << die_total;
				cout << " Seven Out" << endl;
				cout << "Won!" << endl;
		}
		else if(die_total == 11)
		{
				cout << "Die 1: " << die1;
				cout << " Die 2: " << die2;
				cout << " Sum: " << die_total;
				cout << " Yo-leven" << endl;
				cout << "Won!" << endl;

		}
	}
	else if (die_total == 2 || die_total == 3 || die_total == 12)
	{
		if(die_total == 2)
		{
				cout << "Die 1: " << die1;
				cout << " Die 2: " << die2;
				cout << " Sum: " << die_total;
				cout << " Snake Eyes" << endl;
				cout << "Lost!" << endl;
		}
		if(die_total == 3)
		{
				cout << "Die 1: " << die1;
				cout << "Die 2: " << die2;
				cout << "Sum: " << die_total;
				cout << " Ace Deuce" << endl;
				cout << "Lost!" << endl;
		}
		if(die_total == 12)
		{
				cout << "Die 1: " << die1;
				cout << " Die 2: " << die2;
				cout << " Sum: " << die_total;
				cout << " Box Cars" << endl;
				cout << "Lost!" << endl;
		}
		
	}
	else
	{
		int die_total = die1 + die2;
		int point_num = die_total;
		cout << "Die 1: " << die1 << " Die 2: ";
		cout << die2 << " Sum: " << die_total;
		
		if(die_total == 4)
		{
			if(die1 == 2 && die2 == 2)
			{
				cout << " Hard Four" << endl;
			}
			else
			{
				cout << " Easy Four" << endl;
			}
		}
		else if(die_total == 5)
			cout << " Fever Five" << endl;
			
		else if(die_total == 6)
		{
			if(die1 == 3 && die2 == 3)
			{
				cout << " Hard Six" << endl;
			}
			else
			{
				cout << " Easy Six" << endl;
			}
		}
		else if(die_total == 8)
		{
			if(die1 == 4 && die2 == 4)
			{
				cout << " Hard Eight" << endl;
			}
			else
			{
				cout << " Easy Eight" << endl;
			}
		}
		else if(die_total == 9)
			cout << " Nina" << endl;
			
		else if(die_total == 10)
		{
			if(die1 == 5 && die2 == 5)
			{
				cout << " Hard Ten" << endl;
			}
			else
			{
				cout << " Easy Ten" << endl;
			}
		}			
		cout << "Point: " << point_num << endl;
		
		//while(display)
		{

			int die1 = rand() % 6 + 1;
			int die2 = rand() % 6 + 1;
			int die_total = die1 + die2;

			if(die_total == 2)
			{
				cout << "Die 1: " << die1 << " Die 2: ";
				cout << die2 << " Sum: " << die_total;
				cout << " Snake Eyes" << endl;
			}
			else if(die_total == 3)
			{
				cout << "Die 1: " << die1 << " Die 2: ";
				cout << die2 << " Sum: " << die_total;			
				cout << " Ace Deuce" << endl;			
			}
			else if(die_total == 4)
			{
				cout << "Die 1: " << die1 << " Die 2: ";
				cout << die2 << " Sum: " << die_total;				
				if(die1 == 2 && die2 == 2)
				{
					cout << " Hard Four" << endl;
				}
				else
				{
					cout << " Easy Four" << endl;
				}
				if(die_total == point_num)
				{
					cout << "Won!" << endl;
				}
			}
			else if(die_total == 5)
			{
				cout << "Die 1: " << die1 << " Die 2: ";
				cout << die2 << " Sum: " << die_total;							
				cout << " Fever Five" << endl;
				if(die_total == point_num)
				{
					cout << "Won!" << endl;
				}
			}
			else if(die_total == 6)
			{
				cout << "Die 1: " << die1 << " Die 2: ";
				cout << die2 << " Sum: " << die_total;							
				if(die1 == 3 && die2 == 3)
				{
					cout << " Hard Six" << endl;
				}
				else
				{
					cout << " Easy Six" << endl;
				}
				if(die_total == point_num)
				{
					cout << "Won!" << endl;
				}
			}
			else if(die_total == 8)
			{
				cout << "Die 1: " << die1 << " Die 2: ";
				cout << die2 << " Sum: " << die_total;											
				if(die1 == 4 && die2 == 4)
				{
					cout << " Hard Eight" << endl;
				}
				else
				{
					cout << " Easy Eight" << endl;
				}
				if(die_total == point_num)
				{
					cout <<" Won!" << endl;
				}
			}
			else if(die_total == 9)
			{
				cout << "Die 1: " << die1 << " Die 2: ";
				cout << die2 << " Sum: " << die_total;											
				cout << " Nina" << endl;
				if(die_total == point_num)
				{

					cout << "Won!" << endl;
				}
			}
			else if(die_total == 10)
			{
				cout << "Die 1: " << die1 << " Die 2: ";
				cout << die2 << " Sum: " << die_total;							
				if(die1 == 5 && die2 == 5)
				{
					cout << " Hard Ten" << endl;
				}
				else
				{
					cout << " Easy Ten" << endl;
				}
				if(die_total == point_num)
				{
					cout << "Won!" << endl;
				}
			}
			else if(die_total == 11)
			{
				cout << "Die 1: " << die1 << " Die 2: ";
				cout << die2 << " Sum: " << die_total;							
				cout << " Yo-leven" << endl;
			}
			else if(die_total == 12)
			{
				cout << "Die 1: " << die1 << " Die 2: ";
				cout << die2 << " Sum: " << die_total;							
				cout << " Boxcars" << endl;
			}
			else if(die_total == 7)
			{
				cout << "Die 1: " << die1 << " Die 2: ";
				cout << die2 << " Sum: " << die_total;							
				cout << " Seven Out" << endl;
				cout << "Lost!" << endl;
			}
		}
}
}
