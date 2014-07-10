#ifndef ComplexCommandH
#define ComplexCommandH
using namespace std;
#include "string"
#include "xPiece.h"

class AbstractCommand
{
public:
	AbstractCommand(string name): commandName(name)
	{
		
	}

	void virtual Process(Piece *p) = 0;
	string getName(){ return commandName; };
protected:
	string commandName;
};

#endif