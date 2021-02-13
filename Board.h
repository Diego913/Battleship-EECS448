//change turn function
#include <iostream>

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
char board[10][10];
bool turn;
bool hitMarker;

public:

Board();
void changeTurn();
void placeShips();
void attackShips();
bool isSunk();
void printBoard();



};
#endif
