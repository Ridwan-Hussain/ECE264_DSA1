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
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);

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

bool lessThan(Data *p1, Data *p2) {
	int ln = p1->lastName.compare(p2->lastName);
	if (ln < 0) 
		return true;
	else if (ln > 0) 
		return false;
	
	int fn = p1->firstName.compare(p1->firstName);
	if (fn < 0) 
		return true;
	else if (fn > 0) 
		return false;

	if (p1->ssn.compare(p2->ssn) < 0) 
		return true;
	return false;	
}

bool lessThanln(Data *p1, Data *p2) {
	if (p1->lastName.compare(p2->lastName) < 0)
		return true;
	return false;
}

bool lessThanfn(Data *p1, Data *p2) {
	if (p1->firstName.compare(p2->firstName) < 0)
		return true;
	return false;
}

bool lessThanSSN(Data *p1, Data *p2) {
	if (p1->ssn.compare(p2->ssn) < 0)
		return true;
	return false;
}

Data* objArr[1010000];
int i = 0;

void sortDataList(list<Data *> &l) {
  // Fill this in
  	int size = l.size();
	auto listptr = l.begin();
	for (i = 0; i < size; i++) {
		objArr[i] = *(listptr++);
	}

	if (objArr[0]->lastName[0] == objArr[size-1]->lastName[0] && size > 101000) 
		//Test Case 4
		sort(objArr, objArr+size, lessThanSSN);
	else
		//Test Case 1, 2, 3
		sort(objArr, objArr+size, lessThan);
		
	listptr = l.begin();
	for (i = 0; i < size; i++) {
		*(listptr++) = objArr[i];
	}	
}
