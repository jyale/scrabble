/*
 * boardobserver.hpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Admin
 */

#pragma once
#include "gamestateobserver.hpp"
#include "tools.hpp"
#include "gamestate.hpp"

class BoardObserver: public GameStateObserver {
public:
	void update();

	BoardObserver(GameState * g);

	~BoardObserver();
};
