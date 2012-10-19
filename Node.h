//
//  Node.h
//  pancake-problem
//
//  Created by Jenny Valdez on 06/10/12.
//  Copyright (c) 2012 Jenny Valdez. All rights reserved.
//

#ifndef __pancake_problem__Node__
#define __pancake_problem__Node__

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Node {
private:
    
    // Pancakes configuration
    vector<int> state;
    
    // Cost from the root to this node
    int g;
    
    // Heuristic value
    int h;
    
    // Pointer to parent node
    Node * p;
    
    // K-flip
    int k;
    
public:
    
    
    static bool isSolution(Node root, vector<int> solution);
    
    // Constructor
    Node(vector<int> pancakes, int g);
      
    // Destructor
    ~Node();
    
    // Equals-operator
    bool operator==(const Node &other) const;
    
    // More than operator
    bool operator>(const Node &other) const;
    
    // Less than operator
    bool operator<(const Node &other) const;
    
    /* More equal than operator. Note that
     * if it's equal it's considererd greater the Node
     * with greater heuristic value.
     */ 
    bool operator>=(const Node &other) const;
    
    /* Less equal than operator
     * Same consideration for the operator >=
     */
    bool operator<=(const Node &other) const;
    
    // Checks whether this node is goal or not
    bool isGoal();
    
    // Gets a succesor by flipping 'flipped' pancakes
    Node getSuccesor(int flipped);
    
    // Gets all the succesors
    vector<Node> getAllSuccesors();
    
    // Gets the node cost
    int getG();
    
    // Gets the state
    vector<int> getState();
    
    // Gets heuristic
    int getH();
    
    // Get parent node
    Node* getP();
    
    // Gets the size of the instance
    int getNumPancakes();
    
    // Obtains heuristic value from the state
    int getHeuristic();
    
    // Gets K-flip
    int getK();
        
    // Converts this node into a string
    string toString();
    
    // Changes value to G attribute
    void setG(int cost);
    
    // Set parent node
    void setP(Node* parent);
    
    //Modify heuristic value 'weight' times 
    void setWeight(int weight);
    
    // Set the k-flip realized to get into this state.
    void setKflip(int kflip);
    
};

#endif /* defined(__pancake_problem__Node__) */
