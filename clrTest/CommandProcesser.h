#pragma once
#include "CommandIterator.h"
#include "CommandParser.h"
using namespace System;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
//____________________________________________
// Command processer for building and processing commands.
ref class CommandProcesser
{
public:
	CommandProcesser(void);
    CommandProcesser(Label ^backGroud, Label ^pControl);
	~CommandProcesser();
	
    void reset();
	void processCommand(AbstractCommand *ac, string &errorString);
	void checkCommand(AbstractCommand *ac, bool commandSuccess, string &errorString); 
	void reprintLines();
	bool runCommand(string &errorString);
	CommandIterator* buildCommands(TextBox ^commandTxt);
		
private:
    CommandIterator *cIt;
    Piece *pi;
    Control ^background;
    Control ^pieceControl;

    CommandParser ^parser;

    List<Point> pointList1;
	List<Point> pointList2;

    String ^builtString;
	AbstractCommand *headCommand;
};