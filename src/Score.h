#ifndef SCORE_H_
#define SCORE_H_

#include <string>
#include <SDL2/SDL_ttf.h>

class Score {

	private:
		SDL_Surface* surface;
		SDL_Texture* texture;
		TTF_Font* font;
		SDL_Color color;
		int value;

	public:
		Score (std::string fontPath, SDL_Color fontColor, int size);
		void write (SDL_Renderer* renderer, SDL_Point position);
		void increase ();
		void reset ();
		~Score ();
};

#endif /* SCORE_H_ */
