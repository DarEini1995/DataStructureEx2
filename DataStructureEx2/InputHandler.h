#ifndef InputHandler
#define InputHandler

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <sstream> 
#include <iostream>
#include<string.h>  
using namespace std;
#define END_LINE "\n\n"
#define CREATE_NEW_STRUCTURE "e"
#define INSERT "f"
#define MEDIAN "g"
#define WRONG_INPUT -1
#define _CRT_SECURE_NO_WARNINGS

string* getInput();
int getANativeNum();
int* getArr(int size);
bool isInsertAction(string line);
bool isMedianAction(string line);
bool isNewStructureAction(string line);
bool isInsertAction(string line);

#endif