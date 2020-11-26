#ifndef App_h
#define App_h
#include <vector>
#include "GlutApp.h"
#include "Player.h"
#include "UFO.h"
#include "Game.h"
#include "Barrier.h"
#include "invader.h"
#include "Start.h"
#include "Hive.h"
#include <vector>


class App: public GlutApp {
	
	Start* screen;
    Player* playerShip; 
    UFO* ufo; 
    Game* game;
    Hive* hiveMind;
    std::vector<Barrier*> walls;

    
public:
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
