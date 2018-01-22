#include "jsonToken.h"

string Token::to_string() {
	string output = "Character: " + std::to_string( char_num ) + "   Type: " 
			+ token_type_to_string( type );
	switch (type) {
		case STRING: output += "   \"" + literal.str + "\""; break;
		case NUMBER: output += "   " + std::to_string( literal.dbl ); break;
		case BOOL: output += "   "; output += ( literal.bl ? "true" : "false" ); break;
	}
	return output;
}

Token::Token( token_type t, int c ) : type(t), char_num(c) {}   

Token::Token( token_type t, int c, string s ) : type(t), char_num(c) {
	literal.str = s;
}

Token::Token( token_type t, int c, double d ) : type(t), char_num(c) {
	literal.dbl = d;
}

Token::Token( token_type t, int c, bool b ) : type(t), char_num(c) {
	literal.bl = b;
}
