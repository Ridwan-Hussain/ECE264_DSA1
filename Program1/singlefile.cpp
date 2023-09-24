#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Foobar { 
	int position, power;
	std::string name;
public:
	Foobar(std::string nam, int pos=0) {
		position = pos;
		power = pos;
		name = nam;
	}
	virtual int get_power() { return power;}
	std::string get_name() { return name; }
};

class Foo: public Foobar {
	int position, power;
	std::string name;
public:
	Foo(std::string nam, int pos=0) : Foobar(nam, pos) {
		position = pos;
		power = pos * 3;
		name = nam;
	}
};

class Bar: public Foobar {
	int position, power;
	std::string name;
public:
	Bar(std::string nam, int pos=0) : Foobar(nam, pos) {
		position = pos;
		power = pos + 15;
		name = nam;
	}
};

void openInputFile(std::ifstream* inputStream, std::string inputFileName) {
std::cout << "Insert the Input File Name: ";

}

int main() { 
	std::ifstream inputFile;
	std::cout << "Insert the Input File Name: ";
	std::string inputFileName;
	std::cin >> inputFileName;
	inputFile.open(inputFileName); 
	std::string fooType, fooName, fileLine, power;
	char filechar;
	std::vector<std::vector<std::string>> fileVector;
	if (inputFile.is_open() ) { 
		while (inputFile) {
			std::getline (inputFile, fileLine);
			for (int i = 0; i < fileLine.size(); i++) {
				filechar = fileLine[i];
				if (filechar != ' ') {
					fooType += filechar;
				} else {
					fooName.append(fileLine, i + 1, fileLine.size() - 1);
					break;
				}
			}
			std::vector<std::string> vectInput = {fooType, fooName, "0"};
			fileVector.push_back(vectInput);
			fooType = fooName = "";
		}	
	}/*
	for (int i = 0; i < fileVector.size(); i++) {
		for (int j = 0; j < fileVector[i].size(); j++) { 
			std::cout << fileVector[i][j] << " ";
		}
		std::cout << "\n";
	}*/
	fileVector.pop_back();

	std::cout << "\nFILE OUTPUT STARTS HERE \n";
	std::cout << "Enter the file you want to write the output to: ";
	std::string fileOutputName;
	std::cin >> fileOutputName; 
	std::ofstream outputFile;
	outputFile.open(fileOutputName);
	if (fileVector.size() == 1) {
		//print out single output, power = 0;
		//return 0
	}
	for (int i = 0; i < fileVector.size(); i++) {
		if (fileVector[i][0] == "foobar") {
			fileVector[i][2] = std::to_string (Foobar(fooType, fileVector.size() - i).get_power());
		} else if (fileVector[i][0] == "foo") {
			fileVector[i][2] = std::to_string (Foo(fooType, fileVector.size() - i).get_power());
		} else if (fileVector[i][0] == "bar") {
			fileVector[i][2] = std::to_string (Bar(fooType, fileVector.size() - i).get_power());
		}
		outputFile << fileVector[i][1] << " " << fileVector[i][2] << "\n";
	}

	//Ask for file output Name
	//If single element, power is 0
	return 0;
}

