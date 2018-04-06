#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>
#include <memory>

#include "GameObjectStruct.h"

#include "Utils/Stats.h"
#include "Objects/MovingObjects/Pacman.h"
#include "Objects/Object.h"
#include "Utils/Map.h"
#include "Utils/CollisionDetector.h"
#include "Objects/StaticObjects/Dot.h"

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
	CollisionDetector collisionDetector;

	std::vector<std::unique_ptr<Object>> listOfObjects;

	Map map;
	std::vector<GameObjectStruct> objects;
	unsigned int countUpdates = 0;

	int pointsForEatingGhost = 200;
	bool fruitAdded = false;
	int lowerBoundFruit = 500;
	int fruitCount = 250;
};

#endif // !GAME_H


