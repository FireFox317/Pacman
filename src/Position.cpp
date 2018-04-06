#include "Utils/Position.h"

Position::Position(int x, int y) : x(x), y(y)
{
}

void Position::setX(int _x)
{
	x = _x;
}


void Position::setY(int _y)
{
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

bool Position::operator==(const Position & pos)
{
	return (this->x == pos.x && this->y == pos.y);
}
