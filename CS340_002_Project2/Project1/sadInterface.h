#ifndef INTERFACESAD_H
#define INTERFACESAD_H

#include "BTNode.h"

// C++ Interface
class sadInterface {
public:
	virtual bool searchTree(Node * node, string key) = 0;
	virtual void insert(Node *& node, string& key) = 0;
private:

};

#endif