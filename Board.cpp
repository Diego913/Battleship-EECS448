#include "Board.h"
#include <iostream>
#include <cmath>
Board::Board()
{
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			board[i][k] = '.';
		}
	}
	turn = 1;
	hitMarker = 0;
}


void Board::setShipNum(int num)
{
	m_shipNum = num;
}

int Board::getShipNum()
{
	return(m_shipNum);
}
void Board::changeTurn()
{
	if (turn == 1)
	{
		turn = 0;//Player 2 turn begins.
	}
	else
	{
		turn = 1;//Player 1 turn begins.
	}
}

void Board::placeShips(int x1Coor, int y1Coor, int x2Coor, int y2Coor)
{
	if ((x1Coor - 1 == x2Coor - 1) && (y1Coor - 1 == y2Coor - 1))
	{
		board[x1Coor - 1][y1Coor - 1] = 'S';
	}
	else if (x1Coor - 1 == x2Coor - 1)
	{
		if ((y1Coor - 1) < (y2Coor - 1))
		{
			for (int i = y1Coor - 1; i <= y2Coor - 1; i++)
			{
				board[x1Coor - 1][i] = 'S';
			}
		}
		else if ((y1Coor - 1) > (y2Coor - 1))
		{
			for (int i = y2Coor - 1; i <= y1Coor - 1; i++)
			{
				board[x1Coor - 1][i] = 'S';
			}
		}
	}
	else if (y1Coor - 1 == y2Coor - 1)
	{
		if ((x1Coor - 1) < (x2Coor - 1))
		{
			for (int i = x1Coor - 1; i <= x2Coor - 1; i++)
			{
				board[i][y1Coor - 1] = 'S';
			}
		}
		else if ((x2Coor - 1) < (x1Coor - 1))
		{
			for (int i = x2Coor - 1; i <= x1Coor - 1; i++)
			{
				board[i][y1Coor - 1] = 'S';
			}
		}
	}
}

bool Board::checkForShips(int x1, int y1, int x2, int y2, int CountShip)
{
	//Horizontal
	int crrent = m_shipNum - CountShip;

	if (x1 - 1 == x2 - 1)
	{
		int collen = abs(y2 - y1);

		for (int i = y1 - 1; i <= y2 - 1; i++)
		{
			if (board[x1 - 1][i] == 'S')
			{
				return false;
			}
			else if (collen != crrent)
			{
				return false;
			}
		}
		for (int i = y2 - 1; i <= y1 - 1; i++)
		{
			if (board[x1 - 1][i] == 'S')
			{
				return false;
			}
		}
	}
	//Vertical
	else if (y1 - 1 == y2 - 1)
	{
		int rowlen = abs(x2 - x1);

		for (int i = x1 - 1; i < x2 - 1; i++)
		{
			if (board[i][y1 - 1] == 'S')
			{
				return false;
			}
			else if (rowlen != crrent) 
			{
				return false;
			}
		}
		for (int i = x2 - 1; i < x1 - 1; i++)
		{
			if (board[i][y1 - 1] == 'S')
			{
				return false;
			}
		}
	}
	else if (x1 - 1 != x2 - 1 && y1 - 1 != y2 - 1)
	{
		return false;
	}
	return true;
}

void Board::attackShips()
{

}

bool Board::isSunk()
{
	return(0);
}

void Board::printBoard()
{
	std::cout << "     A B C D E F G H I J \n";
	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			std::cout << " ";
			std::cout << " 1| ";
		}
		else if (i == 1)
		{
			std::cout << " ";
			std::cout << " 2| ";
		}
		else if (i == 2)
		{
			std::cout << " ";
			std::cout << " 3| ";
		}
		else if (i == 3)
		{
			std::cout << " ";
			std::cout << " 4| ";
		}
		else if (i == 4)
		{
			std::cout << " ";
			std::cout << " 5| ";
		}
		else if (i == 5)
		{
			std::cout << " ";
			std::cout << " 6| ";
		}
		else if (i == 6)
		{
			std::cout << " ";
			std::cout << " 7| ";
		}
		else if (i == 7)
		{
			std::cout << " ";
			std::cout << " 8| ";
		}
		else if (i == 8)
		{
			std::cout << " ";
			std::cout << " 9| ";
		}
		else if (i == 9)
		{
			std::cout << " 10| ";
		}
		for (int k = 0; k < 10; k++)
		{
			std::cout << board[i][k];
			std::cout << " ";
		}
		std::cout << "\n";
	}
}

