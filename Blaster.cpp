#include "Blaster.h"

Blaster::Blaster(const char* blast_img, float x, float y, float w, float h, bool status): TexRect(blast_img, x, y, w, h) {

	player = status;
	if(player) {
		setRate(10);
	} else {
		setRate(80);
	}
}

void Blaster::draw(float z) {

	if (shoot) {
	    glBindTexture( GL_TEXTURE_2D, texture_id);
	    glEnable(GL_TEXTURE_2D);
	    
	    glBegin(GL_QUADS);
	    glColor4f(1, 1, 1, 1);
	    glTexCoord2f(0, 0);
	    glVertex3f(x, y - h, z);
	    
	    glTexCoord2f(0, 1);
	    glVertex3f(x, y, z);
	    
	    glTexCoord2f(1, 1);
	    glVertex3f(x+w, y, z);
	    
	    glTexCoord2f(1, 0);
	    glVertex3f(x+w, y - h, z);
	    
	    glEnd();
	    
	    glDisable(GL_TEXTURE_2D);
	}
}

void Blaster::action() {
	
	if (player) {
		this->y += 0.07;
		if(this->y > 1.0) {
			shoot = false; 
			stop();
		}
	} else {
		this->y -= 0.08;
		if(this->y < -1.0) {
			shoot = false; 
			stop();
		}
	}
	redrawScene();

}


void Blaster::isFiring() {
	shoot = true; 
	start();
}


void Blaster::reset(float x, float y) {
	this->y = y;
	this->x = x + 0.1;
}

bool Blaster::isShooting() {

	return shoot;

}

void Blaster::hit() {
	shoot = false;
	stop();
	redrawScene(); 
}

void Blaster::kill() {
	stop();
}

Blaster::~Blaster() {

}





