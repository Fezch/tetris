//Declaring Constants
const unsigned char BLOCK = 254; //Ascii code for a block
const unsigned char FREE = 0;    //Ascii code for null
const int BOARDWIDTH = 12;       //Board width
const int BOARDHEIGHT = 21;      //Board height
const int STARTX = 2;            //Start x position for pieces
const int STARTY = 0;            //Start y position for pieces

//Creating the Boards
unsigned char gameBoard[BOARDHEIGHT][BOARDWIDTH]; //For drawing with a temp piece
unsigned char savedBoard[BOARDHEIGHT][BOARDWIDTH]; //For collided blocks
unsigned char initBoard[BOARDHEIGHT][BOARDWIDTH] =
{
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, BLOCK },
	{ BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK }
};

//Creating the Pieces
unsigned char pieces[7 /* type */][4 /* rotation */][5 /* horizontal blocks */][5 /* vertical blocks */] =
{
	// Square
	{
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		}
	},

		// |
	{
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, BLOCK, BLOCK, BLOCK, BLOCK },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ BLOCK, BLOCK, BLOCK, BLOCK, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		}
	},
		// L
	{
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, BLOCK, BLOCK, BLOCK, FREE },
			{ FREE, BLOCK, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, BLOCK, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, BLOCK, FREE },
			{ FREE, BLOCK, BLOCK, BLOCK, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		}
	},
		// J
	{
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, BLOCK, BLOCK, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, BLOCK, FREE, FREE, FREE },
			{ FREE, BLOCK, BLOCK, BLOCK, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, BLOCK, BLOCK, BLOCK, FREE },
			{ FREE, FREE, FREE, BLOCK, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		}
	},
		// N
	{
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, BLOCK, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, BLOCK, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, BLOCK, BLOCK, FREE, FREE },
			{ FREE, BLOCK, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, BLOCK, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		}
	},
		// N mirrored
	{
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, FREE, BLOCK, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, BLOCK, BLOCK, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, BLOCK, FREE, FREE, FREE },
			{ FREE, BLOCK, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, BLOCK, BLOCK, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		}
	},
		// T
	{
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, BLOCK, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, BLOCK, BLOCK, BLOCK, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, BLOCK, BLOCK, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		},
		{
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, BLOCK, FREE, FREE },
			{ FREE, BLOCK, BLOCK, BLOCK, FREE },
			{ FREE, FREE, FREE, FREE, FREE },
			{ FREE, FREE, FREE, FREE, FREE }
		}
	}
};