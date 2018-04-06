#ifndef DOT_H
#define DOT_H

#include "../Object.h"

class Dot :
	public Object
{
public:
	Dot() = default;
	Dot(Position pos);
	~Dot();
	int getScore();
private:
	void update() override;
	int score = 10;
};

#endif // !DOT_H



