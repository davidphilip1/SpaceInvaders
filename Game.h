#ifndef Game_h
#define Game_h

#include "TexRect.h"
#include "Timer.h"

class Game: public TexRect{ 

	bool playing = false; 
	int enemyCount = 20; 
	int score = 0;
	int level = 1; 

public:

	Game(const char*, float, float, float, float);

	void scoring(int score);
	void displayScore();
	void startGame();
	bool isPlaying();
	void drawString(void* font, char *s, float x, float y);
	void gameOver();
	void killEnemy();
	bool levelComplete();
	void nextLevel();
	int randomShot();
	int getEnemyCount();
	int getLevel();

};


#endif