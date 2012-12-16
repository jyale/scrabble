//============================================================================
// Name        : Scrabble.cpp
// Author      : John Maheswaran
// Version     :
// Copyright   : Copyright 2010
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "tools.hpp"
#include "dictionary.hpp"
#include "letters.hpp"
#include "board.hpp"
#include "player.hpp"
#include "playround.hpp"

using namespace std;

int main() {
	srand(time(NULL));

	PlayRound * play = new PlayRound();
	play->playGame();

	delete play;

	return 0;
}
