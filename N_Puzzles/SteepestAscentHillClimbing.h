//
//  SteepestAscentHillClimbing.h
//  N_Puzzles
//
//  Copyright © 2015年 vitasuper. All rights reserved.
//

#ifndef SteepestAscentHillClimbing_h
#define SteepestAscentHillClimbing_h
#include "Puzzle.h"
class SteepestAscentHillClimbing {
public:
    SteepestAscentHillClimbing();
    void hillClimbing(Puzzle p);
    bool getResult();
    void setResult(bool flag);
    int getSteps();
    void setSteps(int s);
private:
    bool meetResult;
    int steps;
};

#endif /* SteepestAscentHillClimbing_h */