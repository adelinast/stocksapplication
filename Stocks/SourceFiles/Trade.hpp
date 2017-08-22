#ifndef TRADE__HPP
#define TRADE__HPP

//--------------------------------------------------------------------------
// #include "Trade.hpp" 
//
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// system includes
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// project includes
//--------------------------------------------------------------------------
#include "ITrade.hpp"
#include "TimeStamp.hpp"


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
// Trade
//--------------------------------------------------------------------------

class Trade : public ITrade
{
   public:
      Trade() {};

      // Trade
      // params:
      //    Price ... price
      //    Quantity ... quantity
      //    Indicator ... trade indicator
      //    TimeStamp ... timestamp
      // return:
      Trade(double Price, double Quantity, TradeIndicator Indicator, TimeStamp TimeStamp);

      // Destructor
      virtual ~Trade();

      // GetPrice
      // params:
      // return:
      //    price
      virtual double GetPrice() const;

      // GetQuantity
      // params:
      // return:
      //    quantity
      virtual double GetQuantity() const;

      // GetTradeIndicator
      // params:
      // return:
      //    trade indicator
      virtual TradeIndicator GetTradeIndicator() const;

      // GetTimestamp
      // params:
      // return:
      //    timestamp
      virtual TimeStamp GetTimestamp() const;
      
      // IsFromPastMinutes
      // params:
      // return:
      //    true if it's from past minutes
      virtual bool IsFromPastMinutes(unsigned int minutes);

   private:
      TimeStamp mTimeStamp;

      double mPrice;

      double mQuantityShares;

      TradeIndicator mTradeIndicator;
};


#endif
