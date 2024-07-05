#pragma once
#include <string>
using namespace std;

class StockBrockerDriver {
public:
	virtual void loginBrocker(string ID, string password) = 0;
	virtual void buyStock(string stockCode, int count, int price) = 0;
	virtual void sellStock(string stockCode, int count, int price) = 0;
	virtual int getPrice(string stockCode) = 0;
	virtual pair<int, int> buyStockNiceTiming(string stockCode, int price) = 0;
	virtual pair<int, int> sellStockNiceTiming(string stockCode, int count) = 0;
};