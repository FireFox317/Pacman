#pragma once

#include <vector>
#include "Position.h"
#include "include\GameObjectStruct.h"

class Map
{
public:
	Map() = default;
	void init(std::vector<std::vector<int>> map);
	bool checkWall(Position pos, Direction dir);
	size_t getSizeX();
	size_t getSizeY();
	bool checkPath(Position pos);
private:
	std::vector<std::vector<int>> map;
};

