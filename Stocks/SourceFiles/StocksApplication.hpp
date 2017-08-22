#ifndef STOCKSAPPLICATION__HPP
#define STOCKSAPPLICATION__HPP

//--------------------------------------------------------------------------
// #include "StocksApplication.hpp" 
//
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// system includes
//--------------------------------------------------------------------------
#include <vector>

//--------------------------------------------------------------------------
// project includes
//--------------------------------------------------------------------------
#include "IStock.hpp"
#include "Stock.hpp"


//--------------------------------------------------------------------------
// forward references
//--------------------------------------------------------------------------
class Stock;


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
// StocksApplication
//--------------------------------------------------------------------------

class StocksApplication
{
   public:
      // StocksApplication
      // params:
      // return:
      StocksApplication();

      // Destructor
      virtual ~StocksApplication();

      // CalculateGBCEAllSharesIndex
      // params:
      // return:
      //    calculated shares index
      double CalculateGBCEAllSharesIndex();

      // AddStock
      // params:
      //    Symbol ... stock symbol
      //    Type ... stock type
      //    LastDividend ... last dividend
      //    FixedDividend ... fixed dividend
      //    TickerPrice ... ticker price
      //    ParValue ... par value
      // return:
      Stock* AddStock(std::wstring StockSymbol, Stock::StockType Type, double LastDividend, double FixedDividend, double TickerPrice, double ParValue);

      // ListStocks
      // params:
      // return:
      void ListStocks();

   private:
      std::vector<IStock*> mStockList;

};


#endif
