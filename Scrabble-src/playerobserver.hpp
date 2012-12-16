/*
 * playerobserver.hpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Admin
 */

#pragma once
#include "gamestateobserver.hpp"
#include "tools.hpp"
#include "gamestate.hpp"

class PlayerObserver: public GameStateObserver {
private:
	int playerNum;

public:

	void update();

	PlayerObserver(GameState * g, int);
	~PlayerObserver();
};
