#ifndef TIMER_H_
#define TIMER_H_

#include <SDL2/SDL.h>

class Timer {

	private:
		Uint32 startTicks;
		Uint32 pausedTicks;
		bool paused;
		bool started;

	public:
		Timer();
		void start();
		void stop();
		void pause();
		void unpause();
		Uint32 getTicks();
		bool isStarted();
		bool isPaused();
		~Timer();
};

#endif /* TIMER_H_ */
