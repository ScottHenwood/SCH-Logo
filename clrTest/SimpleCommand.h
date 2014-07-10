#ifndef SimpleCommandH
#define SimpleCommandH
using namespace std;
#include "string"
#include "AbstractCommand.h"
//____________________________________________
// A class for a simple command object which has only one part (the name).
class SimpleCommand : public AbstractCommand
{
public:
	SimpleCommand(string name);

	bool virtual Process(Piece *p);
	string virtual getDescrition();
};
#endif