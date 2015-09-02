//Includes
#include <iostream>
#include <string>
#include <sstream>
#include "bits.h"
#include <windows.h>
#include <time.h>

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
		}
		boardBuilder << "\n";
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

	//Doubles for timing
	double timerStart = (clock() / CLOCKS_PER_SEC);
	double timerCurrent = timerStart;

	//Main loop
	while (!gameOver)
	{
		//Save current time
		timerCurrent = (clock() / CLOCKS_PER_SEC);

		//Check if screen needs refreshed
		if (timerCurrent > timerStart + 0.5)
		{
			//Clear screen
			system("CLS");

			//Draw Board
			cout << drawBoard();

			//Reset timerCurrent
			timerStart = (clock() / CLOCKS_PER_SEC);
		}
	}

	return 0;
}