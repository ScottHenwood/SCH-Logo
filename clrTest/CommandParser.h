#pragma once
#include "AbstractCommand.h"
#include "ControlCommand.h"
#include "xPiece.h"
using namespace std;
using namespace System;
using namespace System::Collections::Generic;
//____________________________________________
// Command parser for taking an array of strings, 
// and creating a linked list of commands.
ref class CommandParser
{
public:
	CommandParser(Piece *p);
	~CommandParser();

	AbstractCommand* parseCommand(String ^commandString, int row);
	AbstractCommand *parseCommands(array<String^, 1> ^c);
	AbstractCommand *parseCommands(int startRow, ControlCommand *preCommand);
	void PrintCommands();

private:
	int lineCount;
	array<AbstractCommand*> ^aCommands;
	array<String^, 1> ^commands;
	Piece *piece;

	CommandParser();
	void MarshalString ( String ^ s, string& os ); // FROM: http://msdn.microsoft.com/en-us/library/1b4az623.aspx
	void clearCommands();
};
