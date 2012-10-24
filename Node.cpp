//
//  Node.cpp
//  pancake-problem
//
//  Created by Jenny Valdez on 06/10/12.
//  Copyright (c) 2012 Jenny Valdez. All rights reserved.
//

#include "Node.h"

using namespace std;

int weight = 1;
int bound = 10000;

Node::Node(vector<int> state) {
    this->state = state;
    g = h = parentFlip = 0;
}

Node::Node(vector<int> state, int g, vector<int> lastState, int parentFlip) {
    this->state = state;
    this->g = g;
    this->parentFlip = parentFlip;
    h = 0;
    
    lastState.push_back(parentFlip);
    this->flips = lastState;
}

Node::~Node() {
    g = h = 0;
    state.clear();
    flips.clear();
    
    vector<int>().swap(state);
    vector<int>().swap(flips);
}

bool Node::operator==(const Node &other) const {
    for (unsigned int i = 0; i != state.size(); ++i)
        if (other.state[i] != state[i])
            return false;
    return true;
}

bool Node::isGoal() {
    for (unsigned int i = 0; i != state.size(); ++i)
        if (state[i] != (int)i)
            return false;
    return true;
}

Node Node::getSuccesor(int flipped) {
    vector<int> copy(state);
    reverse(copy.begin(), copy.begin() + flipped);
    
    return Node(copy, g + 1, flips, flipped);
}

vector<Node> Node::getAllSuccesors() {
    vector<Node> solution;
    for (int i = 2; i != getNumPancakes() + 1; ++i) {
        if (i == parentFlip)
            continue;
        
        solution.push_back(getSuccesor(i));
    }
    
   // stable_sort(solution.begin(), solution.end(), compareNodes);
    return solution;
}

bool Node::compareNodes(Node x, Node y) {
    return x.getH() < y.getH();
}

vector<int> Node::getState() {
    return state;
}

vector<int> Node::getFlips() {
    return flips;
}

int Node::getG() {
    return g;
}

int Node::getH() {
    if (h == 0)
        h = getHeuristic();
	return h;
}

int Node::getParentFlip() {
    return parentFlip;
}

int Node::getNumPancakes() {
    return (int) state.size();
}

bool Node::isSolution(Node root, vector<int> solution) {
    for (int i = 0; i != (int)solution.size(); ++i)
        root = root.getSuccesor(solution[i]);
    
    return root.isGoal();
}

int Node::getHeuristic() {
	int gaps = 0;
	for (unsigned int i = 0; i != state.size() -1; ++i){
		if (abs(state[i] - state[i+1]) > 1){
			++gaps;
		}
	}
    
    if (state[state.size()-1] != state.size() -1){
        ++gaps;
    }

	return gaps;
}

string Node::toString() {
    stringstream ss;
    
    ss << "state = [";
    for (unsigned int i = 0; i != state.size(); ++i)
        ss << " " << state[i];
    ss << " ]\ng = " << g;
    ss << "    h = " << getH() << "\n";
    ss << "goal = " << isGoal() << endl;
    
    return ss.str();
}
