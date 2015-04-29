//functions to calc costs for advia machine
//Date: 1-27-2015

#include "functions.h" 
#include <iostream> 
#include <string> 

using namespace std; 

double techTime()
{
	double hourlyCost = 23.38; // per CCM
	double timePerHour = (1/3); //approx. 20 minutes to run controls, enter data, get results
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
	return perDay; 
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