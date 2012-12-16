/*
 * playerobserver.cpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Admin
 */

#include "playerobserver.hpp"

// print out player details
void PlayerObserver::update() {
	Player * p = gameState->getPlayer(playerNum);
	cout << "Player " << playerNum << "'s hand: ";
	p->printHand();
}

PlayerObserver::PlayerObserver(GameState * g, int num) {
	// the model is the game state
	gameState = g;
	playerNum = num;

}

PlayerObserver::~PlayerObserver() {
	// TODO Auto-generated destructor stub
}
