using namespace std;
#include "stdafx.h"
#include "string"
#include "AbstractCommand.h"
#include "xPiece.h"
#include "CommandIterator.h"

CommandIterator::CommandIterator( AbstractCommand * startCommand ) 
								: currentCommand(startCommand) { }

CommandIterator::~CommandIterator() { }
//_______________________________________________
bool CommandIterator::hasNext()
{
	return currentCommand->hasNextCommand();
}
//_______________________________________________
void CommandIterator::Next()
{
	currentCommand = currentCommand->getNextCommand();;
}
//_______________________________________________
AbstractCommand* CommandIterator::getCommand() {	return currentCommand;	}
//_______________________________________________
AbstractCommand* CommandIterator::operator *() {	return getCommand();	}
//_______________________________________________
CommandIterator& CommandIterator::operator ++()
{
	Next();
	return *this;
}
//_______________________________________________
CommandIterator& CommandIterator::operator ++(int){	return ++*this;			}
