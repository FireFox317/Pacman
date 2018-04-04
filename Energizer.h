#pragma once
#include "Object.h"
class Energizer :
	public Object
{
public:
	Energizer(Position pos);
	~Energizer();
	int getScore();
private:
	void update() override;
	int score = 50;
};

