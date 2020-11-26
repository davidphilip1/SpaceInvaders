#ifndef Start_h
#define Start_h

#include "TexRect.h"

class Start: public TexRect {

	bool started = false;

public:
	Start(const char*, float x, float y, float w, float h);
	void startNow(); 
	bool isStarted();

};

#endif