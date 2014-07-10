#ifndef AbstractCommandH
#define AbstractCommandH
using namespace std;
#include "string"
#include "xPiece.h"
//____________________________________________
// An abstract command class, base class for all command objects
// The command objects can process themselves, and give the next command when requested.
class AbstractCommand
{
public:
	AbstractCommand(string name);

	bool virtual Process(Piece *p) = 0;
	string virtual getName();
	string virtual getNextDescrition();
	string virtual getDescrition();// { return ""; } // = 0;
	AbstractCommand virtual *getNextCommand();
	void setNextCommand( AbstractCommand *nCommand );
	bool virtual hasNextCommand();

protected:
	string commandName;
	AbstractCommand *nextCommand;
};

#endif