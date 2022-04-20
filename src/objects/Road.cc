/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 5:12:46 pm
 */

#include "Road.h"
#include "../data/Constants.h"
#include "../lib/DesignByContract.h"


const std::string &Road::getName() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return name;
}


void Road::setName(const std::string &n) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    ENSURE(!name.empty(), "Road name cannot be empty");
    Road::name = n;
}


double Road::getLength() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return length;
}


void Road::setLength(double l) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    ENSURE(l > 0, "Length must be strictly positive");
    Road::length = l;
}


const std::vector<Vehicle *> &Road::getVehicles() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return vehicles;
}


void Road::addVehicle(Vehicle *v) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    ENSURE(v != nullptr, "Cannot add empty vehicle to road");
    v->setId(vehicles.size());
    vehicles.push_back(v);
}


void Road::addTrafficLight(TrafficLight *t) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    ENSURE(t != nullptr, "Cannot add empty traffic light to road");
    trafficLights.push_back(t);
}


const std::vector<TrafficLight *> &Road::getTrafficLights() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return trafficLights;
}


VehicleGenerator *Road::getGenerator() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return generator;
}


void Road::setGenerator(VehicleGenerator *g) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    ENSURE(g != nullptr, "Cannot add empty generator to road");
    generator = g;
}


Vehicle *Road::getLeadingVehicle(Vehicle *v) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    Vehicle *leadingVehicle = nullptr;
    for (Vehicle *candidate: vehicles) {
        if (candidate->getPosition() <= v->getPosition()) continue;
        if (leadingVehicle == nullptr ||
            leadingVehicle->getPosition() - v->getPosition() > candidate->getPosition() - v->getPosition())
            leadingVehicle = candidate;
    }
    return leadingVehicle;
}


void Road::cleanup() {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    std::vector<Vehicle *>::iterator vehicle = vehicles.begin();
    while (vehicle != vehicles.end()) {
        if ((*vehicle)->getPosition() > length) {
            vehicles.erase(vehicle);
        } else ++vehicle;
    }
}


Vehicle *Road::getFirstToTrafficLight(TrafficLight *t) const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    int trafficLightPosition = t->getPosition();
    Vehicle *firstVehicle = nullptr;
    for (Vehicle *vehicle: vehicles) {
        double distanceToLight = ((double) trafficLightPosition) - vehicle->getPosition();
        if (firstVehicle == nullptr) {
            if (distanceToLight > 0) firstVehicle = vehicle;
            continue;
        }

        double previousDistanceToLight = ((double) trafficLightPosition) - firstVehicle->getPosition();

        if (distanceToLight > 0 && distanceToLight < previousDistanceToLight) firstVehicle = vehicle;
    }
    return firstVehicle;
}

void Road::spawnVehicle(const VehicleType &type) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    ENSURE(Enum::IsDefined(VehicleType, type), "Vehicle type is not defined");
    Vehicle *v = new Vehicle(0, VehicleType::Personal);
    addVehicle(v);
}