using namespace std;
using namespace System::Collections::Generic;
#include "stdafx.h"
#include "AbstractCommand.h"
#include "SimpleCommand.h"
#include "SplitCommand.h"
#include "IfCommand.h"
#include "WhileCommand.h"
#include "ControlCommand.h"
#include "xPiece.h"
#include "CommandParser.h"

CommandParser::CommandParser(): piece(new Piece()) { }

CommandParser::CommandParser(Piece *p): piece(p) { }
CommandParser::~CommandParser() { clearCommands(); }
//_______________________________________________
AbstractCommand* CommandParser::parseCommand(String ^commandString, int row)
{
	string s;
	MarshalString(commandString, s);
	AbstractCommand *ac = NULL;
				
	if (commandString->Contains(" "))
	{
		int i = commandString->IndexOf(' ');
		string s2;
		MarshalString(commandString->Substring(i + 1), s2);
		if (commandString->StartsWith("WHILE") || commandString->StartsWith("IF"))
		{
			ControlCommand *cc;
			if (commandString->StartsWith("IF"))
				cc = new IfCommand(s2, piece);
			else
				cc = new WhileCommand(s2, piece);
			ac = cc;
			parseCommands(row + 1, cc)->setNextCommand(ac); 
		}
		else
		{
			int count = atoi(s2.c_str()); // number of times the command will repeat.
			MarshalString(commandString->Substring(0, i), s);
			ac = new SplitCommand(s, count);
		}
	}
	else
	{
		ac = new SimpleCommand(s);
	}
	return ac;
}
//_______________________________________________
AbstractCommand* CommandParser::parseCommands(array<String^, 1> ^c)
{
	if (aCommands) clearCommands();
	commands = c;

	aCommands = gcnew array<AbstractCommand*>(commands->Length + 1);
	//currentLine = 0;
	lineCount = 0;
	AbstractCommand *programCommand = new SimpleCommand("Program");
	AbstractCommand *pCommand = programCommand;
	int i = 0;
	while (i < commands->Length) 
	{
		String ^command = commands[i]->Trim();
		AbstractCommand *ac = parseCommand(command, i);
		if (i != lineCount)
			i = lineCount;
		aCommands[lineCount] = ac;

		pCommand->setNextCommand(ac);

		pCommand = ac;
		lineCount++;
		i++;
	}
	aCommands[aCommands->Length - 1] = programCommand;
	return programCommand;
}

//_______________________________________________
AbstractCommand* CommandParser::parseCommands(int startRow, ControlCommand *preCommand)
{
	int i = startRow;
	AbstractCommand *ac = NULL;
	AbstractCommand *pCommand = NULL;
	if (commands->Length > i)
	{
		String ^command = commands[i]->Trim();

		while (i < commands->Length && (!command->StartsWith("END"))) 
		{
			ac = parseCommand(command, i);
			if (i == startRow)
				preCommand->setNestedCommand(ac);
			else if (lineCount > 0)
				pCommand->setNextCommand(ac);

			if (i != lineCount)
				i = lineCount;
			aCommands[lineCount] = (ac);

			pCommand = ac;
			lineCount++;
			i++;
			command = (i < commands->Length ? commands[i] : "");
		}
	}	 
	return ac;
}
//_______________________________________________
void CommandParser::PrintCommands()
{
	for each (AbstractCommand *command in aCommands)
	{
		cout << command->getName() << endl;
	}
}
//_______________________________________________
void CommandParser::MarshalString ( String ^ s, string& os ) // FROM: http://msdn.microsoft.com/en-us/library/1b4az623.aspx
{
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}
//_______________________________________________
void CommandParser::clearCommands()
{
	for each (AbstractCommand* command in aCommands)
	{
		delete aCommands;
	}
	delete aCommands;
	delete commands;
}