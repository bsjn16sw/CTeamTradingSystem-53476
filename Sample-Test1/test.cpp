#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../CTeamTradingSystem-53476/Application.cpp"
#include "../CTeamTradingSystem-53476/StockBrockerDriver.h"

class MockDriver : public StockBrockerDrvier {
public:
	MOCK_METHOD(void, loginBrocker, (string, string), (override));
	MOCK_METHOD(void, buyStock, (string, int, int), (override));
	MOCK_METHOD(void, sellStock , (string, int, int), (override));
	MOCK_METHOD(int, getPrice, (string), (override));
	MOCK_METHOD(pair<int, int>, buyStockNiceTiming, (string, int), (override));
	MOCK_METHOD(pair<int, int>, sellStockNiceTiming, (string, int), (override));
};

class TestFixture : public testing::Test {
public:
	void SetUp() override {
		app->selectStockBrocker(&mk);
		app->login("userid", "userpasswd");
	}
	Application* app = new Application();
	MockDriver mk;
	const int MAX_BUY_CNT = 10;
};

TEST_F(TestFixture, MakeApplicationInstance) {
	EXPECT_TRUE(app != nullptr);
}

TEST_F(TestFixture, LoginStockBrocker) {
	EXPECT_CALL(mk, loginBrocker, ("userid", "userpasswd"), ())
		.Times(1);
}

TEST_F(TestFixture, BuyStock) {
	app->buy("stockid", 1000, 10);
	EXPECT_CALL(mk, buyStock, ("stockid", 1000, 10), ())
		.Times(1);
}

TEST_F(TestFixture, SellStock) {
	app->sell("stockid", 1000, 10);
	EXPECT_CALL(mk, sellStock, ("stockid", 1000, 10), ())
		.Times(1);
}

TEST_F(TestFixture, GetPrice) {
	int ret = app->getPrice("stockid");
	EXPECT_CALL(mk, getPrice, ("stockid"), ())
		.Times(1)
		.WillRepeatedly(12345);
	EXPECT_EQ(ret, 12345);
}