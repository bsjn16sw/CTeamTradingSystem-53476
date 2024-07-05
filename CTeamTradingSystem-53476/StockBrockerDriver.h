#pragma once
#include <string>
using namespace std;

class StockBrockerDriver
{
public:
	virtual void sellStock(string, int, int) = 0;
private:
};
