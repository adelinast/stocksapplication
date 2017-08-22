//--------------------------------------------------------------------------
// class implementation.
//
// Copyright (c) by Wittmann Kunststoffgeräte GmbH, Wien
//              All Rights Reserved.
//
// Unauthorized redistribution of this source code, in whole or part,
// without the express written permission of Wittmann Kunststoffgeräte Wien
// is strictly prohibited.
//
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// system includes
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// project includes
//--------------------------------------------------------------------------
#include "Stock.hpp"
#include "Trade.hpp"


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

// Stock
// params:
//    Symbol ... stock symbol
//    Type ... stock type
//    LastDividend ... last dividend
//    FixedDividend ... fixed dividend
//    TickerPrice ... ticker price
//    ParValue ... par value
// return:
Stock::Stock(std::wstring Symbol, StockType Type, double LastDividend, double FixedDividend, double TickerPrice, double ParValue) 
{
   mFixedDividend = FixedDividend;
   mLastDividend = LastDividend;
   mParValue = ParValue;
   mSymbol = Symbol;
   mTickerPrice = TickerPrice;
   mType = Type;
}

// Destructor
Stock::~Stock()
{
   for (unsigned int i = 0; i < mTradeList.size(); i++)
   {
      if (mTradeList[i])
      {
         delete mTradeList[i];
      }
   }
   mTradeList.clear();
}

// CalculateDividendYield
// params:
// return:
//    dividend yield
double Stock::CalculateDividendYield() 
{
   switch(mType)
   {
   case COMMON:
	  return CalculateCommonDividendYield();
   case PREFERRED:
      return CalculatePreferredDividendYield();
   default:
      break;
   }

   return 0;
}

// CalculatePERatio
// params:
// return:
//    pe ratio
double Stock::CalculatePERatio() 
{
   double dividend = CalculateDividendYield();
   if (dividend == 0 || mTickerPrice == 0)
   {
      return 0;
   }

   return mTickerPrice/dividend;
}

// CreateTrade
// params:
// return:
ITrade* Stock::CreateTrade(double Price, double Quantity, ITrade::TradeIndicator Indicator)
{
   TimeStamp timestamp = TimeStamp::GetCurrentTimeStamp();
   
   Trade* p_trade = new Trade(Price, Quantity, Indicator, timestamp);
   
   return p_trade;
}

// RecordTrade
// params:
// return:
void Stock::RecordTrade(ITrade* pTrade)
{
   mTradeList.push_back(pTrade);
}

// CalculateStockPriceFromPastMinutes
// params:
// return:
//    stock price
double Stock::CalculateStockPriceFromPastMinutes() 
{
   //get all trades from the past minutes
   double productSum = 0;
   double quantitySum = 0;
   const unsigned int c_recent_minutes = 15;

   for (unsigned int i = 0; i < mTradeList.size(); i++)
   {
      ITrade* trade = mTradeList[i];
      //if trade is from past minutes
      if (trade->IsFromPastMinutes(c_recent_minutes))
      {
         // sum the product tradePrice*quantity
         productSum += trade->GetPrice() * trade->GetQuantity();

         // sum the quantity
         quantitySum += trade->GetQuantity();
      }
   }

   if (productSum == 0 || quantitySum == 0)
   {
      return 0;
   }

   return productSum / quantitySum;
}

// GetSymbol
// params:
// return:
//    stock symbol
std::wstring Stock::GetSymbol()
{
   return mSymbol;
}

// CalculateCommonDividendYield
// params:
// return:
//    calculated common dividend yield
double Stock::CalculateCommonDividendYield() 
{
   if (mLastDividend == 0 || mTickerPrice == 0)
   {
      return 0;
   }

   return mLastDividend/mTickerPrice;
}

// CalculatePreferredDividendYield
// params:
// return:
//    calculated preferred dividend yield
double Stock::CalculatePreferredDividendYield() 
{
   if (mFixedDividend == 0 || mTickerPrice == 0)
   {
      return 0;
   }

   return mFixedDividend/mTickerPrice;
}

