
#include "stdafx.h"
//--------------------------------------------------------------------------
// system includes
//--------------------------------------------------------------------------
#include "TestStock.h"
#include "Stock.hpp"
#include "MockTrade.h"

//--------------------------------------------------------------------------
// project includes
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

namespace nsTestStock {

   //--------------------------------------------------------------------------
   // TestStock
   //--------------------------------------------------------------------------
   //*************************** PUBLIC   *************************************

   //++++++++++++++++++++++ Operations of TestStock +++++++++++++++++++++++++

   //--------------------------------------------------------------------------
   // SetUp
   // prepares the TestEnvironment before every test
   // params:
   // return:
   //--------------------------------------------------------------------------
   //virtual
   void TestStock::SetUp()
   {
      mpSUT = new Stock(L"IBM", Stock::COMMON, 100, 100, 100, 10);
      mpTradeMock = new MockTrade();
   }

   //--------------------------------------------------------------------------
   // TearDown
   // destroys the TestEnvironment after every test
   // params:
   // return:
   //--------------------------------------------------------------------------
   //virtual
   void TestStock::TearDown()
   {
      delete mpSUT;
   }

   //--------------------------------------------------------------------------
   // check_yield
   //--------------------------------------------------------------------------
   TEST_F(TestStock, check_yield)
   {
      //ARRANGE
      //ACT
      double expected_yield = 1;
      double actual_yield = mpSUT->CalculateDividendYield();

      //ASSERT
      EXPECT_EQ(expected_yield, actual_yield);
   }

   //--------------------------------------------------------------------------
   // check_pe
   //--------------------------------------------------------------------------
   TEST_F(TestStock, check_pe)
   {
      //ARRANGE
      //ACT
      double expected_pe = 100;
      double actual_pe = mpSUT->CalculatePERatio();

      //ASSERT
      EXPECT_EQ(expected_pe, actual_pe);
   }

   //--------------------------------------------------------------------------
   // check_price_last_minutes
   //--------------------------------------------------------------------------
   TEST_F(TestStock, check_price_last_minutes)
   {
      //ARRANGE
      double expected_price = 0;
      double price = 10;

      mpSUT->RecordTrade(mpTradeMock);

      ON_CALL(*mpTradeMock, GetPrice())
         .WillByDefault(Return(price));

      EXPECT_CALL(*mpTradeMock, GetPrice())
         .Times(0);

      ON_CALL(*mpTradeMock, IsFromPastMinutes(_))
         .WillByDefault(Return(false));

      EXPECT_CALL(*mpTradeMock, IsFromPastMinutes(_))
         .Times(1);

      //ACT
      double actual_price = mpSUT->CalculateStockPriceFromPastMinutes();

      //ASSERT
      EXPECT_EQ(expected_price, actual_price);
   }

   //--------------------------------------------------------------------------
   // check_price_last_minutes_add_record
   //--------------------------------------------------------------------------
   TEST_F(TestStock, check_price_last_minutes_add_record)
   {
      //ARRANGE
      double expected_price = 10;
      double price = 10;
      mpSUT->RecordTrade(mpTradeMock);

      ON_CALL(*mpTradeMock, GetPrice())
         .WillByDefault(Return(price));

      EXPECT_CALL(*mpTradeMock, GetPrice())
         .Times(1);

      ON_CALL(*mpTradeMock, IsFromPastMinutes(_))
         .WillByDefault(Return(true));

      EXPECT_CALL(*mpTradeMock, IsFromPastMinutes(_))
         .Times(1);

      //ACT
      double actual_price = mpSUT->CalculateStockPriceFromPastMinutes();


      //ASSERT
      EXPECT_EQ(expected_price, actual_price);
   }

}