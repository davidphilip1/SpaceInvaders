#include "invader.h"

invader::invader(const char* invader_img, float x, float y, float w, float h): TexRect(invader_img, x, y, w, h) {
	
	blaster = new Blaster("blaster.jpg", x + 0.04, y - h, 0.01, 0.05, false);
	true_x = x; 
	true_y = y;

}

int invader::dir() {return direction;}

void invader::move() { 
	
	if(direction == 1) {
		this->x += rate;
		if(this->x + this->w >= 0.8)
			direction = 0;

	}
	else if(direction == 0) {
		this->y -= this->h;
		if(this->x + this->w >= 0.8)
			direction = -1;
		else if(this->x <= -0.8)
			direction = 1;

	}
	else if(direction == -1) {
		this->x -= rate;
		if(this->x <= -0.8)
			direction = 0;

	}
	redrawScene();

}

void invader::action() {}

void invader::blast() {

	if(!blaster->isShooting()) {
		blaster->reset(this->x, this->y);
		blaster->isFiring();
    }
}

void invader::kill() {
	dead = true; 
	this->x = 1.0;
	this->y = -1.0;
}

void invader::reset() {
	this->x = true_x;
	this->y = true_y;
	redrawScene();
}

void invader::resetAll() {
	dead = false;
	direction = 1;
	this->x = true_x;
	this->y = true_y;
	redrawScene();
}

void invader::setLevel(int speed) {
	rate = rate * speed; 
}

bool invader::isDead() {
	return dead;
}

void invader::invade() {}


invader::~invader() {

}



