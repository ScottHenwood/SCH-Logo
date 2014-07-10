using namespace std;
#include "stdafx.h"
#include "string"
#include "xPiece.h"
#include "AbstractCommand.h"
#include "ControlCommand.h"
#include "WhileCommand.h"

WhileCommand::WhileCommand(string condition, Piece *p): ControlCommand(condition, p) { }
//______________________________________________
WhileCommand::~WhileCommand() { }
//______________________________________________
AbstractCommand* WhileCommand::getNextCommand()
{
	if (checkCondition())
	{
		return nestedCommand;
	}
	else
	{
		return AbstractCommand::getNextCommand();
	}
}
//______________________________________________
string WhileCommand::getDescrition()
{
	return "While: " + AbstractCommand::getName() + 
			" Nested | " + nestedCommand->getName();
}