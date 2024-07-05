#pragma once
#include <string>

using namespace std;

class StockBrockerDriver
{
public:
	virtual void buyStock(string code, int price, int amount) = 0;
};