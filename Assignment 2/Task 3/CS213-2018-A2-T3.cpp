// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1
// Program: CS213-2018-A2-T3.cpp
// Purpose: A bignumber class that can handle very large numbers not storable in long long and/or int.
// Author:  Ahmed Nasr Eldardery, Belal Hamdy Ezzat, Adham Mamdouh Mohammed
// Date:    1st November 2018
// Version: 1.0

#include <iostream>
#include "bignumber.h"
using namespace std;

int main()
{
	bignumber a(1234567890);
	bignumber b("-1234567890");
	bignumber c("0001234567890");
	bignumber d("1357923459732");
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a + c << endl;
	cout << a - c << endl;
	cout << a + d << endl;
	cout << a - d << endl;
	cout << b + d << endl;
}
