#include "foobar.hpp"

void outputFile(std::ofstream &outputFileObj){
	std::string outputFileName;
	std::cout << "Enter the Output File: ";
	std::cin >> outputFileName;
	outputFileObj.open(outputFileName);
}

void writeToOutputFile(std::ofstream &outputFileObj, std::vector<Foobar*> fileVector) {
	int size = fileVector.size();
	for (int i = 0; i < size; i++) {
		outputFileObj << fileVector[i]->get_name() << " " << fileVector[i]->get_power() << "\n";
	}
}


