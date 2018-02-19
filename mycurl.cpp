#include "mycurl.h"

MyCURL* MyCURL::instance = 0;

size_t MyCURL::writeCallback ( char* buf, size_t size, size_t nmemb, void* up ) {
	
	static_cast<string*>(up)->append( buf, size*nmemb );

        return size*nmemb;

}

string MyCURL::send_url( string url ) {

	if ( instance == 0 ) instance = new MyCURL();

	return instance->_send_url( url );

}

string MyCURL::_send_url( string url ) {

	string response;

        CURL* curl_handle;

        curl_global_init( CURL_GLOBAL_ALL );
        curl_handle = curl_easy_init();

        curl_easy_setopt( curl_handle, CURLOPT_URL, url.c_str() );
	curl_easy_setopt( curl_handle, CURLOPT_WRITEDATA, &response );
        curl_easy_setopt( curl_handle, CURLOPT_WRITEFUNCTION, &MyCURL::writeCallback );

        curl_easy_perform( curl_handle );

        curl_easy_cleanup( curl_handle );
        curl_global_cleanup();

	return response;

}
