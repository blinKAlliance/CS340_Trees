#pragma once
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "sadInterface.h"
#include "BTNode.h"

#include <time.h> 
#include <string>
#include <stdexcept>
#include <new>
using namespace std;

class BinarySearchTree : public sadInterface {
public:
	typedef void(*Function)(string& key);

	Node * createNode(Node * previous, string& key, Node * after, Node * parent) throw (bad_alloc) {
		return new Node(previous, after, parent, key);
	}

	// Inorder Traversal From Textbook
	void inorder(Node * node, Function visit) {
		if (node != NULL) {
			inorder(node->previous, visit);
			visit(node->key);
			inorder(node->after, visit);
		}
	}

	// Iterative Tree Search From Textbook
	bool sadInterface::searchTree(Node * node, string key) {    
		while (node != NULL && key != node->key) {
			if (key < node->key) {
				node = node->previous;
			}
			else {
				node = node->after;
			}
		}

		return node;
	}

	// Recursivly Implemented Insertion
	void sadInterface::insert(Node *& node, string& key) {
		if (node == nullptr) {
			node = createNode(nullptr, key, nullptr, nullptr);

		}
		else if (key < node->key) {
			insert(node->previous, key);

		}
		else {
			insert(node->after, key);

		}
	}

	Node * root;

	BinarySearchTree() {
		root = nullptr;
	}
};

#endif