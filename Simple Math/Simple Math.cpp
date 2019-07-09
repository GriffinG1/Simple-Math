// Simple Math.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "conio.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <utility>

const double clothingAndGardenTax = 0.06, beautyTax = 0.07, groceryAndSchoolTax = 0.03, tobaccoTax = 0.1;

// computes tax
double computeTax(double d, const std::string& str) {
	int categoryAsInt;

	// converts categories to int
	if (str == "clothing" || str == "gardening") categoryAsInt = 1;
	else if (str == "beauty") categoryAsInt = 2;
	else if (str == "grocery" || str == "school") categoryAsInt = 3;
	else if (str == "tobacco") categoryAsInt = 4;
	else categoryAsInt = 0;

	// returns taxed price of each item based on category
	switch (categoryAsInt) {
		case 1:
			return d + d * clothingAndGardenTax;
		case 2:
			return d + d * beautyTax;
		case 3:
			return d + d * groceryAndSchoolTax;
		case 4:
			return d + d * tobaccoTax;
		default:
			return d; // Can't compute tax if no valid category, so just returns price
	}
}

int main()
{
	// Declare variables
	std::string category;
	std::vector<std::pair<double, std::string>> cost;
	double finalCost = 0; 
	size_t dividerLength = 19; // minimum possible divider length

	// Set decimal limits and give instructions for finishing input
	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	std::cout << "Enter 'Finish' as a category to see your final total.\n" << std::endl;
	std::cout << "Categories:\n" << "\tClothing\n" << "\tBeauty\n" << "\tGrocery\n" <<
		"\tGardening\n" << "\tSchool\n" << "\tTobacco\n" << std::endl;

	do { // Loops until "finish" is inputted
		double price, taxPrice;

		// get category
		std::cout << "Enter the most appropriate of the above categories for the item: ";
		std::cin >> category;
		std::transform(category.begin(), category.end(), category.begin(), ::tolower); // lowercase input string to make it idiot proof
		std::cout << std::endl;

		if (category == "finish") break; // ends while loop early
		
		// get price
		std::cout << "Enter price of item: ";
		std::cin >> price;
		std::cout << std::endl;

		// Find tax price, then add the new pair to the vector
		taxPrice = computeTax(price, category);
		cost.emplace_back(taxPrice, category);

		std::cout << "$" << taxPrice << " - item total\n" << std::endl;
	} while (category != "finish");

	for (std::pair<double, std::string> p : cost) { // Adds up total cost
		finalCost += p.first;
		if (p.second.length() + 14 > dividerLength) dividerLength = p.second.length() + 14; // updates divider length to max
		std::cout << "$" << p.first << " - " << p.second << " item" << std::endl; // outputs each taxed price with category
	}

	for (size_t i = 0; i < dividerLength; i++) printf("-"); printf("\n"); // outputs divider

	std::cout << "$" << finalCost << " - total cost\n" << std::endl; // outputs final cost

	// Wait for user input before closing
	std::cout << "Press any key to close the program.";
	_getch();

	return 0;
}