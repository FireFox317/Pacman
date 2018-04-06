#ifndef FRUIT_H
#define FRUIT_H

#include "../Object.h"

class Fruit :
	public Object
{
public:
	Fruit() = default;
	Fruit(Position pos);
	~Fruit();
	int getScore();
private:
	void update() override;
};


#endif // !FRUIT_H


