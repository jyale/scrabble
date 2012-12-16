/*
 * gamestate.cpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Admin
 */

#include "gamestate.hpp"

void GameState::addObserver(GameStateObserver* g) {
	observers.push_back(g);
}

void GameState::notifyObservers() {
	//	cout << "notifying observer " << endl;

	for (int i = 0; i < observers.size(); ++i) {
		observers[i]->update();
	}
}

bool GameState::makeMove(int player, char* word, int length, int row, int col,
		bool vert) {
	// check word is in dictionary
	Dictionary * d = new Dictionary();
	string myStr = string(word);
	myStr = myStr.substr(0, length);
	if ((d->checkDictionary(myStr))) {
		// word is permitted
		//		cout << "Word permitted" << endl;
		// now check whether player has sufficient letters


		Player * curPlayer = getPlayer(player);
		//		if (curPlayer->hasLetters(word, length)) {
		// now check the board itself when adding the word
		char * reqChars;
		int lenOut;
		if (board->addWord(word, length, row, col, vert, curPlayer, reqChars,
				lenOut)) {
			// successfully added word
			// now update the player's hand
			//			curPlayer->newLetters(word, length);
			curPlayer->newLetters(reqChars, lenOut);

			// change the player turn
			if (turn == 1) {
				turn = 2;
			} else {
				turn = 1;
			}

			// notify all observers/viewers
			notifyObservers();

			return true;
		} else {
			// bad word
			cout << "Unable to add word - invalid move" << endl;
			return false;
		}

		//		} else {
		//			// player does not have correct letters
		//			cout << "Player " << player << " does not have required letters"
		//					<< endl;
		//			return false;
		//		}
	} else {
		// word is not permitted
		cout << "Word not in dictionary" << endl;
		return false;
	}

}

Board * GameState::getBoard() {
	return board;
}

Player * GameState::getPlayer(int n) {
	if (n == 1) {
		return player1;
	} else if (n == 2) {
		return player2;
	}
	cout << "error in GameState::getPlayer" << endl;
}

GameState::GameState() {
	player1 = new Player();
	player2 = new Player();
	turn = 1;
	board = new Board();

}

GameState::~GameState() {
	delete player1;
	delete player2;
	delete board;
}
