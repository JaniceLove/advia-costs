//functions to calc costs for advia machine
//Date: 1-27-2015

#include "functions.h" 
#include <iostream> 
#include <string> 

using namespace std; 

//Costs updated: April 30, 2015

double techTime()
{
	double hourlyCost = 23.38; // per CCM
	double timePerHour = (0.5); //approx. 30 minutes to run controls, enter data, get results
	double timeCost = hourlyCost * timePerHour; 
	return timeCost; 
}

double machineCost()
{
	//depreciated value in terms of cost per sample
	double price = 64355; //purchased in 2013 
	double years = 8; // from BCM intranet, property control
	double depreciation_per_year = ( 64355 / years ); 
	double daysUsed = 52 * 5; 
	double testsPerDay = 10;

	double cost = depreciation_per_year / daysUsed / testsPerDay; 
	return cost;
} 

double primerCost ()
{
	double price = 49.33;
	double perVial = price / 25;
	double perDay = perVial * (1/3);
	double cost = perDay * 5;
	return cost;
}

double ezWashCost()
{
	double ezWash_cost = 43.53;
	double perBottle = ezWash_cost / 2; 
	double perDay = perBottle / 14;
	double average = perDay / 10; 
	return average; 
}

double controlCost()
{
	double price = 247.18;
	double oneFourth = price / 4;
	double priceWeek = oneFourth / 5;
	double average = priceWeek / 10; 
	return average; 
}

double reticControlCost()
{
	double price = 148.99;
	double oneFourth = price / 4;
	double priceWeek = oneFourth / 5;
	double average = priceWeek / 10; 
	return average; 
}

double reticSOLUTION()
{
	double price = 665.53;
	double no_tests = 600;
	double per_test = price / no_tests;
	return per_test;
}

double defoamer ()
{ 
	//cost per test
	double price = 93.18;
	double priceEach = price / 4; //pack of 4
	double days = 20; //one bottle per month, 5 days/week
	double samples = 5; //average 5 samples/day
	double tSamples = days * samples; //total samples per bottle
	double perRun = priceEach / tSamples;
	return perRun; 
}

double diff_timepac()
{
	//cost per test
	double price = 283.12;
	double onboard = 60; //60 days in machine
	double samplesDay = 5;
	double samples = samplesDay * onboard;
	double cost = price / samples;
	return cost;
}

double shealth_rinse ()
{
	//cost per test
	double price = 66.87;
	double quantity = 700; // no of tests
	double cost = price / quantity;
	return cost;
}

double RBCtimepac()
{
	double price = 246.75;
	double onboard = 60; //60 days in machine
	double samplesDay = 5;
	double samples = samplesDay * onboard;
	double cost = price / samples;
	return cost;
}

double nonBCM (double yy)
{
	double x = yy * 0.25; 
	double price = yy + x; 
	return price;
}

double nonAcademic (double aa)
{
	double b = aa * 0.5;
	double price = aa + b;
	return price;
}

