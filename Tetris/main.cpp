//Includes
#include <iostream>
#include <string>
#include <sstream>
#include "bits.h"
#include <windows.h>

//Namespace
using namespace std;

//Draw Board
string drawBoard()
{
	//Holder for screen
	stringstream boardBuilder;

	//Create board
	for (int y = 0; y < BOARDHEIGHT; y++)
	{
		for (int x = 0; x < BOARDWIDTH; x++)
		{
			//Build String
			boardBuilder << board[y][x] << " ";
			
			//Legacy cout
			//cout << board[y][x] << " ";
		}
		boardBuilder << "\n";

		//Legacy cout
		//cout << endl;
	}
	return boardBuilder.str();
}

//Draw Pieces
void drawPieces()
{
	//Print first block
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			cout << pieces[0][0][x][y] << " ";
		}
		cout << endl;
	}
}

//Main Method
int main()
{
	//Boolean for game over
	bool gameOver = false;

	//Main loop
	while (!gameOver)
	{
		//Clear Screen
		system("CLS");

		//Draw Board
		cout << drawBoard();

		//Wait for a second
		Sleep(100);
	}

	return 0;
}