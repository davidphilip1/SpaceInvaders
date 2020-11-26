#include "Hive.h"

Hive::Hive(
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
		    invader* alien20) {


	hiveMind.push_back(alien1);
	hiveMind.push_back(alien2);
	hiveMind.push_back(alien3);
	hiveMind.push_back(alien4);
	hiveMind.push_back(alien5);
	hiveMind.push_back(alien6);
	hiveMind.push_back(alien7);
	hiveMind.push_back(alien8);
	hiveMind.push_back(alien9);
	hiveMind.push_back(alien10);
	hiveMind.push_back(alien11);
	hiveMind.push_back(alien12);
	hiveMind.push_back(alien13);
	hiveMind.push_back(alien14);
	hiveMind.push_back(alien15);
	hiveMind.push_back(alien16);
	hiveMind.push_back(alien17);
	hiveMind.push_back(alien18);
	hiveMind.push_back(alien19);
	hiveMind.push_back(alien20);
	
	setRate(250);
}



void Hive::action() {

	for (int i = 0; i < 20; i++) {
		hiveMind[i]->move();
	}

}

void Hive::ceaseFire() {
	stop();
}

void Hive::invade() {
	start();
}

Hive::~Hive() {

}
