#pragma once
class Stats
{
public:
	Stats(int initialScore, int initialLives);
	void changeScore(int amount);
	void changeLives(int amount);
	int getScore();
	int getLives();
private:
	int score, lives;
};

