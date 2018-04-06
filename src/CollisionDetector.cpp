#include "Utils/CollisionDetector.h"

CollisionDetector::CollisionDetector()
{
}


CollisionDetector::~CollisionDetector()
{
}

bool CollisionDetector::pacmanGhostCollision(Pacman * pacman, std::vector<std::unique_ptr<Object>>& list, Ghost & copyGhost)
{
	for (int i = 1; i < list.size(); i++) {
		Ghost* ghost = dynamic_cast<Ghost*>(list[i].get());
		if (ghost != nullptr) {
			if (ghost->getPosition() == pacman->getPosition()) {
				copyGhost = *ghost;
				list.erase(list.begin() + i);
				return true;
			}
		}
	}
	return false;
}

bool CollisionDetector::pacmanFruitCollision(Pacman * pacman, std::vector<std::unique_ptr<Object>>& list, Fruit & copyFruit)
{
	for (int i = 1; i < list.size(); i++) {
		Fruit* fruit = dynamic_cast<Fruit*>(list[i].get());
		if (fruit != nullptr) {
			if (fruit->getPosition() == pacman->getPosition()) {
				copyFruit = *fruit;
				list.erase(list.begin() + i);
				return true;
			}
		}
	}
	return false;
}

bool CollisionDetector::pacmanEnergizerCollision(Pacman * pacman, std::vector<std::unique_ptr<Object>>& list, Energizer & copyEnergizer)
{
	for (int i = 1; i < list.size(); i++) {
		Energizer* energizer = dynamic_cast<Energizer*>(list[i].get());
		if (energizer != nullptr) {
			if (energizer->getPosition() == pacman->getPosition()) {
				copyEnergizer = *energizer;
				list.erase(list.begin() + i);
				return true;
			}
		}
	}
	return false;
}

bool CollisionDetector::pacmanDotCollision(Pacman* pacman, std::vector<std::unique_ptr<Object>>& list, Dot &copyDot)
{
	for (int i = 1; i < list.size(); i++) {
		Dot* dot = dynamic_cast<Dot*>(list[i].get());
		if (dot != nullptr) {
			if (dot->getPosition() == pacman->getPosition()) {
				copyDot = *dot;
				list.erase(list.begin() + i);
				return true;
			}
		}
	}
	return false;
}
