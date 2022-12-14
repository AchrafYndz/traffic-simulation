/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 5:12:46 pm
 */

#include <algorithm>
#include <limits>
#include "Crossroad.h"
#include "Road.h"
#include "../lib/DesignByContract.h"


const std::string &Road::getName() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return name;
}


void Road::setName(const std::string &n) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    ENSURE(!name.empty(), "Road name cannot be empty");
    Road::name = n;
    ENSURE(Road::name == n, "Road name was not set properly");
}


double Road::getLength() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return length;
}


void Road::setLength(double l) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    ENSURE(l > 0, "Length must be strictly positive");
    Road::length = l;

    ENSURE(std::abs(Road::length - l) < std::numeric_limits<double>::epsilon(), "Road length was not set properly");
}


const std::vector<Vehicle *> &Road::getVehicles() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return vehicles;
}


void Road::addVehicle(Vehicle *v) {
    REQUIRE(v != nullptr, "Cannot add empty vehicle to road");
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    REQUIRE(v->getPosition() < length, "Road not long enough for vehicle");

    v->setId(vehicles.size());
    vehicles.push_back(v);
    ENSURE(std::find(vehicles.begin(), vehicles.end(), v) != vehicles.end(), "Vehicle was not added properly");
}


void Road::addTrafficLight(TrafficLight *t) {
    ENSURE(t != nullptr, "Cannot add empty traffic light to road");
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    REQUIRE(t->getPosition() < length, "Road not long enough for traffic light");

    trafficLights.push_back(t);
    ENSURE(std::find(trafficLights.begin(), trafficLights.end(), t) != trafficLights.end(),
           "Traffic light was not added properly");
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
    REQUIRE(g != nullptr, "Cannot add empty generator to road");
    generator = g;
    ENSURE(generator == g, "Generator was not set properly");
}


Vehicle *Road::getLeadingVehicle(Vehicle *vehicle) const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    REQUIRE(vehicle != nullptr, "Vehicle may not be a nullptr");
    REQUIRE(std::find(vehicles.begin(), vehicles.end(), vehicle) != vehicles.end(), "Vehicle must be on road");
    Vehicle *leadingVehicle = nullptr;
    for (Vehicle *candidate: vehicles) {
        if (candidate->getPosition() <= vehicle->getPosition()) continue;
        if (leadingVehicle == nullptr ||
            leadingVehicle->getPosition() - vehicle->getPosition() > candidate->getPosition() - vehicle->getPosition())
            leadingVehicle = candidate;
    }
    return leadingVehicle;
}


void Road::cleanup() {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    std::vector<Vehicle *>::iterator vehicle = vehicles.begin();
    while (vehicle != vehicles.end()) {
        if ((*vehicle)->getPosition() > length) {
            delete (*vehicle);
            vehicles.erase(vehicle);
        } else ++vehicle;
    }
}


Vehicle *Road::getFirstToTrafficLight(TrafficLight *trafficLight, double minDistance) const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    REQUIRE(trafficLight != nullptr, "Traffic light cannot be nullptr");
    REQUIRE(std::find(trafficLights.begin(), trafficLights.end(), trafficLight) != trafficLights.end(),
            "Traffic light must be on road");

    int trafficLightPosition = trafficLight->getPosition();
    Vehicle *firstVehicle = nullptr;
    for (Vehicle *vehicle : vehicles) {
        if (std::find(gPriorityVehicleTypes.begin(), gPriorityVehicleTypes.end(), vehicle->getType()) !=
                gPriorityVehicleTypes.end())
                continue;
        
        double distanceToLight = ((double) trafficLightPosition) - vehicle->getPosition();
        if (distanceToLight < minDistance) continue;
        
        if (firstVehicle == nullptr) {
            if (distanceToLight > 0) firstVehicle = vehicle;
            continue;
        }

        double previousDistanceToLight = ((double) trafficLightPosition) - firstVehicle->getPosition();

        if (distanceToLight > 0 && distanceToLight < previousDistanceToLight) firstVehicle = vehicle;
    }
    return firstVehicle;
}


Vehicle *Road::getFirstBusToBusStop(BusStop *busStop) const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    REQUIRE(busStop != nullptr, "Bus stop cannot be nullptr");
    REQUIRE(std::find(busStops.begin(), busStops.end(), busStop) != busStops.end(), "Bus stop must be on road");

    int busStopPosition = busStop->getPosition();
    Vehicle *firstBus = nullptr;
    for (Vehicle *bus: vehicles) {
        if (bus->getType() != Bus) continue;
        double distanceToStop = ((double) busStopPosition) - bus->getPosition();
        if (firstBus == nullptr) {
            if (distanceToStop > 0) firstBus = bus;
            continue;
        }

        double previousDistanceToBusStop = ((double) busStopPosition) - firstBus->getPosition();

        if (distanceToStop > 0 && distanceToStop < previousDistanceToBusStop) firstBus = bus;
    }
    return firstBus;
}


void Road::spawnVehicle(const VehicleType &type) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    int countBefore = vehicles.size();

    Vehicle *v = new Vehicle(0, type);
    addVehicle(v);

    int countAfter = vehicles.size();
    ENSURE(countAfter == countBefore + 1, "Vehicle was not spawned correctly");
}

void Road::tickTrafficLights() {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    // Loop over all traffic lights
    for (TrafficLight *trafficLight: trafficLights) {
        int cycleCount = trafficLight->getCycleCount();
        // We should switch our traffic light to orange, let's go ahead and do that
        if (trafficLight->isGreen() && cycleCount * gSimTime > (trafficLight->getCycle() * (1 - gOrangePercentage))) trafficLight->setState(TrafficLightState::Orange);
        
        // We should fully toggle our traffic light
        else if (cycleCount * gSimTime > trafficLight->getCycle()) {
            trafficLight->setState(trafficLight->isGreen() || trafficLight->isOrange() ? TrafficLightState::Red : TrafficLightState::Green);
             trafficLight->setCycleCount(0);

        // Let's just keep counting
        } else trafficLight->setCycleCount(cycleCount + 1);

        // Get the first vehicle relative to the traffic light
        // To make vehicles decelerate or stop, we just need to perform the action
        // on the first vehicle driving towards the traffic light.
        double minDistance = trafficLight->isOrange() ? gBrakeDistance : 0;
        Vehicle *firstVehicle = getFirstToTrafficLight(trafficLight, minDistance);

        // No vehicles are driving towards the traffic light, continue to the next traffic light
        if (firstVehicle == nullptr) continue;

        // If the traffic light is green, all vehicles should accelerate
        if (trafficLight->getState() == TrafficLightState::Green) firstVehicle->accelerate();
        else {
            // The light is red, let's check the distance from the first vehicle to the traffic light
            double distanceToLight = trafficLight->getPosition() - firstVehicle->getPosition();

            // Stop the vehicle if it's in the braking zone
            // This if statement will never be triggered when dealing with orange lights
            if (distanceToLight < gBrakeDistance) firstVehicle->stop();
            // Force the vehicle to decelerate if it's in the deceleration zone
            else if (distanceToLight < gDecelerationDistance) firstVehicle->decelerate();
        }
    }
}


void Road::tickBusStops() {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    for (BusStop *busStop: busStops) {
        int waitTime = busStop->getWaitTime();
        // Get the first bus relative to the bus stop
        Vehicle *firstBus = getFirstBusToBusStop(busStop);

        // Check if there's a bus that can move again
        Vehicle *bus = busStop->getBus();
        if (bus != nullptr) {
            int timeCount = busStop->getTimeCount();

            // Handle busses leaving
            if (bus != firstBus) {
                // The bus has left, let's prepare for the next bus
                busStop->removeBus();
                busStop->setTimeCount(0);
            }

            // Handle busses waiting
            if ((double) waitTime / (double) gSimTime < (double) timeCount) {
                // Let's get the bus to leave
                bus->accelerate();
                // Make sure the bus is not stopped while it is still leaving
                firstBus = nullptr;

                // Start counting once the bus has slowed down enough
            } else if (bus->getSpeed() < 0.01) busStop->incrementTimeCount();
        }

        // No busses are driving towards the bus stop, continue to the next bus stop
        if (firstBus == nullptr) continue;

        // Check the distance from the first bus to the bus stop
        double distanceToStop = busStop->getPosition() - firstBus->getPosition();

        // Stop the bus if it's in the braking zone
        if (distanceToStop < gBrakeDistance) {
            firstBus->stop();
            busStop->setBus(firstBus);
        }


            // Force the bus to decelerate if it's in the deceleration zone
        else if (distanceToStop < gDecelerationDistance) firstBus->decelerate();
    }
}

void Road::tickVehicles(std::ostream &onStream) {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");

    // Loop over all vehicles
    for (std::vector<Vehicle *>::iterator vehicle = vehicles.begin(); vehicle != vehicles.end();) {
        // Save position before tick
        double pBefore = (*vehicle)->getPosition();
        // Tick the relevant vehicle
        (*vehicle)->tick(getLeadingVehicle(*vehicle));
        // Save position after tick
        double pAfter = (*vehicle)->getPosition();

        // Create boolean to keep track of removal
        bool remove = false;
        // Handle crossroads
        for (Crossroad *crossroad: crossroads) {
            // Get crossroad position
            double crossroadPosition = crossroad->getPositionForRoad(this);
            if (pAfter >= crossroadPosition && pBefore < crossroadPosition) {
                // 1/2 chance to move roads
                int random = rand() % 2;

                // Vehicle has to move roads
                if (random == 1) {
                    // Get other road info
                    std::pair<CrossroadDetails *, CrossroadDetails *> details = crossroad->getDetails();
                    CrossroadDetails *otherDetails = details.first->road == this ? details.second : details.first;

                    // Move to other road
                    (*vehicle)->setPosition(otherDetails->position);
                    otherDetails->road->addVehicle(*vehicle);

                    // Set a boolean indicating that the vehicle should be removed
                    remove = true;
                }
            }
        }


        // Print all information on the vehicle in
        // the requested format
        onStream << "Vehicle " << (*vehicle)->getId() << std::endl;
        onStream << "-> Road: " << getName() << std::endl;
        onStream << "-> Position: " << (*vehicle)->getPosition() << std::endl;
        onStream << "-> Speed: " << (*vehicle)->getSpeed() << std::endl;

        if (remove) vehicles.erase(vehicle);
        else vehicle++;
    }
}

void Road::tickVehicleGenerators() {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    // If there's a generator running on the road and the cycle time
    // has been exceeded, spawn a new vehicle
    if (generator == nullptr) return;

    // Get the frequency count for the generator
    int freqCount = generator->getFrequencyCount();
    bool shouldSpawn = freqCount * gSimTime > generator->getFrequency();

    // Spawn a vehicle if necessary
    if (shouldSpawn) {
        spawnVehicle(generator->getType());
        generator->setFrequencyCount(0);
    } else generator->setFrequencyCount(freqCount + 1);
}

void Road::tick(std::ostream &stream) {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    tickVehicleGenerators();
    tickTrafficLights();
    tickBusStops();
    tickVehicles(stream);

    cleanup();
}

const std::vector<BusStop *> &Road::getBusStops() const {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    return busStops;
}

const std::vector<Crossroad *> &Road::getCrossroads() const {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    return crossroads;
}

void Road::addCrossroad(Crossroad *c) {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    REQUIRE(c != nullptr, "Crossroad cannot be nullptr");
    REQUIRE(c->getPositionForRoad(this) < length, "Road not long enough for crossroad");
    Road::crossroads.push_back(c);
    ENSURE(std::find(crossroads.begin(), crossroads.end(), c) != crossroads.end(), "Crossroad was not added properly");
}

void Road::addBusStop(BusStop *b) {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    REQUIRE(b != nullptr, "Bus stop cannot be nullptr");
    REQUIRE(b->getPosition() < length, "Road not long enough for bus stop");
    busStops.push_back(b);
    ENSURE(std::find(busStops.begin(), busStops.end(), b) != busStops.end(), "Bus was not added properly");
}

Road::Road(std::string n, double l) : name(n), length(l) {
    REQUIRE(l > 0, "Road length must be strictly positive");

    _init = this;
    ENSURE(properlyInitialized(), "_init reference must be set");
}
