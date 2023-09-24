//Ridwan Hussain - Program #1 for DSA 1 where a vector of Foobar pointers were use so that polymorphism for Foo and Bar can be implemented (so get_power calls the correct get_power for its respective class). 

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//SuperClass Foobar
class Foobar { 
	int position;
	std::string name;
public:
	Foobar(std::string nam, int pos=0) {
		position = pos;
		name = nam;
	}
	void set_position(int pos) { 
		position = pos; 
	}	
	virtual int get_power() { return position;}
	std::string get_name() { return name; }
//get_position needs to be protected to get the private data member position for subclasses
protected:
	int get_position() { return position; }
};

//SubClass Foo from Superclass Foobar
class Foo: public Foobar {
public:
	Foo(std::string nam, int pos=0) : Foobar(nam, pos) { }
	int get_power() { return get_position() * 3; }
};

//SubClass Bar from Superclass Foobar
class Bar: public Foobar {
public:
	Bar(std::string nam, int pos=0) : Foobar(nam, pos) { }
	int get_power() { return get_position() + 15; }
};

void inputFile(std::ifstream);
void writeToVector(std::ifstream, std::vector<Foobar*>);
void outputFile(std::ofstream);
void setPosition(std::vector<Foobar*>);
void writeToOutputFile(std::ofstream, std::vector<Foobar*>);

int main() { 
	//Determine name of input file
	std::ifstream inputFileObj;
	inputFile(inputFileObj);
	
	//Create a vector of Foobar* and storing them from the input file
	std::vector<Foobar*> fileVector;
	writeToVector(inputFileObj, &fileVector);
	
	//Determining the name of the output file
	std::ofstream outputFileObj;
	outputFile(outputFileObj);
	
	//Setting the correct position for each Foobar* inside the vector
	setPosition(fileVector);

	//Writing the desired output of the program into the output file
	writeToOutputFile(outputFileObj, fileVector);
	
	inputFileObj.close();
	outputFileObj.close();

	return 0;
}

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
	//cout statement displaying all objects within the Foobar vector
	/*for (int i = 0; i < (*fileVector).size(); i++) {
		std::cout << (*fileVector)[i]->get_name() << "\n";
	}*/
}

//Function that reads user input to determine name of output file
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

//Function that writes the output of the program into the output file
void writeToOutputFile(std::ofstream &outputFileObj, std::vector<Foobar*> fileVector) {
	int size = fileVector.size();
	for (int i = 0; i < size; i++) {
		outputFileObj << fileVector[i]->get_name() << " " << fileVector[i]->get_power() << "\n";
	}
}
