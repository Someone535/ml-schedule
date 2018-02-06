#include "jsonValue.h"

JsonObject::~JsonObject() {
	for ( JsonPair* p : members ) delete p;
}

JsonArray::~JsonArray() {
	for ( JsonValue* v : elements ) delete v; 
}

JsonPair::~JsonPair() {
	delete value;
}

void JsonVisitor::visit_value( JsonValue* v ) {

	switch ( v->type ) {

		case JSON_V_STRING: visit_string( (JsonString*)v ); break;
		case JSON_V_NUMBER: visit_number( (JsonNumber*)v ); break;
		case JSON_V_BOOL: visit_bool( (JsonBool*)v ); break;
		case JSON_V_NULL: visit_null( (JsonNull*)v ); break;
		case JSON_V_PAIR: visit_pair( (JsonPair*)v ); break;
		case JSON_V_OBJECT: visit_object( (JsonObject*)v ); break;
		case JSON_V_ARRAY: visit_array( (JsonArray*)v ); break;

	}

}

void JsonValue::accept_visitor( JsonVisitor v ) { v.visit_value( this ); }
void JsonString::accept_visitor( JsonVisitor v ) { v.visit_string( this ); }
void JsonNumber::accept_visitor( JsonVisitor v ) { v.visit_number( this ); }
void JsonBool::accept_visitor( JsonVisitor v ) { v.visit_bool( this ); }
void JsonPair::accept_visitor( JsonVisitor v ) { v.visit_pair( this ); }
void JsonObject::accept_visitor( JsonVisitor v ) { v.visit_object( this ); }
void JsonArray::accept_visitor( JsonVisitor v ) { v.visit_array( this ); }
void JsonNull::accept_visitor( JsonVisitor v ) { v.visit_null( this ); }

void JsonValuePrinter::visit_string( JsonString* s ) {
	cout << "str " << s->value;
}

void JsonValuePrinter::visit_number( JsonNumber* n ) {
	cout << "num " << to_string( n->value );
}

void JsonValuePrinter::visit_bool( JsonBool* b ) {
	cout << "bool " << to_string( b->value );
}

void JsonValuePrinter::visit_pair( JsonPair* p ) {
	cout << p->name << " : ";
	depth += p->name.length() + 3;
	visit_value( p->value );
	depth -= p->name.length() + 3;
}

void JsonValuePrinter::visit_object( JsonObject* o ) {
	cout << "{" << endl;
	depth += 2;
	for ( auto m : o->members ) {
		cout << string( depth, ' ' );
		visit_pair( m );
		cout << endl;
	}
	depth -= 2;
	cout << string( depth, ' ' );
	cout << "}";
}

void JsonValuePrinter::visit_array( JsonArray* a ) {
	cout << "[" << endl;
	depth++;
	for ( auto e : a->elements ) {
		cout << string( depth, ' ' );
		visit_value( e );
		cout << endl;
	}
	depth--;
	cout << string( depth, ' ' );
	cout << "]";
}

void JsonValuePrinter::visit_null( JsonNull* a ) {
	cout << "NULL";
}
