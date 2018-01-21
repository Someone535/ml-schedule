#include "jsonStrScanner.h"

void JsonStrScanner::addToken( token_type t, int c ) { tokens.push_back( Token( t, c ) ); }
void JsonStrScanner::addToken( token_type t, int c, string s ) { tokens.push_back( Token( t, c, s ) ); }
void JsonStrScanner::addToken( token_type t, int c, double d ) { tokens.push_back( Token( t, c, d ) ); }

char JsonStrScanner::consume() { return file[current++]; }
void JsonStrScanner::advance() { current++; }
char JsonStrScanner::peek() { return file[current]; }
char JsonStrScanner::peek_twice() { return file[current + 1]; }
bool JsonStrScanner::atEnd() { return current >= file.length(); }
bool JsonStrScanner::nearEnd() { return current + 1 >= file.length(); }
bool JsonStrScanner::isNum( char c ) { return ( c == '-' ) or ( 48 < c and c < 57 ); }

void JsonStrScanner::scan_token() {
	char c = consume();
	switch (c) {
		case '{': addToken( LEFTCURLY, current - 1 ); break;
		case '}': addToken( RIGHTCURLY, current - 1 ); break;
		case '[': addToken( LEFTSQUARE, current - 1 ); break;
		case ']': addToken( RIGHTSQUARE, current - 1 ); break;
		case ':': addToken( COLON, current - 1 ); break;
		case ',': addToken( COMMA, current - 1 ); break;

		case '\t':
		case '\n':
		case '\f':
		case '\v':
		case ' ':
		case '\r': break;

		case '"':
			   while ( peek() != '"' && !atEnd() ) { advance(); }
			   addToken( STRING, start, file.substr( start + 1, current - start - 1 ) );
			   advance();
			   break;

		default: 
			if ( isNum(c) ) {
				while ( isNum( peek() ) or peek() == '.' ) {
					advance();
					if ( !nearEnd() && isNum( peek_twice() ) ) {
						advance();
						while ( isNum( peek() ) ) { advance(); }
					}
				}
				double num = atof( file.substr( start, current - start ).c_str() );
				addToken( NUMBER, start, num );
			}
			break;
	}
	start = current;
}

JsonStrScanner::JsonStrScanner( string input ) {

	file = "test {1.2}[],:\"abcd\"{} ,;\"poop\"{55";
	cout<<file<<endl<<endl;

	start = 0;
	current = 0;

	while ( !atEnd() ) {
		scan_token();
	}
}

void JsonStrScanner::print_tokens() {
	for ( Token t : tokens ) {
		cout << to_string( t.char_num) << " " << to_string( t.type );
		if ( t.type == NUMBER ) {
			cout << " " << to_string( t.literal.dbl );
		}
		else if ( t.type == STRING ) {
			cout << " " << t.literal.str;
		}
		cout << endl;
	}
}
