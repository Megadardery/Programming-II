// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1
// Program: bignumber.cpp
// Purpose: bignumber class actual code file
// Author:  Ahmed Nasr Eldardery, Belal Hamdy Ezzat, Adham Mamdouh Mohammed
// Date:    N/A
// Version: N/A

#include "bignumber.h"

void bignumber::clear() {
	data.clear();
	negative = false;
}

bool bignumber::initalize_from_string(const std::string& num) {
	int n = num.size();
	data.resize(n);
	for (int i = 0; i < n; ++i) {
		int j = n - 1 - i;					//j moves the opposite direction of i
		if (j == 0 && num[j] == '-') {		//if the first character in the num is a negative sign
			negative = 1;
			data.pop_back();
		}
		else if (num[j] > '9' || num[j] < '0') {
			clear();
			return false;
		}
		else
			data[i] = num[j] - '0';
	}
	//remove leading zeros
	while (!data.empty() && data.back() == 0)
		data.pop_back();
	//remove the negative sign if the number is zero.
	if (data.empty())
		negative = 0;

	return true;
}

bignumber::bignumber() {}

bignumber::bignumber(const std::string& num) {
	initalize_from_string(num);
}
bignumber::bignumber(const long long num) {
	negative = (num < 0);
	long long temp = negative ? -num : num;
	while (temp) {
		data.push_back(temp % 10);
		temp /= 10;
	}
}

bignumber bignumber::operator-(const bignumber& b) const {
	if (b.negative != negative)
		return add_digits(*this, b);
	else
		return subtract_digits(*this, b);
}
bignumber bignumber::operator-() const
{
	bignumber temp = *this;
	temp.negative = !temp.negative;
	return temp;
}
bignumber bignumber::operator+(const long long & b) const
{
	//TODO : plus operator for long long

	return bignumber();
}
bignumber bignumber::operator-(const long long & b) const
{
	//TODO : plus operator for long long


	return bignumber();
}
bignumber bignumber::operator+ (const bignumber &b) const {
	if (b.negative == negative)
		return add_digits(*this, b);
	else
		return subtract_digits(*this, b);
}
bignumber add_digits(const bignumber& a, const bignumber& b) {
	const bignumber* first;
	const bignumber* second;
	//after this call, first contains the bigger number, and second is the smaller
	bool ret = biggersmaller(a, b, first, second);
	
	bool negative = a.negative;

	int n = first->data.size(), m = second->data.size();
	bignumber res;
	res.negative = negative;

	bool carry = 0;
	for (int i = 0; i < n; ++i) {
		char second_val = 0;
		if (i < m)
			second_val = second->data[i];

		char digit = first->data[i] + second_val + carry;
		
		carry = 0;
		if (digit >= 10) {
			digit -= 10;
			carry = 1;
		}

		res.data.push_back(digit);
	}
	if (carry) res.data.push_back(carry);

	return res;
}

bignumber subtract_digits(const bignumber& a, const bignumber& b) {
	const bignumber* first;
	const bignumber* second;
	//after this call, first contains the bigger number, and second is the smaller
	bool ret = biggersmaller(a, b, first, second);
	//if a swap occured, the sign is inverted
	bool negative = ret ^ a.negative;

	int n = first->data.size(), m = second->data.size();
	bignumber res;
	res.negative = negative;

	bool borrow = 0;
	for (int i = 0; i < n; i++) {
		char second_val = 0;
		if (i < second->data.size())
			second_val = second->data[i];

		char digit = first->data[i] - borrow - second_val;

		borrow = 0;
		if (digit < 0) {
			digit += 10;
			borrow = 1;
		}

		res.data.push_back(digit);
	}
	while (!res.data.empty() && res.data.back() == 0)
		res.data.pop_back();

	return res;

}

bool biggersmaller(const bignumber &a, const bignumber &b, const bignumber*& first, const bignumber*& second) {
	int n = a.data.size(), m = b.data.size();
	bool swap = 0;
	if (n < m)	//if a has fewer digits than b
		swap = 1;
	else if (n == m) {
		while (--n >= 0) {	//check digit by digit
			if (a.data[n] < b.data[n]) {
				swap = 1;
				break;
			}
			else if (a.data[n] > b.data[n])
				break;
		}
	}

	if (swap) {
		first = &b;
		second = &a;
		return true;
	}
	else {
		first = &a;
		second = &b;
		return false;
	}
}

std::ostream& operator<<(std::ostream& out, const bignumber& big) {
	if (big.data.empty())
		return out << "0";
	int n = big.data.size();
	if (big.negative) out << "-";
	for (int i = 0; i < n; ++i) {
		out << char(big.data[n - 1 - i] + '0');
	}
	return out;
}

std::istream& operator>>(std::istream& in, bignumber& big) {
	std::string num;
	in >> num;
	
	big.initalize_from_string(num);

	return in;
}
