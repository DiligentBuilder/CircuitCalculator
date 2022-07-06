// Class Implementation File for DC Voltage Source

#include "DCVoltageSource.h"

#include <iostream>
#include <cmath>
#include <fstream>

DCVoltageSource::DCVoltageSource() {
	sourceV = 0;
}

void DCVoltageSource::setSourceV(double d) {
	sourceV = d;
}

double DCVoltageSource::getSourceV() const {
	return sourceV;
}

void DCVoltageSource::writeDCToFile(ofstream &outfile) {
	outfile << "\n";
	outfile << "Component # " << getComponentIndex() << " is a DC Voltage Source, Vs = " << sourceV << " Volts." << endl;
	writeToFile(outfile);
	
	if (sourceI > 0) {
		outfile << "The current in this DC Voltage Source = " << abs(sourceI) << " Amps, " << endl;
		outfile << "flowing from Node " << getIndexB() << " to Node " << getIndexA() << "." << endl;
	}
	else {
		outfile << "The current in this DC Voltage Source = " << abs(sourceI) << " Amps, " << endl;
		outfile << "flowing from Node " << getIndexA() << " to Node " << getIndexB() << "." << endl;
	}
	
	outfile << "The power supplied by this DC Voltage Source = " << abs(sourceV * sourceI) << " Watts." << endl;
}

void DCVoltageSource::setSourceI(double d) {
	sourceI = d;
}

double DCVoltageSource::getSourceI() const {
	return sourceI;
}

double DCVoltageSource::getSourceP() const {
	return sourceI*sourceV;
}
