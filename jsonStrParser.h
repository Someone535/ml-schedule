#ifndef __JSONSTRPARSER_H
#define __JSONSTRPARSER_H

#include <string>
#include <iostream>
#include <vector>

enum token {
	LEFTCURLY, RIGHTCURLY, 
	LEFTSQUARE, RIGHTSQUARE, 
	COLON, COMMA,
	STRING, NUMBER
};

class lexeme {
	token type;
	int char_num;
	void* literal;
};

class JsonStrParser {

	string file;
	int cur;
	vector<lexeme> output;

	vector<lexeme> parse();

	char consume();
	void advance();
	char peek();

	public:

	JsonStrParser( string input );
	void print_output();

}

#endif
