#include "Game.h"

#include "../Dot.h"

Game::Game(std::vector<std::vector<int>> _map)
{
	map.init(_map);
	Position pos(1, 1);
	pacman = new Pacman(pos, map);
	listOfObjects.push_back(pacman);
}

Game::~Game()
{
}

void Game::init()
{
	for (size_t y = 0; y < map.getSizeY(); y++) {
		for (size_t x = 0; x < map.getSizeX(); x++) {
			Position pos(x, y);
			if (map.checkPath(pos)) {
				Dot* dot = new Dot(pos);
				listOfObjects.push_back(dot);
				listOfDots.push_back(dot);
			}
		}
	}


	stats = std::make_unique<Stats>(0, 3);

}

void Game::render()
{
	objects = {};
	for (auto object : listOfObjects) {
		GameObjectStruct temp;
		temp.x = object->getPosition().getX();
		temp.y = object->getPosition().getY();
		temp.dir = object->getDirection();
		temp.type = object->getType();
		objects.push_back(temp);
	}
}

void Game::update()
{
	for (auto object : listOfObjects) {
		if (object->getVelocity() != -1 && countUpdates % object->getVelocity() == 0) {
			object->update();
		}
	}
	for (int i = 0; i < listOfDots.size(); i++) {
		auto dot = listOfDots[i];
		if (dot->getPosition() == pacman->getPosition()) {
			listOfDots.erase(listOfDots.begin() + i);
		}
		break;
	}

	countUpdates++;
}

void Game::input(SDL_Keycode key)
{
	switch (key) {
	case SDLK_LEFT: // YOUR CODE HERE
		pacman->setDirection(LEFT);
		break;
	case SDLK_RIGHT: // YOUR CODE HERE
		pacman->setDirection(RIGHT);
		break;
	case SDLK_UP: // YOUR CODE HERE
		pacman->setDirection(UP);
		break;
	case SDLK_DOWN: // YOUR CODE HERE
		pacman->setDirection(DOWN);
		break;
	}
}

std::vector<GameObjectStruct> Game::getStructs()
{
	return objects;
}

int Game::getLives()
{
	return stats->getLives();
}

int Game::getScore()
{
	return stats->getScore();
}
