#ifndef CommandH
#define CommandH
using namespace std;
#include <iostream>
#include <conio.h>
#include "string"
#include "xPiece.h"

class Command
{
public:
	Command(Piece *p) : piece(p)
	{

	}

	~Command()
	{ // it should not need to delete piece.
	}

	void Process(string commandString)
	{
		int count = 1;
		int i = commandString.find(' '); // Improve design.
		if(i != string::npos)
		{
			string s2 = commandString.substr(i + 1);
			count = atoi(s2.c_str());
			string s1 = commandString.substr(0, i);
			//cout << s1 << '|' << s2 << '|' << count << endl;
			commandString = s1;
		}

		if (commandString == "Forward" || commandString == "FW")
		{
			for (int i = 0; i < count; i++)
			{
				piece->move();
				//cout << "Move: " << i << '|' << count << endl;
			}
		}
		else if (commandString == "TurnLeft" || commandString == "TL")
		{
			piece->turnLeft();
		}
		else if (commandString == "PenUp" || commandString == "PU")
		{
			piece->PenUp();
		}
		else if (commandString == "PenDown" || commandString == "PD")
		{
			piece->PenDown();
		}
	}

private:
	
	Piece *piece;
};




#endif