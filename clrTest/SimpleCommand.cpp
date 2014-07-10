using namespace std;
#include "stdafx.h"
#include "string"
#include "xPiece.h"
#include "AbstractCommand.h"
#include "SimpleCommand.h"

SimpleCommand::SimpleCommand(string name): AbstractCommand(name) { }
//______________________________________________
bool SimpleCommand::Process(Piece *p)
{
	bool vaildCommand = true;
	string commandString = getName(); 
	if (commandString == "Forward" || commandString == "FW")
	{
		p->move();
	}
	else if (commandString == "TurnLeft" || commandString == "TL")
	{
		p->turnLeft();
	}
	else if (commandString == "PenUp" || commandString == "PU")
	{
		p->PenUp();
	}
	else if (commandString == "PenDown" || commandString == "PD")
	{
		p->PenDown();
	}
	else if (commandString == "Program" || commandString == "END") {}
	else
	{
		vaildCommand = false;
	}

	return vaildCommand;
}
//______________________________________________
string SimpleCommand::getDescrition()
{
	return "Simple: " + AbstractCommand::getName();
}