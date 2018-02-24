#include "jsonStr.h"

JsonStr::JsonStr( string input ) : result(0), s(0), p(0) {

	s = new JsonStrScanner( input );

	p = new JsonStrParser( s->return_tokens() );

	result = p->return_output();

}

JsonStr::~JsonStr() {
	delete result;
	delete s;
	delete p;
}

JsonValue* JsonStr::return_result() {
	return result;
}

void JsonStr::print_scanner_tokens() {
	s->print_tokens();
}
