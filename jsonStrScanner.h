#ifndef __JSONSTRSCANNER_H
#define __JSONSTRSCANNER_H

#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>

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
	void addToken( token_type t, int c, bool b );

	char consume();
	void advance();
	bool cond_adv( char c );
	char peek();
	char peek_twice();
	bool atEnd();
	bool nearEnd();
	bool isNum( char c );

	void scan_token();

	public:

	JsonStrScanner( string input );
	void print_tokens();
	vector<Token> return_tokens() { return tokens; }

};

#endif
