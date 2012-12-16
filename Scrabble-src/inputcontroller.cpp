/*
 * inputcontroller.cpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Admin
 */

#include "inputcontroller.hpp"

InputController::InputController(GameState* g) {
	gameState = g;
	firstTime = true;
}

void InputController::start() {
	if (firstTime) {
		// print out hands at start
		cout << "Player 1's hand: ";
		gameState->getPlayer(1)->printHand();
		cout << "Player 2's hand: ";
		gameState->getPlayer(2)->printHand();
		cout << "Player 1's turn" << endl;
		firstTime = false;
	}

	int row = -1;
	int col = -1;
	int vert = -1;
	string str;
	char * word2;
	bool isVert;

	do {
		cout << endl << "Enter your word: " << endl;
		cin >> str;

		while (!(row >= 0 && row < 15)) {
			cout << "Enter your row (from 1 to 15): " << endl;
			cin >> row;
			row--;
		}

		while (!(col >= 0 && col < 15)) {
			cout << "Enter your column (from 1 to 15): " << endl;
			cin >> col;
			col--;
		}

		while (!(vert == 1 || vert == 0)) {
			cout << "Place word vertically? (enter 1 for yes or 0 for no)"
					<< endl;
			cin >> vert;
		}

		const char * word = str.c_str();
		// copy to non const char *
		word2 = new char[str.length()];
		for (int i = 0; i < str.length(); i++) {
			word2[i] = word[i];
		}

		isVert = false;
		if (vert == 1) {
			isVert = true;
		} else {
			isVert = false;
		}
	} while (!gameState->makeMove(gameState->turn, word2, str.length(), col,
			row, isVert));

}

InputController::~InputController() {
	// TODO Auto-generated destructor stub
}
