#pragma once
#include "MovingObject.h"
class Pacman :
	public MovingObject
{
public:
	Pacman(Position initialPosition, Map map);
	~Pacman();
private:
	void update() override;
};

