/*
Ethan Chen
July 27, 2020

This is a program that calculates the roots of a quadratic equation
in the form of ax^2 + bx + c.

The user inputs the values of the coefficients a, b, and c, and the
program prints out the roots.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Roots {
public:
	Roots() {
		root1 = "";
		root2 = "";
	}
	bool isValid(const string& input) {
		int numDec = 0;
		if (input.size() == 0) {
			return false;
		}
		if (input.size() == 1 && input[0] == '-') {
			return false;
		}
		for (int a = 0; a < (int)input.size(); a++) {
			if (input[a] == '.') {
				numDec++;
			}else if ((int)input[a] < 48 || (int)input[a] > 57) {
				if (a != 0 || input[a] != '-') {
					return false;
				}
			}
		}
		return numDec < 2;
	}
	double inputHelper(string& prompt) {
		cout << prompt;
		string input;
		cin >> input;
		while (!isValid(input)) {
			cout << "Input must be a valid number" << endl << endl;
			cout << "The input can be a positive or negative number with up to a single decimal point" << endl;
			cout << "The input cannot contain any letters or other invalid characters" << endl;
			cout << "Example: -30.45 <-- valid" << endl;
			cout << "Example: f3-.4 <-- invalid" << endl << endl;
			cout << prompt;
			cin >> input;
		}
		return stod(input);
	}
	void getInput() {
		cout << "This is a tool to calculate roots of quadratic equations" << endl;
		cout << "in the form of ax^2 + bx + c" << endl;
		cout << "You will be prompted to enter the values for each coefficient, one by one," << endl;
		cout << "then the results of the roots will be printed" << endl << endl;
		string prompt1 = "\nEnter the value for a, the first coefficient: ";
		string prompt2 = "\nEnter the value for b, the second coefficient: ";
		string prompt3 = "\nEnter the value for c, the third coefficient: ";
		a = inputHelper(prompt1);
		b = inputHelper(prompt2);
		c = inputHelper(prompt3);
	}
	void calculate() {
		double x1 = (-b) / (2 * a);
		double x2 = (-b) / (2 * a);
		double discr = b * b - 4 * a*c;
		if (discr >= 0) {
			x1 += (sqrt(discr)) / (2 * a);
			x2 -= (sqrt(discr)) / (2 * a);
			root1 = to_string(x1);
			root2 = to_string(x2);
		}
		else {
			root1 = to_string(x1) + " + " + to_string(abs((sqrt(-discr)) / (2 * a))) + "i";
			root2 = to_string(x2) + " - " + to_string(abs((sqrt(-discr)) / (2 * a))) + "i";
		}
	}
	void printResults() {
		cout << "Here are your results: " << endl;
		cout << "The first root: " << root1 << endl;
		cout << "The second root: " << root2 << endl;
	}
private:
	double a;
	double b;
	double c;
	string root1;
	string root2;
};

int main() {
	Roots r;
	r.getInput();
	r.calculate();
	r.printResults();
	return 0;
}