#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include "InputHandler.h"

void exitProgram() {
	cout << "wrong input";
	exit(0);
}

void runProgram() {
	int numOfLines = 0;
	string input;
	int numOfActions = getANativeNum();
	getline(cin, input);
	while (input!= END_LINE)
	{
		if (++numOfLines > numOfActions) {
			exitProgram();
		}
		if (isMedianAction(input)) {
			//run median action
		}
		else if (isNewStructureAction(input)) {
			//create new structure
		}
		else if (isInsertAction(input)) {
			string token, value;
			int key;
			stringstream ss(input);
			getline(ss, token, ' ');
			getline(ss, token, ' ');
			stringstream(token) >> key;
			getline(ss, value, ' ');
			//insert (send key&val)
		}
		else {
			exitProgram();
		}
		getline(cin, input);
	}
}



int main() {
	runProgram();
}