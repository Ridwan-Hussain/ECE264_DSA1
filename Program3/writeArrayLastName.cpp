#include <fstream> 
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

//Function to read the user input for list of foobars and names/items
void inputFile(ifstream &inputFileObj) {
	string inputFileName;
	cout << "Enter the Input File Name: ";
	cin >> inputFileName;
	inputFileObj.open(inputFileName); 
}

//Function that reads user input to put the output of the program into a file
void outputFile(ofstream &outputFileObj){
	string outputFileName;
	cout << "Enter the Output File: ";
	cin >> outputFileName;
	outputFileObj.open(outputFileName);
}

void writeToOutput(ifstream &inputFileObj, ofstream &outputFileObj) {
	std::string fileLine;
	if (inputFileObj.is_open()) {
		while (inputFileObj) {
			std::getline (inputFileObj, fileLine);
			outputFileObj << "vector<string> " << fileLine.substr(0, fileLine.size()) << "[16] = {0};" << "\n";
		}
	}
}

int main() {
	ifstream inputFileObj;
	inputFile(inputFileObj);
	
	ofstream outputFileObj;
	outputFile(outputFileObj);

	writeToOutput(inputFileObj, outputFileObj);

	inputFileObj.close();
	outputFileObj.close();

	return 0;
}

