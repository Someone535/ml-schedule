#include <iostream>
#include <string>

#include "mycurl.h"

using namespace std;

void curlTest ( string url_string ) {

        mycurl mycurl_h;

        mycurl_h.send_url( url_string );

        string data = mycurl_h.response;
                                                                                                                  cout << endl << data << endl;                                                                     
}

int main() {

	string url = "https://maps.googleapis.com/maps/api/distancematrix/json?origins=Vancouver+BC|Seattle&destinations=San+Francisco|Victoria+BC&mode=bicycling&language=fr-FR&key=AIzaSyD4TY0ecKKJWFvr_mVy96t5Pe2-yDaA7Gg";

	curlTest( url );

	return 0;
}
