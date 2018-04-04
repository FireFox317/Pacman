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
protected:
	Position currentPosition;
	Type sprite;
};

