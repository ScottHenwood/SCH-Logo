#ifndef CommandIteratorH
#define CommandIteratorH
using namespace std;
#include "string"
#include "AbstractCommand.h"
#include "xPiece.h"
//____________________________________________
// Command iterator for iterating through the commands, using the links.
class CommandIterator
{
public:
	CommandIterator( AbstractCommand * startCommand );
	~CommandIterator();
	
	bool hasNext();
	void Next();
	AbstractCommand* getCommand();
	CommandIterator& operator ++();
	CommandIterator& operator ++(int);
	AbstractCommand* operator *();
	
private:
	AbstractCommand *currentCommand;
};
#endif