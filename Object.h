#pragma once

#include "Position.h"
#include "include\GameObjectStruct.h"

class Object
{
public:
	Object();
	~Object();
	void virtual update() = 0;
	Position getPosition();
	Type getType();
	int virtual getVelocity() = 0;
	Direction virtual getDirection() = 0;
protected:
	Position currentPosition;
	Type sprite;
};

