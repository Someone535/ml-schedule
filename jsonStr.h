#ifndef __JSONSTR_H_
#define __JSONSTR_H_

#include <string>

#include "jsonValue.h"
#include "jsonStrParser.h"
#include "jsonStrScanner.h"

class JsonStr {
	private:
		JsonValue* result;
		JsonStrScanner* s;
		JsonStrParser* p;

	public:
		JsonStr( string input );
		~JsonStr();	

		JsonValue* return_result();
		
		void print_scanner_tokens();
		
};

#endif
