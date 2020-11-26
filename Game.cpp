#include "Game.h"
#include <string>

Game::Game(const char* topBar_img, float x, float y, float w, float h): TexRect(topBar_img, x, y, w, h){


}


bool Game::isPlaying() {
	return playing;
}

void Game::gameOver() {
	playing = false;
}

void Game::scoring(int score) {
	this->score += score;
	std::cout << "Score: " << this->score << std::endl;
}

void Game::displayScore() {

	char s = score + '0';

	glColor3f(1.0, 1.0, 1.0);
	drawString(GLUT_BITMAP_HELVETICA_18, &s, 0.0, 0.0);

}

void Game::drawString(void* font, char *s, float x, float y) {
	glRasterPos2f(x,y);
	for (unsigned int i = 0; i < strlen(s); i++) {
		glutBitmapCharacter(font, s[i]);
	}
}

void Game::killEnemy() {

	enemyCount--;

}

bool Game::levelComplete() {
	if(enemyCount == 0) { 
		return true;
	} else {
		false;
	}
}

void Game::nextLevel() {

	std::cout << "NEXT LEVEL" << std::endl;
	enemyCount = 20;
	level++;
	playing = false;

}

int Game::getLevel() {
	return level;
}

void Game::startGame() {
	playing = true;
	redrawScene();
}

int Game::getEnemyCount() {
	return enemyCount;
}

int Game::randomShot() {
	return rand()%(10 - 1 + 1) + 1;
}







