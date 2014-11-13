#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_

#include <vector>
#include "Side.h"

class GameLogic {

	private:
		bool pressed[4];
		bool playerTurn;
		int level;
		std::vector<Side> cpuMoves;
		std::vector<Side> playerMoves;

		void printCPUMoves (); //For debug
		void printPlayerMoves (); //For debug

	public:
		GameLogic ();
		bool noneIsPressed ();
		bool onlyThisIsPressed (Side side);
		void setPressed (Side side);
		void setUnpressed (Side side);
		void addPlayerMove (Side move);
		void newMoveSet ();
		bool areMovesEqual ();
		bool areMoveLengthsEqual ();
		void nextLevel ();
		void reset ();
		bool isPlayerTurn ();
		void toggleTurn ();
		int getCPUMovesNum ();
		Side getCPUMoveAt (int position);
		~GameLogic ();
};

#endif /* GAMELOGIC_H_ */
