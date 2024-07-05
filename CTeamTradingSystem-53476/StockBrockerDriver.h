#pragma once
#define interface struct

#include <string>
using namespace std;

interface StockBrockerDrvier {
	virtual void loginBrocker(string ID, string password) = 0;
	virtual void buyStock(string stockCode, int count, int price) = 0;
	virtual void sellStock(string stockCode, int count, int price) = 0;
	virtual int getPrice(string stockCode) = 0;
};
class KiwerDriver : public StockBrockerDrvier {
public:
	virtual void loginBrocker(string ID, string password) {}
	virtual void buyStock(string stockCode, int count, int price) {}
	virtual void sellStock(string stockCode, int count, int price) {}
	virtual int getPrice(string stockCode) {}
};
class NemoDriver : public StockBrockerDrvier {
public:
	virtual void loginBrocker(string ID, string password) {}
	virtual void buyStock(string stockCode, int count, int price) {}
	virtual void sellStock(string stockCode, int count, int price) {}
	virtual int getPrice(string stockCode) {}
};

