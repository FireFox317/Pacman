#ifndef GHOST_H
#define GHOST_H

#include "../MovingObject.h"

class Ghost :
	public MovingObject
{
public:
	Ghost() = default;
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



#endif // !GHOST_H

