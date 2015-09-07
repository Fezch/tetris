//Includes
#include <iostream>
#include <string>
#include <sstream>
#include "bits.h"
#include <windows.h>
#include <time.h>
#include <cstdlib>

//Namespace
using namespace std;

//Global Variables
int curType; //Current Type of Piece
int curRot; //Current Rotation of Piece
int curPosX; //Current X Position of Piece
int curPosY; //Current Y Position of Piece

//Get Board
string getBoard()
{
	//Holder for screen
	stringstream boardBuilder;

	//Create board
	for (int y = 0; y < BOARDHEIGHT; y++)
	{
		for (int x = 0; x < BOARDWIDTH; x++)
		{
			//Build String
			boardBuilder << initBoard[y][x] << " ";
		}
		boardBuilder << "\n";
	}

	//Return Board
	return boardBuilder.str();
}

//Get Piece
string getPiece(int type, int rotation)
{
	//Holder for Piece
	stringstream pieceBuilder;

	//Create Piece
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			pieceBuilder << pieces[type][rotation][x][y] << " ";
		}
		pieceBuilder << endl;
	}

	//Return Piece
	return pieceBuilder.str();
}

//Draws game board
void drawGame()
{
	//Holder for screen
	stringstream boardBuilder;

	//Create board
	for (int y = 0; y < BOARDHEIGHT; y++)
	{
		for (int x = 0; x < BOARDWIDTH; x++)
		{
			//Build String
			boardBuilder << gameBoard[y][x] << " ";
		}
		boardBuilder << "\n";
	}

	//Draw Board
	cout << boardBuilder.str();
}

//Updates game Board with Current piece
void updateGameBoard()
{
	//Copy saved board to game board
	for (int y = 0; y < BOARDHEIGHT; y++)
	{
		for (int x = 0; x < BOARDWIDTH; x++)
		{
			//Build saved board
			gameBoard[y][x] = savedBoard[y][x];
		}
	}

	//Add current piece to game board
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			gameBoard[y + curPosY][x + curPosX] = pieces[curType][curRot][x][y];
		}
	}
}

//Main Method
int main()
{
	//Boolean for game over
	bool gameOver = false;

	//Initialise random seed
	srand(time(NULL));

	//Randomise First Piece
	curType = rand() % 7;
	curRot = rand() % 4;
	curPosX = STARTX;
	curPosY = STARTY;

	//Save initial Board to saved board
	for (int y = 0; y < BOARDHEIGHT; y++)
	{
		for (int x = 0; x < BOARDWIDTH; x++)
		{
			//Build saved board
			savedBoard[y][x] = initBoard[y][x];
		}
	}

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
			//Update game board
			updateGameBoard();

			//Clear screen
			system("CLS");

			//Draw gameboard
			drawGame();

			//Reset timerCurrent
			timerStart = (clock() / CLOCKS_PER_SEC);
		}
	}

	return 0;
}