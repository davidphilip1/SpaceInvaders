#ifndef Player_h
#define Player_h

#include "TexRect.h"
#include "Blaster.h"


class Player: public TexRect { 

	int lives = 3; 
	bool dead = false; 

public:

	Blaster* blaster;
	Player(const char*, float, float, float, float);
	void move(float x);
	void blast();
	void hit();
	void reset();
	bool isDead();
	~Player();

};


#endif