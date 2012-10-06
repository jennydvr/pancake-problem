//
//  Node.cpp
//  pancake-problem
//
//  Created by Jenny Valdez on 06/10/12.
//  Copyright (c) 2012 Jenny Valdez. All rights reserved.
//

#include "Node.h"

Node::Node(vector<int> state, int g) {
    this->state = state;
    this->g = g;
}

bool Node::isGoal() {
    for (int i = 0; i != state.size(); ++i)
        if (state[i] != i + 1)
            return false;
    return true;
}

Node Node::getSuccesor(int flipped) {
    // Copio 'state' para no dañarlo
    vector<int> copy;
    reverse_copy(state.begin(), state.begin() + flipped, copy);
    
    // El nuevo costo sera el del nodo anterior + las panquecas volteadas
    return Node(copy, g + flipped);
}

vector<Node> Node::getAllSuccesors() {
    vector<Node> solution;
    for (int i = 2; i != state.size() + 1; ++i) {
        // Copio 'state' para no dañarlo
        vector<int> copy;
        reverse_copy(state.begin(), state.begin() + i, copy.begin());
        
        // Creo el nodo y lo pongo en la lista
        solution.push_back(Node(copy, g + i));
    }
    
    return solution;
}

int Node::getG() {
    return g;
}

vector<int> Node::getState() {
    return state;
}
