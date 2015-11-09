//
//  FirstChoiceHillClimbing.h
//  N_Puzzles
//
//  Copyright © 2015年 vitasuper. All rights reserved.
//

#ifndef FirstChoiceHillClimbing_h
#define FirstChoiceHillClimbing_h
#include "Puzzle.h"

class FirstChoiceHillClimbing {
public:
    FirstChoiceHillClimbing();
    void hillClimbing(Puzzle b);
    bool getResult();
    int getSteps();
    void setSteps(int s);
private:
    bool meetResult;
    int steps;
};


#endif /* FirstChoiceHillClimbing_h */
