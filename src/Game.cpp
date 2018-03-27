#include "Game.h"

Game::Game(std::vector<std::vector<int>> map) : map(map)
{
}

Game::~Game()
{
}

void Game::init()
{
	pacman.x = 1;
	pacman.y = 1;
	pacman.type = PACMAN;
	pacman.dir = UP;

	for (size_t y = 0; y < map.size(); y++) {
		for (size_t x = 0; x < map[y].size(); x++) {
			if (map[y][x] == 0) {
				GameObjectStruct dot;
				dot.dir = UP;
				dot.x = x;
				dot.y = y;
				dot.type = DOT;
				listOfDots.push_back(dot);
			}
		}
	}
}

void Game::render()
{
	objects = { pacman };

	for (unsigned int i = 0; i < listOfDots.size(); i++) {
		GameObjectStruct dot = listOfDots[i];
		if (dot.x == pacman.x && dot.y == pacman.y) {
			listOfDots.erase(listOfDots.begin() + i);
		}
	}
	objects.insert(objects.end(), listOfDots.begin(), listOfDots.end());
}

void Game::update()
{
	if (countUpdates % 2 == 0) {
		if (pacman.dir == LEFT && map[pacman.y][pacman.x-1] != 1 ) {
			pacman.x--;
		}
		else if (pacman.dir == RIGHT && map[pacman.y][pacman.x + 1] != 1) {
			pacman.x++;
		}
		else if (pacman.dir == UP && map[pacman.y-1][pacman.x] != 1) {
			pacman.y--;
		}
		else if (pacman.dir == DOWN && map[pacman.y+1][pacman.x] != 1) {
			pacman.y++;
		}
	}

	countUpdates++;
}

void Game::input(SDL_Keycode key)
{
	switch (key) {
	case SDLK_LEFT: // YOUR CODE HERE
		pacman.dir = LEFT;
		break;
	case SDLK_RIGHT: // YOUR CODE HERE
		pacman.dir = RIGHT;
		break;
	case SDLK_UP: // YOUR CODE HERE
		pacman.dir = UP;
		break;
	case SDLK_DOWN: // YOUR CODE HERE
		pacman.dir = DOWN;
		break;
	}
}

std::vector<GameObjectStruct> Game::getStructs()
{
	return objects;
}

unsigned int Game::getLives()
{
	return lives;
}

unsigned int Game::getScore()
{
	return score;
}
