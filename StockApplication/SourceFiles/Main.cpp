#include "StocksApplication.hpp"
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
   StocksApplication stocks_application;
   Stock* p_stock1 = stocks_application.AddStock(L"TEA", Stock::COMMON, 1, 1, 1, 100);
   ITrade* p_trade1 = p_stock1->CreateTrade(100, 10, ITrade::BUY);
   p_stock1->RecordTrade(p_trade1);

   Stock* p_stock2 = stocks_application.AddStock(L"IBM", Stock::COMMON, 1, 1, 1, 100);
   ITrade* p_trade2 = p_stock2->CreateTrade(100, 10, ITrade::BUY);
   p_stock2->RecordTrade(p_trade2);

   Stock* p_stock3 = stocks_application.AddStock(L"GIN", Stock::PREFERRED, 8, 2, 1, 100);
   ITrade* p_trade3 = p_stock3->CreateTrade(100, 10, ITrade::BUY);
   p_stock3->RecordTrade(p_trade3);

   stocks_application.ListStocks();

   printf("index %f\n", stocks_application.CalculateGBCEAllSharesIndex());
}
