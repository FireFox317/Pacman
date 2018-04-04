#include "Pacman.h"



Pacman::Pacman(Position _initialPosition, Map _map) {
	currentPosition = _initialPosition;
	initialPosition = _initialPosition;
	sprite = PACMAN;
	direction = UP;
	velocity = 10;
	map = _map;
}


Pacman::~Pacman()
{
}

void Pacman::update()
{
	if (map.isOnEdge(currentPosition, direction)) {
		switch (direction) {
		case LEFT: currentPosition.setX(map.getSizeX() - 1);
			break;
		case RIGHT: currentPosition.setX(0);
			break;
		case UP: currentPosition.setY(map.getSizeY() - 1);
			break;
		case DOWN: currentPosition.setY(0);
			break;
		}
	}
	else {
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
	
}
