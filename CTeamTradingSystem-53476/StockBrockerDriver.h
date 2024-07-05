#pragma once
#include <string>
using namespace std;

class StockBrockerDriver
{
public:
	virtual void sellStock(string, int, int) = 0;
	virtual void login(string, string) = 0;
private:
};
