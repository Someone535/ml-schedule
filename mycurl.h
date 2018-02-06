#ifndef __MYCURL_H_
#define __MYCURL_H_

#include <string>
#include <curl/curl.h>

using namespace std;

class mycurl {
	string response;
	static size_t writeCallback ( char* buf, size_t size, size_t nmemb, void* up );
	public:
		string send_url( string url );
};

#endif
