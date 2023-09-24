#include "foobar.hpp"

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

