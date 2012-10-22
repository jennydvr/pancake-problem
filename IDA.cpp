//
//  IDA.cpp
//  pancake-problem
//
//  Created by Grace Gimon on 06/10/12.
//  Copyright (c) 2012 Grace Gimon. All rights reserved.
//

#include "IDA.h"

using namespace std;

// Recursive procedure that calculates a solution
// until certain depth is reached
Solution boundedDFS(Node n, int t) {
    Solution solution;
    
    // Check if there is a solution
    if (n.isGoal()) {
        solution.plan = n.getFlips();
        solution.cost = n.getG();
        solution.solved = true;
        return solution;
    }
    
    // Checks if the bound hasn't been reached
    int sum = n.getG() + n.getH() * weight;
    if (sum > t) {
        solution.cost = sum;
        return solution;
    }
    
    int newT = bound;
    
    for (int i = 2; i != n.getNumPancakes() + 1; ++i) {
        if (i == n.getParentFlip())
            continue;
        
        Solution aux = boundedDFS(n.getSuccesor(i), t);
        
        // If there is a solution, push the flip to the plan and return
        if (aux.solved)
            return aux;
        
        // Else, update the bound
        newT = min(newT, aux.cost);
    }
    
    // There is no succesor that reachs the goal
    solution.cost = newT;
    return solution;
}

// IDA* algorithm
Solution ida(Node n, int w) {
    weight = w;
    
    Solution solution;
    solution.cost = n.getH() * weight;
    
    while (!solution.solved && solution.cost < bound)
        solution = boundedDFS(n, solution.cost);
    
    return solution;
}
