//
//  Node.cpp
//  pancake-problem
//
//  Created by Jenny Valdez on 06/10/12.
//  Copyright (c) 2012 Jenny Valdez. All rights reserved.
//

#include "Node.h"

using namespace std;

Node::Node(vector<int> state, int g) {
    this->state = state;
    this->g = g;
    this->h = 0;
    this->k = 0;
    this->p = 0;
}

Node::Node(vector<int> state, int g, vector<int> lastState, int parentFlip) {
    this->state = state;
    this->g = g;
    
    lastState.push_back(parentFlip);
    this->flips = lastState;
}

Node::Node(){
	this->g = 0;
	this->h = 0;
	this->k = 0;
	this->p = 0;
}
Node::~Node() {
    g = 0;
    state.clear();

    vector<int>().swap(state);
    h = 0;
}

bool Node::operator==(const Node &other) const {
    for (unsigned int i = 0; i != state.size(); ++i)
        if (other.state[i] != state[i])
            return false;
    return true;
}

bool Node::operator<(const Node &other) const {
	
	if ((h+g) < (other.h+ other.g)){ 
			return true;
	}
    
	if ((h + g) == (other.h +other.g)){
		if (h < other.h)
			return true;
	}
	return false;
}

bool Node::operator>(const Node &other) const{
	if ((h+ g) > (other.h +other.g)){
			return true;
	}
	
	return false;
}

bool Node::operator<=(const Node &other) const {
	if ((h + g) == (other.h +other.g)){
		if (h < other.h)
			return true;
	}
	if ((h+g) < (other.h+ other.g)){ 
			return true;
	}
	return false;
}

bool Node::operator>=(const Node &other) const{
	if ((h+g) == (other.h+ other.g)){
		if  (h > other.h) 
			return true;
	}
	if ((h+ g) > (other.h +other.g)){
			return true;
	}

	return false;
}

bool Node::isGoal() {
    for (unsigned int i = 0; i != state.size(); ++i)
        if (state[i] != (int)i )
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
    for (unsigned int i = 2; i != state.size() + 1; ++i)
        solution.push_back(getSuccesor(i));
    
    return solution;
}

int Node::getG() {
    return g;
}

int Node::getK() {
	return k;
}
vector<int> Node::getState() {
    return state;
}

int Node::getH() {
    if (h == 0)
        h = getHeuristic();
	return h;
}

Node* Node::getP(){
	return p;
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

void Node::setG(int cost){
	g = cost;
}

void Node::setP(Node* parent){
	p = parent;
}

void Node::setWeight(int weight){
	h = h * weight;
}

void Node::setKflip(int kflip){
	k = kflip;
}

string Node::toString() {
    stringstream ss;
    
    ss << "state = [";
    for (unsigned int i = 0; i != state.size(); ++i)
        ss << " " << state[i];
    ss << " ]\ng = " << g;
    ss << "    h = " << h << "\n";
    ss << "goal = " << isGoal() << endl;
    
    return ss.str();
}

int find(const vector<Node>& pancakes, Node n ){
    for( int i = 0; i < pancakes.size(); i++ ) {
       if( pancakes[i] == n ) {
           return i;
       }
    }
}
