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
int oldPosX; //Old X Position of Piece
int oldPosY; //Old Y Position of Piece
bool lockKeyL = false; //Left Key Lock
bool lockKeyR = false; //Right Key Lock
bool lockKeyD = false; //Down Key Lock
bool lockKeyZ = false; //Z Key Lock
bool lockKeyX = false; //X Key Lock

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
			//Only copy BLOCKs
			if (pieces[curType][curRot][x][y] == BLOCK)
			{
				gameBoard[y + curPosY][x + curPosX] = pieces[curType][curRot][x][y];
			}
		}
	}
}

//Returns true if current piece has hit the bottom
bool checkForBottom()
{
	//Int for checking
	int bottomLine = 0;

	//Check through piece array and find the bottom most block
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			//If there is a block on this line
			if (pieces[curType][curRot][x][y] == BLOCK)
			{
				//Update bottomLine
				bottomLine = y;
			}
		}
	}

	//Check if piece has dropped below board
	if (curPosY + bottomLine >= BOARDHEIGHT - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Returns true if current piece has collided with a placed block
bool checkForBlock()
{
	return false;
}

//Returns true if current piece has gone off the side
bool checkForSide()
{
	return false;
}

//Refreshes Screen
void refreshScreen()
{
	//Update game board
	updateGameBoard();

	//Clear screen
	system("CLS");

	//Draw gameboard
	drawGame();
}

//Checks for keyboard input
void checkForInput()
{
	//If Left key has been pushed
	if (GetAsyncKeyState(VK_LEFT))
	{
		//If key has not been locked
		if (!lockKeyL)
		{
			curPosX--;
			lockKeyL = true;
			refreshScreen();
		}
	}
	else //Key had already been locked
	{
		//Reset lock
		lockKeyL = false;
	}

	//If Right key has been pushed
	if (GetAsyncKeyState(VK_RIGHT))
	{
		//If key has not been locked
		if (!lockKeyR)
		{
			curPosX++;
			lockKeyR = true;
			refreshScreen();
		}
	}
	else //Key had already been locked
	{
		//Reset lock
		lockKeyR = false;
	}

	//If Down key is pushed
	if (GetAsyncKeyState(VK_DOWN))
	{
		//If key has not been locked
		if (!lockKeyD)
		{
			curPosY++;
			lockKeyD = true;
			refreshScreen();
		}
	}
	else //Key had already been locked
	{
		//Reset lock
		lockKeyD = false;
	}

	//If Z key is pushed
	if (GetAsyncKeyState(0x5A))
	{
		//If key has not been locked
		if (!lockKeyZ)
		{
			curRot = (curRot + 1) % 4; //Update rotation
			lockKeyZ = true;
			refreshScreen();
		}
	}
	else //Key had already been locked
	{
		//Reset lock
		lockKeyZ = false;
	}

	//If X key is pushed
	if (GetAsyncKeyState(0x58))
	{
		//If key has not been locked
		if (!lockKeyX)
		{
			curRot = (curRot - 1) % 4; //Update rotation
			lockKeyX = true;
			refreshScreen();
		}
	}
	else //Key had already been locked
	{
		//Reset lock
		lockKeyX = false;
	}
}

//Saves game array to saved array
void gameToSaved()
{
	for (int y = 0; y < BOARDHEIGHT; y++)
	{
		for (int x = 0; x < BOARDWIDTH; x++)
		{
			//Build saved board
			savedBoard[y][x] = gameBoard[y][x];
		}
	}
}

//Resets piece position and gets a new piece
void resetPiece()
{
	//Initialise random seed
	srand(time(NULL));

	//Randomise First Piece
	curType = rand() % 7;
	curRot = rand() % 4;

	//Reset Position
	curPosX = STARTX;
	curPosY = STARTY;
}

//Main Method
int main()
{
	//Boolean for game over
	bool gameOver = false;

	resetPiece();

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
		//Check for Input
		checkForInput();

		//Save current time
		timerCurrent = (clock() / CLOCKS_PER_SEC);

		//Check if screen needs refreshed
		if (timerCurrent > timerStart + 0.5)
		{
			//Save old position
			oldPosX = curPosX;
			oldPosY = curPosY;

			//Move piece down
			curPosY++;

			//If current block is about to collide with another block
			if (checkForBlock())
			{
				//Move block back to old position
				curPosX = oldPosX;
				curPosY = oldPosY;

				//Save game array to saved array
			}
			//If current block is about to collide with the bottom
			if (checkForBottom())
			{
				//Move block back to old position
				curPosX = oldPosX;
				curPosY = oldPosY;

				//Save game array to saved array
				gameToSaved();

				//Reset block position, get new block
				resetPiece();
			}
			//If current block is about to collide with the side
			if (checkForSide())
			{
				//Find out which side
				//Move block in opposite direction
				//DO not save game array to saved array
			}
			//Check for collisions, if true then move piece up, save gameboard to saved board, get new peice
			//Else just draw gameboard

			//Resfresh Screen
			refreshScreen();

			//Reset timerCurrent
			timerStart = (clock() / CLOCKS_PER_SEC);
		}
	}

	return 0;
}