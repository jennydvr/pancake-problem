//
//  main.cpp
//  pancake-problem
//
//  Created by Christian Chomiak on 06/10/12.
//  Copyright (c) 2012 Christian Chomiak. All rights reserved.
//

#include <fstream>
#include "IDA.h"
#include "Astar.h"

using namespace std;

template <class T>
bool from_string(T& t,
                 const std::string& s,
                 std::ios_base& (*f)(std::ios_base&))
{
    istringstream iss(s);
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
        return i;
    else if (s[0] == '#')
        return -2;
    else
        return -1;
}

void Test(vector<int> state, bool usarAstar)
{
    if (state.size() == 0)
        return;
    
    Node n(state);
    bound = 100000;
    
    Solution s;
    clock_t tStart = clock();
    if (usarAstar)
        s = aStar(n);
    else
        s = ida(n);
    double tEnd = (clock() - tStart)/(double)CLOCKS_PER_SEC;
    
    cout << "  SOLUCION\n";
    cout << "    Peso = " << weight << endl;
    cout << "    Pasos = " << s.plan.size() << endl;
    printf("    Tiempo = %.20lf \n\n", tEnd);
}

// archivo peso algoritmo
int main(int argc, const char * argv[])
{
    bool usarAstar;
    vector<int> state;
    string line;
    int number;
    string fileWithTests;
    
    if (argc != 4) {
        cout << "Error: Parametros de entrada mal especificados. Vea las instrucciones.\n";
        return 0;
    }
    
    // Set weight
    weight = atoi(argv[2]);
    if (weight < 1) {
        cout << "Error: Peso no valido. Cambiando a peso por defecto, 1.\n";
        weight = 1;
    }
    
    // Choose algorithm
    int algoritmo = atoi(argv[3]);
    if (algoritmo != 0 && algoritmo != 1) {
        cout << "Error: Algoritmo no indicado. Vea las instrucciones.\n";
        return 0;
    }
    
    usarAstar = algoritmo == 0; // 0: A* - 1: IDA*
    
    fileWithTests = argv[1];
    
    ifstream myfile (fileWithTests);
    
    if (!myfile.is_open()) {
        cout << "Error: No puede abrirse el archivo.";
        return 0;
    }
    
    while (myfile.good())
    {
        getline (myfile,line);
        //cout << line << endl;
        number = readInt(line);
        if (number == -2)
        {
            // Termine de leer un caso de prueba (lei un '#') y lo pruebo
            cout << "=====================" << endl;
            Test(state, usarAstar);
            cout << "=====================" << endl;
            state.clear();
        }
        else if (number != -1)
            state.push_back(number);
    }
    myfile.close();
    return 0;
}
