//
//  Puzzle.h
//  N_Puzzles
//
//  Copyright © 2015年 vitasuper. All rights reserved.
//

#ifndef Puzzle_h
#define Puzzle_h
#include <vector>

using namespace std;

class Puzzle {
public:
    Puzzle(int s);
    void setRandomStatus();
    void setHeuristic();
    int getHeuristic();
    
    static vector<Puzzle> generateNextPuzzles(Puzzle b);
    static Puzzle generateProperPuzzle(Puzzle b);
    static Puzzle generateRandomPuzzle(Puzzle b);
    
    int blockState[3][3];
private:
    int puzzleSize;
    int heuristic;
    int initbBlockState[3][3] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
};
#endif /* Puzzle_h */
