#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDL_Manager.h"
#include "GameSquares.h"
#include "PlayerSquare.h"
#include "GameLogic.h"
#include "Side.h"
#include "Timer.h"
#include "Score.h"
#include "Lines.h"

using namespace std;

int main (int argc, char* argv[])
{
	//Screen constants
	const int SCREEN_WIDTH = 192;
	const int SCREEN_HEIGHT = 192;
	const int SCREEN_FPS = 60;
	const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

	//Colors
	/*SDL_Color black = {24, 48, 48, 255};
	SDL_Color grey = {80, 120, 104, 255};
	SDL_Color white = {215, 232, 148, 255};
	SDL_Color green = {174, 196, 64, 255};*/
	SDL_Color black = {32, 70, 49, 255};
	SDL_Color grey = {82, 127, 57, 255};
	SDL_Color white = {215, 232, 148, 255};
	SDL_Color green = {174, 196, 64, 255};

	//Square size
	const int SQUARE_SIZE = SCREEN_WIDTH / 10;

	//Center point used to draw player square back to its position
	const SDL_Point center = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};

	//Top left point used to draw score
	const SDL_Point topLeft = {SCREEN_WIDTH / 15, SCREEN_HEIGHT / 20};

	//Variable used to keep track of time
	int elapsedTime = 0;

	//Time for displaying CPU moves in ms
	const int displayTime = 500;

	SDL_Manager manager = SDL_Manager (SCREEN_WIDTH, SCREEN_HEIGHT);
	GameSquares gameSquares = GameSquares (SCREEN_WIDTH / 5, SCREEN_HEIGHT / 5, SCREEN_WIDTH, SCREEN_HEIGHT, 2 * SQUARE_SIZE / 3, grey);
	PlayerSquare playerSquare = PlayerSquare (SCREEN_WIDTH / 2 - SQUARE_SIZE / 2, SCREEN_HEIGHT / 2 - SQUARE_SIZE / 2, SQUARE_SIZE, white);
	Lines lines = Lines (white, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_WIDTH / 5, SCREEN_HEIGHT / 5);
	GameLogic logic = GameLogic ();

	manager.init();

	Score score = Score ("data/visitor.ttf", white, SCREEN_WIDTH / 5);
	SDL_Renderer* renderer = manager.getRenderer();
	SDL_Event event;
	bool quit = false;
	bool drawn = false;
	bool pause = true;
	int i = 0;
	int countedFrames = 0;
	Timer fpsTimer;
	Timer capTimer;

	fpsTimer.start ();

	//Main game loop
	while (!quit) {
		capTimer.start ();
		if (logic.isPlayerTurn()) {
			//Event handling
			while (SDL_PollEvent (&event) != 0 ){
				if (event.type == SDL_QUIT)
					quit = true;
				else if (event.type == SDL_KEYDOWN) {
					switch(event.key.keysym.sym){
						case SDLK_UP:
							if (logic.noneIsPressed()) {
								playerSquare.drawTo (renderer, gameSquares.getCenter(S_TOP), black);
								logic.setPressed(S_TOP);
							}
							break;
						case SDLK_RIGHT:
							if (logic.noneIsPressed()) {
								playerSquare.drawTo (renderer, gameSquares.getCenter(S_RIGHT), black);
								logic.setPressed(S_RIGHT);
							}
							break;
						case SDLK_DOWN:
							if (logic.noneIsPressed()) {
								playerSquare.drawTo (renderer, gameSquares.getCenter(S_DOWN), black);
								logic.setPressed(S_DOWN);
							}
							break;
						case SDLK_LEFT:
							if (logic.noneIsPressed()) {
								playerSquare.drawTo (renderer, gameSquares.getCenter(S_LEFT), black);
								logic.setPressed(S_LEFT);
							}
							break;
					}
				}

				else if (event.type == SDL_KEYUP) {
					switch(event.key.keysym.sym){
						case SDLK_UP:
							if (logic.onlyThisIsPressed (S_TOP)) {
								playerSquare.drawTo (renderer, center, black);
								logic.setUnpressed (S_TOP);
								logic.addPlayerMove (S_TOP);
							}
							break;
						case SDLK_RIGHT:
							if (logic.onlyThisIsPressed (S_RIGHT)) {
								playerSquare.drawTo (renderer, center, black);
								logic.setUnpressed (S_RIGHT);
								logic.addPlayerMove (S_RIGHT);
							}
							break;
						case SDLK_DOWN:
							if (logic.onlyThisIsPressed (S_DOWN)) {
								playerSquare.drawTo (renderer, center, black);
								logic.setUnpressed (S_DOWN);
								logic.addPlayerMove (S_DOWN);
							}
							break;
						case SDLK_LEFT:
							if (logic.onlyThisIsPressed (S_LEFT)) {
								playerSquare.drawTo (renderer, center, black);
								logic.setUnpressed (S_LEFT);
								logic.addPlayerMove (S_LEFT);
							}
							break;
					}

					if (logic.areMoveLengthsEqual ()) {
						if (logic.areMovesEqual()) {
							logic.nextLevel ();
							score.increase ();
						}
						else {
							logic.reset ();
							score.reset ();
						}

						logic.toggleTurn (); //In any case, toggle the turn
						elapsedTime = SDL_GetTicks ();
						i = 0;
						drawn = false;
					}
				}
			}
		}
		else { //cpu turn
			if (pause == false) {
				Side tmpSide = logic.getCPUMoveAt (i);

				if (drawn == false) {
					gameSquares.setSizeInPlace (tmpSide, SQUARE_SIZE);
					gameSquares.setColor (tmpSide, green);
					drawn = true;
				}

				if (SDL_GetTicks () - elapsedTime >= displayTime) {
					gameSquares.setSizeInPlace (tmpSide, 2 * SQUARE_SIZE / 3);
					gameSquares.setColor (tmpSide, grey);
					elapsedTime = SDL_GetTicks ();
					pause = true;
					drawn = false;
					i++;
					if (i >= logic.getCPUMovesNum ())
						logic.toggleTurn ();
				}
			}
			else {
				if (SDL_GetTicks () - elapsedTime >= displayTime){
					elapsedTime = SDL_GetTicks ();
					pause = false;
				}
			}

			while (SDL_PollEvent (&event) != 0 ){
				if (event.type == SDL_QUIT)
					quit = true;
			}
		}

		//Calculate and correct fps
		float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
		if (avgFPS > 2000000)
			avgFPS = 0;

		//Drawing section
		SDL_SetRenderDrawColor (renderer, black.r, black.g, black.b, black.a);
		SDL_RenderClear (renderer);
		lines.draw (renderer);
		gameSquares.draw (renderer);
		playerSquare.draw (renderer);
		score.write (renderer, topLeft);
		SDL_RenderPresent (renderer);

		countedFrames++;
		//If frame finished early
		int frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICK_PER_FRAME)
			SDL_Delay (SCREEN_TICK_PER_FRAME - frameTicks); //Wait remaining time
	}

	return 0;
}
