// Implementation file for CurrentDivider class

#include "CurrentDivider.h"

#include <iostream>
#include <fstream>
#include <cmath>

CurrentDivider::CurrentDivider() : Network(2) {
	setSourceI(1);
	setResistances(1000, 1000);
	setNodePointers(&d, 0, 1);
	setNodePointers(&r1, 0, 1);
	setNodePointers(&r2, 0, 1);
	calculateAll();
}

CurrentDivider::CurrentDivider(double d1, double d2, double d3) : Network(2) {
	setSourceI(d1);
	setResistances(d2, d3);
	setNodePointers(&d, 0, 1);
	setNodePointers(&r1, 0, 1);
	setNodePointers(&r2, 0, 1);
	calculateAll();
}

void CurrentDivider::setSourceI(double x) {
	d.setSourceI(x);
	calculateAll();
}

void CurrentDivider::setResistances(double x, double y) {
	r1.setResistance(x);
	r2.setResistance(y);
	calculateAll();
}

void CurrentDivider::calculateAll() {
	setVoltage(0, 0);
	double Req = 1/(1/r1.getResistance() + 1/r2.getResistance());
	setVoltage(1, d.getSourceI()*Req);
}

void CurrentDivider::writeCDToFile(ofstream &outfile) {
	outfile << "\n";
	outfile << "------------------------------------------------" << endl;
	outfile << "\n";
	outfile << "Data for Electric Network # " << returnNetworkIndex() << ":" << endl;
	outfile << "Network # " << returnNetworkIndex() << " is a Current Divider." << endl;
	reportNetworkInfo(outfile);
	outfile << "At present, there are " << d.getNumComponents() << " components in existence." << endl;
	d.writeDCCurrentToFile(outfile);
	r1.writeRToFile(outfile);
	r2.writeRToFile(outfile);
}
