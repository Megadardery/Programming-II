// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1
// Program: bignumber.cpp
// Purpose: bignumber class actual code file
// Author:  Ahmed Nasr Eldardery, Belal Hamdy Ezzat, Adham Mamdouh Mohammed
// Date:    N/A
// Version: N/A

#include "bignumber.h"
void bignumber::clear()
{
	data.clear();
	negative = false;
}

bignumber::bignumber(){}

bignumber::bignumber(const std::string num)
{
	//Belal TODO:
	//Handle '-' at the start of the string, set the "negative" property of bignumber
	int n = num.size();
	data.resize(num.size());
	for (int i = 0; i < n; ++i) {
		int j = n - 1 - i;
		if (num[j] > '9' || num[j] < '0') {
			throw std::invalid_argument("num contains non-numeric values");
			clear();
			return;
		}
		data[i] = num[j] - '0';
	}
}
bignumber::bignumber(const long long num) {
	//Belal TODO:
	//Handle negative values
	long long temp = num;
	while (temp) {
		data.push_back(temp % 10);
		temp /= 10;
	}
}

std::ostream& operator<<(std::ostream& out, const bignumber& big) {
	//Belal TODO:
	//Handle leading zeros in the output.
	//Note, the most useful way would be a seperate function that loops from..
	//..the end of the vector and erases until it encounters a non-zero value
	//DON'T IMPLEMENT IT IN THE CONSTRUCTOR'S CODE

	int n = big.data.size();
	if (big.negative) out << "-";
	for (int i = 0; i < n; ++i) {
		out << char(big.data[n - 1 - i] + '0');
	}
	return out;
}

std::istream& operator>>(std::istream& in, bignumber& big) {
	//Belal TODO
	//Implement the function, don't forget the negative values
	//Might be a wise idea to just read the input as a string and use the constructor's code
	//Also, give this a read: https://stackoverflow.com/questions/2166099

	return in;
}
