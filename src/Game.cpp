#include "Game.h"

#include "../Dot.h"
#include <iostream>

Game::Game(std::vector<std::vector<int>> _map)
{
	map.init(_map);
	Position pos(1, 1);
	listOfObjects.push_back(std::unique_ptr<Pacman>(new Pacman(pos, map)));
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
				listOfObjects.push_back(std::unique_ptr<Dot>(new Dot(pos)));
			}
		}
	}

	stats.init(0, 3);
}

void Game::render()
{
	objects = {};
	for (auto& object : listOfObjects) {
		GameObjectStruct temp;
		temp.x = object->getPosition().getX();
		temp.y = object->getPosition().getY();
		MovingObject* mo = dynamic_cast<MovingObject*>(object.get());
		if (mo == nullptr) {
			temp.dir = UP;
		}
		else {
			temp.dir = mo->getDirection();
		}
		temp.type = object->getType();
		objects.push_back(temp);
	}
}

void Game::move() {
	for (auto& object : listOfObjects) {
		MovingObject* mo = dynamic_cast<MovingObject*>(object.get());
		if (mo != nullptr) {
			if (countUpdates % mo->getVelocity() == 0) {
				object->update();
			}
		}
	}
	countUpdates++;
}

void Game::update()
{
	Pacman* pacman = dynamic_cast<Pacman*>(listOfObjects[0].get());

	for (int i = 1; i < listOfObjects.size(); i++) {
		Dot* dot = dynamic_cast<Dot*>(listOfObjects[i].get());
		if (dot != nullptr) {
			if (dot->getPosition() == pacman->getPosition()) {
				stats.changeScore(dot->getScore());
				listOfObjects.erase(listOfObjects.begin() + i);
				break;
			}
		}
	}
}

void Game::input(SDL_Keycode key)
{
	Pacman* pacman = dynamic_cast<Pacman*>(listOfObjects[0].get());
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
	return stats.getLives();
}

int Game::getScore()
{
	return stats.getScore();
}
