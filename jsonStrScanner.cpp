#include "jsonStrScanner.h"

void JsonStrScanner::addToken( token_type t, int c ) { tokens.push_back( Token( t, c ) ); }
void JsonStrScanner::addToken( token_type t, int c, string s ) { tokens.push_back( Token( t, c, s ) ); }
void JsonStrScanner::addToken( token_type t, int c, double d ) { tokens.push_back( Token( t, c, d ) ); }
void JsonStrScanner::addToken( token_type t, int c, bool b ) { tokens.push_back( Token( t, c, b ) ); }

char JsonStrScanner::consume() { return file[current++]; }
void JsonStrScanner::advance() { current++; }
char JsonStrScanner::peek() { return file[current]; }
char JsonStrScanner::peek_twice() { return file[current + 1]; }
bool JsonStrScanner::atEnd() { return current >= file.length(); }
bool JsonStrScanner::nearEnd() { return current + 1 >= file.length(); }

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

		case 't': {
			   string sample = file.substr( start, 4);
			   if ( sample.compare( "true" ) == 0 ) {
				advance(); advance(); advance();
				addToken( BOOL, start, true );
				break;
			   }
		}
		case 'f': {
			   string sample = file.substr( start, 5);
			   if ( sample.compare( "false" ) == 0 ) {
				advance(); advance(); advance();
				addToken( BOOL, start, false );
				break;
			   }
		}

		default: 
			if ( isdigit(c) or c == '-' ) {
				while ( isdigit( peek() ) ) { advance(); }
				if ( peek() == '.' ) { 
					advance();
					while ( isdigit( peek() ) ) { advance(); }
				}
				if ( peek() == 'E' or peek() == 'e' ) {
					advance();
					if ( peek() == '-' or peek() == '+' or isdigit( peek() ) ) {
						advance();
						while( isdigit( peek() ) ) { advance(); }
					}
				}
				double num = atof( file.substr( start, current - start ).c_str() );
				addToken( NUMBER, start, num );
				break;
			}
			break;
	}
	start = current;
}

JsonStrScanner::JsonStrScanner( string input ) {

	file = input;

	start = 0;
	current = 0;

	while ( !atEnd() ) {
		scan_token();
	}
}

void JsonStrScanner::print_tokens() {
	cout << "Printing Tokens..." << endl;
	for ( Token t : tokens ) {
		cout << t.to_string() << endl;
	}
	cout << endl;
}
