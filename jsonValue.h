#ifndef __JSONVALUE_H
#define __JSONVALUE_H

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

class JsonVisitor;

class JsonValue {
	public:
		json_value_type type;
		JsonValue( json_value_type t ) : type(t) {}
		virtual ~JsonValue() {}
		void accept_visitor( JsonVisitor visitor );
};

class JsonString: public JsonValue {
	public:
		string value;
		JsonString( string s ) : JsonValue( JSON_V_STRING ), value(s) {}
		/* virtual */ void accept_visitor( JsonVisitor v );
};

class JsonNumber: public JsonValue {
	public:
		double value;
		JsonNumber( double d ) : JsonValue( JSON_V_NUMBER ), value(d) {}
		/* virtual */ void accept_visitor( JsonVisitor v );
};

class JsonBool: public JsonValue {
	public:
		bool value;
		JsonBool( bool b ) : JsonValue( JSON_V_BOOL ), value(b) {}
		/* virtual */ void accept_visitor( JsonVisitor v );
};

class JsonNull: public JsonValue {
	public:
		JsonNull() : JsonValue( JSON_V_NULL ) {}
		/* virtual */ void accept_visitor( JsonVisitor v );
};

class JsonPair: public JsonValue {
	public:
		string name;
		JsonValue* value;
		JsonPair( string s, JsonValue* v ) : JsonValue( JSON_V_PAIR ), name(s), value(v) {}
		~JsonPair();
		/* virtual */ void accept_visitor( JsonVisitor v );
};

class JsonObject: public JsonValue {
	public:
		vector<JsonPair*> members;
		JsonObject() : JsonValue( JSON_V_OBJECT ) {}
		~JsonObject();
		void add_member( JsonPair* p ) { members.push_back( p ); }
		/* virtual */ void accept_visitor( JsonVisitor v );
};

class JsonArray: public JsonValue {
	public:
		vector<JsonValue*> elements; 
		JsonArray() : JsonValue( JSON_V_ARRAY ) {}
		~JsonArray();
		void add_element( JsonValue* e ) { elements.push_back( e ); }
		/* virtual */ void accept_visitor( JsonVisitor v );
};

class JsonVisitor {
	public:
		virtual void visit_string( JsonString* s ) = 0;
		virtual void visit_number( JsonNumber* n ) = 0;
		virtual void visit_bool( JsonBool* b ) = 0;
		virtual void visit_null( JsonNull* n ) = 0;
		virtual void visit_pair( JsonPair* p ) = 0;
		virtual void visit_object( JsonObject* o ) = 0;
		virtual void visit_array( JsonArray* a ) = 0;

		void visit_value( JsonValue* v );
};

class JsonValuePrinter : public JsonVisitor {

	int depth = 0;

	public:

		JsonValuePrinter( JsonValue* v ) { visit_value( v ); cout << endl << endl; }

		void visit_string( JsonString* s );
                void visit_number( JsonNumber* n );
                void visit_bool( JsonBool* b );
                void visit_null( JsonNull* n );
                void visit_pair( JsonPair* p );
                void visit_object( JsonObject* o );
                void visit_array( JsonArray* a );
};

#endif
