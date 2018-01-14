#include "maps.h"

void curlTest ( string url_string ) {

	mycurl mycurl_h;

	mycurl_h.send_url( url_string );

	string data = mycurl_h.return_data();

	cout << endl << data << endl;

}
