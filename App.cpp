#include <iostream>
#include "App.h"

int d;
App::App(int argc, char** argv): GlutApp(argc, argv){

    screen = new Start("startscreen.jpg", -0.6, 0.4, 1.2, 0.8);
    playerShip = new Player("playerShip.jpg", -0.1, -0.6, 0.2, 0.2);
    ufo = new UFO("UFO.jpg", 1.6, 0.9, 0.2, 0.15);
    game = new Game("blaster.jpg", -1.0, 1.0, 2.0, 0.05);
    hiveMind = new Hive(
        new invader("invader3.jpg", -0.80, 0.7, 0.08, 0.08),
        new invader("invader3.jpg", -0.45, 0.7, 0.08, 0.08),
        new invader("invader3.jpg", -0.10, 0.7, 0.08, 0.08),
        new invader("invader3.jpg", 0.25, 0.7, 0.08, 0.08),
        new invader("invader3.jpg", 0.60, 0.7, 0.08, 0.08),
        new invader("invader2.jpg", -0.80, 0.55, 0.08, 0.08),
        new invader("invader2.jpg", -0.45, 0.55, 0.08, 0.08),
        new invader("invader2.jpg", -0.10, 0.55, 0.08, 0.08),
        new invader("invader2.jpg", 0.25, 0.55, 0.08, 0.08),
        new invader("invader2.jpg", 0.6, 0.55, 0.08, 0.08),
        new invader("invader1.jpg", -0.80, 0.40, 0.08, 0.08),
        new invader("invader1.jpg", -0.45, 0.4, 0.08, 0.08),
        new invader("invader1.jpg", -0.10, 0.4, 0.08, 0.08),
        new invader("invader1.jpg", 0.25, 0.4, 0.08, 0.08),
        new invader("invader1.jpg", 0.6, 0.4, 0.08, 0.08),
        new invader("invader1.jpg", -0.80, 0.25, 0.08, 0.08),
        new invader("invader1.jpg", -0.45, 0.25, 0.08, 0.08),
        new invader("invader1.jpg", -0.10, 0.25, 0.08, 0.08),
        new invader("invader1.jpg", 0.25, 0.25, 0.08, 0.08),
        new invader("invader1.jpg", 0.6, 0.25, 0.08, 0.08)
    );

    walls = {
            new Barrier("health1.jpg", -0.8, -0.35, 0.2, 0.1), 
            new Barrier("health1.jpg", -0.4, -0.35, 0.2, 0.1), 
            new Barrier("health1.jpg", 0.2, -0.35, 0.2, 0.1), 
            new Barrier("health1.jpg", 0.6, -0.35, 0.2, 0.1)
    };
}

void App::draw() {


    if(screen->isStarted()) {

        if(playerShip->isDead()) {
            std::cout << "GAME OVER" << std::endl;
            game->gameOver();
            exit(0);
        }

        if(game->levelComplete()) {
            game->nextLevel();
            for (int i = 0; i < 20; i++) {
                hiveMind->hiveMind[i]->setLevel(game->getLevel());
                hiveMind->hiveMind[i]->resetAll();
                game->startGame();

            }
        }

        if(game->isPlaying()) { 

            game->draw(1.0); 

            if(game->getEnemyCount() <= 15) {
                    if(ufo->isDead()) {
                        ufo->spawn();
                    }

            }
        
            //INVADER
            for (int i = 0; i < 20; i++) {
                if(!hiveMind->hiveMind[i]->isDead()) {
                    hiveMind->hiveMind[i]->draw(1.0);

                    if(hiveMind->hiveMind[i]->getY() - hiveMind->hiveMind[i]->getH() < -0.35) {

                        for (int j = 0; j < 20; j++) {
                            hiveMind->hiveMind[j]->reset();
                        }

                        playerShip->hit();
                    }

                    if(playerShip->blaster->isShooting()) {
                        if(hiveMind->hiveMind[i]->contains(playerShip->blaster->getX(), playerShip->blaster->getY())){

                            hiveMind->hiveMind[i]->kill();
                            game->killEnemy();
                            game->scoring(10);

                            playerShip->blaster->reset(playerShip->getX(),playerShip->getY());
                            playerShip->blaster->hit();

                        }  
                    }
                }
            }

            //UFO
            if (!ufo->isDead()) {
                ufo->draw(0.15);
                if(ufo->contains(playerShip->blaster->getX(), playerShip->blaster->getY())){
                    playerShip->blaster->hit();
                    playerShip->blaster->reset(playerShip->getX(),playerShip->getY());
                    ufo->kill();
                    game->scoring(100);
                }

                if (!ufo->isDead()) {
                    ufo->draw(0.15);
                }

                if(ufo->blaster->isShooting()) {
                    ufo->blaster->draw(0.15);
                }


                if(ufo->getX() > -0.9 && ufo->getX() < 0.7) {
                    ufo->blast();
                }

            }

            
            //PLAYERSHIPT DRAWING

            if(playerShip->contains(ufo->blaster->getX(), ufo->blaster->getY())) {
                    ufo->blaster->hit();
                    ufo->blaster->reset(ufo->getX(),ufo->getY());
                    playerShip->hit();
            }

            playerShip->draw(0.15);
            if(playerShip->blaster->isShooting()) {
                playerShip->blaster->draw(0.15);
            }

            for (int i = 0; i < 4; i++) {
                if(walls[i]->isUp()) {
                    walls[i]->draw(1.0);

                    if(walls[i]->contains(playerShip->blaster->getX(), playerShip->blaster->getY())) {
                        walls[i]->damage();
                        playerShip->blaster->hit();
                        playerShip->blaster->reset(playerShip->getX(),playerShip->getY());
                    }

                    if(walls[i]->contains(ufo->blaster->getX(), ufo->blaster->getY())) {
                        walls[i]->damage();
                        ufo->blaster->hit();
                        ufo->blaster->reset(ufo->getX(),ufo->getY());
                    }
                }
            }
        }
        // game->displayScore();
    } else {
        screen->draw(0.15);
    }
}

void App::keyDown(unsigned char key, float x, float y){

    if (key == 27){
        exit(0);
    }

    //Right
    if(key == 'x') {
        playerShip->move(0.05);
    }

    //Left
    if(key == 'z') {
        playerShip->move(-0.05);
    }

    //Fire
    if(key == 'c') {
        playerShip->blast();

    }

    if(key == 's') {
        screen->startNow();
                game->startGame();
        hiveMind->invade();
    }

}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete playerShip;
    delete ufo;
    delete game;
    delete hiveMind;
        
}
