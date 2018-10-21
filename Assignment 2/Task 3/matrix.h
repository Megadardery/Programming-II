// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1
// Program: matrix.h
// Purpose: Header file for the matrix class
// Author:  Ahmed Nasr Eldardery, Belal Hamdy Ezzat, Adham Mamdouh Mohammed
// Date:    16 October 2018
// Version: 1

#ifndef _MATRIX_H
#define _MATRIX_H

#include <iostream>
#include <iomanip>

class matrix
{
private:
	int* data;
	int row = 0, col = 0;
	//allocates dynamic memory into the data pointer
	void allocate_memory(const int r, const int c);

public:
	// a constructor that takes the rows and columns count and initializes the memory with zeros.
	matrix(const int r = 0, const int c = 0);
	// a constructor that takes the rows and columns count and initializes the memory with memory from the 1D num array.
	matrix(const int row, const int col, const int* num);

	// a copy constructor, used when 'matrix mat = mat1;' is called
	matrix(const matrix& old);
	// a move constructor, used when old is disposable, such as the return value of a function. 
	matrix(matrix&& old);

	// = operators similar to the above two constructor
	matrix& operator=(const matrix& old);
	matrix& operator=(matrix&& old);

	//overloaded the [] operators so that the matrix' data can be accessed using
	//mat[i][j] instead of mat.data[i*n + j].
	int* operator[] (int i) const;

	//basic arithmetic operations between two matricies. 
	matrix operator+ (const matrix& mat) const;
	matrix operator- (const matrix& mat) const;
	matrix operator* (const matrix& mat) const;

	//basic arithmetic operations between a matrix and a scalar
	matrix operator+ (const int scalar) const;
	matrix operator- (const int scalar) const;
	matrix operator* (const int scalar) const;
	
	//same as above but with the order of the operands reversed
	friend matrix operator+(const int scalar, const matrix& mat);
	friend matrix operator-(const int scalar, const matrix& mat);
	friend matrix operator*(const int scalar, const matrix& mat);

	//unary negative operator
	matrix operator- () const;

	//compound operators for arithmetic operations with a matrix
	matrix& operator+= (const matrix& mat);
	matrix& operator-= (const matrix& mat);
	matrix& operator*= (const matrix& mat);

	//compound operators for arithmetic operations with a scalar
	matrix& operator+= (const int scalar);
	matrix& operator-= (const int scalar);
	matrix& operator*= (const int scalar);

	//postfix and prefix increment and decrement operators
	matrix& operator++ ();
	matrix& operator++ (int);
	matrix& operator-- ();
	matrix& operator-- (int);

	//iostream handling
	//for input, you first enter the rows and columns then you enter the data.
	friend std::istream& operator>> (std::istream& in, matrix& mat);
	friend std::ostream& operator<< (std::ostream& out, const matrix& mat);

	//comparison operators between two matrices
	bool operator== (const matrix& mat) const;
	bool operator!= (const matrix& mat) const;


	bool is_square() const;
	bool is_symetric() const;
	bool is_identity() const;
	matrix transpose() const;

	~matrix();
};
#endif
