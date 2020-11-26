#include "Player.h"

Player::Player(const char* ship_img, float x, float y, float w, float h): TexRect(ship_img, x, y, w, h){

	blaster = new Blaster("blaster.jpg", x + 0.1, y, 0.01, 0.05, true);

}

void Player::move(float x) {

	this->x += x;
	redrawScene();
}

void Player::blast() {

	if(!blaster->isShooting()) {
		blaster->reset(this->x, this->y);
		blaster->isFiring();
    }
}

void Player::hit() {
	if (lives > 0) {
		lives--;
		std::cout << lives << " Lives Left" << std::endl;
		this->reset();
	} else {
		dead = true;
	}
}


bool Player::isDead() {
	return dead;
}

void Player::reset() {
	this->x = -0.2;
	this->y = -0.6;
}

Player::~Player() {
	delete blaster;
}

