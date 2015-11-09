//
//  main.cpp
//  N_Puzzles
//
//  Copyright © 2015年 vitasuper. All rights reserved.
//

#include <iostream>
#include <random>
#include <vector>
#include "Puzzle.h"
#include "SteepestAscentHillClimbing.h"
#include "FirstChoiceHillClimbing.h"
#include "RandomRestartHillClimbing.h"
#include "SimulatedAnnealing.h"
//#define test 1
using namespace std;

int main(int argc, const char * argv[]) {
     Puzzle start(8);
    
#ifdef test
   
    
    for (int i = 0 ; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << start.blockState[i][j] << " ";
        }
    }
    cout << endl;
    
    cout << start.getHeuristic() << endl;
    
    start.setRandomStatus();
    for (int i = 0 ; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << start.blockState[i][j] << " ";
        }
    }
    cout << endl;
    
    cout << start.getHeuristic() << endl;
    
    vector<Puzzle> v = Puzzle::generateNextPuzzles(start);
    
    for(int k = 0; k < v.size(); k++) {
    for (int i = 0 ; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << v[k].blockState[i][j] << " ";
        }
    }
        cout << endl;
    }
    
    cout << endl;
    
    
#else
    srand(time(NULL));
    
    SteepestAscentHillClimbing sahc;
    FirstChoiceHillClimbing fchc;
    RandomRestartHillClimbing rrhc;
    SimulatedAnnealing sa;
    
    
    int testCaseCnt = 100;
    // 1. Test Steepest-ascent Hill Climbing
    int success = 0, failure = 0, successSteps = 0, failureSteps = 0, totalSteps = 0;
    for (int i = 0; i < testCaseCnt; ++i) {
        sahc.setSteps(0);
        sahc.setResult(false);
        start.setRandomStatus();
        sahc.hillClimbing(start);
        if (sahc.getResult()) {
            success++;
            successSteps += sahc.getSteps();
        } else {
            failure++;
            failureSteps += sahc.getSteps();
        }
        totalSteps += sahc.getSteps();
    }
    cout << "1. Steepest-ascent Hill Climbing" << endl;
    cout << "Success rate: " << (success + 0.0) / testCaseCnt * 100  << '%' << endl;
    cout << "Failure rate: " << (failure + 0.0) / testCaseCnt * 100  << '%' << endl;
    cout << "Success average cost: " << (successSteps + 0.0) / success << endl;
    cout << "Failure average cost: " << (failureSteps + 0.0) / failure << endl;
    cout << "Total average cost: " << (totalSteps + 0.0) / testCaseCnt << endl;
    cout << endl;
    
    
    // 2. Test First-choice Hill Climbing
    success = failure = successSteps = failureSteps = totalSteps = 0;
    for (int i = 0; i < testCaseCnt; ++i) {
        start.setRandomStatus();
        fchc.setSteps(0);
        fchc.hillClimbing(start);
        if (fchc.getResult()) {
            success++;
            successSteps += fchc.getSteps();
        } else {
            failure++;
            failureSteps += fchc.getSteps();
        }
        totalSteps += fchc.getSteps();
    }
    cout << "2. First-choice Hill Climbing" << endl;
    cout << "Success rate: " << (success + 0.0) / testCaseCnt * 100  << '%' << endl;
    cout << "Failure rate: " << (failure + 0.0) / testCaseCnt * 100  << '%' << endl;
    cout << "Success average cost: " << (successSteps + 0.0) / success << endl;
    cout << "Failure average cost: " << (failureSteps + 0.0) / failure << endl;
    cout << "Total average cost: " << (totalSteps + 0.0) / testCaseCnt << endl;
    cout << endl;
    
    // 3. Test Hill Climbing with Random Restart
    success = failure = successSteps = failureSteps = totalSteps = 0;
    for (int i = 0; i < testCaseCnt; ++i) {
        start.setRandomStatus();
        rrhc.setSteps(0);
        rrhc.hillClimbing(start);
        if (rrhc.getResult()) {
            success++;
            successSteps += rrhc.getSteps();
        } else {
            failure++;
            failureSteps += rrhc.getSteps();
        }
        totalSteps += rrhc.getSteps();
        
    }
    cout << "3. Hill Climbing with Random Restart" << endl;
    cout << "Success rate: " << (success + 0.0) / testCaseCnt * 100  << '%' << endl;
    cout << "Failure rate: " << (failure + 0.0) / testCaseCnt * 100  << '%' << endl;
    cout << "Success average cost: " << (successSteps + 0.0) / success << endl;
    if (failure != 0) {
        cout << "Failure average cost: " << (failureSteps + 0.0) / failure << endl;
    } else {
        cout << "Failure average cost: " << 0 << endl;
    }
    cout << "Total average cost: " << (totalSteps + 0.0) / testCaseCnt << endl;
    
    cout << endl;
    
    
    // 4. Test Simulated Annealing
    success = failure = successSteps = failureSteps = totalSteps = 0;
    
    for (int i = 0; i < testCaseCnt; ++i) {
        start.setRandomStatus();
        sa.setSteps(0);
        sa.simulatedAnneal(start);
        if (sa.getResult()) {
            success++;
            successSteps += sa.getSteps();
        } else {
            failure++;
            failureSteps += sa.getSteps();
        }
        totalSteps += sa.getSteps();
    }
    cout << "4. Simulated Annealing" << endl;
    cout << "Success rate: " << (success + 0.0) / testCaseCnt * 100  << '%' << endl;
    cout << "Failure rate: " << (failure + 0.0) / testCaseCnt * 100  << '%' << endl;
    cout << "Success average cost: " << (successSteps + 0.0) / success << endl;
    if (failure != 0) {
        cout << "Failure average cost: " << (failureSteps + 0.0) / failure << endl;
    } else {
        cout << "Failure average cost: " << 0 << endl;
    }
    cout << "Total average cost: " << (totalSteps + 0.0) / testCaseCnt << endl;
    
    cout << endl;
    
#endif
    
    return 0;
}
