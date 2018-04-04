#include "Stats.h"

void Stats::init(int initialScore, int initialLives)
{
	score = initialScore;
	lives = initialLives;
}

void Stats::changeScore(int amount)
{
	score += amount;
}

void Stats::changeLives(int amount)
{
	lives += amount;
}

int Stats::getScore()
{
	return score;
}

int Stats::getLives()
{
	return lives;
}
