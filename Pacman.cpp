#include "Pacman.h"



Pacman::Pacman(Position initialPostion, Map _map) {
	currentPosition = initialPostion;
	sprite = PACMAN;
	direction = UP;
	velocity = 2;
	map = _map;
}


Pacman::~Pacman()
{
}

void Pacman::update()
{
	if (direction == LEFT && !map.checkWall(currentPosition, LEFT)) {
		currentPosition.setX(currentPosition.getX() - 1);	
	}
	else if (direction == RIGHT && !map.checkWall(currentPosition, RIGHT)) {
		currentPosition.setX(currentPosition.getX() + 1);
	}
	else if (direction == UP && !map.checkWall(currentPosition, UP)) {
		currentPosition.setY(currentPosition.getY() - 1);
	}
	else if (direction == DOWN && !map.checkWall(currentPosition, DOWN)) {
		currentPosition.setY(currentPosition.getY() + 1);
	}
}
