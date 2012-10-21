//
//  Astar.h
//  pancake-problem
//
//  Created by Grace Gimon on 16/10/12.
//  Copyright (c) 2012 Grace Gimon. All rights reserved.
//

#ifndef __pancake_problem__ASTAR__
#define __pancake_problem__ASTAR__


#include <tuple>
#include "Node.h"

	struct SolutionStar {
	    vector<int> plan; // K-flips ordered from goal to root
	    int cost;
	    bool solved;
	    SolutionStar();
	};
	
	// A* algorithm. When weight = 1
	SolutionStar aStar(Node root, int weight);
	
	// Returns the path of flips realized.
	vector<int> extractSolution(Node* node);
	
	/* Returns the position of the state
	*  in the closedSet if exists, -1 if not.
	*/ 
	int findState(vector<int> state);


#endif /* defined(__pancake_problem__ASTAR__) */
