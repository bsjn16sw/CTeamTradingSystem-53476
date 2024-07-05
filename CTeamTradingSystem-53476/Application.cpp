#pragma once
#include <iostream>
#include <string>
#include "StockBrockerDriver.h"
using namespace std;

class Application
{
public:
	Application() {}
	void selectStockBrocker(StockBrockerDrvier* drv) {
		m_drv = drv;
	}
	void login(string ID, string password) {
		m_drv->loginBrocker(ID, password);
	}
	int getPrice(string stockCode) {
		return m_drv->getPrice(stockCode);
	}
private:
	StockBrockerDrvier* m_drv;
};