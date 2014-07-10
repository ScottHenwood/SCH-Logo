#ifndef ControlCommandH
#define ControlCommandH
using namespace std;
#include "string"
#include "xPiece.h"
#include "AbstractCommand.h"
//____________________________________________
// An abstract control command class, base class for all control command objects.
// All control command objects have nested commands, the set nested function allows that to be set.
// it contains the condidtion checker used by the sub classes.
class ControlCommand : public AbstractCommand
{
public:
	~ControlCommand();

	bool virtual Process(Piece *p);
	void setNestedCommand(AbstractCommand *nCommand);
	bool virtual hasNextCommand();
private:
	Piece * piece;
	map<string, string> directionMap;
protected:
	ControlCommand(string condition, Piece *p);
	bool checkCondition();

	AbstractCommand *nestedCommand;
};
#endif