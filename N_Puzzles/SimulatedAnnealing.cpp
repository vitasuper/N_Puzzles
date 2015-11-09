//
//  SimulatedAnnealing.cpp
//  N_Puzzles
//
//  Copyright © 2015年 vitasuper. All rights reserved.
//

#include "SimulatedAnnealing.h"
#include "Puzzle.h"
#include <cmath>
#include <random>
#include <iostream>

using namespace std;

SimulatedAnnealing::SimulatedAnnealing() {
    meetResult = false;
    steps = 0;
}

bool SimulatedAnnealing::getResult() {
    return meetResult;
}

void SimulatedAnnealing::setSteps(int s) {
    steps = s;
}

int SimulatedAnnealing::getSteps() {
    return steps;
}

void SimulatedAnnealing::simulatedAnneal(Puzzle p) {
    meetResult = false;
    steps = 0;
    curTemperature = 100.0;
    coolingRate = 0.9999;
    minTemperature = 0.0001;
    while (curTemperature > minTemperature) {
        if (p.getHeuristic() == 0) {
            meetResult = true;
            return;
        }
        
        Puzzle successor = Puzzle::generateRandomPuzzle(p);
        steps++;
        
        if (successor.getHeuristic() < p.getHeuristic()) {
            p = successor;
        } else {
            double E = p.getHeuristic() - successor.getHeuristic();
            double T = curTemperature;
            double random = rand() % 100;
            if (random < exp(E / T) * 100) {
                p = successor;
            }
        }
        curTemperature *= coolingRate;
    }
    meetResult = false;
}
