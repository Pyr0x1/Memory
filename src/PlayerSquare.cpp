#include "PlayerSquare.h"

PlayerSquare::PlayerSquare (int x, int y, int size, SDL_Color color) :
							Square (x, y, size, color) {}

void PlayerSquare::drawTo (SDL_Renderer* renderer, SDL_Point center, SDL_Color background) {

	/*
	Uint8 old_r;
	Uint8 old_g;
	Uint8 old_b;
	Uint8 old_a;

	//Delete the square in the middle of the screen
	SDL_GetRenderDrawColor (renderer, &old_r, &old_g, &old_b, &old_a);
	SDL_SetRenderDrawColor (renderer, background.r, background.g, background.b, background.a);
	SDL_RenderFillRect (renderer, &(Square::square));
	SDL_SetRenderDrawColor (renderer, old_r, old_g, old_b, old_a);
	*/

	//Draw player square onto one of the squares on the field
	Square::square.x = center.x - Square::square.w / 2;
	Square::square.y = center.y - Square::square.h / 2;
	Square::draw (renderer);

	return ;
}

PlayerSquare::~PlayerSquare () {
	// TODO Auto-generated destructor stub
}

