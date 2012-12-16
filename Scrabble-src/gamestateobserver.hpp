/*
 * gamestateobserver.hpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Admin
 */

#pragma once
#include "tools.hpp"
#include "gamestate.hpp"

// forward declaration to get it to compile
class GameState;

class GameStateObserver {
private:

protected:
	GameState * gameState;
public:

	// called when then game state changes
	// updates the current "view" (since this is command line application, with just print stuff out
	virtual void update();

	GameStateObserver();
	~GameStateObserver();
};
