#ifndef SDLMANAGER_H_
#define SDLMANAGER_H_

#include <SDL2/SDL.h>

class SDL_Manager {

	private:
		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;
		SDL_Window* window;
		SDL_Renderer* renderer;

	public:
		SDL_Manager (int SCREEN_WIDTH, int SCREEN_HEIGHT);
		bool init ();
		int getWidth ();
		int getHeight ();
		SDL_Renderer* getRenderer ();
		SDL_Window* getWindow ();
		~SDL_Manager ();
};

#endif /* SDLMANAGER_H_ */
