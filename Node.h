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

using namespace std;

class Node {
private:
    
    // Configuracion de las panquecas
    vector<int> state;
    
    // Costo de llegar a esta configuracion desde la inicial
    int g;

    
public:
    
    // Constructor
    Node(vector<int> pancakes, int g);
    
    // Destructor
    ~Node();
    
    // Chequea si este nodo es goal
    bool isGoal();
    
    // Obtiene el sucesor de esta configuracion a voltear 'flipped' panquecas
    Node getSuccesor(int flipped);
    
    // Obtiene todos los sucesores de esta configuracion
    vector<Node> getAllSuccesors();
    
    // Getter del costo de la raiz al nodo
    int getG();
    
    // Getter de la configuracion de las panquecas
    vector<int> getState();
    
    // Obtains heuristic value from the state
    int getHeuristic();
    
    
};

#endif /* defined(__pancake_problem__Node__) */
