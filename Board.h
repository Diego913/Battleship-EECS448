//change turn function
#include <iostream>
#include <vector>

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:

	bool turn;
	bool hitMarker;
	int m_shipNum;
	int shipsLeft;
	std::vector<std::vector<std::pair<int, int>>> shipsCoordinates;


public:

	char board[10][10];

	/**
	* Inlitialize a blank board and variables
	*
	**/
	Board();

	/**
	* Set the number of ships
	*
	* @param int - The number of ships get from getShipsNum function
	* @return int - None
	**/
	void setShipNum(int);

	/**
	* get the number of ships
	*
	* @return int - The number of ships
	**/
	int getShipNum();

	/**
	* get how many number of ship left
	*
	* @return The number of the ships that still left
	**/
	int getShipsLeft();

	/**
	* Change player turns
	*
	* @return None
	**/
	void changeTurn();

	/**
	*Placing ship at the loction that player want, and also make sure it will not over size
	*
	* @param int - Take in the row1 coordinate
	* @param int - Take in the col1 coordinate
	* @param int - Take in the row2 coordinate
	* @param int - Take in the col2 coordinateand
	* @param int - Take in the ship size
	* @return None
	**/
	void placeShips(int, int, int, int, int);

	//bool attackShips(int,int);

	/**
	*Check if player hit or miss in the entered location
	*
	* @param int - Take in the row coordinate
	* @param int - Take in the col coordinate
	* @return Char- Return 'M' shows Missed, return 'H' shows hitted
	**/
	char checkCoordinates(int, int);

	/**
	*Update the current attack result to board
	*
	* @param int - Take in the row coordinate
	* @param int - Take in the col coordinate
	* @param Char - Char to show the attack is miss or hit
	* @return None
	**/
	void update(int, int, char c);

	/**
	*Set the number of left ships
	*
	* @param int - number of left ships getting from getShipsLeft function
	* @return None
	**/
	void setShipsLeft(int);

	/**
	*Help count the number of left ship. Once player sink a ship, the ship left number -1.
	*
	* @return None
	**/
	void sinkShip();

	/**
	*Check if the ship placement is valid
	*
	* @param int - Take in the row1 coordinate
	* @param int - Take in the col1 coordinate
	* @param int - Take in the row2 coordinate
	* @param int - Take in the col2 coordinateand
	* @param int - Take in the number of ships
	* @return Bool - True for valid, false for invalid
	**/
	bool checkForShips(int, int, int, int, int);

	/**
	*Initialize a 2D vector
	*
	* @param int - Take in the number of ships
	* @return None
	**/
	void setShipsVector(int num);

	/**
	*This is a test function we used to see if the coordinate works well
	*
	* @return None
	**/
	void printShipsCoordinates();

	/**
	*Check if player's attack sunk a ship
	*
	* @param int - Row coordinate
	* @param int - Col coordinate
	* @return Bool - True for sunk, false for not missed
	**/
	bool isSunk(int, int);

	/**
	*Print out the board with
	*
	* @param int - Row coordinate
	* @param int - Col coordinate
	* @return Bool - True for sunk, false for not missed
	**/
	void printBoard();
};
#endif
