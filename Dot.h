#pragma once
#include "Object.h"
class Dot :
	public Object
{
public:
	Dot(Position pos);
	~Dot();
	int getScore();
private:
	void update() override;
	int score = 10;
};

