#include "jsonToken.h"

Token::Token( token_type t, int c ) : type(t), char_num(c) {}   

Token::Token( token_type t, int c, string s ) : type(t), char_num(c) {
	literal.str = s;
}

Token::Token( token_type t, int c, double d ) : type(t), char_num(c) {
	literal.dbl = d;
}
