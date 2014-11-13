#ifndef PLAYERSQUARE_H_
#define PLAYERSQUARE_H_

#include <SDL2/SDL.h>
#include "Square.h"

class PlayerSquare : public Square{

	public:
		PlayerSquare (int x, int y, int size, SDL_Color color);
		void drawTo (SDL_Renderer* renderer, SDL_Point center, SDL_Color background);
		~PlayerSquare ();
};

#endif /* PLAYERSQUARE_H_ */
