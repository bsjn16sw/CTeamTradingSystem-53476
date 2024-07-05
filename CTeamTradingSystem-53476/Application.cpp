#include <iostream>
#include <string>
#include "StockBrockerDriver.h"

using namespace std;

class Application {
public:
    void selectStockBrocker(StockBrockerDriver* brokerName) {
       
    }

    void login(string id, string pass) {
 
    }

    void buy(string stockCode, int count, int price) {

    }

    void sell(string stockCode, int count, int price) {
    }
    
    int getPrice(string stockCode) {
    
    }
private:
    StockBrockerDriver* broker;

};