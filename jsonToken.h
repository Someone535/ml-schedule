#ifndef __JSONTOKEN_H
#define __JSONTOKEN_H

#include <string>

using namespace std;

enum token_type {
        LEFTCURLY, RIGHTCURLY,
        LEFTSQUARE, RIGHTSQUARE,                                                                                  COLON, COMMA,                                                                                             STRING, NUMBER,
	BOOL, NILL
};

inline string token_type_to_string( token_type t ) {                                                                     switch (t) {                                                                                                      case LEFTCURLY: return "{";                                                                               case RIGHTCURLY: return "}";                                                                              case LEFTSQUARE: return "[";                                                                              case RIGHTSQUARE: return "]";                                                                             case COLON: return ":";                                                                                   case COMMA: return ",";                                                                                   case STRING: return "str";                                                                                case NUMBER: return "num";   
		case BOOL: return "bool";
		case NILL: return "null";
		default: return "UNKNOWN";
        }
}

struct lit {
	double dbl;
	string str;
	bool bl;
};

class Token {                                                                                                     public:
                token_type type;
                int char_num;
		lit literal;

		string to_string();

                Token( token_type t, int c, string s );
                Token( token_type t, int c, double d );
		Token( token_type t, int c, bool b );
                Token( token_type t, int c );
};

#endif
