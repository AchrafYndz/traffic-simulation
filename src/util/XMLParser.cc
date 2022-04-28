/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: XML parser logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:06 pm
 */

#include "XMLParser.h"

#include "../data/Constants.h"
#include "../objects/Road.h"
#include "../objects/TrafficLight.h"
#include "../objects/Vehicle.h"
#include "../objects/VehicleGenerator.h"
#include "../Simulation.h"
#include "../lib/DesignByContract.h"
#include "../objects/BusStop.h"
#include "../objects/CrossRoad.h"

#include <map>

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized properly");
*/
void XMLParser::validateNode(const pugi::xml_node &node, const std::string &name) const {
    REQUIRE(this->properlyInitialized(), "Parser was not properly initialized");
    ASSERT(!node.empty(), ("XML: no child found for " + name).c_str());
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized properly");
\n ENSURE(value>=0, "Parsed integer cannot be negative");
*/
int XMLParser::parsePositiveInteger(const std::string &s, const std::string &name,
                                    const bool strictlyPositive = false) const {
    REQUIRE(this->properlyInitialized(), "Parser was not properly initialized");
    int value;
    try {
        value = stoi(s);
        ASSERT((strictlyPositive && value > 0) || !strictlyPositive,
               ("XML: " + name + " must be strictly positive").c_str());
        ASSERT(value >= 0, ("XML: " + name + " must be positive").c_str());
    }
    catch (std::exception &e) {
        ASSERT(false, ("XML: " + name + " must be an integer").c_str());
    }
    ENSURE(value >= 0, "Parsed integer cannot be negative");
    return value;
}

/**
\n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
\n ENSURE(road != nullptr, "Road has to be generated");
*/
Road *XMLParser::parseRoad(const pugi::xml_node &node) {
    REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");

    // Fetch nodes
    pugi::xml_node nameNode = node.child("naam");
    pugi::xml_node lengthNode = node.child("lengte");

    // Check if the nodes exist
    validateNode(nameNode, "name");
    validateNode(lengthNode, "length");

    // Extract values
    std::string roadName = nameNode.text().as_string();
    int roadLength = parsePositiveInteger(lengthNode.text().as_string(), "length", true);

    // Create road object
    Road *road = new Road(roadName, roadLength);

    ENSURE(road != nullptr, "Road has to be generated");
    return road;
}

CrossRoad *XMLParser::parseCrossRoad(const pugi::xml_node &node) const {
    REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");

    pugi::xml_node firstRoadNode = node.first_child();
    pugi::xml_node secondRoadNode = firstRoadNode.next_sibling();

    // Fetch nodes
    int firstPos = firstRoadNode.attribute("positie").as_int();
    int secondPos = secondRoadNode.attribute("positie").as_int();

    std::string firstRoadName = firstRoadNode.text().as_string();
    std::string secondRoadName = secondRoadNode.text().as_string();

    // Create cross road object
    CrossRoad *crossRoad = new CrossRoad({firstRoadName, firstPos}, {secondRoadName, secondPos});

    ENSURE(crossRoad != nullptr, "Road has to be generated");
    return crossRoad;
}

/**
\n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
*/
VehicleType XMLParser::parseVehicleType(const pugi::xml_node &node) {
    // Default case
    if (node.empty()) return VehicleType::Personal;

    std::string name = node.text().as_string();
    if (name == "auto") return VehicleType::Personal;
    else if (name == "bus") return VehicleType::Bus;
    else if (name == "brandweerwagen") return VehicleType::FireTruck;
    else if (name == "ziekenwagen") return VehicleType::Ambulance;
    else if (name == "politiecombi") return VehicleType::Police;
    else ASSERT(false, ("XML: unknown vehicle type '" + name + "'").c_str());
}

/**
\n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
\n ENSURE(vehicle != nullptr, "Road has to be generated");
*/
Vehicle *XMLParser::parseVehicle(const pugi::xml_node &node) {
    REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");

    // Fetch nodes
    pugi::xml_node roadNode = node.child("baan");
    pugi::xml_node posNode = node.child("positie");
    pugi::xml_node typeNode = node.child("type"); // we will not validate this node as it can be empty

    // Check if the nodes exist
    validateNode(roadNode, "baan");
    validateNode(posNode, "positie");

    // Extract values
    std::string road = roadNode.text().as_string();
    int pos = parsePositiveInteger(posNode.text().as_string(), "position");

    // Create vehicle object
    VehicleType vehicleType = parseVehicleType(typeNode);
    Vehicle *vehicle = new Vehicle(pos, vehicleType);

    ENSURE(vehicle != nullptr, "Road has to be generated");
    return vehicle;
}

/**
\n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
\n ENSURE(generator != nullptr, "Road has to be generated");
*/
VehicleGenerator *XMLParser::parseVehicleGenerator(const pugi::xml_node &node) {
    REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");

    // Fetch nodes
    pugi::xml_node freqNode = node.child("frequentie");
    pugi::xml_node typeNode = node.child("type"); // we will not validate this node as it can be empty

    // Check if the nodes exist
    validateNode(freqNode, "frequentie");

    // Extract values
    int freq = parsePositiveInteger(freqNode.text().as_string(), "frequency", true);

    // Create vehicle generator object
    VehicleType vehicleType = parseVehicleType(typeNode);
    VehicleGenerator *generator = new VehicleGenerator(freq, vehicleType);

    ENSURE(generator != nullptr, "Road has to be generated");
    return generator;
}

/**
\n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
\n ENSURE(trafficLight != nullptr, "Road has to be generated");
*/
TrafficLight *XMLParser::parseTrafficLight(const pugi::xml_node &node) {
    REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");

    // Fetch nodes
    pugi::xml_node positionNode = node.child("positie");
    pugi::xml_node cycleNode = node.child("cyclus");

    // Check if the nodes exist
    validateNode(positionNode, "position");
    validateNode(cycleNode, "cycle");

    // Extract values
    int pos = parsePositiveInteger(positionNode.text().as_string(), "position");
    int cycle = parsePositiveInteger(cycleNode.text().as_string(), "cycle", true);

    // Create traffic light object
    TrafficLight *trafficLight = new TrafficLight(pos, cycle);

    ENSURE(trafficLight != nullptr, "Road has to be generated");
    return trafficLight;
}


/**
 \n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
 \n ENSURE(busStop != nullptr, "Road has to be generated";
 */
BusStop *XMLParser::parseBusStop(const pugi::xml_node &node) {
    REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");

    // Fetch nodes
    pugi::xml_node roadNode = node.child("baan");
    pugi::xml_node posNode = node.child("positie");
    pugi::xml_node waitTimeNode = node.child("wachttijd");

    // Check if the nodes exist
    validateNode(roadNode, "baan");
    validateNode(posNode, "positie");
    validateNode(waitTimeNode, "wachttijd");

    // Extract values
    std::string road = roadNode.text().as_string();
    double pos = parsePositiveInteger(posNode.text().as_string(), "position", true);
    int waitTime = parsePositiveInteger(waitTimeNode.text().as_string(), "wait time", true);

    // Create bushalte object
    BusStop *busStop = new BusStop(pos, waitTime);

    ENSURE(busStop != nullptr, "Road has to be generated");
    return busStop;
}

/**
\n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
*/
std::string XMLParser::parseRoadReference(const pugi::xml_node &node) {
    // Fetch nodes
    pugi::xml_node roadNode = node.child("baan");

    // Check if the nodes exist
    validateNode(roadNode, "road");

    // Parse road name
    std::string road = roadNode.text().as_string();
    return road;
}

std::pair<std::string, std::string> XMLParser::parseRoadReferences(const pugi::xml_node &node) {
    // Fetch nodes
    pugi::xml_node firstRoadNode = node.first_child();
    pugi::xml_node secondRoadNode = firstRoadNode.next_sibling();

    // Check if the nodes exist
    validateNode(firstRoadNode, "road");
    validateNode(secondRoadNode, "road");

    // Parse road names
    std::pair<std::string, std::string> roads = {firstRoadNode.text().as_string(), secondRoadNode.text().as_string()};
    return roads;
}


/**
\n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
*/
void XMLParser::parse(Simulation &sim, const std::string file) {
    REQUIRE(this->properlyInitialized(), "Parser was not properly initialized");
    // Load input file
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(file.c_str());
    // Make sure the file was loaded correctly
    ASSERT(result, "XML: invalid file");

    // Parameters for validation
    std::map<std::string, std::vector<TrafficLight *>> trafficLights = {};
    std::map<std::string, std::vector<Vehicle *>> vehicles = {};
    std::map<std::string, std::vector<VehicleGenerator *>> generators = {};
    std::map<std::string, std::vector<BusStop *>> busStops = {};
    std::map<std::string, std::vector<CrossRoad *>> crossRoads = {};

    // Loop over all nodes in the document
    // we just loaded
    for (pugi::xml_node node: doc) {
        // Extract the node's name, we'll use this to determine the
        // type of node we're dealing with
        std::string name = node.name();
        if (name == "BAAN") {
            // Parse and register road
            Road *road = parseRoad(node);
            sim.addRoad(road);
        } else if (name == "VERKEERSLICHT") {
            // Parse traffic light
            TrafficLight *trafficLight = parseTrafficLight(node);
            std::string road = parseRoadReference(node);

            // Verify and register traffic light
            if (trafficLights.find(road) == trafficLights.end()) trafficLights.insert({road, {}});
            trafficLights[road].push_back(trafficLight);

        } else if (name == "VOERTUIG") {
            // Parse vehicle
            Vehicle *vehicle = parseVehicle(node);
            std::string road = parseRoadReference(node);

            // Verify and register vehicle
            if (vehicles.find(road) == vehicles.end()) vehicles.insert({road, {}});
            vehicles[road].push_back(vehicle);
        } else if (name == "VOERTUIGGENERATOR") {
            // Parse vehicle generator
            VehicleGenerator *generator = parseVehicleGenerator(node);
            std::string road = parseRoadReference(node);

            // Verify and register vehicle generator
            if (generators.find(road) == generators.end()) generators.insert({road, {}});
            generators[road].push_back(generator);
        } else if (name == "BUSHALTE") {
            // Parse bus stop
            BusStop *busStop = parseBusStop(node);
            std::string road = parseRoadReference(node);

            // Verify and register bus stop
            if (busStops.find(road) == busStops.end()) busStops.insert({road, {}});
            busStops[road].push_back(busStop);
        } else if (name == "KRUISPUNT") {
            // Parse cross road
            CrossRoad *crossRoad = parseCrossRoad(node);
            std::string road1;
            std::string road2;
            std::pair<std::string, std::string> roadStrings = parseRoadReferences(node);

            // Verify and register cross road
            if (crossRoads.find(road1) == crossRoads.end()) crossRoads.insert(road1, {});
            crossRoads[road1].push_back(crossRoad);
            if (crossRoads.find(road2) == crossRoads.end()) crossRoads.insert(road2, {});
            crossRoads[road2].push_back(crossRoad);
        } else {
            ASSERT(false, ("XML: unknown tag '" + name + "'").c_str());
        }
    }


    // Let's continue parsing the data
    // We have to put every vehicle and traffic light
    // on a road, while making sure that the road exists.

    // Vehicles
    for (std::pair<std::string, std::vector<Vehicle *>> p: vehicles) {
        Road *road = sim.findRoad(p.first);
        ASSERT(road != nullptr, ("XML: unknown road " + p.first).c_str());

        // Register the vehicle
        for (Vehicle *v: p.second) {
            ASSERT(v->getPosition() <= road->getLength(), "XML: vehicle outside of road boundaries");
            road->addVehicle(v);
        }
    }

    for (Road *road: sim.getRoads()) {
        std::vector<Vehicle *> roadVehicles = road->getVehicles();
        for (int vehicleIndexOne = 0; vehicleIndexOne < (int) roadVehicles.size(); vehicleIndexOne++) {
            Vehicle *vehicleOne = roadVehicles[vehicleIndexOne];
            for (int vehicleIndexTwo = 0; vehicleIndexTwo < (int) roadVehicles.size(); vehicleIndexTwo++) {
                if (vehicleIndexOne == vehicleIndexTwo) continue;

                Vehicle *vehicleTwo = roadVehicles[vehicleIndexTwo];
                ASSERT(vehicleTwo->getPosition() != vehicleOne->getPosition(),
                       "XML: vehicles cannot be on the same position");
            }
        }
    }

    // Traffic lights
    for (std::pair<std::string, std::vector<TrafficLight *>> p: trafficLights) {
        Road *road = sim.findRoad(p.first);
        ASSERT(road != nullptr, ("XML: unknown road " + p.first).c_str());

        // Register the traffic light
        for (TrafficLight *t: p.second) {
            ASSERT(t->getPosition() <= road->getLength(), "XML: traffic light outside of road boundaries");
            road->addTrafficLight(t);
        }
    }

    for (Road *road: sim.getRoads()) {
        std::vector<TrafficLight *> placedTrafficLights = road->getTrafficLights();
        for (int trafficLightIndexOne = 0;
             trafficLightIndexOne < (int) placedTrafficLights.size(); trafficLightIndexOne++) {
            TrafficLight *trafficLightOne = placedTrafficLights[trafficLightIndexOne];
            for (int trafficLightIndexTwo = 0;
                 trafficLightIndexTwo < (int) placedTrafficLights.size(); trafficLightIndexTwo++) {
                if (trafficLightIndexOne == trafficLightIndexTwo) continue;

                TrafficLight *trafficLightTwo = placedTrafficLights[trafficLightIndexTwo];
                ASSERT(!(trafficLightTwo->getPosition() > (trafficLightOne->getPosition() - gDecelerationDistance) &&
                         trafficLightTwo->getPosition() < trafficLightOne->getPosition()),
                       "XML: traffic light in deceleration zone of other traffic light");
                ASSERT(trafficLightTwo->getPosition() != trafficLightOne->getPosition(),
                       "XML: traffic lights cannot be on the same position");
            }
        }
    }

    // Vehicle generators
    for (std::pair<std::string, std::vector<VehicleGenerator *>> p: generators) {
        Road *road = sim.findRoad(p.first);
        ASSERT(road != nullptr, ("XML: unknown road " + p.first).c_str());
        ASSERT(p.second.size() <= 1, ("XML: multiple vehicle generators on road " + p.first).c_str());

        for (VehicleGenerator *g: p.second) road->setGenerator(g);
    }
}


