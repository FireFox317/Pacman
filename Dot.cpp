#include "Dot.h"



Dot::Dot(Position pos)
{
	currentPosition = pos;
	sprite = DOT;
}


Dot::~Dot()
{
}

int Dot::getScore()
{
	return score;
}

void Dot::update()
{
}
