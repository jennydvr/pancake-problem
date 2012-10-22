//
//  IDA.cpp
//  pancake-problem
//
//  Created by Grace Gimon on 06/10/12.
//  Copyright (c) 2012 Grace Gimon. All rights reserved.
//

#include "IDA.h"

using namespace std;

// Stack where the already visited nodes reside
vector<Node> closed;
    
// Termination bound
int bound = 100000;

// Weight
int w;

// Recursive procedure that calculates a solution
// until certain depth is reached
Solution boundedDFS(Node n, int t, int lastFlip) {
    Solution solution;
    
    // Checks if the bound hasn't been reached
    int sum = n.getG() + n.getH() * w;
    if (sum > t) {
        solution.cost = sum;
        return solution;
    }
    
    // Check if there is a solution
    if (n.isGoal()) {
        solution.cost = n.getG();
        solution.solved = true;
        return solution;
    }
    
    int newT = bound;
    
    for (int i = 2; i != n.getNumPancakes() + 1; ++i) {
        
        // Skip the step that generated this configuration
        if (i == lastFlip)
            continue;
        
        Solution aux = boundedDFS(n.getSuccesor(i), t, i);
        
        // If there is a solution, push the flip to the plan and return
        if (aux.solved) {
            aux.plan.push_back(i);
            return aux;
        }
        
        // Else, update the bound
        newT = min(newT, aux.cost);
    }

    // There is no succesor that reachs the goal
    solution.cost = newT;
    return solution;
}

// IDA* algorithm
Solution ida(Node n, int weight) {
    Solution solution;
    solution.cost = n.getH() * weight;
    w = weight;
    
    while (!solution.solved && solution.cost < bound)
        solution = boundedDFS(n, solution.cost, 0);
    
    return solution;
}
