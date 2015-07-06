//Program to calculate costs for Siemens Advia 120
//Author: Janice Love
//Date: 8/15/2014
//Update: 7-6-2015

#include <iostream>
#include <fstream>
#include <iomanip>
#include "functions.h" 

using namespace std; 


int main ()
{
	ofstream myFile;
	myFile.open("AdviaPrices.txt");
	
	
	double labor = techTime(); 
	double machine = machineCost();
	double contract = maintenance();
	double primer = primerCost();

	double ezWash = ezWashCost();
	double x = controlCost();
		double controls = 3 * x; //high, low, normal controls
	double y =  reticControlCost();
		double reticCONTROLS = 2 * x; //two controls
	double w = reticSOLUTION ();

	double d = defoamer();
	double wbc = diff_timepac();
	double rbc = RBCtimepac();
	double s = shealth_rinse();
		
	double cbc_price = labor + machine + contract + primer + ezWash + controls 
		+ d + wbc + rbc + s;

	double cbc_retic_price = cbc_price + y + w + s + reticCONTROLS;

	double outsideBCM = nonBCM (cbc_price);
	double noAcademic = nonAcademic (cbc_price);

	double retic_nonBCM = nonBCM (cbc_retic_price);
	double retic_outside = nonAcademic (cbc_retic_price); 

	myFile << setprecision(4) << endl;
	myFile <<"Siemens Advia" << endl;
	myFile << endl;
	myFile << "CBC PRICES: " << endl;
	myFile << "CBC: $ " << cbc_price << endl; 
	myFile << "CBC + Reticulocyte count: $ " << cbc_retic_price<< endl; 
	myFile << endl;
	myFile << "CBC (non-BCM): $" << outsideBCM << endl;
	myFile << "CBC + Retic count (non-BCM): $ " << retic_nonBCM << endl;
	myFile << endl;
	myFile << "CBC (non-academic): $ " << noAcademic << endl;
	myFile << "CBC + Retic count (non-academic): $ " << retic_outside << endl;
	myFile << endl;



	myFile.close();

	return 0;
}

