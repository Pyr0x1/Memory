#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "GameLogic.h"

GameLogic::GameLogic() {

	for (int i = 0; i < S_NUM; i++)
		this->pressed[i] = false;

	this->playerTurn = false; //cpu starts playing
	this->level = 1;

	srand (time (NULL)); //Initialize pseudo-randomness with time
	Side random = (Side) (rand() % S_NUM); //Generate random value for side

	this->cpuMoves.push_back(random); //Push back value as first cpu move
}

bool GameLogic::noneIsPressed () {

	bool nonePressed = true;

	for (int i = 0; i < S_NUM; i++) {
		if (this->pressed[i] == true) {
			nonePressed = false;
			break;
		}
	}

	return nonePressed;
}

bool GameLogic::onlyThisIsPressed (Side side) {

	bool thisPressed = true;

	for (int i = 0; i < S_NUM; i++) {
		if (i != side && this->pressed[i] == true) {
			thisPressed = false;
			break;
		}
		else if (i == side && this->pressed[i] == false) {
			thisPressed = false;
			break;
		}
	}

	return thisPressed;
}

void GameLogic::setPressed (Side side) {

	this->pressed[side] = true;

	return ;
}

void GameLogic::setUnpressed (Side side) {

	this->pressed[side] = false;

	return ;
}

void GameLogic::addPlayerMove (Side move) {

	this->playerMoves.push_back (move);

	return ;
}

void GameLogic::newMoveSet () {

	this->cpuMoves.clear();
	this->playerMoves.clear();

	for (int i = 0; i < this->level; i++) {
		Side random = (Side) (rand() % S_NUM);
		this->cpuMoves.push_back(random);
	}

	return ;
}

bool GameLogic::areMovesEqual () {

	this->printCPUMoves();
	this->printPlayerMoves();

	if (this->cpuMoves == this->playerMoves)
		return true;
	else
		return false;
}

bool GameLogic::areMoveLengthsEqual () {

	if (this->cpuMoves.size() == this->playerMoves.size())
			return true;
		else
			return false;
}

void GameLogic::nextLevel () {

	this->level++;
	this->newMoveSet();

	return ;
}

void GameLogic::reset () {

	this->level = 1;
	this->newMoveSet();

	return ;
}

bool GameLogic::isPlayerTurn () {

	return this->playerTurn;
}

void GameLogic::toggleTurn () {

	this->playerTurn = !this->playerTurn;
}

int GameLogic::getCPUMovesNum () {

	return this->cpuMoves.size();
}

Side GameLogic::getCPUMoveAt (int position) {

	return this->cpuMoves[position];
}

void GameLogic::printCPUMoves () {

	printf ("CPU: ");

	for (int i = 0; i < this->cpuMoves.size(); i++)
		printf ("%d  ", this->cpuMoves[i]);

	printf ("\n");
}

void GameLogic::printPlayerMoves () {

	printf ("Player: ");

	for (int i = 0; i < this->playerMoves.size(); i++)
		printf ("%d  ", this->playerMoves[i]);

	printf ("\n");
}

GameLogic::~GameLogic() {

}
