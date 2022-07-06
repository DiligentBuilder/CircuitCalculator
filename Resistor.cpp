// Class implementation file for Resistor class

#include "Resistor.h"

#include <iostream>
#include <cmath>
#include <fstream>

Resistor::Resistor() {
	resistance = 1000;
}

void Resistor::setResistance(double d) {
	resistance = d;
}

double Resistor::getResistance() const {
	return resistance;
}

void Resistor::writeRToFile(ofstream &outfile) {
	outfile << "\n";
	outfile << "Component # " << getComponentIndex() << " is a Resistor, R = " << getResistance() << " Ohms." << endl;
	writeToFile(outfile);
	
	if (returnTerminalV() > 0) {
		outfile << "The current in this Resistor = " << abs(returnTerminalV()/resistance) << " Amps, " << endl;
		outfile << "flowing from Node " << getIndexB() << " to Node " << getIndexA() << "." << endl;
	}
	else {
		outfile << "The current in this Resistor = " << abs(returnTerminalV()/resistance) << " Amps, " << endl;
		outfile << "flowing from Node " << getIndexA() << " to Node " << getIndexB() << "." << endl;
	}
	
	outfile << "The power dissipated in this Resistor = " << abs(returnTerminalV()*returnTerminalV()/resistance) << " Watts." << endl;
}

double Resistor::getI() const {
	return returnTerminalV()/resistance;
}

double Resistor::getP() const {
	return returnTerminalV()*returnTerminalV()/resistance;
}
