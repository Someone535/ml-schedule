#include "myTime.h"

void MyDateTime::calc_wday() {
	if ( mday == -1 or month == MONTH_NILL or year == -1 ) {
		wday = WDAY_NILL;
	} else {
		std::tm this_tm = { 0, 0, 0, mday, month, year - 1900 };
		std::time_t temp_time = std::mktime( &this_tm );
		std::tm out_time = *std::localtime( &temp_time );
		wday = ( tm.tm_wday + 1 ) % 7;
	}
}

MyDateTime::MyDateTime( size_t mday, myMonth_t month, size_t year, 
			size_t hour, size_t min, size_t sec, size_t msec ) 
				: mday(mday), month(month), year(year), 
				hour(hour), min(min), sec(sec), msec(msec), neg(false) {
	calc_wday();
}

MyDateTime MyDateTime::now() {
	std::time_t current = std::time();
	std::tm now = *std::localtime( &current );
	return MyDateTime( now.tm_mday, now.tm_month, now.tm_year+1900,
				now.tm_hour, now.tm_min, now.tm_sec, 0 );
}

MyDateTime MyDateTime::fill_in_context( MyDateTime context ) {}

MyDateTime MyDateTime::next_in_context( MyDateTime context ) {}

MyDateTime MyDateTime::prev_in_context( MyDateTime context ) {}

MyDateTime MyDateTime::nearest_in_context( MyDateTime context ) {}

bool MyDateTime::operator<( MyDateTime limit& ) {}
bool MyDateTime::is_before( MyDateTime limit ) {}

bool MyDateTime::operator>( MyDateTime limit& ) {}
bool MyDateTime::is_after( MyDateTime limit ) {}

bool MyDateTime::operator==( MyDateTime limit& ) {}
bool MyDateTime::is_equal( MyDateTime limit ) {}

bool MyDateTime::operator-( MyDateTime limit& ) {}
MyDateTime MyDateTime::diff( MyDateTime other_dt ) {}

std::string MyDateTime::to_string() {}



MyDate::MyDate( size_t day, myMonth_t month, size_t year ) {}



MyTime::MyTime( size_t hour, size_t min, size_t sec, size_t msec ) {}
MyTime::MyTime( size_t hour, size_t min, size_t sec ) {}
MyTime::MyTime( size_t hour, size_t min ) {}
MyTime::MyTime( size_t hour ) {}



MyDay::MyDay( size_t day ) {}



MyMonth::MyMonth( myMonth_t month ) {}



MyYear::MyYear( size_t year ) {}



MyWeekDay::MyWeekDay( myWDay_t wday ) {}

MyDateTime MyWeekDay::fill_in_context( MyDateTime context ) {}
MyDateTime MyWeekDay::next_in_context( MyDateTime context ) {}
MyDateTime MyWeekDay::prev_in_context( MyDateTime context ) {}
MyDateTime MyWeekDay::nearest_in_context( MyDateTime context ) {}
