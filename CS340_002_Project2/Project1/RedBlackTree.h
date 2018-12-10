#include "BTNode.h"
#include "sadInterface.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class RedBlackTree : public sadInterface {
public:
	Node * root;

	// Rotates Left - Implemented From Textbook
	void leftRotate(Node * currNode) {

		Node * tempNode = currNode->after;
		currNode->after = tempNode->previous;

		if (tempNode->previous != NULL) { tempNode->previous->parent = currNode; }

		tempNode->parent = currNode->parent;

		if (currNode->parent == NULL) { root = tempNode; }
		else if (currNode == currNode->parent->previous) { currNode->parent->previous = tempNode; }
		else { currNode->parent->previous = tempNode; }

		tempNode->previous = currNode;
		currNode->parent = tempNode;

		delete tempNode;
	}

	// Rotates Right - Implemented From Textbook
	void rightRotate(Node * currNode) {

		Node * tempNode = currNode->previous;
		currNode->previous = tempNode->after;

		if (tempNode->after != NULL) { tempNode->after->parent = currNode; }

		if (currNode->parent == NULL) { root = tempNode; }
		else if (currNode == currNode->parent->after) { currNode->parent->after = tempNode; }
		else { currNode->parent->after = tempNode; }

		tempNode->after = currNode;
		currNode->parent = tempNode;

		delete tempNode;
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
	void sadInterface::insert(Node *& currNode, string& key) {
		if (currNode->key > key) {
			if (currNode->previous == NULL) {
				currNode->previous = new Node(NULL, NULL, currNode, key);

				insertFixup(currNode->previous);
			}
			else {
				insert(currNode->previous, key);
			}
		}
		else {
			if (currNode->after == NULL) {
				currNode->after = new Node(NULL, NULL, currNode, key);
				insertFixup(currNode->after);
			}
			else {
				insert(currNode->after, key);
			}
		}

	}

	// RB-Insert-Fixup Implemented From Textbook
	void insertFixup(Node * insertedNode) {
		while (insertedNode->parent->COLOR == "RED") {
			if (insertedNode->parent == insertedNode->parent->parent->previous) {
				Node * tempNode = insertedNode->parent->parent->after;

				if (tempNode->COLOR == "RED") {
					insertedNode->parent->COLOR = "BLACK"; // Case 1
					tempNode->COLOR = "BLACK"; // Case 1
					insertedNode->parent->parent->COLOR = "RED"; // Case 1
					insertedNode = insertedNode->parent->parent; // Case 1

					break;
				}
				else {
					if (insertedNode == insertedNode->parent->after) {
						insertedNode = insertedNode->parent; // Case 2
						leftRotate(insertedNode); // Case 2
					}
					insertedNode->parent->COLOR = "BLACK"; // Case 3
					insertedNode->parent->parent->COLOR = "RED"; // Case 3
					rightRotate(insertedNode->parent->parent); // Case 3
				}
			}
			else {
				Node * tempNode = insertedNode->parent->parent->previous;

				if (tempNode->COLOR == "RED") {
					insertedNode->parent->COLOR = "BLACK"; // Case 1
					tempNode->COLOR = "BLACK"; // Case 1
					insertedNode->parent->parent->COLOR = "RED"; // Case 1
					insertedNode = insertedNode->parent->parent; // Case 1

					break;
				}
				else {
					if (insertedNode == insertedNode->parent->previous) {
						insertedNode = insertedNode->parent; // Case 2
						rightRotate(insertedNode); // Case 2
					}

					insertedNode->parent->COLOR = "BLACK"; // Case 3
					insertedNode->parent->parent->COLOR = "RED"; // Case 3
					leftRotate(insertedNode->parent->parent); // Case 3
				}
			}
		}

	}
};
