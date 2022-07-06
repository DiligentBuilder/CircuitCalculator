// Class specification file for voltage divider class

#include "Network.cpp"

#include <iostream>
#include <fstream>
#include <cmath>

class VoltageDivider : public Network {
	private:
		DCVoltageSource d;
		Resistor r1;
		Resistor r2;
	public:
		VoltageDivider();
		VoltageDivider(double, double, double);
		void setSourceVoltage(double);
		void setResistances(double, double);
		void writeVDToFile(ofstream &);
		
		void calculateAll();
};
