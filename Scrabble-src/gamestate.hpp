/*
 * gamestate.hpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Admin
 */

#pragma once
#include "tools.hpp"
#include "board.hpp"
#include "player.hpp"
#include "gamestateobserver.hpp"
#include "dictionary.hpp"

// forward declaration to get it to compile
class GameStateObserver;

class GameState {
private:
	Board * board;
	Player * player1;
	Player * player2;
	vector<GameStateObserver*> observers;

public:
	// whose turn is it
	int turn;

	void addObserver(GameStateObserver*);
	// tell all the observers to update themselves
	void notifyObservers();

	Player * getPlayer(int);

	Board * getBoard();

	// returns true iff move was completed successfully
	bool makeMove(int player, char* word, int length, int x, int y, bool vert);

	GameState();
	~GameState();
};
