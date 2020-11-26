
#ifndef Barrier_h
#define Barrier_h

#include "TexRect.h"

class Barrier: public TexRect {

	int health = 4;
	bool up = true;
    GLuint fullHealth;
    GLuint threeFourthHealth;
    GLuint halfHealth;
    GLuint quarterHealth;

public:


    Barrier(const char*, float, float, float, float);
    void damage();
    bool isUp();
    ~Barrier();

    
};
    
    
#endif
    
    

    





