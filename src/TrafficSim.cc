/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: simulation entrypoint
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:06 pm
 */

#include <iostream>
#include "util/XMLParser.h"
#include "Simulation.h"

int main() {

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, "../input/testing/ValidSimulationTest3.xml");
    
    sim.writeOn(std::cout, 50);

    return 0;
}
