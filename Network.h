// Class specification file for Network class

#ifndef NETWORK_H
#define NETWORK_H

#include "Resistor.cpp"

#include <iostream>
#include <fstream>
#include <cmath>

class Network {
	private:
		static int numNetworks;
		int networkIndex;
		int numNodes;
		Node *nodeArray;
	public:
		Network(int);
		~Network();
		
		int returnNetworkIndex() const;
		int returnNumNodesThis() const;
		int returnNumNodesInExistence() const;
		
		void setVoltage(int, double);
		void reportNetworkInfo(ofstream &);
		
		void setNodePointers(Component *, int, int);
		Node* getNodePointer(int);
};

int Network::numNetworks = 0;

#endif
