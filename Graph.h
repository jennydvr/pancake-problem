//
//  Graph.h
//  pancakes-problem
//
//  Created by Jenny Valdez on 06/10/12.
//
//

#ifndef PP_GRAPH
#define PP_GRAPH

#include <iostream>
#include <algorithm>
#include <vector>

class Graph {
private:
    int numPancakes;
    
public:
    bool isGoal();
    
    // Calcula todos los sucesores de una configuracion de panquecas
    vector< vector<int> > succ(vector<int> pancakes);
    
    // Calcula el sucesor de una configuraccion voltando 'flipped' panquecas
    vector<int> succ(vector<int> pancakes, int flipped);
    
    int getNumPancakes();
};

#endif /* defined(PP_GRAPH) */
