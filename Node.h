// Class specification file for Node class

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Node {
	private:
		static int nNodes;
		int index;
		double nodeVoltage;
	public:
		Node();
		// Return number of nodes and node index
		int getnNodes() const;
		int getIndex() const;
		
		// Mutator function to set node voltage to desired value
		void setNodeVoltage(double);
		// Accessor function to return node voltage
		double getNodeVoltage() const;
		// Member function to report info about a node
		void reportInfo(ofstream &outfile) const;
};

int Node::nNodes = 0;

#endif
