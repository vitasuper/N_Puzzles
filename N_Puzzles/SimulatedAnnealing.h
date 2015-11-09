//
//  SimulatedAnnealing.h
//  N_Puzzles
//
//  Copyright © 2015年 vitasuper. All rights reserved.
//

#ifndef SimulatedAnnealing_h
#define SimulatedAnnealing_h

#include "Puzzle.h"

class SimulatedAnnealing {
public:
    SimulatedAnnealing();
    void simulatedAnneal(Puzzle b);
    bool getResult();
    void setSteps(int s);
    int getSteps();
private:
    bool meetResult;
    double curTemperature, coolingRate, minTemperature;
    int steps;
};
#endif /* SimulatedAnnealing_h */
