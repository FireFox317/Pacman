#include "Game.h"

#include "../Dot.h"
#include "../Ghost.h"
#include "../Pacman.h"
#include "../Energizer.h"
#include <iostream>

Game::Game(std::vector<std::vector<int>> _map)
{
	map.init(_map);
	Position pos(6, 13);
	listOfObjects.push_back(std::unique_ptr<Pacman>(new Pacman(pos, map)));
}

Game::~Game()
{
}

void Game::init()
{
	stats.init(0, 3);

	// adding dots to the game
	for (size_t y = 0; y < map.getSizeY(); y++) {
		for (size_t x = 0; x < map.getSizeX(); x++) {
			Position pos(x, y);
			if (map.checkPath(pos)) {
				listOfObjects.push_back(std::unique_ptr<Dot>(new Dot(pos)));
			}
		}
	}

	listOfObjects.push_back(std::unique_ptr<Ghost>(new Ghost(Position(13,13), map, PINKY)));
	listOfObjects.push_back(std::unique_ptr<Ghost>(new Ghost(Position(14,13), map, BLINKY)));
	listOfObjects.push_back(std::unique_ptr<Ghost>(new Ghost(Position(13, 14), map, INKY)));
	listOfObjects.push_back(std::unique_ptr<Ghost>(new Ghost(Position(14, 14), map, CLYDE)));

	listOfObjects.push_back(std::unique_ptr<Energizer>(new Energizer(Position(1, 1))));
	listOfObjects.push_back(std::unique_ptr<Energizer>(new Energizer(Position(26, 1))));
	listOfObjects.push_back(std::unique_ptr<Energizer>(new Energizer(Position(1, 25))));
	listOfObjects.push_back(std::unique_ptr<Energizer>(new Energizer(Position(26,25))));
	
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
				Ghost* ghost = dynamic_cast<Ghost*>(object.get());
				if (ghost != nullptr) {
					ghost->moveRandom();
				}
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

	for (int i = 1; i < listOfObjects.size(); i++) {
		Ghost* ghost = dynamic_cast<Ghost*>(listOfObjects[i].get());
		if (ghost != nullptr) {
			if (ghost->getPosition() == pacman->getPosition()) {
				if (ghost->getScared() == true) {
					stats.changeScore(pointsForEatingGhost);
					listOfObjects.erase(listOfObjects.begin() + i);
					pointsForEatingGhost = pointsForEatingGhost * 2;
				}
				else {
					stats.changeLives(-1);
					for (auto& object : listOfObjects) {
						MovingObject* mo = dynamic_cast<MovingObject*>(object.get());
						if (mo != nullptr) {
							mo->reset();
						}
					}
				}

				break;
			}
		}
	}

	for (int i = 1; i < listOfObjects.size(); i++) {
		Energizer* energizer = dynamic_cast<Energizer*>(listOfObjects[i].get());
		if (energizer != nullptr) {
			if (energizer->getPosition() == pacman->getPosition()) {
				stats.changeScore(energizer->getScore());
				listOfObjects.erase(listOfObjects.begin() + i);
				for (auto& object : listOfObjects) {
					Ghost* ghost = dynamic_cast<Ghost*>(object.get());
					if (ghost != nullptr) {
						ghost->setScared(true);
					}
				}
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
