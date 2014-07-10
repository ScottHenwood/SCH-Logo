using namespace std;
#include "stdafx.h"
#include "string"
#include "xPiece.h"
#include "AbstractCommand.h"
#include "ControlCommand.h"
#include "IfCommand.h"

IfCommand::IfCommand(string condition, Piece *p): ControlCommand(condition, p), hasRun(false) { }
//______________________________________________
IfCommand::~IfCommand() { }
//______________________________________________
AbstractCommand* IfCommand::getNextCommand()
{
	if ((!hasRun) && checkCondition())
	{
		hasRun = true;
		return nestedCommand;
	}
	else
	{
		hasRun = false;
		return AbstractCommand::getNextCommand();
	}
}
//______________________________________________
string IfCommand::getDescrition()
{
	return "If: " + AbstractCommand::getName() + 
			" Nested | " + nestedCommand->getName();
}