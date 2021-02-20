#include<iostream>
#include<string>
#include"Board.h"
#include <vector>

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

class Executive
{
private:
	int row1, row2, col1, col2;
	Board P1Board1;
	Board P2Board2;
	Board P1AttackBoard;
	Board P2AttackBoard;

	bool player1Won = false;
	bool player2Won = false;
	int m_shipNum;
	// int convertCol(char col);
public:

	/**
	* Executive Class constructor, Initialize variables and functions
	*
	* @param int - The number of ships
	* @return None
	**/
	Executive(int num);

	/**
	* Print out a board that player can place their ships in order of 1X1, 1X2, 1X3 and ect.
	*
	* @param None
	* @return None
	**/
	void P1Place();
	void P2Place();

	/**
	* Player attack others ships in turns, update board to let player see if they attack or miss
	*
	* @return None
	**/
	void P1Attack();
	void P2Attack();

	/**
	*
	* Determine who is winner
	* @return Bool - True for win, false to continue
	**/
	bool P1Won();
	bool P2Won();

	/**
	* Takes in user input, it must a number or else user must enter new input.
	*
	* @param int - Beggining of valid input range
	* @param int - End valid input range
	* @return int - Returns valid user input
	**/
	int inputNumber(int begin, int end);
	int inputAlphabet(char begin, char end);
};
#endif
