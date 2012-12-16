/*
 * playround.cpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Admin
 */

#include "playround.hpp"

PlayRound::PlayRound() {
	gameState = new GameState();
	controller = new InputController(gameState);
	player1 = new PlayerObserver(gameState, 1);
	player2 = new PlayerObserver(gameState, 2);
	boardObserver = new BoardObserver(gameState);
	letters = Letters::getInstance();


	// add observers to gamestate

	gameState->addObserver(boardObserver);
	gameState->addObserver(player1);
	gameState->addObserver(player2);
}

void PlayRound::playGame() {

	cout << "Welcome to John's simple Scrabble inspired word game." << endl
			<< endl << "This is a two player collaborative game." << endl
			<< "The objective is to try to make as many words as possible between "
			<< endl
			<< "you on the 15x15 grid. Each player has a hand of letters. They "
			<< endl
			<< "take turns to make a word on the grid. This continues until either "
			<< endl
			<< "a player is unable to make a word or all the letters run out."
			<< endl
			<< "You then see how many letters/words you have managed to put down on the board."
			<< endl
			<< "There is no restriction on where you may place words. Only that they "
			<< endl << "cannot contradict existing words on the grid." << endl
			<< endl << "Enjoy!" << endl << endl;

	while (!(letters->numLetters <= 0 || letters->numLetters > 100)) {
		controller->start();
	}
	cout << endl << "No letters left" << endl;
	cout << endl << "Game Over" << endl;
}

PlayRound::~PlayRound() {
	delete gameState;
	delete controller;
	delete player1;
	delete player2;
	delete boardObserver;
}
