#include "Objects/MovingObjects/Ghost.h"

#include <random>
#include <algorithm>
#include <iostream>

Ghost::Ghost(Position _initialPosition, Map _map, Type type)
{
	currentPosition = _initialPosition;
	initialPosition = _initialPosition;
	sprite = type;
	initialType = type;
	direction = UP;
	velocity = 3;
	map = _map;
	updateCount = 2;
}


Ghost::~Ghost()
{
}

void Ghost::moveRandom()
{
	if (map.isOnEdge(currentPosition, direction)) {
		return;
	}
	if (direction == UP) {
		std::vector<Direction> possibleDirections;
		if (!map.checkWall(currentPosition, UP)) {
			possibleDirections.push_back(UP);
		}
		if (!map.checkWall(currentPosition, RIGHT)) {
			possibleDirections.push_back(RIGHT);
		}
		if (!map.checkWall(currentPosition, LEFT)) {
			possibleDirections.push_back(LEFT);
		}

		if (possibleDirections.size() == 0) {
			direction = DOWN;
		}
		else if (possibleDirections.size() == 1) {
			direction = possibleDirections[0];
		}
		else {
			std::random_device r;
			std::default_random_engine generator(r());
			std::shuffle(possibleDirections.begin(), possibleDirections.end(), generator);
			direction = possibleDirections[0];
		}
	}
	else if (direction == RIGHT) {
		std::vector<Direction> possibleDirections;
		if (!map.checkWall(currentPosition, RIGHT)) {
			possibleDirections.push_back(RIGHT);
		}
		if (!map.checkWall(currentPosition, UP)) {
			possibleDirections.push_back(UP);
		}
		if (!map.checkWall(currentPosition, DOWN)) {
			possibleDirections.push_back(DOWN);
		}
		if (possibleDirections.size() == 0) {
			direction = LEFT;
		}
		else if (possibleDirections.size() == 1) {
			direction = possibleDirections[0];
		}
		else {
			std::random_device r;
			std::default_random_engine generator(r());
			std::shuffle(possibleDirections.begin(), possibleDirections.end(), generator);
			direction = possibleDirections[0];
		}
	}
	else if (direction == LEFT) {
		std::vector<Direction> possibleDirections;
		if (!map.checkWall(currentPosition, LEFT)) {
			possibleDirections.push_back(LEFT);
		}
		if (!map.checkWall(currentPosition, UP)) {
			possibleDirections.push_back(UP);
		}
		if (!map.checkWall(currentPosition, DOWN)) {
			possibleDirections.push_back(DOWN);
		}
		if (possibleDirections.size() == 0) {
			direction = RIGHT;
		}
		else if (possibleDirections.size() == 1) {
			direction = possibleDirections[0];
		}
		else {
			std::random_device r;
			std::default_random_engine generator(r());
			std::shuffle(possibleDirections.begin(), possibleDirections.end(), generator);
			direction = possibleDirections[0];
		}
	}
	else if (direction == DOWN) {
		std::vector<Direction> possibleDirections;
		if (!map.checkWall(currentPosition, DOWN)) {
			possibleDirections.push_back(DOWN);
		}
		if (!map.checkWall(currentPosition, RIGHT)) {
			possibleDirections.push_back(RIGHT);
		}
		if (!map.checkWall(currentPosition, LEFT)) {
			possibleDirections.push_back(LEFT);
		}
		if (possibleDirections.size() == 0) {
			direction = UP;
		}
		else if (possibleDirections.size() == 1) {
			direction = possibleDirections[0];
		}
		else {
			std::random_device r;
			std::default_random_engine generator(r());
			std::shuffle(possibleDirections.begin(), possibleDirections.end(), generator);
			direction = possibleDirections[0];
		}
	}


}

void Ghost::setScared(bool _scared)
{
	scared = _scared;
}

bool Ghost::getScared()
{
	return scared;
}

void Ghost::update()
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

	if (scared) {
		sprite = SCARED;
		velocity = 4;
		timeout++;
		if (timeout == 50) {
			scared = false;
		}
	}
	else {
		sprite = initialType;
		timeout = 0;
		velocity = 3;
	}
}
