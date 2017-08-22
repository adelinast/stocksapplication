#ifndef ISTOCK__HPP
#define ISTOCK__HPP


//--------------------------------------------------------------------------
// #include "IStock.hpp" 
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// system includes
//--------------------------------------------------------------------------
#include <string>

//--------------------------------------------------------------------------
// project includes
//--------------------------------------------------------------------------
#include "ITrade.hpp"

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
// IStock
//--------------------------------------------------------------------------

class IStock
{
   public:
      // Constructor
      // params:
      // return:
      IStock() {};

      // Destructor
      // params:
      // return:
      virtual ~IStock() {};

      // GetSymbol
      // params:
      // return:
      virtual std::wstring GetSymbol() = 0;

      // CalculateDividendYield
      // params:
      // return:
      virtual double CalculateDividendYield() = 0;

      // CalculatePERatio
      // params:
      // return:
      virtual double CalculatePERatio() = 0;

      // CreateTrade
      // params:
      // return:
      virtual ITrade* CreateTrade(double Price, double Quantity, ITrade::TradeIndicator Indicator) = 0;

      // RecordTrade
      // params:
      // return:
      virtual void RecordTrade(ITrade* pTrade) = 0;

      // CalculateStockPriceFromPastMinutes
      // params:
      // return:
      virtual double CalculateStockPriceFromPastMinutes() = 0;

};


#endif
