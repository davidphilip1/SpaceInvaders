#include "Barrier.h"


Barrier::Barrier(const char* barrier_img, float x, float y, float w, float h):TexRect(barrier_img, x, y, w, h){
    

    
}



Barrier::~Barrier() {

}

void Barrier::damage() {


    health -= 1;
    std::cout << "Barrier HP: "<< health << std::endl; 

    if(health <= 0) {
    	up = false;
    }
}

bool Barrier::isUp() {
	return up;
}
