#pragma once
#include "MovingObject.h"
class Ghost :
	public MovingObject
{
public:
	Ghost(Position initialPosition, Map map, Type type);
	~Ghost();
	void moveRandom();
	void setScared(bool scared);
	bool getScared();
private:
	void update() override;
	bool scared = false;
	Type initialType;
	int timeout;
};

