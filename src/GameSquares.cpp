#include "GameSquares.h"

GameSquares::GameSquares (int borderX, int borderY, int screenW, int screenH, int squareSize, SDL_Color color) {

	for (int i = 0; i < S_NUM; i++) {
		switch (i){
		case S_TOP:
			this->squares[i].setCoordinates (screenW / 2 - squareSize / 2, borderY - squareSize / 2);
			break;
		case S_RIGHT:
			this->squares[i].setCoordinates (screenW - borderX - squareSize / 2, screenH / 2 - squareSize / 2);
			break;
		case S_DOWN:
			this->squares[i].setCoordinates (screenW / 2 - squareSize / 2, screenH - borderY - squareSize / 2);
			break;
		case S_LEFT:
			this->squares[i].setCoordinates (borderX - squareSize / 2, screenH / 2 - squareSize / 2);
			break;
		}

		this->squares[i].setSize (squareSize);
		this->squares[i].setColor (color);
	}
}

SDL_Point GameSquares::getCenter (Side side) {

	return this->squares[side].getCenter();
}

void GameSquares::draw (SDL_Renderer* renderer) {

	for (int i = 0; i < S_NUM; i++)
		this->squares[i].draw (renderer);

	return ;
}

void GameSquares::setSize (Side side, int size) {

	this->squares[side].setSize(size);
}

void GameSquares::setSizeInPlace (Side side, int size) {

	this->squares[side].setSizeInPlace(size);
}

void GameSquares::setColor (Side side, SDL_Color color) {

	this->squares[side].setColor(color);
}

GameSquares::~GameSquares () {
	// TODO Auto-generated destructor stub
}

