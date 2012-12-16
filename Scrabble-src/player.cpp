/*
 * player.cpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Admin
 */

#include "player.hpp"

void Player::swapLetters(char* charsIn, char* charsOut, int length) {

	// go over all chars in length
	for (int i = 0; i < length; i++) {
		// find the first char in the charsOut
		for (int j = 0; j < handSize; j++) {
			if (charsOut[i] == charHand[j]) {
				// swap it for the chars in one
				charHand[j] = charsIn[i];
				break;
			}
		}
	}
	// update the hand
	hand = letToNum(charHand, handSize);
}

char * Player::numToLet(int * array, int len) {
	char * charArr = new char[len];
	for (int i = 0; i < len; i++) {
		charArr[i] = char(array[i] + 97);
	}
	return charArr;
}

int * Player::letToNum(char * array, int len) {
	int * intArr = new int[len];
	for (int i = 0; i < len; i++) {
		intArr[i] = int(array[i]) - 97;
	}
	return intArr;
}

void Player::useLetters(char* chars2, int length) {
	char* chars = chars2;
	// allocate new array of
	char * tempArr = new char[handSize - length];
	// copy non removed chars to new array
	int k = 0;
	for (int i = 0; i < handSize; i++) {
		if (!inArray(charHand[i], chars, length)) {
			// copy to new array
			tempArr[k] = charHand[i];
			k++;
		} else {
			// remove from the array of chars to exclude
			cout << chars << endl;

			chars = removeFirstChar(charHand[i], chars, length);
			cout << chars << endl;
		}
	}

	delete[] charHand;
	charHand = tempArr;
	delete[] hand;
	handSize = handSize - length;
	hand = letToNum(charHand, handSize);

}

char * Player::removeFirstChar(char c, char * array, int len) {
	char * newArr = new char[len - 1];
	int k = 0;
	bool found = false;
	for (int i = 0; i < len; i++) {
		if (!found) {
			if (array[i] != c) {
				// copy
				newArr[k] = array[i];
				k++;
			}
			found = true;
		} else {
			newArr[k] = array[i];
			k++;
		}
	}
	return newArr;
}

bool Player::hasLetters(char* letter, int len) {
	for (int i = 0; i < len; i++) {
		if (!inArray(letter[i], charHand, handSize)) {
			return false;
		}
	}
	return true;
}

void Player::newLetters(char* oldLetters, int len) {
	// pick some new letters
	int* newLetters = letters->pickLetters(len);
	char * newLetChar = numToLet(newLetters, len);
	delete newLetters;
	swapLetters(newLetChar, oldLetters, len);

}

/*
 void Player::useLetters(char* chars, int length) {
 // create new char array of appropriate length
 char * newHand = new char[length];

 // create multiset of chars
 multiset<char> charSet;

 // copy chars to multiset
 for (int i = 0; i < length; i++) {
 charSet.insert(chars[i]);
 }

 // copy to new array
 int newI = 0;
 for (int i = 0; i < handSize; i++) {
 if (charSet.count(charhand[i]) > 0) {
 charSet.erase(charhand[i]);
 } else {
 newHand[newI] = charhand[i];
 }
 }

 delete[] hand;
 hand = newHand;

 }*/

bool Player::inArray(char c, char* arr, int len) {
	for (int i = 0; i < len; i++) {
		if (c == arr[i]) {
			return true;
		}
	}
	//	cout << "error in inArray" << endl;
	return false;
}

Player::Player() {
	// get the bag of letters remaining
	letters = Letters::getInstance();
	// pick a hand from the letters
	hand = letters->pickLetters(7);
	handSize = 7;

	charHand = numToLet(hand, handSize);
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}
