// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1
// Program: matrix.cpp
// Purpose: The actual file containing code for the matrix class
// Author:  Ahmed Nasr Eldardery, Belal Hamdy Ezzat, Adham Mamdouh Mohammed
// Date:    16 October 2018
// Version: 1

#include "matrix.h"

void matrix::allocate_memory(const int r, const int c)
{
	row = r;
	col = c;
	if (row + col == 0) return;	//An empty matrix should not be initialized.

	data = new int[row*col];
}

matrix::matrix(const int r, const int c)
{
	allocate_memory(r, c);
}

matrix::matrix(const int row, const int col, const int * num) : matrix(row, col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			(*this)[i][j] = *(num++);
}

matrix::matrix(const matrix & old)
{
	*this = old;
}

matrix::matrix(matrix && old)
{
	*this = std::move(old);
}

//deep copy by new allocation and copying each item
matrix & matrix::operator=(const matrix & old)
{
	if (this->row + this->col != 0)
		this->~matrix();

	allocate_memory(old.row, old.col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			(*this)[i][j] = old[i][j];
	}
	return *this;
}

//old is disposable, so we make this point to the old data and mark the old matrix as empty
matrix & matrix::operator=(matrix && old)
{
	this->~matrix();
	data = old.data;
	row = old.row; col = old.col;
	old.row = old.col = 0;
	return *this;
}

//if a 2d array is stored within a 1D array, items can be accessed using i*col + j
//so we can use an overloaded [] operator to transorm the 1D array to 2D.
inline int * matrix::operator[](int i) const
{
	return data + i * col;
}

matrix matrix::operator+(const matrix & mat) const
{
	matrix matx = *this;
	matx += mat;
	return matx;
}

matrix matrix::operator-(const matrix & mat) const
{
	matrix matx = *this;
	matx -= mat;
	return matx;
}

matrix matrix::operator*(const matrix & mat) const
{
	if (col != mat.row) return matrix(0, 0);
	matrix matx(row, mat.col);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < mat.col; ++j)
			for (int k = 0; k < col; ++k)
				matx[i][j] += (*this)[i][k] * mat[k][j];

	return matx;
}

matrix matrix::operator+(const int scalar) const
{
	matrix mat = *this;
	mat += scalar;
	return mat;
}

matrix matrix::operator-(const int scalar) const
{
	matrix mat = *this;
	mat -= scalar;
	return mat;
}

matrix matrix::operator*(const int scalar) const
{
	matrix mat = *this;
	mat *= scalar;
	return mat;
}

matrix matrix::operator-() const
{
	matrix mat = *this;
	mat *= -1;
	return mat;
}

matrix & matrix::operator+=(const matrix & mat)
{
	if (col != mat.col || row != mat.row)
		return *this = matrix(0, 0);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			(*this)[i][j] += mat[i][j];
	return *this;
}

matrix & matrix::operator-=(const matrix & mat)
{
	if (col != mat.col || row != mat.row)
		return *this = matrix(0, 0);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			(*this)[i][j] -= mat[i][j];
	return *this;
}

matrix & matrix::operator*=(const matrix & mat)
{
	return *this = *this * mat;
}

matrix & matrix::operator+=(const int scalar)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			(*this)[i][j] += scalar;
	return *this;
}

matrix & matrix::operator-=(const int scalar)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			(*this)[i][j] -= scalar;
	return *this;
}

matrix & matrix::operator*=(const int scalar)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			(*this)[i][j] *= scalar;
	return *this;
}

matrix & matrix::operator++()
{
	return *this += 1;
}
//dummy variable int to distinguish the postfix++
matrix & matrix::operator++(int)
{
	matrix tmp(*this);
	++(*this);
	return tmp;
}

matrix & matrix::operator--()
{
	return *this -= 1;
}

matrix & matrix::operator--(int)
{
	matrix tmp(*this);
	--(*this);
	return tmp;
}

bool matrix::operator==(const matrix & mat) const
{
	if (col != mat.col || row != mat.row) return false;
	for (int i = 0; i < mat.row; ++i)
		for (int j = 0; j < mat.col; ++j)
			if ((*this)[i][j] != mat[i][j])
				return false;

	return true;
}

bool matrix::operator!=(const matrix & mat) const
{
	return !(*this == mat);
}

bool matrix::is_square() const
{
	return row == col;
}

bool matrix::is_symetric() const
{
	if (!is_square()) return false;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if ((*this)[j][i] != (*this)[i][j]) return false;
	return true;
}

bool matrix::is_identity() const
{
	if (!is_square()) return false;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if ((*this)[i][j] != (i == j)) return false;
	//(i==j) is one when we are on the main diagonal, which should be filled with ones
	// if it is identity.
	return true;
}

matrix matrix::transpose() const
{
	matrix newmat(col, row);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			newmat[j][i] = (*this)[i][j];
	return newmat;
}

matrix::~matrix()
{
	if (row + col != 0)
		delete[] data;
}

matrix operator+(const int scalar, const matrix & mat)
{
	return mat + scalar;
}

matrix operator-(const int scalar, const matrix & mat)
{
	return mat - scalar;
}

matrix operator*(const int scalar, const matrix & mat)
{
	return mat * scalar;
}

std::istream & operator>>(std::istream & in, matrix & mat)
{
	int row, col;
	in >> row >> col;
	mat.allocate_memory(row, col);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			in >> mat[i][j];
	return in;
}

std::ostream & operator<<(std::ostream & out, const matrix & mat)
{
	for (int i = 0; i < mat.row; ++i) {
		for (int j = 0; j < mat.col; ++j)
			out << std::setw(5) << mat[i][j];
		out << '\n';
	}
	return out;
}
