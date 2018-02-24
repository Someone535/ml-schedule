#include <iostream>
#include <string>

#include "mycurl.h"
#include "jsonStr.h"

using namespace std;

string curlTest ( string url_string ) {

        return MyCURL::send_url( url_string );

}

void jsonTest( string json ) {

	cout << "-----Json String-----" << endl << endl;

	cout << json << endl << endl;

	cout << "-----Tokens-----" << endl << endl;

	JsonStr s = JsonStr( json );

	s.print_scanner_tokens();

	cout << endl;

	cout << "-----Json Parser Output-----" << endl << endl;

	JsonValuePrinter printer = JsonValuePrinter( s.return_result() );

}

int main() {

	string url = "https://maps.googleapis.com/maps/api/distancematrix/json?origins=Vancouver+BC|Seattle&destinations=San+Francisco|Victoria+BC&mode=bicycling&language=fr-FR&key=AIzaSyD4TY0ecKKJWFvr_mVy96t5Pe2-yDaA7Gg";
	
	string json = curlTest( url );

	//string json = " { \"members\" : { \"a\" : 5.2 , \"b\" : true } , \"status\" : \"good\" } ";

	jsonTest( json );

	return 0;
}
