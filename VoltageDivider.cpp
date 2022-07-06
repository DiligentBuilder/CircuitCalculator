// Class implementation file for voltage divider class

#include "VoltageDivider.h"

#include <iostream>
#include <fstream>
#include <cmath>

VoltageDivider::VoltageDivider() : Network(3) {
	// Set source voltage of voltage source to 1V
	setSourceVoltage(1);
	// Set resistance of both resistors to 1k
	setResistances(1000, 1000);
	setNodePointers(&d, 0, 1);
	setNodePointers(&r1, 1, 2);
	setNodePointers(&r2, 2, 0);
	calculateAll();
}

VoltageDivider::VoltageDivider(double d1, double d2, double d3) : Network(3) {
	setSourceVoltage(d1);
	setResistances(d2, d3);
	setNodePointers(&d, 0, 1);
	setNodePointers(&r1, 1, 2);
	setNodePointers(&r2, 2, 0);
	calculateAll();
}

void VoltageDivider::setSourceVoltage(double x) {
	d.setSourceV(x);
	calculateAll();
}

void VoltageDivider::setResistances(double x, double y) {
	r1.setResistance(x);
	r2.setResistance(y);
	calculateAll();
}

void VoltageDivider::writeVDToFile(ofstream &outfile) {
	outfile << "\n";
	outfile << "------------------------------------------------" << endl;
	outfile << "\n";
	outfile << "Data for Electric Network # " << returnNetworkIndex() << ":" << endl;
	outfile << "Network # " << returnNetworkIndex() << " is a Voltage Divider." << endl;
	reportNetworkInfo(outfile);
	outfile << "At present, there are " << d.getNumComponents() << " components in existence." << endl;
	d.writeDCToFile(outfile);
	r1.writeRToFile(outfile);
	r2.writeRToFile(outfile);
}

void VoltageDivider::calculateAll() {
	setVoltage(0, 0);
	setVoltage(1, d.getSourceV());
	double loopCurrent = d.getSourceV()/(r1.getResistance() + r2.getResistance());
	d.setSourceI(-loopCurrent);
	setVoltage(2, loopCurrent*r2.getResistance());
}
