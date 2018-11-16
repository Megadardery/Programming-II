// Course:  CS213 - Programming II  - 2018
// Title:   Assignment 3 - Task 2 - Problem 4
// Program: Problem 4.cpp
// Purpose: Recursive Pascal Triangle
// Author:  Ahmed Nasr Eldardery
// Date:    16 October 2018
// Version: 1

#include <iostream>
using namespace std;

int Pascal(int n, int k) {
	if (k < 0 || k > n) return 0;
	if (n == 0) return 1;
	return Pascal(n - 1, k - 1) + Pascal(n - 1, k);
}

int main() {
	int n, k;
	while (true) {
		cout << "Enter n, and k: ";
		cin >> n >> k;
		cout << "Result is: " << Pascal(n, k) << endl;
	}
}
