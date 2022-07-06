// Class implementation file for two-terminal component class

#include "Component.h"

#include <iostream>
#include <fstream>
#include <cmath>

Component::Component() {
	componentIndex = nComponents;
	nComponents++;
	terminalA = nullptr;
	terminalB = nullptr;
}

int Component::getComponentIndex() const {
	return componentIndex;
}
int Component::getNumComponents() const {
	return nComponents;
}

void Component::setA(Node *n) {
	terminalA = n;
}

void Component::setB(Node *n) {
	terminalB = n;
}

int Component::getIndexA() const {
	return terminalA->getIndex();
}
int Component::getIndexB() const {
	return terminalB->getIndex();
}

void Component::writeToFile(ofstream &outfile) {
	outfile << "Component # " << getComponentIndex() << " is connected between node " << getIndexA() << " and node " << getIndexB() << "." << endl;
	
	if (returnTerminalV() > 0) {
		outfile << "The Voltage across Component # " << getComponentIndex() << " = " << abs(returnTerminalV()) << " Volts," << endl;
		outfile << "with the negative terminal at node " << getIndexA() << "." << endl;
	}
	else {
		outfile << "The Voltage across Component # " << getComponentIndex() << " = " << abs(returnTerminalV()) << " Volts, " << endl;
		outfile << "with the negative terminal at node " << getIndexB() << "." << endl;
	}
}

double Component::returnTerminalV() const {
	double A = terminalA->getNodeVoltage();
	double B = terminalB->getNodeVoltage();
	return (B-A);
}
