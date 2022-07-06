// Class implementation file for Node class

#include "Node.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

Node::Node() {
	index = nNodes;
	nNodes++;
	nodeVoltage = 0;
}

int Node::getnNodes() const {
	return nNodes;
}

int Node::getIndex() const {
	return index;
}

void Node::setNodeVoltage(double d) {
	nodeVoltage = d;
}

double Node::getNodeVoltage() const {
	return nodeVoltage;
}

void Node::reportInfo(ofstream &outfile) const {
	outfile << "Voltage at node " << index << " = " << nodeVoltage << "." << endl;
}
