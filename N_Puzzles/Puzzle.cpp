//
//  Puzzle.cpp
//  N_Puzzles
//
//  Copyright © 2015年 vitasuper. All rights reserved.
//

#include "Puzzle.h"
#include <random>
#include <vector>
#include <cmath>

Puzzle::Puzzle(int s) {
    puzzleSize = s;
    setRandomStatus();
}

bool canMove(int r, int c) {
    if (r >= 0 && r < 3 && c >= 0 && c < 3) return true;
    else return false;
}

void Puzzle::setRandomStatus() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            blockState[i][j] = initbBlockState[i][j];
        }
    }
    
    // shuffle
    int random, zeroRow = 0, zeroCol = 0, tmp, moveR, moveC;
    for (int i = 0; i < 100; ++i) {
        random = rand() % 4;
        if (random == 0) { // up
            moveR = zeroRow-1;
            moveC = zeroCol;
        } else if (random == 1) { // left
            moveR = zeroRow;
            moveC = zeroCol-1;
        } else if (random == 2) { // down
            moveR = zeroRow+1;
            moveC = zeroCol;
            
        } else { // right
            moveR = zeroRow;
            moveC = zeroCol+1;
        }
        if (canMove(moveR, moveC)) {
            tmp = blockState[moveR][moveC];
            blockState[moveR][moveC] = 0;
            blockState[zeroRow][zeroCol] = tmp;
            zeroRow = moveR;
            zeroCol = moveC;
            
        }
    }
    
    
    setHeuristic();
}

int calcManhattan(int r, int c, int num) {
    if (num != 0) {
        int tmpr = num / 3, tmpc = num % 3;
        return abs(r-tmpr) + abs(c-tmpc);
    }
    return 0;
}

void Puzzle::setHeuristic() {
    int result = 0;
    int wrongPos = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int num = blockState[i][j];
            result += calcManhattan(i, j, num);
            if (i*3 + j != blockState[i][j]) wrongPos++;
        }
    }
    heuristic = result / 10 + wrongPos;
}

int Puzzle::getHeuristic() {
    return heuristic;
}

vector<Puzzle> Puzzle::generateNextPuzzles(Puzzle b) {
    vector<Puzzle> puzzles;
    int zeroR = 0, zeroC = 0;
    bool flag = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (b.blockState[i][j] == 0) {
                zeroR = i;
                zeroC = j;
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    int r[4] = {-1, 1, 0, 0};
    int c[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; ++i) {
        int moveR = zeroR + r[i], moveC = zeroC + c[i];
        if (canMove(moveR, moveC)) {
            Puzzle successor = b;
            int tmp = successor.blockState[moveR][moveC];
            successor.blockState[moveR][moveC] = 0;
            successor.blockState[zeroR][zeroC] = tmp;
            successor.setHeuristic();
            puzzles.push_back(successor);
        }
    }
    return puzzles;
}

Puzzle Puzzle::generateProperPuzzle(Puzzle b) {
    vector<Puzzle> successors = generateNextPuzzles(b);
    for (int i = 0; i < successors.size(); ++i) {
        if (successors[i].getHeuristic() < b.getHeuristic()) return successors[i];
    }
    return b;
}


Puzzle Puzzle::generateRandomPuzzle(Puzzle b) {
    vector<Puzzle> successors = generateNextPuzzles(b);
    int random = rand() % successors.size();
    return successors[random];
}

