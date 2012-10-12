//
//  IDA.h
//  pancake-problem
//
//  Created by Grace Gimon on 06/10/12.
//  Copyright (c) 2012 Grace Gimon. All rights reserved.
//

#ifndef __pancake_problem__IDA__
#define __pancake_problem__IDA__

#include "Node.h"

using namespace std;
    
    // Stack where the already visited nodes reside
    vector<Node> closed;
    
    // Termination bound
    int bound;
    
    //Struct of the solution
    struct Solution;

    // IDA* algorithm
    Solution ida(Node n);
    
    /* Bounded DFS: using DFS searchs for the optimal path
     * from root to node n considering heuristic function
    */
    Solution boundedDFS(Node n, int t);
    

#endif /* defined(__pancake_problem__IDA__) */