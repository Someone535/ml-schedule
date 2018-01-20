#include <iostream>
#include <string>

#include "mycurl.h"

using namespace std;

string curlTest ( string url_string ) {

        mycurl mycurl_h;

        mycurl_h.send_url( url_string );

        return mycurl_h.response;

}

void jsonTest( string json ) {

	JsonStrParser p = JsonStrParser( json );
	p.print_output();

}

int main() {

	string url = "https://maps.googleapis.com/maps/api/distancematrix/json?origins=Vancouver+BC|Seattle&destinations=San+Francisco|Victoria+BC&mode=bicycling&language=fr-FR&key=AIzaSyD4TY0ecKKJWFvr_mVy96t5Pe2-yDaA7Gg";

	string json = curlTest( url );

	jsonTest( json );

	return 0;
}
