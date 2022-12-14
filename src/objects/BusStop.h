/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 20th April 2022 9:12:10 pm
 */

#ifndef PSE_TRAFFIC_SIM_BUSSTOP_H
#define PSE_TRAFFIC_SIM_BUSSTOP_H

#include <string>
#include "Entity.h"
#include "Vehicle.h"

class BusStop : public Entity {
private:
    BusStop* _init;

    Vehicle* bus = nullptr;

    int timeCount = 0;

    int waitTime = 0;

public:
    /**
    \n REQUIRE(position >= 0, "Position has to be positive");
    \n REQUIRE(w >= 0, "Wait time has to be positive");
    \n ENSURE(properlyInitialized(), "_init reference must be set");
     */
    BusStop(double position, int w);

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    */
    int getTimeCount() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    \n ENSURE(t >= 0, "Bus stop wait time must be positive");
    \n ENSURE(BusStop::timeCount == t, "Time count was not set properly");
     */
    void setTimeCount(int timeCount);

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    \n ENSURE(timeCount >= 0, "Bus stop time count must be positive");
    \n ENSURE(timeCountBefore + 1 == timeCount, "Time count was not incremented");
     */
    void incrementTimeCount();

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    */
    int getWaitTime() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    \n ENSURE(w > 0, "Bus stop wait time must be strictly positive");
    \n ENSURE(BusStop::waitTime == w, "Wait time was not set properly");
    */
    void setWaitTime(int waitTime);

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    */
    Vehicle *getBus() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    \n ENSURE(b != nullptr, "Bus cannot be nullptr");
    \n ENSURE(BusStop::bus == b, "Bus was not set properly");
    */
    void setBus(Vehicle *bus);

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    */
    void removeBus();

    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};


#endif //PSE_TRAFFIC_SIM_BUSSTOP_H
