// Class implementation file for Network class

#include "Network.h"

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

Network::Network(int n = 2){
	networkIndex = numNetworks;
	numNetworks++;
	numNodes = n;
	nodeArray = new Node[numNodes];
	
}

Network::~Network() {
	delete[] nodeArray;
}

int Network::returnNetworkIndex() const {
	return networkIndex;
}

int Network::returnNumNodesThis() const {
	return numNodes;
}

int Network::returnNumNodesInExistence() const {
	return nodeArray[0].getnNodes();
} 

void Network::setVoltage(int i, double d) {
	nodeArray[i].setNodeVoltage(d);
}

void Network::reportNetworkInfo(ofstream &outfile) {
	outfile << "At present, there are " << numNetworks << " Networks in existence." << endl;
	outfile << "At present, there are " << nodeArray[0].getnNodes() << " nodes in existence." << endl;
	outfile << "Network # " << networkIndex << " contains " << numNodes << " nodes." << endl;
	for (int i = 0; i < numNodes; i++) {
		outfile << "Voltage at node " << nodeArray[i].getIndex() << " = " << nodeArray[i].getNodeVoltage() << "." << endl;
	}
}

void Network::setNodePointers(Component *c, int a, int b) {
	c->setA(&nodeArray[a]);
	c->setB(&nodeArray[b]);
}

Node* Network::getNodePointer(int i) {
	return &nodeArray[i];
}
