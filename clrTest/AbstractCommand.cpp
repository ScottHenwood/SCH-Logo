using namespace std;
#include "stdafx.h"
#include "string"
#include "xPiece.h"
#include "AbstractCommand.h"

AbstractCommand::AbstractCommand(string name): commandName(name)
{
	nextCommand = NULL;
}
//______________________________________________
string AbstractCommand::getName() 
{ 
	return commandName; 
}
//______________________________________________
string AbstractCommand::getNextDescrition()
{
	if (nextCommand == NULL)
	{
		return " Next: NULL"; 
	}
	else
		return " Next | " + getNextCommand()->getName(); 
}
string AbstractCommand::getDescrition() { return ""; } // = 0;
//______________________________________________
void AbstractCommand::setNextCommand( AbstractCommand *nCommand )
{
	nextCommand = nCommand;
}
//______________________________________________
AbstractCommand* AbstractCommand::getNextCommand()
{
	return nextCommand;
}
//______________________________________________
bool AbstractCommand::hasNextCommand()
{
	return (nextCommand != NULL);
}