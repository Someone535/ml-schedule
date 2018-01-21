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

	void addToken( token_type t, int c );
	void addToken( token_type t, int c, string s );
	void addToken( token_type t, int c, double d );

	char consume();
	void advance();
	char peek();
	bool atEnd();

	void scan_token();

	public:

	JsonStrScanner( string input );
	void print_tokens();
	vector<Token> return_tokens() { return tokens; }

};

#endif
