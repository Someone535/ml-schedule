#include <iostream>
#include <string>

#include "maps.h"

using namespace std;

int main() {

	string url = "https://maps.googleapis.com/maps/api/distancematrix/json?origins=Vancouver+BC|Seattle&destinations=San+Francisco|Victoria+BC&mode=bicycling&language=fr-FR&key=AIzaSyD4TY0ecKKJWFvr_mVy96t5Pe2-yDaA7Gg";

	curlTest( url );

	return 0;
}
