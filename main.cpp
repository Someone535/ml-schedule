#include <iostream>
#include <string>

#include "mycurl.h"
#include "jsonStrScanner.h"
#include "jsonStrParser.h"

using namespace std;

string curlTest ( string url_string ) {

        mycurl mycurl_h;

        mycurl_h.send_url( url_string );

        return mycurl_h.response;

}

void jsonTest( string json ) {

	cout << "-----Json String-----" << endl << endl;

	cout << json << endl << endl;

	cout << "-----Tokens-----" << endl << endl;

	JsonStrScanner s = JsonStrScanner( json );

	s.print_tokens();

	cout << endl;

	cout << "-----Json Parser Output-----" << endl << endl;

	JsonStrParser p = JsonStrParser( s.return_tokens() );

}

int main() {

	string url = "https://maps.googleapis.com/maps/api/distancematrix/json?origins=Vancouver+BC|Seattle&destinations=San+Francisco|Victoria+BC&mode=bicycling&language=fr-FR&key=AIzaSyD4TY0ecKKJWFvr_mVy96t5Pe2-yDaA7Gg";

	string json = curlTest( url );

	json = " { \"members\" : { \"a\" : 5 , \"b\" : true } , \"status\" : \"good\" } ";

	jsonTest( json );

	return 0;
}
