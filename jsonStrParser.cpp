#include "jsonStrParser.h"

Token JsonStrParser::consume() { return tokens[ current++ ]; }
void JsonStrParser::advance() { current++; }
Token JsonStrParser::peek() { return tokens[ current ]; }
Token JsonStrParser::previous() { return tokens[ current - 1 ]; }
bool JsonStrParser::match( vector<token_type> types ) {
	for ( auto t : types ) {
		if ( check( t ) ) return true;
	}
	return false;
}
bool JsonStrParser::check( token_type t ) {
	if ( atEnd() ) return false;
	return peek().type == t;
}
bool JsonStrParser::atEnd() { return current >= tokens.size(); }

JsonValue* JsonStrParser::parse_value() {

	Token t = peek();

	switch ( t.type ) {

		case LEFTCURLY: return parse_object();
		case LEFTSQUARE: return parse_array();
		case STRING: advance(); return new JsonString( t.literal.str );
		case NUMBER: advance(); return new JsonNumber( t.literal.dbl );
		case BOOL: advance(); return new JsonBool( t.literal.bl );
		case NILL: advance(); return new JsonNull();

		default:
			return nullptr;
	}

}

JsonObject* JsonStrParser::parse_object() {

	JsonObject* obj = new JsonObject();

	advance();

	while ( peek().type != RIGHTCURLY ) {
		obj->add_member( parse_pair() );
		if ( peek().type == COMMA ) advance();
	}

	advance();

	return obj;
}

JsonPair* JsonStrParser::parse_pair() {

	string n = consume().literal.str;

	advance();

	JsonValue* v = parse_value();

	return new JsonPair( n, v );

}

JsonArray* JsonStrParser::parse_array() {

	JsonArray* arr = new JsonArray();

	advance();

	while ( peek().type != RIGHTSQUARE ) {
		arr->add_element( parse_value() );
		if ( peek().type == COMMA ) advance();
	}

	advance();

	return arr;
}

JsonStrParser::JsonStrParser( vector<Token> input ) : tokens(input), current(0), output(nullptr) {

	output = parse_value();

}
