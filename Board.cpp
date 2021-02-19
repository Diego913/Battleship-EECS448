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

void Board::setShipsVector(int num)
{
	for (int i = 0; i < num; i++)
		{
			shipsCoordinates.push_back({});
		}
}

void Board::printShipsCoordinates()
{
	for(int i = 0; i < shipsCoordinates.size(); i++)
	{
		for(int j = 0; j < shipsCoordinates[i].size(); j++)
		{
			std:: cout << shipsCoordinates[i][j].first << " " << shipsCoordinates[i][j].second << std::endl; 
		}
		std::cout << std::endl;
	}
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

void Board::placeShips(int x1Coor, int y1Coor, int x2Coor, int y2Coor, int shipSize)
{
	if ((x1Coor - 1 == x2Coor - 1) && (y1Coor - 1 == y2Coor - 1))
	{
		board[x1Coor - 1][y1Coor - 1] = 'S';
		shipsCoordinates[shipSize].push_back(std::make_pair(x1Coor-1,x2Coor-1));
	}
	else if (x1Coor - 1 == x2Coor - 1)
	{
		if ((y1Coor - 1) < (y2Coor - 1))
		{
			for (int i = y1Coor - 1; i <= y2Coor - 1; i++)
			{
				board[x1Coor - 1][i] = 'S';
				shipsCoordinates[shipSize].push_back(std::make_pair(x1Coor-1,i));
			}
		}
		else if ((y1Coor - 1) > (y2Coor - 1))
		{
			for (int i = y2Coor - 1; i <= y1Coor - 1; i++)
			{
				board[x1Coor - 1][i] = 'S';
				shipsCoordinates[shipSize].push_back(std::make_pair(x1Coor-1,i));
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
				shipsCoordinates[shipSize].push_back(std::make_pair(i,y1Coor));
			}
		}
		else if ((x2Coor - 1) < (x1Coor - 1))
		{
			for (int i = x2Coor - 1; i <= x1Coor - 1; i++)
			{
				board[i][y1Coor - 1] = 'S';
				shipsCoordinates[shipSize].push_back(std::make_pair(i,y1Coor));
			}
		}
	}
}

bool Board::checkForShips(int x1, int y1, int x2, int y2, int CountShip)
{
	//Horizontal
	int crrent = m_shipNum - CountShip;
	//makes sure ship size isn't longer than the size supposed to be placed
	if((abs(x1-x2)) > crrent || abs(y1-y2) > crrent)
	{
		return false;
	}

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
		if(i!=9)
		{
			std::cout << "  " << i+1 << "| ";
		}
		else
		{
			std::cout << " " << i+1 << "| ";  
		}
		
		for (int k = 0; k < 10; k++)
		{
			std::cout << board[i][k] << " ";
		}
		std::cout << "\n";
	}
}

