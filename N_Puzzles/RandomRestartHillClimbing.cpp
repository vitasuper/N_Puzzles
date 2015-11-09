//
//  RandomRestartHillClimbing.cpp
//  N_Puzzles
//
//  Copyright © 2015年 vitasuper. All rights reserved.
//

#include <vector>
#include <algorithm>
#include "RandomRestartHillClimbing.h"
#include "Puzzle.h"

bool cmp2(Puzzle &a, Puzzle &b) {
    return a.getHeuristic() < b.getHeuristic();
}

RandomRestartHillClimbing::RandomRestartHillClimbing() {
    meetResult = false;
}

bool RandomRestartHillClimbing::getResult() {
    return meetResult;
}

void RandomRestartHillClimbing::setSteps(int s) {
    steps = s;
}

int RandomRestartHillClimbing::getSteps() {
    return steps;
}

void RandomRestartHillClimbing::hillClimbing(Puzzle p) {
    meetResult = false;
    while (!meetResult) {
        vector<Puzzle> successors = Puzzle::generateNextPuzzles(p);
        steps++;
        sort(successors.begin(), successors.end(), cmp2);
        if (successors[0].getHeuristic() < p.getHeuristic()) {
            hillClimbing(successors[0]);
        } else {
            if (p.getHeuristic() == 0) {
                meetResult = true;
            }
        }
        if (!meetResult) p.setRandomStatus();
    }
}