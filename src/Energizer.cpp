#include "Objects/StaticObjects/Energizer.h"

Energizer::Energizer(Position pos)
{
	currentPosition = pos;
	sprite = ENERGIZER;
}


Energizer::~Energizer()
{
}

void Energizer::update()
{
}

int Energizer::getScore() {
	return score;
}
