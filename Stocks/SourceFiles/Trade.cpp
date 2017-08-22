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

// Trade
// params:
//    Price ... price
//    Quantity ... quantity
//    Indicator ... trade indicator
//    TimeStamp ... timestamp
// return:
Trade::Trade(double Price, double Quantity, ITrade::TradeIndicator Indicator, TimeStamp TimeStamp) 
{
   mTimeStamp = TimeStamp;
   mPrice = Price;
   mQuantityShares = Quantity;
   mTradeIndicator = Indicator;
}

// Destructor
Trade::~Trade()
{
}

// GetPrice
// params:
// return:
double Trade::GetPrice() const 
{
   return mPrice;
}

// GetQuantity
// params:
// return:
//    quantity
double Trade::GetQuantity() const 
{
   return mQuantityShares;
}

// GetTradeIndicator
// params:
// return:
//    trade indicator
ITrade::TradeIndicator Trade::GetTradeIndicator() const 
{
   return mTradeIndicator;
}

// GetTimestamp
// params:
// return:
//    timestamp
TimeStamp Trade::GetTimestamp() const 
{
   return mTimeStamp;
}

// IsFromPastMinutes
// params:
// return:
//    true if it is from past minutes
bool Trade::IsFromPastMinutes(unsigned int minutes)
{
   return mTimeStamp.IsPastMinutes(minutes);
}
