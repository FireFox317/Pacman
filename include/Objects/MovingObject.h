#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "Object.h"
#include "../GameObjectStruct.h"
#include "../Utils/Map.h"


class MovingObject :
	public Object
{
public:
	MovingObject();
	~MovingObject();
	int getVelocity();
	Direction getDirection();
	void setDirection(Direction dir);
	void reset();
	int updateCount;
protected:
	Direction direction;
	int velocity;
	Map map;
	Position initialPosition;
};



#endif // !MOVINGOBJECT_H


