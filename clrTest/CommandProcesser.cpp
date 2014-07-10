using namespace System;
using namespace System::Collections;
using namespace System::Drawing;
#include "stdafx.h"
#include "CommandProcesser.h"
#include "CommandIterator.h"

CommandProcesser::CommandProcesser(void)
{
    pi = new Piece;
    parser = gcnew CommandParser(pi);
}
//_______________________________________________
CommandProcesser::CommandProcesser(Label ^backGround, Label ^pControl)
	                              : background(backGround), pieceControl(pControl) 
{
    pi = new Piece;
    parser = gcnew CommandParser(pi);
}

CommandProcesser::~CommandProcesser()
{
	delete pi;
    delete parser;
}
//_______________________________________________
void CommandProcesser::reset()
{
	delete pi;
    delete parser;
	pi = new Piece;
    parser = gcnew CommandParser(pi);
}
//_______________________________________________
void CommandProcesser::processCommand(AbstractCommand *ac, string &errorString)
{
	bool penDown = pi->penIsDown();
	if (penDown)
		pointList1.Add(pi->getCurrectLocation());
	cout << "Exacuting: " << ac->getName() << endl;
	bool commandSuccess = ac->Process(pi);
	checkCommand(ac, commandSuccess, errorString);

	Point p2 = pi->getCurrectLocation();
	if (penDown)
		pointList2.Add(p2);
	p2.Offset(0, 24);
	pieceControl->Location = p2;
				
	pieceControl->Text = gcnew String(pi->getDirectionMarker().c_str());
	reprintLines();
}
//_______________________________________________
void CommandProcesser::checkCommand(AbstractCommand *ac, bool commandSuccess, string &errorString)
{
	if (!commandSuccess)
	{
		errorString += " | " + ac->getName() + " Not vaild";
	}
}
//_______________________________________________			 
void CommandProcesser::reprintLines()
{
	Graphics ^g = background->CreateGraphics(); //this->CreateGraphics();
	Pen ^p = gcnew Pen(Color::Red, 1);
	for (int i = 0; i < pointList1.Count; i++)
	{	 
		g->DrawLine(p, pointList1[i], pointList2[i]);
	}
	delete p;
}
//_______________________________________________			 
bool CommandProcesser::runCommand(string &errorString)
{
	if (**cIt != NULL)
	{
		processCommand(**cIt, errorString);
		++*cIt;
	}

	return (**cIt != NULL);
}	 
//_______________________________________________
CommandIterator* CommandProcesser::buildCommands(TextBox ^commandTxt)
{
	if (String::Compare(builtString, commandTxt->Text) != 0)
	{
		array<String^, 1> ^commands = commandTxt->Lines;
		headCommand = parser->parseCommands(commands);
				
		Console::WriteLine("commands built");
		builtString = commandTxt->Text;
	}
		cIt = new CommandIterator(headCommand);
	return cIt;
}