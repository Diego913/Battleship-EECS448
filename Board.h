//change turn function
#include <iostream>

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
char boardP1Ships[10][10];
char boardP2Ships[10][10];
char boardP1Attack[10][10];
char boardP2Attack[10][10];
bool turn;
bool hitMarker;
int m_shipNum;
int shipsLeft;


public:

Board(int num);
void changeTurn();
void placeShips(char row,char col);
void attackShips();
bool hasWon();//Move this function to executive. 
bool isSunk();
void printBoard();



};
#endif
