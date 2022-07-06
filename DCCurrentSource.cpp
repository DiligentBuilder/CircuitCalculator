// Class implementation file for the DCCurrentSource class

#include "DCCurrentSource.h"

#include <iostream>
#include <fstream>
#include <cmath>

DCCurrentSource::DCCurrentSource() {
	sourceI = 0;
}

void DCCurrentSource::setSourceI(double d) {
	sourceI = d;
}

double DCCurrentSource::getSourceI() const {
	return sourceI;
}

double DCCurrentSource::getPower() const {
	return sourceI*returnTerminalV();
}

void DCCurrentSource::writeDCCurrentToFile(ofstream &outfile) {
	outfile << "\n";
	outfile << "Component # " << getComponentIndex() << " is a DC Current Source, Is = " << sourceI << " Amps." << endl;
	writeToFile(outfile);
	
	if (sourceI > 0) {
		outfile << "The current in this DC Current Source = " << abs(sourceI) << " Amps, " << endl;
		outfile << "flowing from Node " << getIndexA() << " to Node " << getIndexB() << "." << endl;
	}
	else {
		outfile << "The current in this DC Current Source = " << abs(sourceI) << " Amps, " << endl;
		outfile << "flowing from Node " << getIndexB() << " to Node " << getIndexA() << "." << endl;
	}
	
	outfile << "The power supplied by this DC Current Source = " << abs(returnTerminalV() * sourceI) << " Watts." << endl;
}
