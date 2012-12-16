/*
 * boardobserver.cpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Admin
 */

#include "boardobserver.hpp"

void BoardObserver::update() {
	gameState->getBoard()->printBoard();
	cout << "Player " << gameState->turn << "'s turn" << endl << endl;
}

BoardObserver::BoardObserver(GameState * g) {
	gameState = g;

}

BoardObserver::~BoardObserver() {
	// TODO Auto-generated destructor stub
}
