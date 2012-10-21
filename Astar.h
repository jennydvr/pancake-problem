//
//  Astar.h
//  pancake-problem
//
//  Created by Grace Gimon on 16/10/12.
//  Copyright (c) 2012 Grace Gimon. All rights reserved.
//

#ifndef __pancake_problem__ASTAR__
#define __pancake_problem__ASTAR__

#include <set>
#include <tuple>
#include "Node.h"

struct SolutionStar {
    vector<int> plan;
    int cost;
    bool solved;
    SolutionStar();
};

// A* algorithm. When weight = 1
SolutionStar aStar(Node root, int weight);

// Returns the path of flips realized.
vector<int> extractSolution(Node* node);

int findState(vector<int> state);


#endif /* defined(__pancake_problem__ASTAR__) */
