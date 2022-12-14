/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 20th April 2022 9:12:10 pm
 */

#include <gtest/gtest.h>
#include <fstream>

#include "../data/Constants.h"
#include "../lib/TestingHelpers.h"
#include "../objects/BusStop.h"
#include "../lib/DesignByContract.h"


TEST(BusStopTests, PositionMutationHappyDay) {
    BusStop busStop = BusStop(0.0, 10);
    EXPECT_EQ(0, busStop.getPosition());
    busStop.setPosition(20);
    EXPECT_EQ(20, busStop.getPosition());
}

TEST(BusStopTests, PositionMutationNegative) {
    BusStop busStop = BusStop(0.0, 10);
    EXPECT_EQ(0, busStop.getPosition());
    EXPECT_DEATH(busStop.setPosition(-20), "positive");
}

TEST(BusStopTests, WaitTimeMutationHappyDay) {
    BusStop busStop = BusStop(0.0, 10);
    EXPECT_EQ(10, busStop.getWaitTime());
    busStop.setWaitTime(20);
    EXPECT_EQ(20, busStop.getWaitTime());
}

TEST(BusStopTests, WaitTimeMutationZero) {
    BusStop busStop = BusStop(0.0, 10);
    EXPECT_EQ(10, busStop.getWaitTime());
    EXPECT_DEATH(busStop.setWaitTime(0), "strictly positive");
}

TEST(BusStopTests, WaitTimeMutationNegative) {
    BusStop busStop = BusStop(0.0, 10);
    EXPECT_EQ(10, busStop.getWaitTime());
    EXPECT_DEATH(busStop.setWaitTime(-20), "strictly positive");
}

TEST(BusStopTests, TimeCountMutationHappyDay) {
    BusStop busStop = BusStop(0.0, 10);
    EXPECT_EQ(0, busStop.getTimeCount());
    busStop.setTimeCount(10);
    EXPECT_EQ(10, busStop.getTimeCount());
}

TEST(BusStopTests, TimeCountMutationNegative) {
    BusStop busStop = BusStop(0.0, 10);
    EXPECT_EQ(0, busStop.getTimeCount());
    EXPECT_DEATH(busStop.setTimeCount(-20), "positive");
}

TEST(BusStopTests, TimeCountIncrementHappyDay) {
    BusStop busStop = BusStop(0.0, 10);
    EXPECT_EQ(0, busStop.getTimeCount());
    busStop.incrementTimeCount();
    EXPECT_EQ(1, busStop.getTimeCount());
}

TEST(BusStopTests, BusMutationHappyDay) {
    BusStop busStop = BusStop(0.0, 10);
    Vehicle *bus = new Vehicle(0.0, Bus);

    EXPECT_EQ(busStop.getBus(), nullptr);

    busStop.setBus(bus);
    ASSERT_EQ(busStop.getBus(), bus);
}
