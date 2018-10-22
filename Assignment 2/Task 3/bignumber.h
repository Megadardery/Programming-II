// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1
// Program: bignumber.h
// Purpose: bignumber class header file
// Author:  Ahmed Nasr Eldardery, Belal Hamdy Ezzat, Adham Mamdouh Mohammed
// Date:    N/A
// Version: N/A

#ifndef _BIGNUMBER_H
#define _BIGNUMBER_H
#include <vector>
#include <iostream>

class bignumber
{
private:
	std::vector<char> data;
	bool negative = false;
	void clear();
	friend bool biggersmaller(const bignumber &a, const bignumber &b, const bignumber*& first, const bignumber*& second);
	friend bignumber add_digits(const bignumber& a, const bignumber& b);
	friend bignumber subtract_digits(const bignumber& a, const bignumber& b);

public:
	bignumber();
	bignumber(const std::string num);
	bignumber(const long long num);
	bignumber operator+ (const bignumber& b) const;
	bignumber operator- (const bignumber& b) const;
	//bignumber operator+ (const long long& b) const;
	//bignumber operator- (const long long&W b) const;

	friend std::ostream& operator<<(std::ostream& out, const bignumber& big);
	friend std::istream& operator>>(std::istream& in, bignumber& big);
};

#endif
