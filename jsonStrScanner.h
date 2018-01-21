#ifndef __JSONSTRSCANNER_H
#define __JSONSTRSCANNER_H

#include <string>
#include <iostream>
#include <vector>

#include "jsonToken.h"

using namespace std;

class JsonStrScanner {

	string file;
	int start;
	int current;
	vector<Token> tokens;

	vector<Token> parse();

	char consume();
	void advance();
	char peek();

	public:

	JsonStrScanner( string input );
	void print_tokens();

};

#endif
