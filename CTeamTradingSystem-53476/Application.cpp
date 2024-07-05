#include "StockBrockerDriver.h"

class Application
{
public:
	void selectStockBrocker(StockBrockerDriver* sbd)
	{
		stockbrockerdriver = sbd;
	}
	void sellStock(string stockCode, int price, int num)
	{
		stockbrockerdriver->sellStock(stockCode, price, num);
	}
private:
	StockBrockerDriver* stockbrockerdriver;
};