#ifndef STOCK__HPP
#define STOCK__HPP

//--------------------------------------------------------------------------
// #include "Stock.hpp" 
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// system includes
//--------------------------------------------------------------------------
#include <string>
#include <vector>

//--------------------------------------------------------------------------
// project includes
//--------------------------------------------------------------------------
#include "IStock.hpp"
#include "ITrade.hpp"


//--------------------------------------------------------------------------
// forward references
//--------------------------------------------------------------------------
class Trade;


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
// Stock
//--------------------------------------------------------------------------

class Stock : public IStock
{
   public:
    enum StockType
    {
       COMMON,
       PREFERRED
    };

      // Stock
      // params:
      //    Symbol ... stock symbol
      //    Type ... stock type
      //    LastDividend ... last dividend
      //    FixedDividend ... fixed dividend
      //    TickerPrice ... ticker price
      //    ParValue ... par value
      // return:
      Stock(std::wstring Symbol, StockType Type, double LastDividend, double FixedDividend, double TickerPrice, double ParValue);

      // Destructor
      virtual ~Stock();

      // CalculateDividendYield
      // params:
      // return:
      //    calculated dividend yield
      double CalculateDividendYield();

      // CalculatePERatio
      // params:
      // return:
      //    calculated pe ratio
      double CalculatePERatio();

      // CreateTrade
      // params:
      // return:
      ITrade* CreateTrade(double Price, double Quantity, ITrade::TradeIndicator Indicator);

      // RecordTrade
      // params:
      // return:
      void RecordTrade(ITrade* pTrade);

      // CalculateStockPriceFromPastMinutes
      // params:
      // return:
      //    calculated stock price
      double CalculateStockPriceFromPastMinutes();

      // GetSymbol
      // params:
      // return:
      //    stock symbol
      std::wstring GetSymbol();

   private:
      // CalculateCommonDividendYield
      // params:
      // return:
      //    calculated common dividend yield
      double CalculateCommonDividendYield();
      
      // CalculatePreferredDividendYield
      // params:
      // return:
      //    calculated preferred dividend yield
      double CalculatePreferredDividendYield();

      std::wstring mSymbol;

      StockType mType;

      double mLastDividend;

      double mFixedDividend;

      double mTickerPrice;

      double mParValue;

      std::vector<ITrade*> mTradeList;

};


#endif
