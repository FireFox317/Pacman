#pragma once
#include "MovingObject.h"
class Ghost :
	public MovingObject
{
public:
	Ghost();
	~Ghost();
private:
	void update() override;
};

