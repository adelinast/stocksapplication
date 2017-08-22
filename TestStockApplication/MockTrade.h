#ifndef MOCKTRADE__HPP
#define MOCKTRADE__HPP

//--------------------------------------------------------------------------
// MockTrade
// 
// #include "MockTrade.hpp" 
//
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// system includes
//--------------------------------------------------------------------------
#include <Trade.hpp>

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
// MockTrade
//--------------------------------------------------------------------------
class MockTrade : public Trade
{
public:
   // Constructor
   // params:
   // return:
   MockTrade() {};

   MOCK_CONST_METHOD0(GetPrice, double());

   // IsFromPastMinutes
   // params:
   // return:
   //    true if it's from past minutes
   MOCK_METHOD1(IsFromPastMinutes, bool(unsigned int));
};


#endif //MOCKTRADE__HPP
