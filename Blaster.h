#ifndef Blaster_h
#define Blaster_h

#include "TexRect.h"
#include "Timer.h"


class Blaster: public TexRect, protected Timer{

	bool player; 
	bool shoot = false;

public:

	Blaster(const char*, float, float, float, float, bool);
	void action();
	void draw(float z);
	void isFiring();
	void reset(float x, float y);
	bool isShooting();
	void hit();
	void kill();
	~Blaster();

};


#endif