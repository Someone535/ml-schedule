#include "jsonStrParser.h"

JsonStrParser::print_output() {
	for ( lexeme l : output  ) {
		cout << l.type << endl;
	}
}
