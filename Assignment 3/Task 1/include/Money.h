#ifndef _MONEY_H
#define _MONEY_H
#include <string>
#include <iostream>
// enum to access the array by the name of currency
enum CoinIndex {
	QUARTERS = 0,
	HALFS,
	ONES,
	FIVES,
	TENS,
	TWENTIES,
	FIFTIES,
	HUNDREDS,
	TWO_HUNDREDS
};
class Money
{
public:
	const static int COIN_COUNT = 9; // maximum number of coins in the machine
	const static int CoinValue[COIN_COUNT]; // array that holds the currency values
	const static std::string CoinNames[COIN_COUNT]; // holds the names of the currency in plural
	const static std::string CoinNamesSingular[COIN_COUNT]; // also holds the names of currency but in single

	Money(int Quantities[COIN_COUNT]); // if the quantities of currency are different
	Money(int Quantity = 0); // if the quantities of currency are same
	Money(const Money& other); // copy constructor for this class

	int getTotalValue() const;

	//to allow money[0]++
	int& operator[](int typeidx);
	int operator[](int typeidx) const;


	Money& operator +=(const Money& other);
	Money& operator -=(const Money& other);

	Money& operator =(const Money& other);

	friend std::ostream& operator << (std::ostream& out, const Money& mon); // operator to print the quantities
protected:
	int quantity[COIN_COUNT];
private:
};

#endif // _MONEY_H
