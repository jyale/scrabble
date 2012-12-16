/*
 * inputcontroller.hpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Admin
 */

#pragma once
#include "tools.hpp"
#include "gamestate.hpp"

/**
 * This class will handle user input in the model view controller MVC design pattern
 */
class InputController {
private:
	GameState * gameState;
	bool firstTime;
public:
	InputController(GameState*);
	~InputController();

	void start();
};
