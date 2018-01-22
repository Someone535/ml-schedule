#ifndef __JSONSTRPARSER_H
#define __JSONSTRPARSER_H

#include <string>
#include <vector>
#include <iostream>

#include "jsonToken.h"

enum json_value_type {
	JSON_V_STRING,
	JSON_V_NUMBER,
	JSON_V_BOOL,
	JSON_V_NULL,
	JSON_V_PAIR,
	JSON_V_OBJECT,
	JSON_V_ARRAY
};

class JsonVisitor {
	public:
}

class JsonValue {
	public:
		void accept_visitor( JsonVisitor visitor );
		json_value_type type;
		JsonValue( json_value_type t ) : type(t) {}
}

class JsonString: public JsonValue {
	public:
		string value;
		JsonString( string s ) : JsonValue( JSON_V_STRING ), value(s) {}
}

class JsonNumber: public JsonValue {
	public:
		double value;
		JsonNumber( double d ) : JsonValue( JSON_V_NUMBER ), value(d) {}
}

class JsonBool: public JsonValue {
	public:
		bool value;
		JsonBool( bool b ) : JsonValue( JSON_V_BOOL ), value(b) {}
}

class JsonNull: public JsonValue {
	public:
		JsonNull() : JsonValue( JSON_V_NULL ) {}
}

class JsonPair: public JsonValue {
	public:
		string name;
		JsonValue value;
}

class JsonObject: public JsonValue {
	public:
		vector<JsonPair> members;
}

class JsonArray: public JsonValue {
	public:
		vector<JsonValue> elements 
}

#endif
