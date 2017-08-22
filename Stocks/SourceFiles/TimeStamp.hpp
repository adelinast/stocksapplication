#ifndef TIMESTAMP__HPP
#define TIMESTAMP__HPP

//--------------------------------------------------------------------------
// #include "TimeStamp.hpp" 
//
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// system includes
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// project includes
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// forward references
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
// TimeStamp
//--------------------------------------------------------------------------

class TimeStamp
{
   public:
      // TimeStamp
      // params:
      // return:
      TimeStamp();
      
      // TimeStamp
      // params:
      //    Year ... Year
      //    Month ... Month
      //    Day ... Day
      //    Hour ... Hour
      //    Min ... Minutes
      //    Sec ... Seconds
      // return:
      TimeStamp(unsigned int Year, unsigned int Month, unsigned int Day, unsigned int Hour, unsigned int Min, unsigned int Sec);

      // Destructor
      virtual ~TimeStamp();

      // GetYear
      // params:
      // return:
      //    year
      unsigned int GetYear() const;
      
      // GetMonth
      // params:
      // return:
      //    month
      unsigned int GetMonth() const;
      
      // GetDay
      // params:
      // return:
      //    day
      unsigned int GetDay() const;
      
      // GetHour
      // params:
      // return:
      //    hour
      unsigned int GetHour() const;
      
      // GetMin
      // params:
      // return:
      //    min
      unsigned int GetMin() const;
      
      // IsSameDay
      // params:
      // return:
      bool IsSameDay(unsigned int Year, unsigned int Month, unsigned int Day);
      
      // IsPastMinutes
      // params:
      // return:
      //    true if from past minutes
      bool IsPastMinutes(unsigned int minutes);

      // GetCurrentTimeStamp
      // params:
      // return:
      //    current timestamp
      static TimeStamp GetCurrentTimeStamp();

      // ConvertYear
      // params:
      // return:
      //    converted year
      static unsigned int ConvertYear(unsigned int Year);

      // ConvertMonth
      // params:
      // return:
      //    converted month
      static unsigned int ConvertMonth(unsigned int Month);

   private:
      unsigned int mYear;

      unsigned int mMonth;

      unsigned int mDay;

      unsigned int mHour;

      unsigned int mSec;

      unsigned int mMin;
   
      static const unsigned int scmDefaultYear;

      static const unsigned int scmDefaultMonth;

      static const unsigned int scmDefaultDay;

      static const unsigned int scmDefaultHour;

      static const unsigned int scmDefaultMin;

      static const unsigned int scmDefaultSec;
};



#endif
