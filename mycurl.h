#ifndef __MYCURL_H_
#define __MYCURL_H_

#include <string>
#include <curl/curl.h>
#include <iostream>

using namespace std;

class MyCURL {
	public:
		static string send_url( string url );
	protected:
		MyCURL() {}
	private:
		static MyCURL* instance;
		string _send_url( string url );
		size_t writeCallback ( char* buf, size_t size, size_t nmemb, void* up );
};

#endif
