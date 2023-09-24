#include "foobar.hpp"

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

void setPosition(std::vector<Foobar*> &fileVector) {
	int size = fileVector.size();
	for (int i = 0; i < size; i++) {
		fileVector[i]->set_position(size - i);
	}
} 
