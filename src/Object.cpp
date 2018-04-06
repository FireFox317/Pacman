#include "Objects/Object.h"



Object::Object()
{
}


Object::~Object()
{
}

Position Object::getPosition()
{
	return currentPosition;
}

Type Object::getType()
{
	return sprite;
}
