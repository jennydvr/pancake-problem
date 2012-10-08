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
#include <stack>

using namespace std;
	
	// Stack where the already visited nodes reside
	stack<Node> closed;
	
	// Termination bound
	int bound;
	
	//Struct of the solution
	struct Solution {
		stack<Node> plan;
		int cost;
	};
	
	// Returns the path from root to node n
	stack<Node> extractSolution(Node n);

	// IDA* algorithm
	Solution ida(Node n, int cost);
	
	// Bounded DFS
	Solution boundedDFS(Node n, int t);
	

#endif /* defined(__pancake_problem__IDA__) */