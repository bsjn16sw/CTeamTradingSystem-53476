#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include "StockBrockerDriver.h"
using namespace std;

class NemoDriver : public StockBrockerDriver
{
public:
public:
	NemoDriver(NemoAPI nAPI) : nemoAPI{ nAPI }
	{

	}
	void sellStock(string stockCode, int price, int num)
	{
		nemoAPI.sellingStock(stockCode, price, num);
	}
private:
	NemoAPI nemoAPI;
};
class NemoAPI {
public:
	void certification(string ID, string pass) {
		cout << "[NEMO]" << ID << " login GOOD\n";
	}

	void purchasingStock(string stockCode, int price, int count) {
		cout << "[NEMO]" << stockCode << " buy stock ( price : " << price << " ) * ( count : " << count << ")\n";
	}

	void sellingStock(string stockCode, int price, int count) {
		cout << "[NEMO]" << stockCode << " sell stock ( price : " << price << " ) * ( count : " << count << ")\n";
	}

	int getMarketPrice(string stockCode, int minute) {
		//minute ms초 이후 구매가 되는 방식 (최소 1 ms)
		if (minute <= 0) minute = 1;
		Sleep(minute);
		srand(time(NULL));
		int ret = rand() % 10 * 100 + 5000;
		return ret;
	}
};