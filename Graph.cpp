//
//  Graph.cpp
//  pancakes-problem
//
//  Created by Jenny Valdez on 06/10/12.
//
//

#include "Graph.h"

vector< vector<int> > Graph::succ(vector<int> pancakes) {
    vector< vector<int> > solution;
    for (int i = 2; i != numPancakes + 1; ++i) {
        vector<int> copy;
        reverse_copy(pancakes.begin(), pancakes.begin() + i, copy.begin());
        solution.push_back(copy);
    }
    
    return solution;
}

vector<int> Graph::succ(vector<int> pancakes, int flipped) {
    reverse(pancakes.begin(), pancakes.begin() + flipped);
    return pancakes;
}

bool Graph::isGoal(vector<int> pancakes) {
    for (int i = 0; i != numPancakes; ++i)
        if (pancakes[i] != i + 1)
            return false;
    return true;
}
