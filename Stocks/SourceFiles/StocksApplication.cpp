//--------------------------------------------------------------------------
// class implementation.
//
//
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// system includes
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// project includes
//--------------------------------------------------------------------------
#include "StocksApplication.hpp"
#include "Stock.hpp"


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
// StocksApplication
// params:
// return:

StocksApplication::StocksApplication()
{
}

// Destructor
StocksApplication::~StocksApplication()
{
   for (unsigned int i = 0; i < mStockList.size(); i++)
   {
      if (mStockList[i])
      {
         delete mStockList[i];
      }
   }
   mStockList.clear();
}

// CalculateGBCEAllSharesIndex
// params:
// return:
//    calculated shares index
double StocksApplication::CalculateGBCEAllSharesIndex() 
{
   double product = 1.0;

   for (unsigned int i = 0; i < mStockList.size(); i++)
   {
      double price = mStockList[i]->CalculateStockPriceFromPastMinutes();
		product*=price;
   }

   return pow(product,1.0/mStockList.size());
}

// AddStock
// params:
//    Symbol ... stock symbol
//    Type ... stock type
//    LastDividend ... last dividend
//    FixedDividend ... fixed dividend
//    TickerPrice ... ticker price
//    ParValue ... par value
// return:
Stock* StocksApplication::AddStock(std::wstring StockSymbol, Stock::StockType Type, double LastDividend, double FixedDividend, double TickerPrice, double ParValue)
{
   Stock* p_stock = new Stock(StockSymbol, Type, LastDividend, FixedDividend, TickerPrice, ParValue);
   
   mStockList.push_back(p_stock);
   
   return p_stock;
}

// ListStocks
// params:
// return:
void StocksApplication::ListStocks()
{
   for (unsigned int i = 0; i < mStockList.size(); i++)
   {
      printf("%ls %2f\n", mStockList[i]->GetSymbol().c_str(), mStockList[i]->CalculateDividendYield());
   }
}
