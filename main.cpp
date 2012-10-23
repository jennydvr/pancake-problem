//
//  main.cpp
//  pancake-problem
//
//  Created by Christian Chomiak on 06/10/12.
//  Copyright (c) 2012 Christian Chomiak. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
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
    if (s.length() == 0)
        return -1;    

    // the third parameter of from_string() should be
    // one of std::hex, std::dec or std::oct
    if(from_string<int>(i, s, std::dec))
    {
        //std::cout << i << std::endl;
        return i;
    }
    else if (s[0] == '#')
    {
        return -2;
    }
    else
    {
        //std::cout << "from_string failed" << std::endl;
        return -1;
    }
}

void Test(vector<int> state, int weight)
{
    if (state.size() == 0)
    {
        cout << "Prueba vacia" << endl << "====================" << endl;    
    }

    Node n(state);
   // cout << "#Nodo Inicial#" << endl;
   // cout << n.toString() << endl;
    //cout << n.getH() << endl;
    
    // Time measure:
 /*
    clock_t tStart = clock();
    Solution s = aStar(n, weight);
    double tEnd = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
    cout << "SOLUCIONES\n" << endl;
    cout << "  AStar\n";
    cout << "   Peso: " << weight << endl;
   
    cout << "    pasos = " << s.plan.size() << endl;
    printf("    tiempo: %.20lf \n\n", tEnd);
    */
    clock_t tStart = clock();
    Solution s = ida(n, weight);
    double tEnd = (clock() - tStart)/(double)CLOCKS_PER_SEC;
 
   // cout << "  IDA\n";
   // cout << "   Peso: " << weight << endl;
    // cout << "    pasos = " << s.plan.size() << endl;
    //printf("    tiempo: %.20lf \n\n", tEnd);
    
    
    
    // COSAS A IMPRIMIR
    
    printf("%.20lf \n", tEnd);
    cout << expanded << endl;
    cout << s.plan.size() << endl;
    cout << n.getH() << endl;
}

int main(int argc, const char * argv[])
{
    
    vector<int> state;
    string line;
    int number;
    int weight = 0;
    string fileWithTests;
    
     while (weight < 1)
    {
  //	cout << "Enter weight for IDA and Astar: ";
  	cin >> weight; 
    }
  //  cout << "File name is: " << fileWithTests << endl;

    fileWithTests = argv[1];
    ifstream myfile (fileWithTests);
    
    if (!myfile.is_open()) {
        cout << "Unable to open file";
        return 0;
    }
    

    while ( myfile.good() )
    {
        getline (myfile,line);
        //cout << line << endl;
        number = readInt(line);
        if (number == -2)
        {
            //Termine de leer un caso de prueba (lei un '#') y lo pruebo
          //  cout << "=====================" << endl;
            Test(state,weight);
          //  cout << "=====================" << endl;
            state.clear();
        }
        else if (number != -1)
        {
            state.push_back(number);
        }
    }
    myfile.close();
    return 0;
}
