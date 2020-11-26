#ifndef invader_h
#define invader_h

#include "Timer.h"
#include "TexRect.h"
#include "Blaster.h"

class invader: public TexRect, private Timer{

		bool dead = false; 
		float rate = 0.05;
		float true_x, true_y;

	public: 

		Blaster* blaster;
		int direction = 1;
		invader(const char*, float x, float y, float w, float h);
		void action();
		void move();
		bool isDead();
		void invade();
		int dir();
		void setLevel(int speed);
		void reset();
		void resetAll();
		void kill();
		void blast();
		~invader();
	
}; 

#endif
