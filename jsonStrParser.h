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
        JsonValue output;

	Token consume();
	Token peek();
	void advance();
	Token previous();
	bool match( vector<token_type> types );
	bool check( token_type t );
	bool atEnd();

	JsonValue parse_value();
	JsonObject parse_object();
	JsonArray parse_array();
	JsonPair parse_pair();

        public:

        JsonStrParser( vector<Token> input );

};

#endif
