#include "Dot.h"



Dot::Dot(Position pos)
{
	currentPosition = pos;
	sprite = DOT;
}


Dot::~Dot()
{
}

int Dot::getVelocity()
{
	return -1;
}

Direction Dot::getDirection()
{
	return UP;
}

void Dot::update()
{
}
