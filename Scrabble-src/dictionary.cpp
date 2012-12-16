#include "dictionary.hpp"

bool Dictionary::checkDictionary(string t) {

	ifstream fin("dict.txt");
	string s;
	bool permitted = false;

	while (getline(fin, s)) {
		if (s.find(t) != string::npos) {
			permitted = true;
			break;
		}
	}
	if (permitted) {
//		cout << "permitted: ";
//		cout << t << endl;
		return true;
	} else {
		cout << "not permitted: ";
		cout << t << endl;
		return false;
	}

	/*
	 string line;
	 string * words = new string[380645];
	 ifstream myfile("dict.txt");
	 if (myfile.is_open()) {
	 int i = 0;
	 while (myfile.good()) {
	 getline(myfile, line);
	 //cout << line << endl;
	 words[i] = line;
	 i++;
	 }
	 myfile.close();
	 }

	 else
	 cout << "Unable to open file";
	 delete[] words;
	 */
}

