#include "jsonStrScanner.h"

void JsonStrScanner::addToken( token_type t, int c ) { tokens.push_back( Token( t, c ) ); }
void JsonStrScanner::addToken( token_type t, int c, string s ) { tokens.push_back( Token( t, c, s ) ); }
void JsonStrScanner::addToken( token_type t, int c, double d ) { tokens.push_back( Token( t, c, d ) ); }

char JsonStrScanner::consume() { return file[current++]; }
void JsonStrScanner::advance() { current++; }
char JsonStrScanner::peek() { return file[current]; }
bool JsonStrScanner::atEnd() { return current >= file.length(); }

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

		default: break;
	}
	start = current;
}

JsonStrScanner::JsonStrScanner( string input ) {

	file = "test {}[],:\"abcd\"{} ,;\"abcd\"{} ,";
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
			cout << " " << to_string( *(double*)t.literal );
		}
		else if ( t.type == STRING ) {
			cout << " " << *(string*)t.literal;
		}
		cout << endl;
	}
}
