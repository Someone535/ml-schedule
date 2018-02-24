#ifndef __MYTIME_H_
#define __MYTIME_H_

#include <ctime>
#include <string>

enum myMonth_t {
	JANUARY,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER,
	MONTH_NILL
};

enum myWDay_t {
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY,
	WDAY_NILL
};

class MyDateTime {
	private:
		int mday;
		myMonth_t month;
		int year;
		myWDay_t wday;
		int hour;
		int min;
		int sec;
		int msec;

		myWDay_t calc_wday();

	public:
		MyDateTime( size_t mday, myMonth_t month, size_t year, 
				size_t hour, size_t min, size_t sec, size_t msec );

		static MyDateTime now();

		virtual MyDateTime fill_in_context( MyDateTime context );
		virtual MyDateTime next_in_context( MyDateTime context );
		virtual MyDateTime prev_in_context( MyDateTime context );
		virtual MyDateTime nearest_in_context( MyDateTime context );

		bool operator<( MyDateTime limit& );
		virtual bool is_before( MyDateTime limit );

		bool operator>( MyDateTime limit& );
		virtual bool is_after( MyDateTime limit );

		bool operator==( MyDateTime limit& );
		virtual bool is_equal( MyDateTime limit );

		bool operator-( MyDateTime limit& );
		virtual MyDateTime diff( MyDateTime other_dt );

		virtual std::string to_string();

		bool neg;
};

class MyDate : public MyDateTime {
	public:
		MyDate( size_t day, myMonth_t month, size_t year );
};

class MyTime : public MyDateTime {
	public:
		MyTime( size_t hour, size_t min, size_t sec, size_t msec );
		MyTime( size_t hour, size_t min, size_t sec );
		MyTime( size_t hour, size_t min );
		MyTime( size_t hour );
};

class MyDay : public MyDateTime {
	public:
		MyDay( size_t day );
};

class MyMonth : public MyDateTime {
	public:
		MyMonth( myMonth_t month );
};

class MyYear : public MyDateTime {
	public:
		MyYear( size_t year );
};

class MyWeekDay : public MyDateTime {
	public:
		MyWeekDay( myWDay_t wday );

		MyDateTime fill_in_context( MyDateTime context );
		MyDateTime next_in_context( MyDateTime context );
		MyDateTime prev_in_context( MyDateTime context );
		MyDateTime nearest_in_context( MyDateTime context );

};

#endif
