//
//  Astar.cpp
//  pancake-problem
//
//  Created by Grace Gimon on 22/10/12.
//  Copyright (c) 2012 Grace Gimon. All rights reserved.
//

#include "AStar.h"

using namespace std;

// Priority queue
vector<Node> open;

// Set of closed nodes
vector<Node> closed;

// Termination bound
int bounds = 100000;

// Weight
int wstar;

// Compares the nodes according to their cost and heuristic value
bool priorityComparator(Node x, Node y) {
    int xval = x.getG() + wstar * x.getH();
    int yval = y.getG() + wstar * y.getH();
    
    if (xval == yval)
        return x.getH() > y.getH();
    
    return xval > yval;
}

// A* algorithm
Solution aStar(Node n, int weight) {
    Solution solution;
    wstar = weight;
    open.push_back(n);
    
    while (!open.empty()) {
        // Get the first element of the queue
        Node f = open.front();
        pop_heap(open.begin(), open.end(), priorityComparator);
        open.pop_back();
        
        // Check if there is a solution
        if (f.isGoal()) {
            solution.plan = f.flips;
            solution.cost = f.getG();
            solution.solved = true;
            return solution;
        }
        
        // Check if the node is not in the closed list
        vector<Node>::iterator c = find(closed.begin(), closed.end(), f);
        
        // If the node is closed and its cost is not better, continue
        if (c != closed.end() && f.getG() >= c->getG())
            continue;
        
        // If the element is not on the set, add it
        if (c == closed.end())
            closed.push_back(f);
        
        // If the element is in the set but there is a better way, replace it
        else if (c != closed.end() && f.getG() < c->getG())
            *c = f;
        
        // Now check the succesors
        for (int i = 2; i != f.getNumPancakes() + 1; ++i) {
            Node succ = f.getSuccesor(i);
            
            // If the cost of this succesor is between the bound, add it
            if (succ.getG() + wstar * succ.getH() < bounds) {
                open.push_back(succ);
                push_heap(open.begin(), open.end(), priorityComparator);
            }
        }
    }
    
    // At this point, problem UNSOLVABLE
    return solution;
}