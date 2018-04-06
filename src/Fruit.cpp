#include "Objects/StaticObjects/Fruit.h"

#include <array>
#include <random>
#include <algorithm>

Fruit::Fruit(Position pos)
{
	currentPosition = pos;

	std::array<Type, 6> fruits = { CHERRY,STRAWBERRY, ORANGE, LEMON, APPEL, GRAPES };
	std::random_device r;
	std::default_random_engine generator(r());
	std::shuffle(fruits.begin(), fruits.end(), generator);
	sprite = fruits[0];
}


Fruit::~Fruit()
{
}

int Fruit::getScore()
{
	switch (sprite) {
	case CHERRY: return 100; break;
	case STRAWBERRY: return 300; break;
	case ORANGE: return 500; break;
	case LEMON: return 1000; break;
	case APPEL: return 700; break;
	case GRAPES: return 2000; break;
	}
}

void Fruit::update()
{
}
