#include "Executive.h"
#include"Board.h"


Executive::Executive(int num)
{
	m_shipNum = num;
	P1Board1.setShipNum(num);
	P1Board1.setShipsVector(num);
}
// void Executive::displayP1()
// {
//
// }
void Executive::P1Place()
{
	char column = ' ';
	int row = 0;
	bool placing = true;
	int count = m_shipNum;

	while (placing)
	{
		P1Board1.printBoard();
		int c;
		bool check1x1 = 1;

		while ((c = getchar()) != '\n' && c != EOF);

		if (count == m_shipNum)//count=6
		{
			std::cout << "\n ----------------------------------------\n    This is player 1 turn     \n";
			std::cout << "\nLet's start with the 1x1 ship!\n";
			std::cout << "Player 1, What row would you like to place the 1x1 ship: ";
			row2 = row1 = inputNumber(1, 10);

			std::cout << "Player 1, What column would you like to place the 1x1 ship: ";
			col2 = col1 = inputAlphabet('A', 'J');
		}
		else 
		{
			std::cout<<"\n----------------------------------------\nThis is a 1x"<<(m_shipNum-count)+1<<" ship.\n";
			std::cout << "Player 1, What row would you like to place the front of the ship: ";
			row1 = inputNumber(1, 10);
			
			std::cout << "Player 1, What column would you like to place the front of the ship: ";
			col1 = inputAlphabet('A', 'J');

			std::cout << "Player 1, What row would you like to place the back of the ship: ";
			row2 = inputNumber(1, 10);

			std::cout << "Player 1, What column would you like to place the back of the ship: ";
			col2 = inputAlphabet('A', 'J');
		}

		std::cout << row1 << " " << col1 << "       " << row2 << " " << col2 << "\n";
		bool check1xN = P1Board1.checkForShips(row1, col1, row2, col2, count);
		
		if (check1xN == 0)
		{
			std::cout << "Invalid placement, please try again\n";
		}
		else
		{

			P1Board1.placeShips(row1, col1, row2, col2, m_shipNum - count);
			P1Board1.printBoard();
			std::cout << "\n\n\n";
			P1Board1.printShipsCoordinates();
			std::cout << "Here is the first row you selected: " << row1 << "\n";
			std::cout << "Here is the first column you selected: " << col1 << "\n\n";

			std::cout << "Here is the second row you selected: " << row2 << "\n";
			std::cout << "Here is the second column you selected: " << col2 << "\n";
			count--;
		}
		//6 5 4 3 2 1 
		if (count == 0)
		{
			placing = false;
		}
	}
}

/*void Executive::P2Place(int numofShips)
{
	m_shipNum = numofShips;
	char column = ' ';
	int row = 0;
	bool placing = 0;
	int count = numofShips;
	while (placing == 0)
	{
		P2Board2.printBoard();
		int c;
		bool check1x1 = 1;
		while ((c = getchar()) != '\n' && c != EOF);
		if (count == m_shipNum)//count=6
		{
			std::cout << "\n ----------------------------------------\n    This is player 2 turn     \n";
			std::cout << "\nLet's start with the 1x1 ship!\n";
			std::cout << "Player 2, What row would you like to place the 1x1 ship: ";
			row2 = row1 = inputNumber(1, 10);

			std::cout << "Player 2, What column would you like to place the 1x1 ship: ";
			col2 = col1 = inputAlphabet('A', 'J');
		}
		else
		{
			std::cout << "\n----------------------------------------\nThis is a 1x" << (m_shipNum - count) + 1 << " ship.\n";//count=(6-5)+1=2
			std::cout << "Player 2, What row would you like to place the front of the ship: ";
			row1 = inputNumber(1, 10);

			std::cout << "Player 2, What column would you like to place the front of the ship: ";
			col1 = inputAlphabet('A', 'J');

			std::cout << "Player 2, What row would you like to place the back of the ship: ";
			row2 = inputNumber(1, 10);

			std::cout << "Player 2, What column would you like to place the back of the ship: ";
			col2 = inputAlphabet('A', 'J');
		}
		//std::cout << row1 << " " << col1 << "       " << row2 << " " << col2 << "\n";
		bool check1xN = (P2Board2.checkForShips(row1, col1, row2, col2, count));
		if (check1xN == 0)
		{
			std::cout << "\nInvalid placement, please try again\n\n----------------------------------------\n";
		}
		else
		{

			P2Board2.placeShips(row1, col1, row2, col2);
			P2Board2.printBoard();
			std::cout << "Here is the first row you selected: " << row1 << "\n";
			std::cout << "Here is the first column you selected: " << col1 << "\n\n";

			std::cout << "Here is the second row you selected: " << row2 << "\n";
			std::cout << "Here is the second column you selected: " << col2 << "\n";
			std::cout << "\n----------------------------------------\n";

			count--;//count=5
		}
		if (count == 0)
		{
			placing = 1;
		}
	}
}*/

void Executive::P1Attack()
{

}

void Executive::P2Attack()
{

}

/*int Executive::convertCol(char col)
{
	int convertcol = 0;
	//Converting column into an int so we can use it to place ships
	if (col == 'A')
	{
		convertcol = 1;
	}
	else if (col == 'B')
	{
		convertcol = 2;
	}
	else if (col == 'C')
	{
		convertcol = 3;
	}
	else if (col == 'D')
	{
		convertcol = 4;
	}
	else if (col == 'E')
	{
		convertcol = 5;
	}
	else if (col == 'F')
	{
		convertcol = 6;
	}
	else if (col == 'G')
	{
		convertcol = 7;
	}
	else if (col == 'H')
	{
		convertcol = 8;
	}
	else if (col == 'I')
	{
		convertcol = 9;
	}
	else if (col == 'J')
	{
		convertcol = 10;
	}
	else
	{
		convertcol = 50;
	}
	return(convertcol);
}
*/

//Fix the row input.Deal with if input is not a number. 
int Executive::inputNumber(int begin, int end)
{
	int v;
	while (true) {
		if (std::cin >> v) {
			if (v >= begin && v <= end) {
				break;
			}
			else {
				std::cout << "The input range is not valid! please retry input!" << std::endl;
			}
		}
		else {
			std::cout << "input not a number! please retry input!" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}
	return v;
}

//I tried to Converting and range cheacker together
int Executive::inputAlphabet(char begin, char end) {
	char v;
	while (true) {
		if (std::cin >> v) {
			if (v >= begin && v <= end) {
				break;
			}
			else {
				std::cout << "The input range is not valid! please retry input!" << std::endl;
			}
		}
		else {
			std::cout << "input not a alphabet! please retry input!" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}
	return (v - begin) + 1;
}

