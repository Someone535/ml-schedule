#include "jsonToken.h"

Token::Token( token_type t, int c ) : type(t), char_num(c) {}   

Token::Token( token_type t, int c, string s ) : type(t), char_num(c) {
        literal = new string( s );
}

Token::Token( token_type t, int c, double d ) : type(t), char_num(c) {                                            literal = new double( d );
}

Token::~Token() {                                                                                                 if ( type == STRING ) { delete (string*)literal; }
        if ( type == NUMBER ) { delete (double*)literal; }                                                }
