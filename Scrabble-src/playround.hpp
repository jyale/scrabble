/*
 * playround.hpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Admin
 */

#pragma once
#include "tools.hpp"
#include "gamestate.hpp"
#include "inputcontroller.hpp"
#include "playerobserver.hpp"
#include "boardobserver.hpp"
#include "letters.hpp"

class PlayRound {
private:
	GameState * gameState;
	InputController * controller;
	PlayerObserver * player1;
	PlayerObserver * player2;
	BoardObserver * boardObserver;
	Letters * letters;
public:
	PlayRound();
	~PlayRound();
	void playGame();
};
