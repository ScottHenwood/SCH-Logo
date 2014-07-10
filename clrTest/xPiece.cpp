using namespace std;
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "string"
#include "map"
#include "Direction.h"
#include "xPiece.h"
using namespace System::Drawing;

Piece::Piece() : direction(DOWN), penDown(true)
{
	Point l(50, 50);
	location = l;
}
//______________________________________________
void Piece::move()
{
	switch (direction)
	{
	case UP:
		location.Offset(0, -1);
		break;
	case LEFT:
		location.Offset(-1, 0);
		break;
	case DOWN:
		location.Offset(0, 1);
		break;
	case RIGHT:
		location.Offset(1, 0);
		break;
	default:
		break;
	} 
}
//______________________________________________
Point Piece::getCurrectLocation()
{
	return location;
}
//______________________________________________
bool Piece::penIsDown()
{
	return penDown;
}
//______________________________________________
void Piece::turnLeft()
{
	++direction;
}
//______________________________________________
string Piece::getDirectionMarker()
{
	char marker = ' ';
	direction >> marker;
			
	string s = " ";
	s[0] = marker;
	return s;
}
//______________________________________________
void Piece::PenUp()
{
	penDown = false;
}
//______________________________________________
void Piece::PenDown()
{
	penDown = true;
}