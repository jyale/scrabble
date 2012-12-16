/*
 * letters.hpp
 *
 *  Created on: Dec 7, 2010
 *      Author: Admin
 */

#pragma once
#include "tools.hpp"

class Letters {
	/**
	 * This class represents the letters available in the game
	 */
private:
	static Letters lettersInstance;

	Letters();
	~Letters() {
	}
	Letters(const Letters &); // intentionally undefined
	Letters & operator=(const Letters &); // intentionally undefined


	// the number of each letter remaining
	int letBlank;
	int letA;
	int letE;
	int letI;
	int letO;
	int letN;
	int letR;
	int letT;
	int letL;
	int letS;
	int letU;
	int letD;
	int letG;
	int letB;
	int letC;
	int letM;
	int letP;
	int letF;
	int letH;
	int letV;
	int letW;
	int letY;
	int letK;
	int letJ;
	int letX;
	int letQ;
	int letZ;

	int lettersArr[26];

	int RandomUniform(int);
	int findChar(int n);

public:
	static Letters * getInstance();
	// the number of letters remaining
	int numLetters;
	int * pickLetters(int);
	int * replaceLetters(int *);
	char * numToLet(int *);

};

