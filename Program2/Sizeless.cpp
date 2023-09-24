//Ridwan Hussain - DSA 1 Program 2 assignment where one creates their own simple psuedo linked list (can only push and pop) as an abstract class, then makes dervied stacks and queue class from it; these stacks and queues are stored into a standard linked list from the C++ list library. Templates were also used so the lists can be done with ints, doubles, and floats.

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

/*class SimpleList;
template <typename T> class Stack : public SimpleList<T>;
template <typename T> class Queue : public SimpleList<T>;
void inputFile(ifstream &inputFileObj);
void outputFile(ofstream &outputFileObj);
template <typename T> SimpleList<T> *search(list<SimpleList<T> *> &metaList, string name);
template <typename T> void create(ofstream &outputFileObj, list<SimpleList<T> *> &metaList, string name, string type);
template <typename T> void push(ofstream &outputFileObj, list<SimpleList<T> *> metaList, string name, T data);
template <typename T> void pop(ofstream &outoutFileObj, list<SimpleList<T> *> metalList, string name);
void commands(ifstream &inputFileObj, ofstream &outputFileObj);*/

template <typename T>
class SimpleList {
	class Node { //Private Node Class
	public:
		T data;
		Node* next_node;
		Node (T d) {
			data = d;
			next_node = NULL;
		}
	};
	string name;

public:
	SimpleList<T>(string n) {
		name = n;
	}
	Node *first_node = NULL; //Head pointer
	Node *last_node = NULL;  //Tail pointer
	string get_name() { return name; }
	virtual void push(T i) = 0; //virtual function so dervied classes call the right function
	virtual T pop() = 0;        //virtual function so dervied classes call the right function
	
protected:
	void insert_node_start(T d) { //push function for Stack Class
		Node* new_node = new Node(d);
		if (first_node == NULL) {
			first_node = new_node;
		} else {
			new_node->next_node = first_node;
			first_node = new_node;
		}
	}
	void insert_node_end(T d) { //push function for Queue Class
		Node* new_node = new Node(d);
		if (last_node == NULL) {
			first_node = last_node = new_node;
		} else {
			last_node->next_node = new_node;
			last_node = new_node;
		}
	}
	T remove_node() { //pop function for both Stacks and Queue
		Node *tmp = first_node;
		T d = first_node->data;
		first_node = first_node->next_node;
		delete tmp;
		if (first_node == NULL) {
			last_node = NULL;
		}
		return d;
	}
};

//Templated Derived Stack class of SimpleList that has pop and push (pushes to the start).
template <typename T>
class Stack: public SimpleList<T> {
public:
	Stack (string nam) : SimpleList<T> (nam) { }
	T pop() { return this->remove_node(); }
	void push(T d) { this->insert_node_start(d); }
};

//Templated Derived Queue class of SimpleList that has pop and push (pushes to the end).
template <typename T>
class Queue: public SimpleList<T> {
public:
	Queue (string nam) : SimpleList<T> (nam) { }
	T pop () { return this->remove_node(); }
	void push (T d) { this->insert_node_end(d); }
};

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

//A templated search function to sees if a stack or queue exits within a certain metaList
template <typename T>
SimpleList<T> *search(list<SimpleList<T> *> &metaList, string name){
	for (auto pmL = metaList.begin(); pmL != metaList.end(); pmL++)
		if ((*pmL)->get_name() == name) { return (*pmL); }
	return NULL;
}

//A templated create command that creates a new stack or queue if one doesn't exist within the metaList.
template <typename T>
void create(ofstream &outputFileObj, list<SimpleList<T> *> &metaList, string name, string type) {
	auto pSL = search(metaList, name);
	if (pSL != NULL) {
		outputFileObj << "ERROR: This name already exists!\n";
	} else {
		if (type == "stack") {
			metaList.push_front(new Stack<T>(name));
		} else if (type == "queue") {
			metaList.push_front(new Queue<T>(name));
		}
	}
}

//A templated push command that pushes nodes into a stack or queue if a list of that name exists within the metaList.
template <typename T>
void push(ofstream &outputFileObj, list<SimpleList<T> *> metaList, string name, T data) {
	SimpleList<T>* pSL = search(metaList, name);
	if (pSL == NULL) {
		outputFileObj << "ERROR: This name does not exist!\n";
		return;
	}
	pSL->push(data);
}

//A templated pop command that pops the first or last node of a stack or queue, respectively, if a list of the name exists & the list is not empty.
template <typename T>
void pop(ofstream &outputFileObj, list<SimpleList<T> *> metaList, string name) {
	SimpleList<T>* pSL = search(metaList, name);
	if (pSL == NULL) {
		outputFileObj << "ERROR: This name does not exist!\n";
		return;
	} 
	if (pSL->first_node == NULL && pSL->last_node == NULL) {
		outputFileObj << "ERROR: This list is empty!\n";
		return;
	}
	T data = pSL->pop();
	outputFileObj << "Value popped: " << data << "\n";
}

//Function that creates the 3 metaList for each type (int, double, string), reads in the command of an input file, and calls the correct function command (create, push, pop) while printing the outputs into the outputFile. 
void commands(ifstream &inputFileObj, ofstream &outputFileObj) {
	string command, name, type, data;
	list<SimpleList<int> *> listSLi;     //metaList for ints
	list<SimpleList<double> *> listSLd;  //metaList for doubles
	list<SimpleList<string> *> listSLs;  //metaList for string
	if (inputFileObj.is_open()) {
		while (inputFileObj) {
			getline (inputFileObj, command, ' '); //get the first word of an input file line
			if (command == "create") {
				getline (inputFileObj, name, ' '); //get the name of the list
				getline(inputFileObj, type); //get the type whether it's a stack or queue
				outputFileObj << "PROCESSING COMMAND: create " << name << " " << type << "\n";
				if (name[0] == 'i')
					create(outputFileObj, listSLi, name, type);
				else if (name[0] == 'd')
					create(outputFileObj, listSLd, name, type);
				else if (name[0] == 's') 
					create(outputFileObj, listSLs, name, type);

			} else if (command == "push") {
				getline (inputFileObj, name, ' '); //get the name of the list
				getline(inputFileObj, data); //get the data value of a node
				outputFileObj << "PROCESSING COMMAND: push " << name << " " << data << "\n";
				if (name[0] == 'i')
					push(outputFileObj, listSLi, name, stoi(data));
				else if (name[0] == 'd')
					push(outputFileObj, listSLd, name, stod(data));
				else if (name[0] == 's') 
					push(outputFileObj, listSLs, name, data);

			} else if (command == "pop") {
				getline (inputFileObj, name); //get the name of the list
				outputFileObj << "PROCESSING COMMAND: pop " << name << "\n";
				if (name[0] == 'i') {
					pop(outputFileObj, listSLi, name);
				} else if (name[0] == 'd') {
					pop(outputFileObj, listSLd, name);
				} else if (name[0] == 's') {
					pop(outputFileObj, listSLs, name);
				}
			}
		}
	}
	/*for (auto pmL = listSLi.begin(); pmL != listSLi.end(); pmL++) 
		cout << (*pmL)->get_name() << " ";
		for (auto pSL = (*pmL).begin(); pSL != (*pmL).end(); pSL++) {
			cout << (*pSL)->data << " ";
		}
		cout << "\n";
	for (auto pmL = listSLd.begin(); pmL != listSLd.end(); pmL++) 
		cout << (*pmL)->get_name() << " ";
	for (auto pmL = listSLs.begin(); pmL != listSLs.end(); pmL++) 
		cout << (*pmL)->get_name() << " "; cout << "\n";
	cout << "\n";*/
}

int main() {
	ifstream inputFileObj;
	inputFile(inputFileObj);
	
	ofstream outputFileObj;
	outputFile(outputFileObj);

	commands(inputFileObj, outputFileObj);

	inputFileObj.close();
	outputFileObj.close();

	return 0;
}
