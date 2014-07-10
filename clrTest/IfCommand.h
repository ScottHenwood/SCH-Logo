#ifndef IfCommandH
#define IfCommandH
using namespace std;
#include "string"
#include "xPiece.h"
#include "AbstractCommand.h"
#include "ControlCommand.h"
//____________________________________________
// A class for an If command object which has a condition (the name),
// and will only go through once if true.
class IfCommand : public ControlCommand
{
public:
	IfCommand(string condition, Piece *p);
	~IfCommand();

	AbstractCommand virtual *getNextCommand();
	string virtual getDescrition();
private:
	bool hasRun;
};

#endif