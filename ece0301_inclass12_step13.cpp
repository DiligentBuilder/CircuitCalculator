/*
 * In-Class Assignment 12
 */

#include "CurrentDivider.cpp"

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
	// Define ifstream object, use it to open text file
	ifstream infile;
	infile.open("ECE 0301 - Circuits to Simulate.txt");
	
	// Define ofstream object, use it to open file
	ofstream outfile;
	outfile.open("ECE 0301 - Electrical Network Reports.txt");
	
	// Write introductory message
	outfile << "ECE 0301 - Electrical Network Simulation" << endl;
	
	string line;
	
	double Vs, Is;
	double R1, R2;
	
	// Iterate through this loop until there are no more lines to read from input file
	while (getline(infile, line)) {
		if (line != "Voltage Divider" && line != "Current Divider") {
			cout << "ERROR! Invalid network type.";
			exit(EXIT_FAILURE);
		}
		else if (line == "Voltage Divider") {
			getline(infile, line);
			Vs = stod(line);
			getline(infile, line);
			R1 = stod(line);
			getline(infile, line);
			R2 = stod(line);
			
			// Define voltage divider object, pass values to constructor
			VoltageDivider vd(Vs, R1, R2);
			
			// Write info to output file
			vd.writeVDToFile(outfile);
		}
		else {
			getline(infile, line);
			Is = stod(line);
			getline(infile, line);
			R1 = stod(line);
			getline(infile, line);
			R2 = stod(line);
			
			// Define current divider object with source voltage and resistances
			CurrentDivider cd(Is, R1, R2);
			
			// Write info to output file
			cd.writeCDToFile(outfile);
		}
	}
		
	// Close input and output files
	infile.close();
	outfile.close();
	
	return 0;
}
