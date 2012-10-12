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

Node::~Node() {
    g = 0;
    state.clear();
    
    // Clear no borra la memoria en realidad! Esto, si
    vector<int>().swap(state);
}

bool Node::operator==(const Node &other) const {
    for (int i = 0; i != state.size(); ++i)
        if (other.state[i] != state[i])
            return false;
    return true;
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
    
    return Node(copy, g + 1);
}

vector<Node> Node::getAllSuccesors() {
    vector<Node> solution;
    for (int i = 2; i != state.size() + 1; ++i)
        solution.push_back(getSuccesor(i));
    
    return solution;
}

int Node::getG() {
    return g;
}

vector<int> Node::getState() {
    return state;
}

int Node::getNumPancakes() {
    return (int) state.size();
}

int Node::getHeuristic() {
	int gaps = 0;
	for (int i = 1; i != state.size(); ++i)
		if (abs(state[i] - state[i+1]) > 1)
			++gaps;
            
	return gaps;
}

string Node::toString() {
    string res("state = [");
    for (int i = 0; i != state.size(); ++i) {
        res += " ";
        res += state[i];
    }
    res += "]\ng = ";
    res += g;
    res += "    h = ";
    res += getHeuristic();
    res += "\n";
    
    return res;
}
