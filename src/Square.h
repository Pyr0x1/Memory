#ifndef SQUARE_H_
#define SQUARE_H_

#include <SDL2/SDL.h>

class Square {

	private:
		SDL_Color color;

	protected:
		SDL_Rect square;

	public:
		Square ();
		Square (int x, int y, int size, SDL_Color color);
		void setCoordinates (int x, int y);
		void setSize (int size);
		void setColor (SDL_Color color);
		void setSizeInPlace (int size);
		SDL_Point getCenter ();
		void draw (SDL_Renderer* renderer);
		~Square ();

};

#endif /* SQUARE_H_ */
