/*
 * letters.cpp
 *
 *  Created on: Dec 7, 2010
 *      Author: Admin
 */

#include "letters.hpp"

Letters Letters::lettersInstance;

Letters * Letters::getInstance() {
	return &lettersInstance;
}

Letters::Letters() {
	// the number of letters remaining
	numLetters = 100;
	// the number of each letter remaining
	letBlank = 2;
	letA = 9;
	letE = 12;
	letI = 9;
	letO = 8;
	letN = 6;
	letR = 6;
	letT = 6;
	letL = 4;
	letS = 4;
	letU = 4;
	letD = 4;
	letG = 3;
	letB = 2;
	letC = 2;
	letM = 2;
	letP = 2;
	letF = 2;
	letH = 2;
	letV = 2;
	letW = 2;
	letY = 2;
	letK = 1;
	letJ = 1;
	letX = 1;
	letQ = 1;
	letZ = 1;

	// note this does not contain blank letters
	lettersArr[0] = letA;
	lettersArr[1] = letB;
	lettersArr[2] = letC;
	lettersArr[3] = letD;
	lettersArr[4] = letE;
	lettersArr[5] = letF;
	lettersArr[6] = letG;
	lettersArr[7] = letH;
	lettersArr[8] = letI;
	lettersArr[9] = letJ;
	lettersArr[10] = letK;
	lettersArr[11] = letL;
	lettersArr[12] = letM;
	lettersArr[13] = letN;
	lettersArr[14] = letO;
	lettersArr[15] = letP;
	lettersArr[16] = letQ;
	lettersArr[17] = letR;
	lettersArr[18] = letS;
	lettersArr[19] = letT;
	lettersArr[20] = letU;
	lettersArr[21] = letV;
	lettersArr[22] = letW;
	lettersArr[23] = letX;
	lettersArr[24] = letY;
	lettersArr[25] = letZ;

}

// This method will pick n letters from the remaining letters and then return them as a letter group

int* Letters::pickLetters(int n) {
	// if not enough letters left return what we have
	if (n > numLetters) {
		n = numLetters;
	}

	int * returnArr;
	returnArr = new int[n];

	for (int i = 0; i < n; i++) {
		// get a random number between 1 and the number of letters we have
		int num = RandomUniform(numLetters);
		// now pick that letter
		int letterIndex = findChar(num);
		returnArr[i] = letterIndex;
		// now remove a letter from the letter picked
		lettersArr[letterIndex]--;
		// now decrease the total number of letters remaining
		numLetters--;
	}

	return returnArr;

}

// given a number in range 1 to number of letters remaining, will return the corresponding character
int Letters::findChar(int randomNum) {

	// sum so far
	int total = 0;
	for (int i = 0; i < 26; i++) {
		total += lettersArr[i];
		if (randomNum < total) {
			return i;
		}
	}
	cout << "error in findChar";
}

// replaces an array of 7 letters and gets another 7
int * Letters::replaceLetters(int * in) {
	// first take the 7 letters and put them back
	for (int i = 0; i < 7; i++) {
		lettersArr[in[i]]++;
	}
	// delete the old letters array
	delete[] in;
	// now pick another 7 and return them
	return pickLetters(7);
}

// A method to take an array of ints of size 7 and return an array of char*s
char * Letters::numToLet(int * array) {
	char * charArr = new char[7];
	for (int i = 0; i < 7; i++) {
		charArr[i] = char(array[i] + 97);
	}
	return charArr;
}

// A method to generate a random number uniformly over the range
// {0,...,n-1} using the library function rand().
int Letters::RandomUniform(int n) {
	int top = ((((RAND_MAX - n) + 1) / n) * n - 1) + n;
	int r;
	do {
		r = rand();
	} while (r > top);
	return (r % n);
}

