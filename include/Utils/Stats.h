#ifndef STATS_H
#define STATS_H

class Stats
{
public:
	Stats() = default;
	void init(int initialScore, int initialLives);
	void changeScore(int amount);
	void changeLives(int amount);
	int getScore();
	int getLives();
private:
	int score, lives;
};

#endif // !STATS_H




