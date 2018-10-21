// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1
// Program: CS213-2018-A2-T1.cpp
// Purpose: Demonstrating classes and headers by an example involving matricies.
// Author:  Ahmed Nasr Eldardery, Belal Hamdy Ezzat, Adham Mamdouh Mohammed
// Date:    16 October 2018
// Version: 1

#include <iostream>
#include <iomanip>
#include "matrix.h"

using namespace std;

int main()
{
	cout << left;

	int data1[] = { 1,2,3,4,5,6,7,8 };
	int data2[] = { 13,233,3,4,5,6 };
	int data3[] = { 10,100,10,100,10,100,10,100 };

	//Memory leakage test
	//If the implementation didn't have a destructor this would easily take over 3 GB of memory
	//and would probably crash
	/*
		for (int i = 0; i < 1e4; ++i) {
			matrix test1(160, 128);
			matrix test2(320, 64);
			matrix temp = test1;
			test1 = test2;
			test2 = temp;
			temp = 3 * test1;
			temp = test1 * 11;
			temp = test1 + test2;
		}
	*/

	matrix mat1(4, 2, data1),
		mat2(2, 3, data2),
		mat3(4, 2, data3),
		mat4 = mat3 * 2 + mat1 * 7,
		mat5;
	cout << "Matrix 1 is:" << endl << mat1 << endl;
	cout << "Matrix 2 is:" << endl << mat2 << endl;
	cout << "Matrix 3 is:" << endl << mat3 << endl;
	cout << "Matrix 4 is:" << endl << mat4 << endl;
	cout << "Enter matrix 5, rows columns and then data:" << endl;
	cin >> mat5;
	cout << "Matrix 5 is:" << endl << mat5 << endl;
	cout << "Matrix 1 + Matrix 3:" << endl;
	cout << (mat1 + mat3) << endl << endl;
	cout << "Matrix 3 + Matrix 3:" << endl;
	cout << (mat3 + mat3) << endl << endl;

	cout << "mat4 = 7 * mat1 + mat3 * 2 is: " << ((7 * mat1 + mat3 * 2 == mat4) ? "true" : "false") << endl;
	cout << "++++++mat1:" << endl;
	cout << ++++++mat1 << endl;
	cout << "mat1++:" << endl;
	cout << mat1++ << endl;
	cout << "Matrix 1 is:" << endl << mat1 << endl;
	cout << "mat4 = 7 * mat1 + mat3 * 2 is: " << ((7 * mat1 + mat3 * 2 == mat4) ? "true" : "false") << endl;
	cout << "----mat1:" << endl;
	cout << ----mat1 << endl;

	mat1 += mat3 += mat3;
	cout << "After doing mat1 += mat3 += mat3:" << endl;
	cout << "Matrix 1 is:" << endl << mat1 << endl;
	cout << "Matrix 2 is:" << endl << mat2 << endl;
	cout << "Matrix 3 is:" << endl << mat3 << endl;
	cout << "fail test: (shouldn't output anything)" << endl;
	cout << mat1 + mat2;
	mat1 += mat2;

	return 0;
}
