using namespace std;
#include "stdafx.h"
#include "string"
#include "xPiece.h"
#include "AbstractCommand.h"
#include "ControlCommand.h"

ControlCommand::~ControlCommand() { }
//______________________________________________
bool ControlCommand::Process(Piece *p) { return true; }
//______________________________________________
void ControlCommand::setNestedCommand(AbstractCommand *nCommand) 
{ 
	nestedCommand = nCommand;
}
//______________________________________________
bool ControlCommand::hasNextCommand()
{
	return (nextCommand != NULL || nestedCommand != NULL);
}
//______________________________________________
ControlCommand::ControlCommand(string condition, Piece *p): AbstractCommand(condition), piece(p), nestedCommand(NULL)
{
	directionMap["^"] = "FacingUp";
	directionMap["<"] = "FacingLeft";
	directionMap["!"] = "FacingDown";
	directionMap[">"] = "FacingRight";
}
//______________________________________________
bool ControlCommand::checkCondition()
{
	if (0 == directionMap[piece->getDirectionMarker()].compare(AbstractCommand::getName()))
	{
		return true;
	}
	else
		return false;
}