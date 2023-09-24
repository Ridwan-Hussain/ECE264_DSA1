#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//SuperClass for Foobar
class Foobar { 
	int position;
	std::string name;
public:
	Foobar(std::string nam, int pos=0) {
		position = pos;
		name = nam;
	}
	void set_position(int pos) { position = pos;	}	
	virtual int get_power() { return position;}
	std::string get_name() { return name; }
protected:
	int get_position() { return position; }
};

//SubClass for Foo
class Foo: public Foobar {
public:
	Foo(std::string nam, int pos=0) : Foobar(nam, pos) { }
	int get_power() { return get_position() * 3; }
};

//SubClass for Bar
class Bar: public Foobar {
public:
	Bar(std::string nam, int pos=0) : Foobar(nam, pos) { }
	int get_power() { return get_position() + 15; }
};

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
	inputFile(inputFileObj);
	
	std::vector<Foobar*> fileVector;
	writeToVector(inputFileObj, &fileVector);
	
	std::ofstream outputFileObj;
	outputFile(outputFileObj);
	
	setPosition(fileVector);

	writeToOutputFile(outputFileObj, fileVector);
	
	inputFileObj.close();
	outputFileObj.close();

	return 0;
}

