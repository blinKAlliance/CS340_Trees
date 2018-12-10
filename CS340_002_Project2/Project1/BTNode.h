#ifndef BINARYSEARCHTREENODE_H
#define BINARYSEARCHTREENODE_H

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Node {
public:
	Node * previous;
	string key;
	Node * after;
	Node * parent;
	string COLOR;

	Node() {
		this->previous = NULL;
		this->key = "";
		this->after = NULL;
		this->parent = NULL;
	}

	Node(Node * previous, Node * after, Node * parent, string key) {
		this->previous = previous;
		this->key = key;
		this->after = after;
		this->parent = parent;
	}

};

#endif