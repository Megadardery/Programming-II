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
public:
	bignumber();
	bignumber(const std::string num);
	bignumber(const long long num);
	//bignumber operator+ (const bignumber b);
	//bignumber operator- (const bignumber b);
	//bignumber operator+ (const long long b);
	//bignumber operator- (const long long b);

	friend std::ostream& operator<<(std::ostream& out, const bignumber& big);
	friend std::istream& operator>>(std::istream& in, bignumber& big);
};

#endif
