//
//  SteepestAscentHillClimbing.cpp
//  N_Puzzles
//
//  Copyright © 2015年 vitasuper. All rights reserved.
//

#include "SteepestAscentHillClimbing.h"
#include "Puzzle.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(Puzzle &a, Puzzle &b) {
    return a.getHeuristic() < b.getHeuristic();
}

SteepestAscentHillClimbing::SteepestAscentHillClimbing() {
    meetResult = false;
    steps = 0;
}

bool SteepestAscentHillClimbing::getResult() {
    return meetResult;
}

void SteepestAscentHillClimbing::setResult(bool flag) {
    meetResult = flag;
}

int SteepestAscentHillClimbing::getSteps() {
    return steps;
}

void SteepestAscentHillClimbing::setSteps(int s) {
    steps = s;
}

void SteepestAscentHillClimbing::hillClimbing(Puzzle p) {
    //cout << p.getHeuristic() << endl;
    vector<Puzzle> successors = Puzzle::generateNextPuzzles(p);
    steps++;
    sort(successors.begin(), successors.end(), cmp);
    //cout << successors[0].getHeuristic() << endl;
    if (successors[0].getHeuristic() < p.getHeuristic()) {
        hillClimbing(successors[0]);
    } else {
        if (p.getHeuristic() == 0) {
            meetResult = true;
        } else {
            meetResult = false;
        }
    }
}

