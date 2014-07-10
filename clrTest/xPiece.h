#ifndef xPieceH
#define xPieceH
using namespace std;
#include <iostream>
#include <conio.h>
#include "string"
#include "map"
#include "Direction.h"
using namespace System::Drawing;

class Piece
{
	public:
		Piece();

		void move();
		Point getCurrectLocation();
		bool penIsDown();
		void turnLeft();
		string getDirectionMarker();
		void PenUp();
		void PenDown();
		
	private:
		Point location;
		Direction direction;
		bool penDown;
};
#endif