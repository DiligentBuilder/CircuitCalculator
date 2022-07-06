// Class specification file for the DCCurrentSource class

#ifndef DCCURRENTSOURCE_H
#define DCCURRENTSOURCE_H

#include "VoltageDivider.cpp"

#include <iostream>
#include <fstream>
#include <cmath>

class DCCurrentSource : public Component {
	private:
		double sourceI;
	public:
		DCCurrentSource();
		void setSourceI(double);
		double getSourceI() const;
		double getPower() const;
		void writeDCCurrentToFile(ofstream &);
};

#endif
