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



int* getArr(int size) {
	int* arr = new int[size];
	string input;
	int currentSizeCounter = 0;
	stringstream ss;
	getline(cin, input);
	ss << input;
	string tmp;
	int candidateNum;
	while (!ss.eof()) {
		if (currentSizeCounter > size) return 0;
		ss >> tmp;
		if ((stringstream(tmp) >> candidateNum) && (candidateNum > 0)) {
			arr[currentSizeCounter++] = candidateNum;
			tmp = " ";
		}
		else return 0;
	}
	if (currentSizeCounter == size)
		return arr;
	return 0;
}


bool isInsertAction(string line) {
	return true;
}

bool isValidAction(string line) {
	if (line == MEDIAN || line == CREATE_NEW_STRUCTURE || isInsertAction(line))
		return true;
	return false;
}




string* getInput() {
	string input;
	stringstream ss;
	//int actionsCount = 0;
	int numOfActions = getANativeNum();
	string* actions = new string[numOfActions];
	if (numOfActions == WRONG_INPUT)return NULL;
	for (int i = 0; i < numOfActions; i++) {
		getline(cin, input);
		if (isValidAction(input))
			actions[i] = input;
		else return NULL;
	}
	//if(!(ss<<inp).eof())
	return actions;

}