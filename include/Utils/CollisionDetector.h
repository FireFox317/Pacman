#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include "../Objects/MovingObjects/Pacman.h"
#include "../Objects/MovingObjects/Ghost.h"

#include "../Objects/StaticObjects/Dot.h"
#include "../Objects/StaticObjects/Fruit.h"
#include "../Objects/StaticObjects/Energizer.h"

#include <vector>
#include <memory>

class CollisionDetector
{
public:
	CollisionDetector();
	~CollisionDetector();
	bool pacmanGhostCollision(Pacman* pacman, std::vector<std::unique_ptr<Object>>& list, Ghost& copyGhost);
	bool pacmanFruitCollision(Pacman* pacman, std::vector<std::unique_ptr<Object>>& list, Fruit& copyFruit);
	bool pacmanEnergizerCollision(Pacman* pacman, std::vector<std::unique_ptr<Object>>& list, Energizer& copyEnergizer);
	bool pacmanDotCollision(Pacman* pacman, std::vector<std::unique_ptr<Object>>& list, Dot& copyDot);
};


#endif // !COLLISIONDETECTOR_H


