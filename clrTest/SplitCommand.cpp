using namespace std;
#include "stdafx.h"
#include "string"
#include "xPiece.h"
#include "AbstractCommand.h"
#include "SplitCommand.h"

SplitCommand::SplitCommand(string name, int number): AbstractCommand(name), doNum(number) { }
//______________________________________________
bool SplitCommand::Process(Piece *p)
{
	bool vaildCommand = true;
	string commandString = getName();
	if (commandString == "Forward" || commandString == "FW")
	{
		for (int i = 0; i < doNum; i++)
		{
			p->move();
		}
	}
	else
		vaildCommand = false;

	return vaildCommand;
}
//______________________________________________
string SplitCommand::getDescrition()
{
	return "Split: " + AbstractCommand::getName();
}