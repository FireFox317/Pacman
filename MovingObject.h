#pragma once

#include "Object.h"
#include "include\GameObjectStruct.h"
#include "Map.h"


class MovingObject :
	public Object
{
public:
	MovingObject();
	~MovingObject();
	int getVelocity();
	Direction getDirection();
	void setDirection(Direction dir);
protected:
	Direction direction;
	int velocity;
	Map map;
};

