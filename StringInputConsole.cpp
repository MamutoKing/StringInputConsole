/*
Program: ConcatenationApp
Author: Cameron
Date: 2023-10-01
Description: 
	This program demonstrates string concatenation in C++.
	Accepts two strings from user input
	concatenates strings together
	Repeat process 3 times

Security Considerations:
	Limit input length to prevent buffer overflow.
	prevent empty input
	Check for input stream failure
	Check combined string length before concatenation
*/
#include <iostream>
#include <string>

int main() {

	//Limit number of Characters to 100
	const size_t MAX_CHARS = 100;

	//Variables to hold user input + Resulting concatenated string
	std::string firstString;
	std::string secondString;
	std::string concatString;

	std::cout << "----------String Concatenation App----------" << std::endl;

	//Repeat the process 3 times
	for (int iteration = 1; iteration <= 3; iteration++) {

		std::cout << "\nInput Set #" << iteration << std::endl;

		//Get First String
		while (true) {
			std::cout << "Enter the First String: ";

			//Detect input stream failures
			if (!std::getline(std::cin, firstString)) {
				std::cerr << "Error: Input Failure." << std::endl;
				return 1;
			}

			//Prevent empty input
			if (firstString.empty()) {
				std::cout << "Input cannot be empty. Please try again.\n";
				continue;
			}

			//Prevent Excessively large input
			if (firstString.length() > MAX_CHARS) {
				std::cout << "Input Exceeds " << MAX_CHARS << " characters. Try again.\n";
				continue;
			}

			//Input passed validation
			break;
		}

		//Get Second String
		while (true) {
			std::cout << "Enter the Second String: ";

			//Detect input stream failures
			if (!std::getline(std::cin, secondString)) {
				std::cerr << "Error: Input Failure." << std::endl;
				return 1;
			}

			//Prevent empty input
			if (secondString.empty()) {
				std::cout << "Input cannot be empty. Please try again.\n";
				continue;
			}

			//Prevent Excessively large input
			if (secondString.length() > MAX_CHARS) {
				std::cout << "Input Exceeds " << MAX_CHARS << " characters. Try again.\n";
				continue;
			}

			//Input passed validation
			break;
		}

		//Confirm combined length meets parameters
		if ((firstString.length() + secondString.length() + 1) > (MAX_CHARS * 2)) {
			std::cout << "Combined string would be excessively large." << "Operation skipped.\n";
			continue;
		}
		//Concatenate the strings with a space between them
		concatString = firstString + " " + secondString;

		//Display Results
		std::cout << "\nCombined String: " << concatString << std::endl;
		std::cout << "Length of First String: " << firstString.length() << std::endl;
		std::cout << "Length of Second String: " << secondString.length() << std::endl;
		std::cout << "Length of combined String: " << concatString.length() << std::endl;
	}
	std::cout << "\nProgram Complete." << std::endl;

	return 0;
}
	
