#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../CTeamTradingSystem-53476/Application.cpp"
#include "../CTeamTradingSystem-53476/StockBrockerDriver.h"

class MockDriver : public StockBrockerDriver {
public:
	MOCK_METHOD(void, loginBrocker, (string, string), (override));
	MOCK_METHOD(void, buyStock, (string, int, int), (override));
	MOCK_METHOD(void, sellStock, (string, int, int), (override));
	MOCK_METHOD(int, getPrice, (string), (override));
	MOCK_METHOD(bool, buyStockNiceTiming, (string, int), (override));
	MOCK_METHOD(bool, sellStockNiceTiming, (string, int), (override));
};

class TestFixture : public testing::Test {
public:
	void SetUp() override {
		app->selectStockBrocker(&mk);
		app->login("userid", "userpasswd");
	}
	Application* app = new Application();
	testing::NiceMock<MockDriver> mk;
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
	EXPECT_CALL(mk, buyStock, ("stockid", 1000, 10), ())
		.Times(1);
	app->buy("stockid", 1000, 10);
}

TEST_F(TestFixture, SellStock) {
	EXPECT_CALL(mk, sellStock, ("stockid", 1000, 10), ())
		.Times(1);
	app->sell("stockid", 1000, 10);
}

TEST_F(TestFixture, GetPrice) {
	EXPECT_CALL(mk, getPrice, ("stockid"), ())
		.Times(1)
		.WillRepeatedly(testing::Return(12345));

	int ret = app->getPrice("stockid");
	EXPECT_EQ(ret, 12345);
}


TEST_F(TestFixture, BuyNiceTimingIncreasingTrend) {
    EXPECT_CALL(mk, getPrice, ("stockid"), ())
        .Times(5)
        .WillOnce(testing::Return(700))
        .WillOnce(testing::Return(700))
        .WillOnce(testing::Return(900))
        .WillOnce(testing::Return(1000))
        .WillOnce(testing::Return(1100));

    EXPECT_CALL(mk, buyStock, ("stockid", 1100, 90)) // FLOOR(100000/1100) = 90
        .Times(1); // CALLED

    bool ret = app->buyNiceTiming("stockid", 100000); // TOTAL BUDGET = 100000
    EXPECT_EQ(ret, true);
}

TEST_F(TestFixture, BuyNiceTimingNotIncreasingTrend) {
    EXPECT_CALL(mk, getPrice, ("stockid"), ())
        .Times(5)
        .WillOnce(testing::Return(700))
        .WillOnce(testing::Return(800))
        .WillOnce(testing::Return(900))
        .WillOnce(testing::Return(1000))
        .WillOnce(testing::Return(900));

    EXPECT_CALL(mk, buyStock)
        .Times(0); // NOT CALLED

    bool ret = app->buyNiceTiming("stockid", 100000); // TOTAL BUDGET = 100000
    EXPECT_EQ(ret, false);
}

TEST_F(TestFixture, SellNiceTimingDecreasingTrend) {
    EXPECT_CALL(mk, getPrice, ("stockid"), ())
        .Times(5)
        .WillOnce(testing::Return(1000))
        .WillOnce(testing::Return(900))
        .WillOnce(testing::Return(800))
        .WillOnce(testing::Return(800))
        .WillOnce(testing::Return(700));

    EXPECT_CALL(mk, sellStock, ("stockid", 700, 10))
        .Times(1); // CALLED

    bool ret = app->buyNiceTiming("stockid", 10); // QUANTITY = 10
    EXPECT_EQ(ret, true);
}

TEST_F(TestFixture, SellNiceTimingNotDecreasingTrend) {
    EXPECT_CALL(mk, getPrice, ("stockid"), ())
        .Times(5)
        .WillOnce(testing::Return(1000))
        .WillOnce(testing::Return(900))
        .WillOnce(testing::Return(1200))
        .WillOnce(testing::Return(800))
        .WillOnce(testing::Return(700));

    EXPECT_CALL(mk, sellStock)
        .Times(0); // NOT CALLED

    bool ret = app->buyNiceTiming("stockid", 10); // QUANTITY = 10
    EXPECT_EQ(ret, false);
}