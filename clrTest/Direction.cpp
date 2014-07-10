using namespace std;
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "Direction.h"

Direction& operator ++(Direction& d)
{
	switch (d)
	{
		case UP:
			d = LEFT;
			break;
		case LEFT:
			d = DOWN;
			break;
		case DOWN:
			d = RIGHT;
			break;
		case RIGHT:
			d = UP;
			break;
		default:
			d = UP;
			break;
	}
	return d;
}
//_______________________________________________
Direction operator ++(Direction& d, int)
{
	Direction orDirection = d;
	++d;
	return orDirection;
}
//_______________________________________________
char& operator >>(Direction& d, char& marker)
{
	switch (d)
	{
		case UP:
			marker = '^';
			break;
		case LEFT:
			marker = '<';
			break;
		case DOWN:
			marker = '!';
			break;
		case RIGHT:
			marker = '>';
			break;
		default:
			d = UP;
			marker = '?';
			break;
	}
	return marker;
}