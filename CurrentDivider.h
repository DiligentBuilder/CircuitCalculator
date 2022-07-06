// Specification file for CurrentDivider class

#ifndef CURRENTDIVIDER_H
#define CURRENTDIVIDER_H

#include "DCCurrentSource.cpp"

#include <iostream>
#include <fstream>
#include <cmath>

class CurrentDivider : public Network {
	private:
		DCCurrentSource d;
		Resistor r1;
		Resistor r2;
	public:
		CurrentDivider();
		CurrentDivider(double, double, double);
		void setSourceI(double);
		void setResistances(double, double);
		void calculateAll();
		void writeCDToFile(ofstream &);
};

#endif
