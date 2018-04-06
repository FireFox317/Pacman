#include "Objects/MovingObject.h"



MovingObject::MovingObject()
{
}


MovingObject::~MovingObject()
{
}

int MovingObject::getVelocity()
{
	return velocity;
}

Direction MovingObject::getDirection()
{
	return direction;
}


void MovingObject::setDirection(Direction dir)
{
	direction = dir;
}

void MovingObject::reset()
{
	currentPosition = initialPosition;
}

