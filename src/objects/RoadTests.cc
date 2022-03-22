#include <gtest/gtest.h>
#include "Road.h"

TEST(RoadTests, roadLengthZero) {
    Road road = Road();

    road.setLength(0);
}

TEST(RoadTests, roadLengthNegative) {
    Road road = Road();

    road.setLength(-20);
}

TEST(RoadTests, multipleGenerators) {
    Road road = Road();

    VehicleGenerator* g1 = new VehicleGenerator();
    VehicleGenerator* g2 = new VehicleGenerator();
    road.addGenerator(g1);
    road.addGenerator(g2);
}

TEST(RoadTests, getSetName) {
    Road road = Road();

    road.setName("test");
    ASSERT_EQ("test", road.getName());
}

TEST(RoadTests, getSetLength) {
    Road road = Road();

    road.setLength(5);
    ASSERT_EQ(5, road.getLength());
}

TEST(RoadTests, getSetVehicle) {
    Road road = Road();

    Vehicle* v = new Vehicle();
    road.addVehicle(v);
    ASSERT_EQ(v, road.getVehicles()[0]);
}

TEST(RoadTests, getSetGenerator) {
    Road road = Road();

    VehicleGenerator* g = new VehicleGenerator();
    road.addGenerator(g);
    ASSERT_EQ(g, road.getGenerators()[0]);
}




