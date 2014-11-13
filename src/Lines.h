#ifndef LINES_H_
#define LINES_H_

#include <SDL2/SDL.h>

class Lines {

	private:
		SDL_Color color;
		int borderX;
		int borderY;
		int screenW;
		int screenH;

	public:
		Lines (SDL_Color color, int screenW, int screenH, int borderX, int borderY);
		void draw (SDL_Renderer* renderer);
		~Lines ();
	};

#endif /* LINES_H_ */
