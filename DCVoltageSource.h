// Class specification file for DC Voltage Source

#ifndef DCVOLTAGESOURCE_H
#define DCVOLTAGESOURCE_H

#include "Component.cpp"

#include <iostream>
#include <cmath>
#include <fstream>


using namespace std;

class DCVoltageSource : public Component {
	private:
		double sourceV;
		double sourceI;
	public:
		DCVoltageSource();
		void setSourceV(double);
		double getSourceV() const;
		void writeDCToFile(ofstream &);
		void setSourceI(double);
		double getSourceI() const;
		double getSourceP() const;
};

#endif
