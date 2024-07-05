#include <iostream>
#include <string>
#include "StockBrockerDriver.h"
using namespace std;

class Application
{
public:
	void selectStockBrocker(StockBrockerDriver* drv)
	{
		m_drv = drv;
	}
	void buy(string code, int price, int amount)
	{
		m_drv->buyStock(code, price, amount);
	}

private:
	StockBrockerDriver* m_drv;
};