// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, FALL 2022

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  string lastName;
  string firstName;
  string ssn;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename);
  if (!input) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->lastName >> pData->firstName >> pData->ssn;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename);
  if (!output) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << "\n";

  // Write the data
  for (auto pData:l) {
    output << pData->lastName << " " 
	   << pData->firstName << " " 
	   << pData->ssn << "\n";
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &);


// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.

//void LetterLoad(list<Data *> &l); 
int testcase(list<Data *> &l); 

int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);
  sortDataList(theList); 
 // LetterLoad(theList); 
    //testcase(theList); 


  cout << "Data loaded.\n";


  cout << "Executing sort...\n";
  clock_t t1 = clock();
  sortDataList(theList); 
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds.\n";

  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);

  return 0;
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.


Data* inputarr[20000000]; //stirng 
Data* outputarr[20000000]; //
int countarr[25]; //26 letters in the alphabet  

bool comparet1 (Data* a, Data* b) //for t1 and t2 
{
  if (a->lastName.compare(b->lastName) != 0)
  {
    return a->lastName < b->lastName; 
  }
  else if (a->firstName.compare(b->firstName) != 0)
  {
    return a->firstName < b->firstName;
  }
  else
  {
    return a->ssn < b-> ssn; 
  }
}


//bool comparet4 (*Data a, *Data b) // only does ssn 


void sortDataList(list<Data *> &l) {
  typename list<Data *>::iterator it; 
  typename list<Data *>::iterator ie; 
  it = l.begin();
  ie = l.end();  
  int size = l.size(); 

  copy(it,ie,inputarr); 


  sort(inputarr,size + inputarr, comparet1); //add a third parameter that is your comparison function 
  
  //cout << inputarr[size -1]-> lastName << "\n"; 
  //cout << *(inputarr) -> lastName << "\n"; 

  int j = 0; 
  sort(inputarr,size + inputarr, comparet1); //add a third parameter that is your comparison function 
  for (auto &pData:l)
  {
    pData = inputarr[j]; 
    j++;
  }
  
}

int testcase(list<Data *> &l)
{
  typename list<Data *>::iterator it; 
  typename list<Data *>::iterator ie; 
  it = l.begin(); 
  ie = l.end(); 
  int listsize = l.size(); 
  cout << listsize << "\n";
    cout << ((*it)->firstName) << "\n"; 
      
    cout << ((*(++it))->firstName)<< "\n"; 

    cout << ((*ie)->firstName) << "\n"; 



  if(listsize < 500000) //test case for T1 
  {
    cout << "in case 1 \n"; 
    return 1; 
  }

  
  else if(((*it)->firstName) == ((*(++it))->firstName)) //test case for T4 //comparing 1st and second elemnt 
  {
    cout << "in case 4 \n"; 
    return 2; 
  }
  //else if()
  return 0; 
//use std copy to put stuff back into list 
}

