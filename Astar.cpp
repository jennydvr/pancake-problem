//
//  Astar.cpp
//  pancake-problem
//
//  Created by Grace Gimon on 16/10/12.
//  Copyright (c) 2012 Grace Gimon. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
#include "Astar.h"

    
    // Priority queue
    vector<Node> open;
    
    // Tuple of state and cost to that state
    vector<tuple<vector<int>,int>> closedSet;
    
    // Bound
    int boundS = 100000;
   
    SolutionStar::SolutionStar() {
        solved = false;
    }    

    SolutionStar aStar(Node root, int weight){
    	SolutionStar sol;
    	root.setWeight(weight);
    	open.push_back(root);  // Add the root to the "open" priority queue
    	make_heap(open.begin(), open.end());  // The heap open is ordered from lowest (g+h) values to highest. 	
    	while (!open.empty()){
    		Node* n = new Node();
    		*n = (open.front());
    		pop_heap(open.begin(), open.end());
    		
    		open.pop_back(); // Removed from open set.
    		
    		if (n->isGoal()){
    			sol.solved = true;
    			sol.cost = n->getG();
    			sol.plan = extractSolution(n);
    			reverse(sol.plan.begin(), sol.plan.end());
    			return sol;
    		}
    		
    		int statePos = findState(n->getState()); // 
    		
    		if (statePos != -1)
    		cout << get<1>(closedSet[statePos]) << " closedSet > n.getG  " << n->getG() << endl;
    	
    			if ( (statePos == -1) || n->getG() < get<1>(closedSet[statePos])){// If state has already been visited
	    			if (statePos == -1){ // If node doesn't exists in closedSet
	    				closedSet.push_back(make_tuple(n->getState(),n->getG())); // Add it
	    			}
	    			else{ // If cost from root to actual node is better than the one in closedSet
	    				get<1>(closedSet[statePos]) = n->getG();
	    			
	    			}
	    			Node succesor;
	    			for (int i = 2; i != n->getNumPancakes() + 1; ++i) {
	    				 succesor = n->getSuccesor(i);
					     succesor.setP(n); // Set parent node
					     succesor.setWeight(weight); // We add this to multiply heuristic value * weight (W-Astar case)
					     succesor.setKflip(i); // Which k-flip was made to get current succesor.
	
					     if (succesor.getH() < boundS){ // Continue exploring if heuristic value lower than bound.
					    	 open.push_back(succesor); // Add it to "open"
					    	 push_heap(open.begin(), open.end());
					     }  
			    		}
	    		}
    		sort_heap(open.begin(), open.end()); // We sort "open" from lowest (g+h) to highest.
    	}
    	
    	sol.cost = -1; // If algorithm reaches this point, problem UNSOLVABLE
    	return sol;
    	
    }
    
    vector<int>  extractSolution(Node* node){
    	vector<int> miniplan;
   
    	if (node->getP() != 0){
			miniplan = extractSolution(node->getP());
			miniplan.push_back(node->getK()); // We list every k-flip made from root to goal
    		 return miniplan;
    	}
    	else{
    		miniplan.push_back(node->getK());
    		return 	miniplan;
    	}
    	
    }
    
    int findState(vector<int> state){
	   for (int i = 0; i != closedSet.size(); ++i){
	    	if (get<0>(closedSet[i]) == state){ 
	    		cout << "Find State: " << i << endl;
	    		return i;
			}
	   }
	   return -1;
    }
    
    
    
