// Class specification file for two-terminal component class

#ifndef COMPONENT_H
#define COMPONENT_H

#include "Node.cpp"

#include <iostream>
#include <fstream>
#include <cmath>

class Component {
	private:
		static int nComponents;
		int componentIndex;
		
		// Pointers to objects from the node class
		Node *terminalA;
		Node *terminalB;
	public:
		Component();
		// const accessor functions
		int getComponentIndex() const;
		int getNumComponents() const;
		int getIndexA() const;
		int getIndexB() const;
		// mutator functions
		void setA(Node *);
		void setB(Node *);
		
		// writes info about component to text file
		void writeToFile(ofstream &);
		
		// returns terminal voltage
		double returnTerminalV() const;
};

int Component::nComponents = 0;

#endif
