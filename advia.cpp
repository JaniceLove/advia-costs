//Program to calculate costs for Siemens Advia 120
//Author: Janice Love
//Date: 8/15/2014
//Update: 1-27-2015

#include <iostream>
#include <fstream>
#include <iomanip>
#include "functions.h" 

using namespace std; 

//Reagents, costs (year 2015, provided by Siemens company rep)
double perox_timepac = 283.12; //3700 tests
double sheathRinse = 66.87; //700 tests 

double retic_soln_cost = 665.53; //600 tests 
double rbc_timepac = 246.75; //3700 tests
//double ezWash_cost = 43.53; //2 per box

double defoamer_cost = 93.18; //one piece

//controls
double primer; //10 ml, pack of 25. BCM marketplace 
double control_high = 247.18;
double control_normal = 247.18;
double control_low = 247.18; 

double retic_low = 148.99;
double retic_high = 148.99;

//MISC expenses 
double tubeEDTA = 31.06; //per pack, 50 ct.
double labor;
double machine; 
double diffCost;
double sheathRinseCost; 
double cbcTimepac;
double ezWash;
double defoamer;
double controls; 

double reticControls;
double reticSoln; 

double cbc_price;
double cbcRetic_price; 



int main ()
{
	ofstream myFile;
	myFile.open("AdviaPrices.txt");
	
	int aveTests = 10;
	labor = techTime(); 
	machine = machineCost();
	primer = primerCost();

	diffCost = (perox_timepac / 3700) * aveTests; 
	sheathRinseCost = (sheathRinse / 700) * aveTests; 
	cbcTimepac = (rbc_timepac / 3700) * aveTests; 
	ezWash = ezWashCost();

	defoamer = (defoamer_cost / 30) / 10; 

	double x;
	x = controlCost();
	controls = 3 * x; 


	double y;
	y =  reticControlCost();
	reticControls = 2 * x;

	reticSoln = (retic_soln_cost / 600) *10; 

	
	cbc_price = labor + machine + primer + diffCost + sheathRinseCost +
				cbcTimepac + ezWash + defoamer + controls; 

	cbcRetic_price = cbc_price + reticControls + reticSoln;

	myFile << setprecision(4) << endl;
	myFile <<"Siemens Advia" << endl;
	myFile << endl;
	myFile << "CBC PRICES: " << endl;
	myFile << "CBC: $ " << cbc_price << endl; 
	myFile << "CBC + Reticulocyte count: $" << cbcRetic_price << endl; 
	


	myFile.close();

	return 0;
}

