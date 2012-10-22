#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>
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
    myfile << "###" << "\n";
    myfile.close();

    return;
}


template <class T>
bool from_string(T& t, 
                 const std::string& s, 
                 std::ios_base& (*f)(std::ios_base&))
{
  std::istringstream iss(s);
  return !(iss >> f >> t).fail();
}

int readInt(string s)
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

int main () {

  int numberOfPancakes = 0;
  int numberOfSteps = 0;
  int numberOfTests = 0;

  while (numberOfPancakes < 1)
  {
  	cout << "Enter number of pancakes: "; 
  	cin >> numberOfPancakes; 
  }

  /*while (numberOfSteps < 1)
  {
  	cout << "Enter number of steps: "; 
  	cin >> numberOfSteps; 
  }*/
  numberOfSteps = (numberOfPancakes - 2) + (1 / numberOfPancakes);

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


  for (int i = 0; i < numberOfTests; i++)
  {
    stringstream ss;
    ss << "Prueba_" << numberOfPancakes << "p_" << numberOfTests << "i_" << ".txt";
    string sss = ss.str();
    flipIt(myvector, numberOfSteps, (char*)sss.c_str());
  }

  return 0;
}
