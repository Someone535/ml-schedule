#ifndef __JSONSTRPARSER_H
#define __JSONSTRPARSER_H

#include <string>
#include <vector>
#include <iostream>

#include "jsonToken.h"
#include "jsonValue.h"

using namespace std;

class JsonStrParser {

        int current;
        vector<Token> tokens;
        JsonValue* output;

	Token consume();
	Token peek();
	Token previous();
	bool match( token_type types );
	bool check( token_type t );
	bool atEnd();

        public:

        JsonStrParser( vector<Token> input );

};

#endif
