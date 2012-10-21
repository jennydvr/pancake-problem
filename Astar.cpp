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
    int boundS;
   
    SolutionStar::SolutionStar() {
        solved = false;
    }    

    SolutionStar aStar(Node root, int weight){
    	SolutionStar sol;
    	boundS = 100000;
    	open.push_back(root);
    	make_heap(open.begin(), open.end());

		// The heap open is ordered from lowest (g+h) values to highest. 	
    	while (!open.empty()){
    		
    		Node n = open.front();
    		pop_heap(open.begin(), open.end());
    		open.pop_back(); // Removed from open set.
    		
    		if (n.isGoal()){
    			cout << "GOAL" << endl;
    			cout << n.toString() << endl;
    			cout << "PAPA DEL GOAL" << endl;
    			if (n.getP() != 0){
    			cout << n.getP()->toString() << endl;
    			}
    			sol.solved = true;
    			sol.cost = n.getG();
    			sol.plan = extractSolution(&n);
    			return sol;
    		}
    		cout << endl;
    		
    		int statePos = findState(n.getState()); // Returns position
    		
    		if (statePos != -1)
    		cout << get<1>(closedSet[statePos]) << " closedSet > n.getG  " << n.getG() << endl;
    		if ( (statePos == -1) || n.getG() < get<1>(closedSet[statePos])){ 
    			if (statePos == -1){ // If node doesn't exists in closedSet
    				closedSet.push_back(make_tuple(n.getState(),n.getG())); // Add it
    			}
    			else{ // If n.G is better than closedSet
    				get<1>(closedSet[statePos]) = n.getG();
    				cout << "Modifique el G" << endl;
    			
    			}
    			Node succesor;
    			for (int i = 2; i != n.getNumPancakes() + 1; ++i) {
    				 succesor = n.getSuccesor(i);
    				 cout << "N" << endl;
    				 cout << n.toString() << endl;
    				 cout << "SUCCESOR " << endl;
    				 cout << succesor.toString() << endl;
    				 cout << endl;
				     succesor.setP(&n);

				     succesor.setWeight(weight); // We add this to multiply heuristic value * weight
				     succesor.setKflip(i);

				     if (succesor.getH() < boundS){
				    	 open.push_back(succesor);
				    	 push_heap(open.begin(), open.end());
				     }  
		    		}


		    sort_heap(open.begin(), open.end()); // We sort it, to make possible binary search.	
    		cout << "Nodo open y mi papa " << endl;
    		    		
    		cout << "SIZE INI " << open.size() << endl;
	     	for (int i = 0; i < open.size(); ++i){

	    		cout << open[i].toString() << endl;
	    		if (open[i].getP() != 0){ // si papa
	    		cout << open[i].getP()->toString() << endl;
	    		}
	    		cout << "----------------------" << endl;
	    		cout << endl;
	     	}
	     	cout << "END OPEN" << endl;
    		}

    		
    		
    	}
    	sol.cost = -1;
    	return sol;
    	
    }
    
    vector<int>  extractSolution(Node* node){
    	vector<int> miniplan;
   
    	if (node->getP() != 0){
    		// cout << "Nodo parent" << node->getP()->toString() << endl;
			miniplan = extractSolution(node->getP());
			miniplan.push_back(node->getK());
    		 return miniplan;
    	}
    	else{
    		miniplan.push_back(node->getK());
    		return 	miniplan;        		cout << "Nodo open y mi papa " << endl;
    		
    		cout << "SIZE INI" << open.size() << endl;
	     	for (int i = 0; i < open.size(); ++i){

	    		cout << open[i].toString() << endl;
	    		if (open[i].getP() != 0){ // si papa
	    		cout << open[i].getP()->toString() << endl;
	    		}
	    		cout << "----------------------" << endl;
	    		cout << endl;
	     	}
	     	cout << "END OPEN" << endl;
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
    
    
    
