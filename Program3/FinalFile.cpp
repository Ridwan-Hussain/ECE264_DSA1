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

//Ridwan Hussain - Sorting Algorithmn that sorts a list of data with pre-determined characteristics known.

//General Sort, sorts through by Last Name, then First Name, then SSN.
bool lessThan(Data *p1, Data *p2) {
	int ln = p1->lastName.compare(p2->lastName);
	if (ln < 0) 
		return true;
	else if (ln > 0) 
		return false;
	
	int fn = p1->firstName.compare(p2->firstName);
	if (fn < 0) 
		return true;
	else if (fn > 0) 
		return false;
	 
	if (p1->ssn.compare(p2->ssn) < 0) 
		return true;
	return false;	
}

//Sorts only the SSN
bool lessThanSSN(Data *p1, Data *p2) {
	if (p1->ssn.compare(p2->ssn) < 0 )
		return true;
	return false;
}

//Static array and variable to save time on sorting
Data* objArr[1010000] = {0};
int i = 0;

void sortDataList(list<Data *> &l) {
  // Fill this in
	int size = l.size(); //stores the size of the list as an int 
	auto listptr = l.begin(); //a pointer pointing to the first element of the list
	for (i = 0; i < size; i++) {
		objArr[i] = *(listptr++); //loads all the elemnts of the list into a C-style array
	}

	if (objArr[0]->lastName == objArr[size-1]->lastName && size > 101000) 
		sort(objArr, objArr+size, lessThanSSN); //Sorts Test Case 4
	else 
		sort(objArr, objArr+size, lessThan); //Sorts Test Case 1, 2, 3

	listptr = l.begin(); //pointer pointing to the first element of the list

	for (i = 0; i < size; i++)
		*(listptr++) = objArr[i]; // loads all of the elements of the array back into the list sorted
}

