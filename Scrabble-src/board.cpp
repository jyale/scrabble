/*
 * board.cpp
 *
 *  Created on: Dec 8, 2010
 *      Author: Admin
 */

#include "board.hpp"

// last 2 pass by reference are for returning a char array of req letters and its length
bool Board::addWord(char * s, int wordLength, int row, int col, bool vert,
		Player * curPlayer, char* &reqChars, int &m) {

	// check word length
	if (wordLength > 7) {
		cout << "Word too long" << endl;
		return false;
	}

	if (!vert) {
		// add word horizontally

		// first check that it fits
		if (row + wordLength < 15) {
			// should fit

			// now check for invalid letters
			// build up new array of chars to check
			// first time round just count up the number
			int k = 0;
			for (int i = 0; i < wordLength; i++) {
				if (board[row + i][col] != 27) {
					if (board[row + i][col] != int(s[i]) - 97) {
						return false;
					}
				} else {
					k++;
				}
			}

			// this time copy the required chars
			reqChars = new char[k];
			m = 0;
			for (int i = 0; i < wordLength; i++) {
				if (board[row + i][col] != 27) {

				} else {
					reqChars[m] = s[i];
					m++;
				}
			}

			//			cout << reqChars << " " << m << endl;
			// now check the player has the req chars
			if (curPlayer->hasLetters(reqChars, k)) {

				// fits and no letter conflicts so can add word

				for (int i = 0; i < wordLength; i++) {
					board[row + i][col] = int(s[i]) - 97;
				}
				return true;
			} else {
				cout << "Insufficient letters" << endl;
				return false;
			}
		} else {
			cout << "Word does not fit" << endl;

			return false;
		}
	} else {
		// add word vertically

		if (col + wordLength < 15) {

			// now check for invalid letters
			// build up new array of chars to check
			// first time round just count up the number
			int k = 0;
			for (int i = 0; i < wordLength; i++) {
				if (board[row][col + i] != 27) {
					if (board[row][col + i] != int(s[i]) - 97) {
						return false;
					}
				} else {
					k++;
				}
			}

			// this time copy the required chars
			reqChars = new char[k];
			m = 0;
			for (int i = 0; i < wordLength; i++) {
				if (board[row][col + i] != 27) {

				} else {
					reqChars[m] = s[i];
					m++;
				}
			}

			//			cout << reqChars << " " << m << endl;
			// now check the player has the req chars
			if (curPlayer->hasLetters(reqChars, k)) {

				// fits and no letter conflicts so can add word

				for (int i = 0; i < wordLength; i++) {
					board[row][col + i] = int(s[i]) - 97;
				}
				return true;
			} else {
				cout << "Insufficient letters" << endl;
				return false;
			}

			/*
			 // now check for invalid letters
			 for (int i = 0; i < wordLength; i++) {
			 if (board[row][col + i] != 27) {
			 cout << board[row][col + i] << endl;
			 if (board[row][col + i] != int(s[i]) - 97) {
			 cout << "err" << endl;

			 return false;
			 }
			 }
			 }

			 for (int i = 0; i < wordLength; i++) {
			 board[row][col + i] = int(s[i]) - 97;
			 }
			 return true;*/
		} else {
			cout << "Word does not fit" << endl;

			return false;
		}
	}
}

void Board::printBoard() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cout << char(board[j][i] + 97);
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

Board::Board() {
	//initialize board to all 27s (empty)
	//	cout << "initializing board" << endl;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			board[j][i] = 27;
		}
	}
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}
