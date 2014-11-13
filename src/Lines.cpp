#include "Lines.h"

Lines::Lines (SDL_Color color, int screenW, int screenH, int borderX, int borderY) {

	this->color = color;
	this->borderX = borderX;
	this->borderY = borderY;
	this->screenW = screenW;
	this->screenH = screenH;
}

void Lines::draw (SDL_Renderer* renderer) {

	SDL_SetRenderDrawColor (renderer, this->color.r, this->color.g, this->color.b, this->color.a);
	SDL_RenderDrawLine (renderer, this->screenW / 2, this->borderY, this->screenW - this->borderX, this->screenH / 2);
	SDL_RenderDrawLine (renderer, this->screenW - this->borderX, this->screenH / 2, this->screenW / 2, this->screenH - this->borderY);
	SDL_RenderDrawLine (renderer, this->screenW / 2, this->screenH - this->borderY, this->borderX, this->screenH / 2);
	SDL_RenderDrawLine (renderer, this->borderX, this->screenH / 2, this->screenW / 2, this->borderY);

	return ;
}

Lines::~Lines() {
	// TODO Auto-generated destructor stub
}

