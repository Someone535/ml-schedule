#include "maps.h"

string data;

size_t writeCallback ( char* buf, size_t size, size_t nmemb, void* up ) {

	for ( int c = 0; c < size*nmemb; c++ ) {
		data.push_back( buf[c] );
	}

	return size*nmemb;

}

void curlTest ( string url_string ) {

	CURL* curl_handle;

	curl_global_init( CURL_GLOBAL_ALL );
	curl_handle = curl_easy_init();

	curl_easy_setopt( curl_handle, CURLOPT_URL, url_string.c_str() );
	curl_easy_setopt( curl_handle, CURLOPT_WRITEFUNCTION, &writeCallback );

	curl_easy_perform( curl_handle );

	cout << endl << data << endl;

	curl_easy_cleanup( curl_handle );
	curl_global_cleanup();

}
