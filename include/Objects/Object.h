#ifndef OBJECT_H
#define OBJECT_H

#include "../Utils/Position.h"
#include "../GameObjectStruct.h"

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


#endif // !OBJECT_H



