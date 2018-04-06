#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Position.h"
#include "../GameObjectStruct.h"

class Map
{
public:
	Map() = default;
	void init(std::vector<std::vector<int>> map);
	bool checkWall(Position pos, Direction dir);
	size_t getSizeX();
	size_t getSizeY();
	bool checkPath(Position pos);
	bool isOnEdge(Position pos, Direction dir);
	Position calculateRandomPosition();
private:
	std::vector<std::vector<int>> map;
};

#endif // !MAP_H



