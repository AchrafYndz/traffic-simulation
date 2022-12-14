/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description:
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 1st March 2022 10:27:21 pm
 */

#include <gtest/gtest.h>
#include <fstream>
#include <cmath>

#include "data/Constants.h"
#include "lib/TestingHelpers.h"
#include "util/XMLParser.h"
#include "Simulation.h"


TEST(SimulationTests, ValidSimulationStdout1) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest1.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest1.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest1.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 0, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationStdout2) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest2.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest2.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest2.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 0, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationStdout3) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest3.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest3.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest3.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationStdout4) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest4.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest4.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest4.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationStdout5) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest5.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest5.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest5.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationStdout6) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest6.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest6.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest6.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationStdout7) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest7.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest7.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest7.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationStdout8) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest8.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest8.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest8.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationStdout9) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest9.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest9.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest9.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationHTML1) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest1.html";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest1.html";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest1.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeToFile(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationHTML2) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest2.html";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest2.html";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest2.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeToFile(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationHTML3) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest3.html";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest3.html";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest3.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeToFile(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationHTML4) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest4.html";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest4.html";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest4.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeToFile(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationHTML5) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest5.html";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest5.html";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest5.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeToFile(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationHTML6) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest6.html";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest6.html";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest6.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeToFile(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationHTML7) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest7.html";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest7.html";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest7.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeToFile(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationHTML8) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest8.html";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest8.html";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest8.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeToFile(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationHTML9) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest9.html";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest9.html";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest9.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeToFile(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, RoadMutationHappyDay) {
    Simulation sim = Simulation();
    Road* road = new Road("example", 100.0);
    road->setName("example");

    sim.addRoad(road);

    EXPECT_EQ(road, sim.findRoad("example"));
}

TEST(SimulationTests, CountVehiclesHappyDay) {
    Simulation sim = Simulation();
    Road* road = new Road("example", 100.0);
    road->setName("example");
    sim.addRoad(road);

    Vehicle* vehicle = new Vehicle(0.0, VehicleType::Personal);
    road->addVehicle(vehicle);

    EXPECT_EQ(1, sim.countVehicles());
}

TEST(SimulationTests, GetSetRoads) {
    Simulation sim = Simulation();
    REQUIRE(sim.getRoads().empty(), "simulation should not have roads yet");
    Road* road = new Road("example", 10.0);
    sim.addRoad(road);
    REQUIRE(sim.getRoads().size()==1, "added road was not detected");
    REQUIRE(sim.findRoad("example")==road, "could not find road with added name");
}
