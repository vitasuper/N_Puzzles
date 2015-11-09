//
//  RandomRestartHillClimbing.h
//  N_Puzzles
//
//  Copyright © 2015年 vitasuper. All rights reserved.
//

#ifndef RandomRestartHillClimbing_h
#define RandomRestartHillClimbing_h
#include "Puzzle.h"

class RandomRestartHillClimbing {
public:
    RandomRestartHillClimbing();
    void hillClimbing(Puzzle b);
    bool getResult();
    void setSteps(int s);
    int getSteps();
private:
    bool meetResult;
    int steps;
};


#endif /* RandomRestartHillClimbing_h */
