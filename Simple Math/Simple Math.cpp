// Simple Math.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "conio.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

const double clothingAndGardenTax = 0.06, beautyTax = 0.07, groceryAndSchoolTax = 0.03, tobaccoTax = 0.1;

// Handles switch statement, including converting categories to int values
double computeTax(double d, const std::string& str) {
	int switchVal;
	if (str == "clothing" || str == "garden") switchVal = 1;
	else if (str == "beauty") switchVal = 2;
	else if (str == "grocery" || str == "school") switchVal = 3;
	else if (str == "tobacco") switchVal = 4;
	else switchVal = 0;
	switch (switchVal) {
		case 1:
			return d + d * clothingAndGardenTax;
		case 2:
			return d + d * beautyTax;
		case 3:
			return d + d * groceryAndSchoolTax;
		case 4:
			return d + d * tobaccoTax;
		default:
			return d;
	}
}

int main()
{
	// Declare variables
	std::string category;
	std::vector<double> cost;
	double finalCost = 0;

	// Set decimal limits and give instructions for finishing input
	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	std::cout << "Enter 'Finish' as a category to see your final total.\n" << std::endl;

	do { // Loops until "finish" is inputted
		double price, taxPrice;
		std::cout << "Categories:\n" << "\tClothing\n" << "\tBeauty\n" << "\tGrocery\n" <<
			"\tGardening\n" << "\tSchool\n" << "\tTobacco\n\n" <<
			"Enter the most appropriate of the above categories for the item: ";
		std::cin >> category;
		std::transform(category.begin(), category.end(), category.begin(), ::tolower); // lowercase input string to make it idiot proof
		std::cout << std::endl;

		if (category == "finish") break;
		std::cout << "Enter price of item: ";
		std::cin >> price;
		std::cout << std::endl;

		taxPrice = computeTax(price, category);
		cost.push_back(taxPrice);
	} while (category != "finish");

	for (double d : cost) { // Adds up total cost
		finalCost += d;
	}
	std::cout << "Final Cost: $" << finalCost << std::endl;

	// Wait for user input before closing
	std::cout << "Press any key to close the program.";
	_getch();

	return 0;
}