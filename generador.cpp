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

  int numberOfPancakes = -1;

  while (numberOfPancakes < 1)
  {
  	cout << "Enter number of pancakes: "; 
  	cin >> numberOfPancakes; 
  }

  srand ( unsigned ( time (NULL) ) );

  vector<int> myvector;
  vector<int>::iterator it;

  for (int i = 0; i < numberOfPancakes; i++)
	myvector.push_back(i);

  random_shuffle(myvector.begin(), myvector.end(), p_myrandom); 

  ofstream myfile;
  myfile.open ("test.txt");
  for (int i = 0; i < numberOfPancakes; i++)
	myfile << myvector[i] << "\n";

  myfile.close();


/*  string line;
  int number;
  ifstream myfile ("test.txt");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
      cout << line << endl;
      number = readInt(line);
      if (number != -1)
      	myvector.push_back(number);
    }
    myfile.close();


    reverse(myvector.begin(),myvector.begin() + (int)myvector.size());
    random_shuffle(myvector.begin(), myvector.end(), p_myrandom); 

    // print out content:
    cout << "myvector contains:";
    for (it=myvector.begin(); it!=myvector.end(); ++it)
    cout << " " << *it;

    cout << endl;l
    //vectores();
  }
  else cout << "Unable to open file"; 
*/

    //reverse(myvector.begin(),myvector.begin() + (int)myvector.size());
    //random_shuffle(myvector.begin(), myvector.end(), p_myrandom); 

    // print out content:
    cout << "myvector contains:";
    for (it=myvector.begin(); it!=myvector.end(); ++it)
    cout << " " << *it;

    cout << endl;

  return 0;
}
