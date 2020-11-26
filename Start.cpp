#include "Start.h"


Start::Start(const char* start_img, float x, float y, float w, float h): TexRect(start_img, x, y, w, h) {
		
}

void Start::startNow() {
	started = true;
}

bool Start::isStarted() {
	return started;
}