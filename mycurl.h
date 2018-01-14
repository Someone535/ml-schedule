#ifndef __MYCURL_H_
#define __MYCURL_H_

#include <string>
#include <curl/curl.h>

using namespace std;

class mycurl {

	string data;

	size_t writeCallback ( char* buf, size_t size, size_t nmemb, void* up );

	public:
		
		void send_url( string url );
		string return_data();

};

#endif
