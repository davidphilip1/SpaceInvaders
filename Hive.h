#ifndef Hive_h
#define Hive_h

#include "Timer.h"
#include "TexRect.h"
#include "invader.h"
#include <vector>

class Hive: protected Timer{

	public: 
		std::vector<invader*> hiveMind;
		Hive(
			invader* alien1,
		    invader* alien2,
		    invader* alien3,
		    invader* alien4,
		    invader* alien5,
		    invader* alien6,
		    invader* alien7,
		    invader* alien8,
		    invader* alien9,
		    invader* alien10,
		    invader* alien11,
		    invader* alien12,
		    invader* alien13,
		    invader* alien14,
		    invader* alien15,
		    invader* alien16,
		    invader* alien17,
		    invader* alien18,
		    invader* alien19,
		    invader* alien20);
		void action();
		void ceaseFire();
		void invade();
		~Hive();
	
}; 

#endif
