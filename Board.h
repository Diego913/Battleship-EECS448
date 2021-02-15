//change turn function
#include <iostream>

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
char board[10][10];
//char boardP1Ships[10][10];
//char boardP2Ships[10][10];
//char boardP1Attack[10][10];
//char boardP2Attack[10][10];
bool turn;
bool hitMarker;
int m_shipNum;
int shipsLeft;


public:
Board();
void setShipNum(int);
int getShipNum();
void changeTurn();
void placeShips(int,int,int,int);
void attackShips();
bool checkForShips(int,int,int,int,int);
bool hasWon();//Move this function to executive.
bool isSunk();
void printBoard();



};
#endif
