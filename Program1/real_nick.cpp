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
    int getPos(){
        return Position;
    }
public:
    Foobar(string name, int pos=0) {
        fbName = name;
        Position = pos;
    }
    void setPos(int p){
        Position = p;
    }
    string getName(){return fbName;}
    virtual int getStr(){return Position;}
};


class Foo: public Foobar {
public:
    int getStr(){
        return (getPos() * 3);
    }
    Foo(string fooName, int pos=0) : Foobar(fooName, pos){ }
};


class Bar: public Foobar {
public:
    int getStr(){
        return (getPos() + 15);
    }
    Bar(string barName, int pos=0) : Foobar(barName, pos){ }
};

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
	string inputFile;
    cout << "Enter the name of the input file: ";
    cin >> inputFile;
    cout << "\n";
	string fileLine;
	ifstream inputFileObj(inputFile);
	if (inputFileObj.is_open()) {
		while (inputFileObj) {
			std::getline (inputFileObj, fileLine);
			if (fileLine.substr(0, 7) == "foobar ") {
				(*fbVect).push_back(new Foobar(fileLine.substr(7, fileLine.size() - 7)));
			} else if (fileLine.substr(0,4) == "foo ") {
				(*fbVect).push_back(new Foo(fileLine.substr(4, fileLine.size() - 4)));
			} else if (fileLine.substr(0,4) == "bar ") {
				(*fbVect).push_back(new Bar(fileLine.substr(4, fileLine.size() - 4)));
			}
		}
	}
	inputFileObj.close();
	/*ifstream input(inputFile);
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
        }
        else if(type == "foo"){
            Foobar* fbptr;
            Foo foo(name);
            fbptr = &foo;
            (*fbVect).push_back(fbptr);
        }
        else if(type == "bar"){
            Foobar* fbptr;
            Bar bar(name);
            fbptr = &bar;
            (*fbVect).push_back(fbptr);
        }
        else
            cout << "type not recognized\n";
    }
    
    input.close();*/
}

// This function iterates through the foobars and updates their position
void updatelist(vector<Foobar*> *fbptr) {
    int size = (*fbptr).size();
    for (int i=0; i<size; i++) {
        (*fbptr)[i]->setPos(size-i);
    }
}


void processOutput(vector<Foobar*> *fbptr) {
    int size = (*fbptr).size();
    string outputFile;
    cout << "Enter the name of the output file: ";
    cin >> outputFile;
    cout << "\n";
    ofstream output(outputFile);

    for (int i=0; i<size; i++) {
        output << (*fbptr)[i]->getName() << " ";
        output << (*fbptr)[i]->getStr() << "\n";
    }

    output.close();
}
/*
for (Foobar* i: *fbptr)
    cout << i << "\n";
*/
