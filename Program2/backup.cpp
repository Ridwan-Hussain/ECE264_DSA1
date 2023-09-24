//To-Do 
// - Create a stack/queue class using Sable's stuff
// - Create the create, push, pop functions
// - Comment code/Update comments
// - Search function
// - fix up private vs. public data members
// - make vector of queues and stacks into a list

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>

using namespace std;

void inputFile(ifstream &inputFileObj);
void outputFile(ofstream &inputFileObj);
void readFile(ifstream &inputFileObj, vector<string> &inputFile);
//figure out naming scheme for string vector
//void printVector(vector<string> &inputFile);
//void search(list<template T>);

template <class T>
class SimpleList {
	class Node {
	public:
		T data;
		Node* next_node;
		Node (T d) {
			data = d;
			next_node = NULL;
		}
	};
	string name;
	int size = 0;

public:
	SimpleList<T>(string nam) {
		name = nam;
	}
	Node *first_node = NULL;
	Node *last_node = NULL;
	string get_name() { return name; }
	int get_size() { return size; }
	virtual void push(T i) = 0;
	virtual T pop() = 0; 
	void print() {
		Node *tmp = first_node;
		cout << name << ": ";
		while (tmp != NULL) {
			cout << to_string(tmp->data) << " ";
			tmp = tmp->next_node;
		}
		cout << "\n";
	}

protected:
	void insert_node_start(T d) {
		size++;
		Node* new_node = new Node(d);
		if (first_node == NULL) {
			first_node = new_node;
		} else {
			new_node->next_node = first_node;
			first_node = new_node;
		}
	}
	void insert_node_end(T d) {
		size++;
		Node* new_node = new Node(d);
		if (last_node == NULL) {
			first_node = last_node = new_node;
		} else {
			last_node->next_node = new_node;
			last_node = new_node;
		}
	}
	T remove_node() {
		size--;
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

template <typename T>
class Stack: public SimpleList<T> {
public:
	Stack (string nam) : SimpleList<T> (nam) { }
	T pop() { return this->remove_node(); }
	void push(T d) { this->insert_node_start(d); }
};

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

//Gotta template this function so that it works for stacks & queues
template <typename T>
SimpleList<T> *search(list<SimpleList<T> *> &metaList, string name){
	for (auto pmL = metaList.begin(); pmL != metaList.end(); pmL++)
		if ((*pmL)->get_name() == name) { return (*pmL); }
	return NULL;
}

template <typename T>
void create(ofstream &outputFileObj, list<SimpleList<T> *> &metaList, string name, string type) {
	auto pSL = search(metaList, name);
	if (pSL != NULL) {
		outputFileObj << "ERROR: This name already exists!\n";
		cout << "ERROR: This name already exists!\n";
	} else {
		if (type == "stack") {
			metaList.push_front(new Stack<T>(name));
		} else if (type == "queue") {
			metaList.push_front(new Queue<T>(name));
		}
	}
}

template <typename T>
void push(ofstream &outputFileObj, list<SimpleList<T> *> metaList, string name, T data) {
	SimpleList<T>* pSL = search(metaList, name);
	if (pSL == NULL) {
		outputFileObj << "ERROR: This name does not exist!\n";
		cout << "ERROR: This name does not exist!\n";
		return;
	}
	pSL->push(data);
}

template <typename T>
void pop(ofstream &outputFileObj, list<SimpleList<T> *> metaList, string name) {
	SimpleList<T>* pSL = search(metaList, name);
	if (pSL == NULL) {
		outputFileObj << "ERROR: This name does not exist!\n";
		cout << "ERROR: This name does not exist!\n";
		return;
	} 
	if (pSL->get_size() == 0) {
		outputFileObj << "ERROR: This list is empty!\n";
		cout << "ERROR: This list is empty!\n";
		return;
	}
	T data = pSL->pop();
	outputFileObj << "Value popped: " << data << "\n";
	cout << "Value popped: " << data << "\n";
}

//Function that reads user input to put the output of the program into a file
void outputFile(ofstream &outputFileObj){
	string outputFileName;
	cout << "Enter the Output File: ";
	cin >> outputFileName;
	outputFileObj.open(outputFileName);
}

//Function that takes in file input and stores it into a string vector
void readFile(ifstream &inputFileObj, ofstream &outputFileObj) {
	string command, name, type, data;
	list<SimpleList<int> *> listSLi;
	list<SimpleList<double> *> listSLd;
	list<SimpleList<string> *> listSLs;
	if (inputFileObj.is_open()) {
		while (inputFileObj) {
			getline (inputFileObj, command, ' ');
			getline (inputFileObj, name, ' ');
			if (command == "create") {
				getline (inputFileObj, name, ' ');
				getline(inputFileObj, type);
				outputFileObj << "PROCESSING COMMAND: create " << name << " " << type << "\n";
				cout << "PROCESSING COMMAND: create " << name << " " << type << "\n";
				if (name[0] == 'i')
					create(outputFileObj, listSLi, name, type);
				else if (name[0] == 'd')
					create(outputFileObj, listSLd, name, type);
				else if (name[0] == 's') 
					create(outputFileObj, listSLs, name, type);

			} else if (command == "push") {
				getline (inputFileObj, name, ' ');
				getline(inputFileObj, data);
				outputFileObj << "PROCESSING COMMAND: push " << name << " " << data << "\n";
				cout << "PROCESSING COMMAND: push " << name << " " << data << "\n";
				if (name[0] == 'i')
					push(outputFileObj, listSLi, name, stoi(data));
				else if (name[0] == 'd')
					push(outputFileObj, listSLd, name, stod(data));
				else if (name[0] == 's') 
					push(outputFileObj, listSLs, name, data);

			} else if (command == "pop") {
				getline (inputFileObj, name);
				outputFileObj << "PROCESSING COMMAND: pop " << name << "\n";
				cout << "PROCESSING COMMAND: pop " << name << "\n";
				if (name[0] == 'i') {
					pop(outputFileObj, listSLi, name);
				} else if (name[0] == 'd') {
					pop(outputFileObj, listSLd, name);
				} else if (name[0] == 's') {
					pop(outputFileObj, listSLs, name);
				}
			}
			//inputFile.push_back(fileLine);
		}
	}
	/*for (auto pmL = listSLi.begin(); pmL != listSLi.end(); pmL++) 
		cout << (*pmL)->get_name() << " ";
	for (auto pmL = listSLd.begin(); pmL != listSLd.end(); pmL++) 
		cout << (*pmL)->get_name() << " ";
	for (auto pmL = listSLs.begin(); pmL != listSLs.end(); pmL++) 
		cout << (*pmL)->get_name() << " ";*/
}

int main() {
	ifstream inputFileObj;
	inputFile(inputFileObj);
	
	ofstream outputFileObj;
	outputFile(outputFileObj);

	readFile(inputFileObj, outputFileObj);


	/*auto S = new Stack<int>("Stack Tester");
	S->push(1);
	S->push(2);
	S->push(3);
	S->push(4);
	S->push(5);
	S->print();
	cout << S->pop() << "\n";
	cout << S->pop() << "\n";
	cout << S->pop() << "\n";
	cout << S->pop() << "\n";
	cout << S->pop() << "\n";
	S->print();*/
	
	/*auto Q = new Queue("Queue Tester");
	Q->push(1);
	Q->push(2);
	Q->push(3);
	Q->push(4);
	Q->push(5);
	Q->print();
	cout << Q->pop() << " \n";
	Q->print();*/

	inputFileObj.close();
	//outputFileObj.close();

	return 0;
}
