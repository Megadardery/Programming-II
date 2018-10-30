// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1
// Program: bignumber.h
// Purpose: bignumber class header file
// Author:  Ahmed Nasr Eldardery, Belal Hamdy Ezzat, Adham Mamdouh Mohammed
// Date:    N/A
// Version: N/A

#ifndef _BIGNUMBER_H
#define _BIGNUMBER_H
#include <iostream>
#include <vector>
#include <string>

class bignumber
{
private:
	//digits are stored each in a character, stored in reverse order.
	//for example, "1234" is stored as {4,3,2,1}
	//the actual numbers are stored, not their ascii equivalent.
	std::vector<char> data;
	bool negative = false;
	void clear();
	//helper function gets two numbers a and b,
	//sets first to be a pointer to the absolutly bigger one and second to the other
	friend bool biggersmaller(const bignumber &a, const bignumber &b, const bignumber*& first, const bignumber*& second);

	friend bignumber add_digits(const bignumber& a, const bignumber& b);
	friend bignumber subtract_digits(const bignumber& a, const bignumber& b);

public:
	bignumber();
	bignumber(const std::string& num);
	bignumber(const long long num);

	bool initalize_from_string(const std::string& num);		//returns whether it was successful or not.
	bignumber operator+ (const bignumber& b) const;
	bignumber operator- (const bignumber& b) const;
	bignumber operator- () const;
	bignumber operator+ (const long long& b) const;
	bignumber operator- (const long long& b) const;

	friend std::ostream& operator<<(std::ostream& out, const bignumber& big);
	friend std::istream& operator>>(std::istream& in, bignumber& big);
};

#endif
