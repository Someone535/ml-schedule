#include "jsonStrScanner.h"

JsonStrScanner::JsonStrScanner( string input ) {

	file = input;

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
