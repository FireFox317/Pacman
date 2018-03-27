#pragma once
#include "Object.h"
class Dot :
	public Object
{
public:
	Dot(Position pos);
	~Dot();
	int getVelocity() override;
	Direction getDirection() override;
private:
	void update() override;
};

