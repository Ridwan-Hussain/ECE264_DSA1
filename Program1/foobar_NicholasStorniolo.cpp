/* 
Nicholas Storniolo
ECE-264 Programming Assignment 1
This is foobar, a program which proves basic understanding of C++ concepts
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// foobar base class, protected getPos is needed for the inhereted getStr fcn
class Foobar {
    string fbName;
    int Position;
protected:
    int getPos(){ return Position; }
public:
    Foobar(string name, int pos=0) {
        fbName = name;
        Position = pos;
	}
    void setPos(int p){ Position = p; }
    string getName(){return fbName;}
    virtual int getStr(){return Position;}
};


class Foo: public Foobar {
public:
    Foo(string fooName, int pos=0) : Foobar(fooName, pos){ }
    int getStr(){return (getPos() * 3);  }
};

class Bar: public Foobar {
public:
    Bar(string barName, int pos=0) : Foobar(barName, pos){ }
    int getStr(){ return (getPos() + 15);}
};
/*
void processInput(vector<Foobar*> *);
void updatelist(vector<Foobar*> *);
void processOutput(vector<Foobar*> *);

int main()
{
    vector<Foobar*> fbVect;
    processInput(&fbVect);

    updatelist(&fbVect);

    processOutput(&fbVect);
    return 1;
}

void processInput(vector<Foobar *> *fbVect){
    string inputFileName;
    ifstream input;
	cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    cout << "\n";
    input.open(inputFileName);
    for (string line; getline(input, line); )
    {
        istringstream iss(line);
        string type, name;
        iss >> type;
        iss >> name;
        if(type == "foobar"){
            Foobar* fbptr;
            Foobar fb(name);
            fbptr = &fb;
            (*fbVect).push_back(fbptr);
        } else if(type == "foo"){
            Foobar* fbptr;
            Foo foo(name);
            fbptr = &foo;
            (*fbVect).push_back(fbptr);
        } else if(type == "bar"){
            Foobar* fbptr;
            Bar bar(name);
            fbptr = &bar;
            (*fbVect).push_back(fbptr);
        } else
            cout << "type not recognized\n";
    }
    input.close();
}

// This function iterates through the foobars and updates their position
void updatelist(vector<Foobar*> *fbptr) {
    int size = (*fbptr).size();
    for (int i=0; i<size; i++) {
        (*fbptr)[i]->setPos(size-i);
    }
}


void processOutput(vector<Foobar*> fbptr) {
    int size = fbptr.size();
    cout << "size: " + size;
	string outputFile;
    cout << "Enter the name of the output file: ";
    cin >> outputFile;
    cout << "\n";
    ofstream output(outputFile);
	cout << "checkpoint1\n";
	
    for (int i=0; i<size; i++) {
		cout << "checkpoint2\n";
        output << (*fbptr)[i]->getName() << " ";
		cout << "checkpoint3\n";
        output << (*fbptr)[i]->getStr() << "\n";
		cout << "checkpoint4\n";
    }
	cout << "checkpointfinal\n";
    //output.close();
}*/
//Function to read the user input for list of foobars and names/items
void inputFile(std::ifstream &inputFileObj) {
	std::string inputFileName;
	std::cout << "Enter the Input File Name: ";
	std::cin >> inputFileName;
	inputFileObj.open(inputFileName); 
}

//Function that stores the Foobars, Foos, Bars, into a vector of Foobar*
void writeToVector(std::ifstream &inputFileObj, std::vector<Foobar*> *fileVector) {
	std::string fileLine;
	if (inputFileObj.is_open()) {
		while (inputFileObj) {
			std::getline (inputFileObj, fileLine);
			if (fileLine.substr(0, 7) == "foobar ") {
				(*fileVector).push_back(new Foobar(fileLine.substr(7, fileLine.size() - 7)));
			} else if (fileLine.substr(0,4) == "foo ") {
				(*fileVector).push_back(new Foo(fileLine.substr(4, fileLine.size() - 4)));
			} else if (fileLine.substr(0,4) == "bar ") {
				(*fileVector).push_back(new Bar(fileLine.substr(4, fileLine.size() - 4)));
			}
		}
	}
	/*
	for (int i = 0; i < (*fileVector).size(); i++) {
		std::cout << (*fileVector)[i]->get_name() << "\n";
	}*/
}

//Function that reads user input to put the output of the program into a file
void outputFile(std::ofstream &outputFileObj){
	std::string outputFileName;
	std::cout << "Enter the Output File: ";
	std::cin >> outputFileName;
	outputFileObj.open(outputFileName);
}

//Function to set the position for each of the Foobars within the vector of Foobar.
void setPosition(std::vector<Foobar*> &fileVector) {
	int size = fileVector.size();
	for (int i = 0; i < size; i++) {
		fileVector[i]->set_position(size - i);
	}
} 

//Function that actually writes the output of the program into the output file
void writeToOutputFile(std::ofstream &outputFileObj, std::vector<Foobar*> fileVector) {
	int size = fileVector.size();
	for (int i = 0; i < size; i++) {
		outputFileObj << fileVector[i]->get_name() << " " << fileVector[i]->get_power() << "\n";
	}
}

int main() { 
	std::ifstream inputFileObj;
	//void inputFile(std::ifstream &inputFileObj) {
	inputFile(inputFileObj);
	
	std::vector<Foobar*> fileVector;
	//void writeToVector(std::ifstream &inputFileObj, std::vector<Foobar*> *fileVector) {
	writeToVector(inputFileObj, &fileVector);
	
	std::ofstream outputFileObj;
	//void outputFile(std::ofstream &outputFileObj){
	outputFile(outputFileObj);

	//void setPosition(std::vector<Foobar*> &fileVector) {
	setPosition(fileVector);

	//void writeToOutputFile(std::ofstream &outputFileObj, std::vector<Foobar*> fileVector) {
	writeToOutputFile(outputFileObj, fileVector);
	
	inputFileObj.close();
	outputFileObj.close();

	return 0;
}
