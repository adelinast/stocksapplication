//--------------------------------------------------------------------------
// class implementation.
//
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// system includes
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// project includes
//--------------------------------------------------------------------------
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "TimeStamp.hpp"
#include <ctime>


//--------------------------------------------------------------------------
// forward references
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// external references
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// global variables
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// static variables
// MUST be initialized!
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// macros
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// enums
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// typedefs
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// forward references
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
// external references
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
// global variables
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
// static variables
// MUST be initialized!
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
// macros
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
// enums
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
// typedefs
//--------------------------------------------------------------------------

// TimeStamp
// params:
// return:
TimeStamp::TimeStamp():
   mYear(scmDefaultYear),
   mMonth(scmDefaultMonth),
   mDay(scmDefaultDay),
   mHour(scmDefaultHour),
   mMin(scmDefaultMin),
   mSec(scmDefaultSec)
{
}

// TimeStamp
// params:
//    Year ... Year
//    Month ... Month
//    Day ... Day
//    Hour ... Hour
//    Min ... Minutes
//    Sec ... Seconds
// return:
TimeStamp::TimeStamp(unsigned int Year, unsigned int Month, unsigned int Day, unsigned int Hour, unsigned int Min, unsigned int Sec):
   mYear(Year),
   mMonth(Month),
   mDay(Day),
   mHour(Hour),
   mMin(Min),
   mSec(Sec)
{
}

// Destructor
TimeStamp::~TimeStamp()
{
}

// GetYear
// params:
// return:
//    Year
unsigned int TimeStamp::GetYear() const 
{
   return mYear;
}

// GetMonth
// params:
// return:
//    Month
unsigned int TimeStamp::GetMonth() const
{
   return mMonth;
}

// GetDay
// params:
// return:
//    Day
unsigned int TimeStamp::GetDay() const
{
   return mDay;
}

// GetHour
// params:
// return:
//    Hour
unsigned int TimeStamp::GetHour() const
{
   return mHour;
}

// GetMin
// params:
// return:
//    Min
unsigned int TimeStamp::GetMin() const
{
   return mMin;
}

// IsSameDay
// params:
// return:
//    True if the same day
bool TimeStamp::IsSameDay(unsigned Year, unsigned Month, unsigned Day)
{
   return mYear == Year && mMonth == Month && mDay == Day;
}

// IsPastMinutes
// params:
// return:
//    True if it from past minutes
bool TimeStamp::IsPastMinutes(unsigned int minutes)
{
   bool diff_recent_min = false;
   int current_min = 0;
   int current_hour = 0;
   bool is_same_day = false;
   int diff_min = 0;
   int diff_hour = 0;
   time_t timer;
   tm * time;
   std::time(&timer);
   time = localtime(&timer);

   is_same_day = IsSameDay(ConvertYear(time->tm_year),ConvertMonth(time->tm_mon), time->tm_mday);

   current_min = time->tm_min;
   current_hour = time->tm_hour;
  
   diff_min = current_min - mMin;
   diff_hour = current_hour - mHour;
   
   if (is_same_day && diff_min>=0 && static_cast<unsigned int>(diff_min) <= minutes && diff_hour<=1)
   {
      diff_recent_min = true;
   }

   return diff_recent_min;
}

// GetCurrentTimeStamp
// params:
// return:
//    current timestamp
TimeStamp TimeStamp::GetCurrentTimeStamp()
{
   TimeStamp timestamp;
   time_t timer;
   tm * time;
   std::time(&timer);

   time = localtime(&timer);

   timestamp.mYear = ConvertYear(time->tm_year);
   timestamp.mMonth = ConvertMonth(time->tm_mon);
   timestamp.mDay = time->tm_mday;
   timestamp.mHour = time->tm_hour;
   timestamp.mMin = time->tm_min;
   timestamp.mSec = time->tm_sec;
   
   return timestamp;
}

// ConvertYear
// params:
// return:
//    converted year
unsigned int TimeStamp::ConvertYear(unsigned int Year)
{
   return Year + 1900;
}

// ConvertMonth
// params:
// return:
//    converted month
unsigned int TimeStamp::ConvertMonth(unsigned int Month)
{
   return Month + 1;
}

const unsigned int TimeStamp::scmDefaultYear = 2017;
const unsigned int TimeStamp::scmDefaultMonth = 1;
const unsigned int TimeStamp::scmDefaultDay = 1;
const unsigned int TimeStamp::scmDefaultHour = 0;
const unsigned int TimeStamp::scmDefaultMin = 0;
const unsigned int TimeStamp::scmDefaultSec = 0;

