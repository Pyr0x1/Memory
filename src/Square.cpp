#include "Square.h"

Square::Square (){

}

Square::Square (int x, int y, int size, SDL_Color color) {

	this->square.x = x;
	this->square.y = y;
	this->square.w = size;
	this->square.h = size;
	this->color = color;
}

void Square::setCoordinates (int x, int y) {

	this->square.x = x;
	this->square.y = y;

	return ;
}

void Square::setSize (int size) {

	this->square.w = size;
	this->square.h = size;

	return ;
}

void Square::setSizeInPlace (int size) {

	int oldSize = this->square.w;

	this->setSize (size);
	this->square.x += (oldSize - size) / 2;
	this->square.y += (oldSize - size) / 2;

	return ;
}

void Square::setColor (SDL_Color color) {

	this->color = color;

	return ;
}

SDL_Point Square::getCenter () {

	SDL_Point center = {this->square.x + this->square.w / 2, this->square.y + this->square.h / 2};

	return center;
}

void Square::draw (SDL_Renderer* renderer) {

	Uint8 old_r;
	Uint8 old_g;
	Uint8 old_b;
	Uint8 old_a;

	SDL_GetRenderDrawColor (renderer, &old_r, &old_g, &old_b, &old_a);
	SDL_SetRenderDrawColor (renderer, this->color.r, this->color.g, this->color.b, this->color.a);
	SDL_RenderFillRect (renderer, &this->square);
	SDL_SetRenderDrawColor (renderer, old_r, old_g, old_b, old_a);

	return ;
}

Square::~Square () {

}

