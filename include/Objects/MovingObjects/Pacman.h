#ifndef PACMAN_H
#define PACMAN_H

#include "../MovingObject.h"

class Pacman :
	public MovingObject
{
public:
	Pacman(Position initialPosition, Map map);
	~Pacman();
private:
	void update() override;
};

#endif // !PACMAN_H



