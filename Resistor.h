// Class specification file for Resistor class

#include "DCVoltageSource.cpp"

#include <iostream>
#include <cmath>
#include <fstream>

class Resistor : public Component {
	private:
		double resistance;
	public:
		Resistor();
		void setResistance(double);
		double getResistance() const;
		void writeRToFile(ofstream &);
		double getI() const;
		double getP() const;
};
