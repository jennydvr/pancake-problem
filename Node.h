//
//  Node.h
//  pancake-problem
//
//  Created by Jenny Valdez on 06/10/12.
//  Copyright (c) 2012 Jenny Valdez. All rights reserved.
//

#ifndef _pancake_problem_Node_
#define _pancake_problem_Node_

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Extra weight
extern int weight;

// Bound for the algorithms
extern int bound;

// Solution structure
struct Solution {
    vector<int> plan;
    int cost;
    bool solved;
    
    // Constructor
    Solution():solved(false) {}
};

// Class that defines a pancake configuration
class Node {
private:
    
    // Pancakes configuration
    vector<int> state;
    
    // Flips that generate it (according to certain root node)
    vector<int> flips;
    
    // Cost from the root to this node
    int g = 0;
    
    // Heuristic value
    int h = 0;
    
    // Flip that generated this node
    int parentFlip = 0;
    
    // Obtains heuristic value from the state
    int getHeuristic();
    
public:
    
// STATICS
    
    // Checks if the node is a goal applying certain steps
    static bool isSolution(Node root, vector<int> solution);
    
    // Compares two nodes according to their heuristic value
    static bool compareNodes(Node x, Node y);
    
// CONSTRUCTORS
    
    // Recieves the cost of this node
    Node(vector<int> state);

    // Recieves the state of the last node and the flip that generated it
    Node(vector<int> state, int g, vector<int> lastState, int parentFlip);
    
// DESTRUCTORS
    
    // Destroys everything
    ~Node();
    
// COMPARATORS
    // Equals-operator
    bool operator==(const Node &other) const;
    
// USEFUL STUFF
    
    // Checks whether this node is goal or not
    bool isGoal();
    
    // Gets a succesor by flipping 'flipped' pancakes
    Node getSuccesor(int flipped);
    
    // Gets all the succesors
    vector<Node> getAllSuccesors();
    
    
// GETTERS
    
    // Gets the state
    vector<int> getState();
    
    // Gets the flips
    vector<int> getFlips();
    
    // Gets the node cost
    int getG();
    
    // Gets heuristic
    int getH();
    
    int getParentFlip();
    
    // Gets the size of the instance
    int getNumPancakes();
    
// TO STRING
    
    // Converts this node into a string
    string toString();
    
};

#endif /* defined(_pancake_problem_Node_) */
