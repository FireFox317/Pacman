#pragma once

#include "GameObjectStruct.h"
#include <SDL2/SDL.h>
#include <vector>

class Game
{
public:
	Game(std::vector<std::vector<int>> map);
	~Game();
	void init();
	void render();
	void update();
	void input(SDL_Keycode key);

	std::vector<GameObjectStruct> getStructs();
	unsigned int getLives();
	unsigned int getScore();
private:
	GameObjectStruct pacman;
	std::vector<GameObjectStruct> listOfDots;
	std::vector<GameObjectStruct> objects;
	std::vector<std::vector<int>> map;
	unsigned int countUpdates = 0;
	unsigned int lives = 3;
	unsigned int score = 0;
};