#pragma once

#include "GameObjectStruct.h"
#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "../Stats.h"
#include "../Pacman.h"
#include "../Object.h"
#include "../Map.h"
#include "../Dot.h"

class Game
{
public:
	Game(std::vector<std::vector<int>> map);
	~Game();
	void init();
	void render();
	void update();
	void move();
	void input(SDL_Keycode key);

	std::vector<GameObjectStruct> getStructs();
	int getLives();
	int getScore();
private:
	Stats stats;

	std::vector<std::unique_ptr<Object>> listOfObjects;

	Map map;
	std::vector<GameObjectStruct> objects;
	unsigned int countUpdates = 0;

	int pointsForEatingGhost = 200;
};