#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>

#include <iomanip>
using namespace std;


// random generator function:
ptrdiff_t myrandom (ptrdiff_t i) { return rand() % i;}

// pointer object to it:
ptrdiff_t (*p_myrandom)(ptrdiff_t) = myrandom;


void flipIt(vector<int> original, unsigned int steps, char* fileName)
{
    ofstream myfile;

    vector<int>::iterator it;
    int flips = 0;
    int lastFlip = 0;
    int n = original.size();
    int randomNum = 0;

    if (n < 2)
        return;

    for (unsigned int i = 0; i < steps; i++)
    {
        while (lastFlip == flips || flips < 2)
        {     
            randomNum = (rand() % n) + 1;            
            flips = (randomNum);
            //cout << endl << "random: " << randomNum;
        }

        lastFlip = flips;

        reverse(original.begin(), original.begin() + flips);
    }

    myfile.open(fileName, ios::out | ios::app);
    for (int i = 0; i < n; i++)
        myfile << original[i] << "\n";
    myfile << "\n" << "#" << "\n" << "\n";
    myfile.close();

    return;
}


int main (int argc, char* argv[]) {

  int numberOfPancakes = 0;
  int numberOfSteps = 0;
  int numberOfTests = 0;

  while (numberOfPancakes < 1)
  {
  	cout << "Enter number of pancakes: "; 
  	cin >> numberOfPancakes; 
  }

  numberOfSteps = (numberOfPancakes - 2); // + (1 / numberOfPancakes);

  while (numberOfTests < 1)
  {
  	cout << "Enter number of tests: "; 
  	cin >> numberOfTests; 
  }

  srand ( unsigned ( time (NULL) ) );

  vector<int> myvector;
  vector<int>::iterator it;

  for (int i = 0; i < numberOfPancakes; i++)
	myvector.push_back(i);

    stringstream ss;
    ss << "Prueba_" << numberOfPancakes << "p_" << numberOfTests << "i_" << ".txt";
    string sss = ss.str();
    for (int i = 0; i < numberOfTests; i++)
    {
    flipIt(myvector, numberOfSteps, (char*)sss.c_str());
    }
    
    ofstream myfile;
    myfile.open("nombres.txt", ios::out | ios::app);
    myfile << sss << "\n";
    myfile.close();

  return 0;
}
