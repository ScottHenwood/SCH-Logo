#ifndef WhileCommandH
#define WhileCommandH
using namespace std;
#include "string"
#include "xPiece.h"
#include "ControlCommand.h"
//____________________________________________
// A class for a while command object which has a condition (the name),
// and will continue as long as it is true.
class WhileCommand : public ControlCommand
{
public:
	WhileCommand(string condition, Piece *p);
	~WhileCommand();

	AbstractCommand virtual *getNextCommand();
	string virtual getDescrition();
};
#endif