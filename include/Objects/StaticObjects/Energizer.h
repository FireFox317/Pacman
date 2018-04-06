#ifndef ENERGIZER_H
#define ENERGIZER_H

#include "../Object.h"

class Energizer :
	public Object
{
public:
	Energizer() = default;
	Energizer(Position pos);
	~Energizer();
	int getScore();
private:
	void update() override;
	int score = 50;
};


#endif // !ENERGIZER_H



