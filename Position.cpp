#include "Position.h"

Position::Position(int x, int y) : x(x), y(y)
{
}

void Position::SetPosition(int _x, int _y)
{
	x = _x;
	y = _y;
}

int Position::getX()
{
	return x;
}

int Position::getY()
{
	return y;
}
