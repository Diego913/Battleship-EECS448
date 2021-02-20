//change turn function
#include <iostream>
#include <vector>

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
//char board[10][10];
//char boardP1Ships[10][10];
//char boardP2Ships[10][10];
//char boardP1Attack[10][10];
//char boardP2Attack[10][10];
bool turn;
bool hitMarker;
int m_shipNum;
int shipsLeft;
std::vector<std::vector<std::pair<int,int>>> shipsCoordinates;


public:
char board[10][10];

/**
* Inlitialize a blank board and variables
*
* @param int - None
* @return int - None
**/
Board();

/**
* Set the number of ships
*
* @param int - The player input of ships number
* @return int - None
**/
void setShipNum(int);

/**
* get the number of ships
*
* @param int - None
* @return int - The number of ships
**/
int getShipNum();

/**
* get how many number of ship left
*
* @param int - None
* @return int - The number of the ships that still left
**/
int getShipsLeft();

/**
* Change player turns
*
* @param int - None
* @return int - None
**/
void changeTurn();

/**
* Change player turns
*
* @param int - None
* @return int - None
**/
void placeShips(int,int,int,int,int);
bool attackShips(int,int);
char checkCoordinates(int, int);
void update(int,int,char c);
void setShipsLeft(int);
void sinkShip();
bool checkForShips(int,int,int,int,int);
void setShipsVector(int num);
void printShipsCoordinates();
bool hasWon();//Move this function to executive.
bool isSunk(int,int);
void printBoard();



};
#endif
