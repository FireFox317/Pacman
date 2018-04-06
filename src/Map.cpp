#include "Utils/Map.h"

#include <random>
#include <iostream>

void Map::init(std::vector<std::vector<int>> _map)
{
	map = _map;
}

bool Map::checkWall(Position pos, Direction dir)
{
	switch (dir) {
	case LEFT: return (map[pos.getY()][pos.getX() - 1] == 1);
	case RIGHT: return (map[pos.getY()][pos.getX() + 1] == 1);
	case DOWN: return (map[pos.getY() + 1][pos.getX()] == 1);
	case UP: return (map[pos.getY() - 1][pos.getX()] == 1);
	default: return false;
	}
}

size_t Map::getSizeX()
{
	return map[0].size();
}

size_t Map::getSizeY()
{
	return map.size();
}

bool Map::checkPath(Position pos)
{
	return map[pos.getY()][pos.getX()] == 0;
}

bool Map::isOnEdge(Position pos, Direction dir)
{
	switch (dir) {
	case LEFT: return pos.getX() == 0;
	case RIGHT: return pos.getX() == getSizeX() - 1;
	case UP: return pos.getY() == 0;
	case DOWN: return pos.getY() == getSizeY() - 1;
	}
}

Position Map::calculateRandomPosition()
{
	std::random_device r;
	std::default_random_engine eng{ r() };
	std::uniform_int_distribution<int> randomX(0, getSizeX() - 1);
	std::uniform_int_distribution<int> randomY(0, getSizeY() - 1);

	while (true) {
		int x = randomX(eng);
		int y = randomY(eng);
		Position pos = Position(x, y);
		if (checkPath(pos)) {
			return pos;
		}
	}
}
