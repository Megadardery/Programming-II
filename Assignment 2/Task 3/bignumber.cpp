// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1
// Program: bignumber.cpp
// Purpose: bignumber class actual code file
// Author:  Ahmed Nasr Eldardery, Belal Hamdy Ezzat, Adham Mamdouh Mohammed
// Date:    N/A
// Version: N/A

#include "bignumber.h"
void bignumber::clear(){
	data.clear();
	negative = false;
}

bignumber::bignumber() {}

bignumber::bignumber(const std::string num){

	int n = num.size();
	data.resize(num.size());
	for (int i = 0; i < n; ++i) {
		int j = n - 1 - i;
		if (!j && num[j] == '-') {
			negative = 1;
			data.pop_back();
		}
		else if (num[j] > '9' || num[j] < '0') {
			throw std::invalid_argument("num contains non-numeric values");
			clear();
			return;
		}
		else
			data[i] = num[j] - '0';
	}
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
bignumber bignumber::operator+ (const bignumber &b) const {
	if (b.negative == negative)
		return add_digits(*this, b);
	else
		return subtract_digits(*this, b);
}
bignumber add_digits(const bignumber& a, const bignumber& b) {
	const bignumber* first = &a;
	const bignumber* second = &b;
	biggersmaller(a, b, first, second);
	bignumber res;
	res.negative = first->negative;
	//Adham TODO:
	//|first| guarenteed bigger than or equal to |second|
	//implement adding digits and stuff
	int n = first->data.size(), m = second->data.size();
	bool carry = 0;	
	
	for (int i = 0; i < n; ++i) {
		
		char second_val = 0;
		if (i < second->data.size())
			second_val = second->data[i];
		char digit = first->data[i] + second_val + carry;
		(digit >= 10) ? digit -= 10, carry = 1 : carry = 0;
		
		res.data.push_back(digit);
		
		if(carry && i == n-1) res.data.push_back(carry);

	}

	return res;
}
bignumber subtract_digits(const bignumber& a, const bignumber& b) {
	const bignumber* first = &a;
	const bignumber* second = &b;
	//after this call, first contains the bigger number, and second is the smaller
	bool ret = biggersmaller(a, b, first, second);
	//if a swap occured, the sign is inverted
	bool negative = ret ^ first->negative;

	int n = first->data.size(), m = second->data.size();
	bignumber res;
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

	res.negative = negative;
	return res;

}

bool biggersmaller(const bignumber &a, const bignumber &b, const bignumber*& first, const bignumber*& second) {
	first = &a;
	second = &b;

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
		const bignumber* temp = second;
		second = first;
		first = temp;
	}
	return swap;
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
		
	new (&big) bignumber(num);
}



