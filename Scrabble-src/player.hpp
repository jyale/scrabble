/*
 * player.hpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Admin
 */

#pragma once
#include "tools.hpp"
#include "letters.hpp"

class Player {

private:
	// the 7 letters in the players hand at present
	// FROM ZERO **0=a** to 25=z
	int * hand;

	// character array representation of hand
	char * charHand;
	// only less than 7 if at end of game
	int handSize;
	// pointer to letters class
	Letters * letters;

	char * numToLet(int * array, int len);
	int * letToNum(char * array, int len);

	bool inArray(char, char*, int);

	char * removeFirstChar(char c, char * array, int len);

	void swapLetters(char* charsIn, char* charsOut, int length);

public:

	// true iff the player has the letters in the input
	bool hasLetters(char* letter, int len);

	void newLetters(char* oldLetters, int len);

	void useLetters(char*, int);

	int * getHand() {
		return hand;
	}

	void printHand() {
//		for (int i = 0; i < handSize; i++) {
//			cout << hand[i] << " ";
//		}
//		cout << endl;

		for (int i = 0; i < handSize; i++) {
			cout << charHand[i] << " ";
		}
		cout << endl;
	}

	Player();
	~Player();
};
