#include "InputHandler.h"

int getANativeNum() {
	string input;
	int candidateNum, tmp;
	stringstream ss;

	getline(cin, input);
	ss << input;
	ss >> tmp;
	if (ss.eof()) { //validate we get only one word
		//validate this word is a nateive number
		if ((stringstream(input) >> candidateNum) && (candidateNum > 0))
			return candidateNum;
	}
	return -1;
}

int isValidNum(string input) {
	int candidateNum, tmp;
	stringstream ss;

	ss << input;
	ss >> tmp;
	if (ss.eof()) { //validate we get only one word
		//validate this word is a nateive number
		if ((stringstream(input) >> candidateNum) && (candidateNum >= 0))
			return candidateNum;
	}
	return 0;
}

bool isInsertAction(string line) {
	int countOfString = 0;
	string token;  
	stringstream ss(line); 
	getline(ss, token, ' ');
	if (token!= INSERT) return false;
	countOfString++;
	getline(ss, token, ' ');
	if((countOfString==line.length())||!(isValidNum(token))) return false;
	countOfString += token.length()+1;
	if (countOfString==line.length()) return false;
	return true;
}


bool isMedianAction(string line) {
	if (line == MEDIAN)
		return true;
	return false;
}


bool isNewStructureAction(string line) {
	if (line == CREATE_NEW_STRUCTURE)
		return true;
	return false;
}
