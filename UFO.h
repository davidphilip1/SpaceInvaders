#ifndef UFO_h
#define UFO_h

#include "TexRect.h"
#include "Timer.h"
#include "Blaster.h"


class UFO: public TexRect, protected Timer{ 

	bool dead = true;
	bool left = true;
	int blastReady = 0;

public:

	Blaster* blaster;
	UFO(const char*, float, float, float, float);
	void move();
	void action();
	void reset();
	bool isDead();
	void kill();
	void spawn();
	void blast();
	~UFO();

};


#endif
