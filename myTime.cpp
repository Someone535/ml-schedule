#include "myTime.h"

std::tm MyDateTime::to_tm() {
	MyDateTime zero = MyYear( 0 );
	MyDateTime temp = this->fill_in_context( zero );
	std::tm out_tm = { temp.sec, temp.min, temp.hour, temp.mday, temp.month, temp.year - 1900 };
	return out_tm;
}

void MyDateTime::calc_wday() {
	if ( mday == -1 or month == MONTH_NILL or year == -1 ) {
		wday = WDAY_NILL;
	} else {
		std::tm this_tm = to_tm();
		std::time_t temp_time = std::mktime( &this_tm );
		std::tm out_time = *std::localtime( &temp_time );
		wday = (myWDay_t)( ( out_time.tm_wday + 1 ) % 7 );
	}
}

MyDateTime::MyDateTime( size_t mday, myMonth_t month, size_t year, 
			size_t hour, size_t min, size_t sec, size_t msec ) 
				: mday(mday), month(month), year(year), 
				hour(hour), min(min), sec(sec), msec(msec), neg(false) {
	calc_wday();
}

MyDateTime MyDateTime::now() {
	std::time_t current = std::time(nullptr);
	std::tm now = *std::localtime( &current );
	return MyDateTime( now.tm_mday, (myMonth_t)now.tm_mon, now.tm_year+1900, 
				now.tm_hour, now.tm_min, now.tm_sec, 0 );
}

MyDateTime MyDateTime::fill_in_context( MyDateTime context ) {
	
	MyDateTime result = *this;

	result.mday = ( mday == -1 ) ? context.mday : mday;
	result.month = ( month == MONTH_NILL ) ? context.month : month;
	result.mday = ( year == -1 ) ? context.year : year;
	result.mday = ( hour == -1 ) ? context.hour : hour;
	result.mday = ( min == -1 ) ? context.min : min;
	result.mday = ( sec == -1 ) ? context.sec : sec;
	result.mday = ( msec == -1 ) ? context.msec : msec;

	result.calc_wday();

}

MyDateTime MyDateTime::next_in_context( MyDateTime context ) {

	MyDateTime result = *this;

	if ( year == -1 ) {
		if ( month == MONTH_NILL ) {
			if ( day == -1 ) {
				if ( hour < context.hour) {
					result.day++;
				}
			}
		}
	}


}

MyDateTime MyDateTime::prev_in_context( MyDateTime context ) {}

MyDateTime MyDateTime::nearest_in_context( MyDateTime context ) {}

bool MyDateTime::operator<( const MyDateTime& limit ) {}
bool MyDateTime::is_before( MyDateTime limit ) {}

bool MyDateTime::operator>( const MyDateTime& limit ) {}
bool MyDateTime::is_after( MyDateTime limit ) {}

bool MyDateTime::operator==( const MyDateTime& limit ) {}
bool MyDateTime::is_equal( MyDateTime limit ) {}

bool MyDateTime::operator-( const MyDateTime& limit ) {}
MyDateTime MyDateTime::diff( MyDateTime other_dt ) {}

std::string MyDateTime::to_string() {}



MyDate::MyDate( size_t day, myMonth_t month, size_t year ) 
		: MyDateTime( day, month, year, 0, 0, 0, 0 ) {}

MyTime::MyTime( size_t hour, size_t min, size_t sec, size_t msec ) 
		: MyDateTime( -1, MONTH_NILL, -1, hour, min, sec, msec ) {}
MyTime::MyTime( size_t hour, size_t min, size_t sec ) 
		: MyDateTime( -1, MONTH_NILL, -1, hour, min, sec, 0 ) {}
MyTime::MyTime( size_t hour, size_t min ) 
		: MyDateTime( -1, MONTH_NILL, -1, hour, min, 0, 0 ) {}
MyTime::MyTime( size_t hour ) 
		: MyDateTime( -1, MONTH_NILL, -1, hour, 0, 0, 0 ) {}

MyDay::MyDay( size_t day ) : MyDateTime( day, MONTH_NILL, -1, 0, 0, 0, 0 ) {}

MyMonth::MyMonth( myMonth_t month ) : MyDateTime( 1, month, -1, 0, 0, 0, 0 ) {}

MyYear::MyYear( size_t year ) : MyDateTime( 1, JANUARY, year, 0, 0, 0, 0 ) {}

MyDayMonth::MyDayMonth( size_t day, myMonth_t month ) : MyDateTime( day, month, -1, 0, 0, 0, 0 ) {}



MyWeekDay::MyWeekDay( myWDay_t wday ) : MyDateTime( -1, MONTH_NILL, -1, 0, 0, 0, 0 ), wday(wday) {}

MyDateTime MyWeekDay::fill_in_context( MyDateTime context ) {}
MyDateTime MyWeekDay::next_in_context( MyDateTime context ) {}
MyDateTime MyWeekDay::prev_in_context( MyDateTime context ) {}
MyDateTime MyWeekDay::nearest_in_context( MyDateTime context ) {}
