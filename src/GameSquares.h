#ifndef GAMESQUARES_H_
#define GAMESQUARES_H_

#include "Square.h"
#include "Side.h"

class GameSquares {

	private:
		Square squares[S_NUM];

	public:
		GameSquares (int borderX, int borderY, int screenW, int screenH, int squareSize, SDL_Color color);
		SDL_Point getCenter (Side side);
		void draw (SDL_Renderer* renderer);
		void setSize (Side side, int size);
		void setSizeInPlace (Side side, int size);
		void setColor (Side side, SDL_Color color);
		~GameSquares ();
};

#endif /* GAMESQUARES_H_ */
