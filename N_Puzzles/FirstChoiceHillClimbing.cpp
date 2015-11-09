//
//  FirstChoiceHillClimbing.cpp
//  N_Puzzles
//
//  Copyright © 2015年 vitasuper. All rights reserved.
//


#include "FirstChoiceHillClimbing.h"

FirstChoiceHillClimbing::FirstChoiceHillClimbing() {
    meetResult = false;
    steps = 0;
}

bool FirstChoiceHillClimbing::getResult() {
    return meetResult;
}

int FirstChoiceHillClimbing::getSteps() {
    return steps;
}

void FirstChoiceHillClimbing::setSteps(int s) {
    steps = s;
}

void FirstChoiceHillClimbing::hillClimbing(Puzzle p) {
    meetResult = false;
    Puzzle successor = Puzzle::generateProperPuzzle(p);
    steps++;
    bool flag = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (p.blockState[i][j] != successor.blockState[i][j]) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    if (flag) {
        if (successor.getHeuristic() == 0) {
            meetResult = true;
        } else {
            meetResult = false;
        }
    } else {
        hillClimbing(successor);
    }
}
