//
//  main.cpp
//  pancake-problem
//
//  Created by Christian Chomiak on 06/10/12.
//  Copyright (c) 2012 Christian Chomiak. All rights reserved.
//

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include "IDA.h"
#include "Astar.h"

using namespace std;

// random generator function:
ptrdiff_t myrandom (ptrdiff_t i) { return rand() % i;}

// pointer object to it:
ptrdiff_t (*p_myrandom)(ptrdiff_t) = myrandom;


template <class T>
bool from_string(T& t,
                 const std::string& s,
                 std::ios_base& (*f)(std::ios_base&))
{
    std::istringstream iss(s);
    return !(iss >> f >> t).fail();
}

int readInt (string s)
{
    int i;
    
    // the third parameter of from_string() should be
    // one of std::hex, std::dec or std::oct
    if(from_string<int>(i, s, std::dec))
    {
        //std::cout << i << std::endl;
        return i;
    }
    else
    {
        //std::cout << "from_string failed" << std::endl;
        return -1;
    }
}

int vectores () {
    vector<int> myvector;
    vector<int>::iterator it;
    
    // set some values:
    for (int i=1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9
    
    reverse(myvector.begin(),myvector.end());       // 9 8 7 6 5 4 3 2 1
    
    // print out content:
    cout << "myvector contains:";
    for (it=myvector.begin(); it!=myvector.end(); ++it)
        cout << " " << *it;
    
    cout << endl;
    
    return 0;
}

int main(int argc, const char * argv[])
{
    bool usarAEstrella = false;
    bool leerArchivo = false;

    //Prueba por lectura de archivo
    vector<int> state;
    vector<int>::iterator it;

    if (leerArchivo)
    {
        string line;
        int number;
        ifstream myfile ("comida.txt");
        
        if (!myfile.is_open()) {
            cout << "Unable to open file";
            return 0;
        }
        
        while ( myfile.good() )
        {
            getline (myfile,line);
            //cout << line << endl;
            number = readInt(line);
            if (number != -1)
                state.push_back(number);
        }
        myfile.close();
    }
    else
    {
        for (int i = 0; i != 60; ++i)
            state.push_back(i);
        srand ( unsigned ( time (NULL) ) );
        random_shuffle(state.begin(), state.end(), p_myrandom);
    }

        
    //reverse(state.begin(), state.end());
    // print out content:
    cout << "myvector contains:";
    for (it=state.begin(); it!=state.end(); ++it)
        cout << " " << *it;
        
    cout << endl;
    //vectores(); */
    
    //Prueba de lo de Grace
    /*vector<int> state;
    for (int i = 1; i != 6; ++i)
        state.push_back(i);

    Node n(state, 0);
    Solution s = ida(n);

    cout << s.solved << endl;*/



    Node node(state, 0);
//    vector<int> copyvec;
//    for (int i = 0; i != 5; ++i)
//            copyvec.push_back(i);
//    Node copy(copyvec, 2,1);
//    
   cout << node.toString() << endl;
//    cout << copy.toString() << endl;
//    if (copy < node){
//    	cout << "node is smaller" << endl;
//    }
//    else{
//    	cout << "node is greater " << endl;
//    }
// 
    // Time measure:
/*
    clock_t tStart = clock();  
        SolutionStar s = aStar(node,1);
    double tEnd = (double)(clock() - tStart)/CLOCKS_PER_SEC;   
*/
    /*vector<Node> succ = node.getAllSuccesors();
    for (int i = 0; i != succ.size(); ++i)
        cout << succ[i].toString();

    cout << "equal = " << (node == succ[1]);*/
    
    clock_t tStart = clock();
    if (usarAEstrella)
    {
        SolutionStar s = aStar(node,1);
        cout << "fin = " << s.solved << endl;       
        cout << "solucion ok = " << Node::isSolution(node, s.plan) << endl;        
        cout << "cost = " << s.cost << endl;
    }
    else
    {
        Solution s = ida(node,1);    
        cout << "fin = " << s.solved << endl;       
        cout << "solucion ok = " << Node::isSolution(node, s.plan) << endl;        
        cout << "cost = " << s.cost << endl;
    }
    double tEnd = (double)(clock() - tStart)/CLOCKS_PER_SEC;


//    
   
//    cout << "plan = ";
//    for (int i = 0; i != s.plan.size(); ++i)
//        cout << s.plan[i] << " ";
//    cout << endl;
//
//
//
    cout << "Tiempo: " << tEnd << endl;
    
    return 0;
}
