//
//  main.cpp
//  pancake-problem
//
//  Created by Christian Chomiak on 06/10/12.
//  Copyright (c) 2012 Christian Chomiak. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "IDA.h"
#include "Astar.h"

using namespace std;

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
    vector<int> state;
    for (int i = 0; i != 50; ++i)
        state.push_back(i);
    random_shuffle(state.begin(), state.end());
    
    Node n(state, 0);
    cout << n.toString() << endl;
    
    // Time measure:
    
    clock_t tStart = clock();
    Solution s = aStar(n);
    double tEnd = (double)(clock() - tStart)/CLOCKS_PER_SEC;
    
    cout << "AStar\n";
    cout << "    pasos = " << s.plan.size() << endl;
    cout << "    tiempo = " << tEnd << endl << endl;
    
    tStart = clock();
    s = ida(n);
    tEnd = (double)(clock() - tStart)/CLOCKS_PER_SEC;
    
    cout << "IDA\n";
    cout << "    pasos = " << s.plan.size() << endl;
    cout << "    tiempo = " << tEnd << endl << endl;
    
    return 0;
}
