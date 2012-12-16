/*
 * board.hpp
 *
 *  Created on: Dec 8, 2010
 *      Author: Admin
 */

#pragma once

#include "tools.hpp"
#include "player.hpp"

class Board {
private:

	// integer from 1-26 represents letter on board
	int board[15][15];

public:
	Board();
	~Board();
	// add word (word, row, col, Matrix style)
	// row and col indexed from zero

	// return false if could not add word, else true
	bool addWord(char *, int, int, int, bool, Player*, char*&, int&);
	void printBoard();
};
