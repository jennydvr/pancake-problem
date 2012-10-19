//
//  Astar.cpp
//  pancake-problem
//
//  Created by Grace Gimon on 16/10/12.
//  Copyright (c) 2012 Grace Gimon. All rights reserved.
//
#include "Astar.h"

    // Heap where the already visited nodes reside
    vector<Node> closedSet;
    
    // Priority queue
    vector<Node> open;
    
    // Bound
    int boundS;
   
    
    SolutionStar aStar(Node root, int weight){
    	SolutionStar sol;
    	boundS = 3;
    	open.push_back(root);
    	make_heap(open.begin(), open.end());
    	set<Node> closed;
    	set<Node>::iterator it;
    	
		// The heap open is ordered from lowest (g+h) values to highest. 	
    	while (!open.empty()){
    		pop_heap(open.begin(), open.end());
    		Node n = open.front();
    		open.pop_back(); // Removed from open set.
//    		
//    		cout << "Nodo open " << endl;
//    		cout << n.toString() << endl;
    		
    		
    		if (n.isGoal()){
    			sol.solved = true;
    			sol.cost = n.getG();
    			sol.plan = extractSolution(&n);
    			cout << "Ya";
    			return sol;
    		}
    	//	closed.insert(n); //Add current node to closed set
    		int distance = n.getG() + 1;
    		it = closed.find(n);
    		cout << "Before iterator " << endl;
    		
    		cout << endl;

    		if (it != closed.end()){ // If node already exists in closed
    			cout << "Inside iterator" << endl;
    			Node nClosed = *it;
    			int distance = nClosed.getG();
    			closed.insert(n);
    			cout << "Distance " << distance << " for node" << nClosed.toString() << endl;
        		if (n.getG() < distance){
        			nClosed.setG(n.getG());
        			nClosed.setP(&n);
        			nClosed.setKflip(n.getK()); // We update the plan
        			
        		}
    		}

    		
    		for (int i = 2; i != n.getNumPancakes() + 1; ++i) {
		     Node succesor = n.getSuccesor(i);
		     succesor.setP(&n);
		     succesor.setWeight(weight); // We add this to multiply heuristic value * weight
		     succesor.setKflip(i);

		     if (succesor.getH() < boundS){
		    	 open.push_back(succesor);
		     }  
    		}
    		push_heap(open.begin(), open.end()); // We sort it, to make possible binary search.
    	}

    	return sol;
    	
    }
    
    vector<int> extractSolution(Node* node){
    	if (node->getP() != 0){
    		vector<int> vector = extractSolution(node->getP());
    		vector.push_back(node->getK());
    		return (vector);
    	}
    	else{
    		vector<int> vec;
    		vec.push_back(node->getK());
    		return vec;
    	}
    }
    
    