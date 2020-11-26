#include "UFO.h"

UFO::UFO(const char* UFO_img, float x, float y, float w, float h): TexRect(UFO_img, x, y, w, h) {

	blaster = new Blaster("blaster.jpg", x, y, 0.02, 0.08, false);
	setRate(100);
}

void UFO::action() {

	if(this->x < -1.5) {
		left = false;
	} else if (this->x > 1.5) {
		left = true;
	}

	if(left) {
		this->x -= 0.05;
	} else {
		this->x += 0.05;
	}

	redrawScene();
	

}

void UFO::blast() {

	if(blastReady == 100) {
		blastReady = 0;
	}

	if(blastReady == 0) {
		blaster->reset(this->x, this->y);
		blaster->isFiring();
		blastReady++;
    } else  {

    	blastReady++;

    }
}

void UFO::reset() {

	dead = true;
	this->x = 1.6;

}

void UFO::spawn() {
	dead = false;
	start();
}

void UFO::kill() {

	stop();
	reset();

}

bool UFO::isDead() {
	return dead;
}

UFO::~UFO() {

	delete blaster;

}
