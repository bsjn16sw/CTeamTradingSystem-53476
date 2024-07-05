#include "StockBrockerDriver.h"

class Application
{
public:
	void selectStockBrocker(StockBrockerDriver* sbd)
	{
		stockbrockerdriver = sbd;
	}
	void sell(string stockCode, int price, int num)
	{
		stockbrockerdriver->sellStock(stockCode, price, num);
	}
	void login(string userID, string userPassword)
	{
		stockbrockerdriver->login(userID, userPassword);
	}
private:
	StockBrockerDriver* stockbrockerdriver;
};