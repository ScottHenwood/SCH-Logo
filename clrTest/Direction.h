#ifndef DirectionH
#define DirectionH
using namespace std;
#include <iostream>
#include <conio.h>
//____________________________________________
// An enum to represent the state of the direction. 
// With overloaded operator for turning. 
enum Direction 
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};

ostream& operator <<(ostream& os, Direction& d);
Direction& operator ++(Direction& d);
Direction operator ++(Direction& d, int);
char& operator >>(Direction& d, char& marker);

#endif