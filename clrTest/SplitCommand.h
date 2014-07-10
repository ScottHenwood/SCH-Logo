#ifndef SplitCommandH
#define SplitCommandH
using namespace std;
#include "string"
#include "AbstractCommand.h"
//____________________________________________
// A class for a split command object which has two parts: 
// the name, and the number of times it will exacute.
class SplitCommand : public AbstractCommand
{
public:
	SplitCommand(string name, int number);

	bool virtual Process(Piece *p);
	string virtual getDescrition();
private:
	int doNum;
};
#endif