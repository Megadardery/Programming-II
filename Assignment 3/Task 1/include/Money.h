#ifndef _MONEY_H
#define _MONEY_H
#include <string>
#include <iostream>

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
	const static int COIN_COUNT = 9;
	const static int CoinValue[COIN_COUNT];
	const static std::string CoinNames[COIN_COUNT];
	const static std::string CoinNamesSingular[COIN_COUNT];

	Money(int Quantities[COIN_COUNT]);
	Money(int Quantity = 0);
	Money(const Money& other);

	int getTotalValue() const;

	//to allow money[0]++
	int& operator[](int typeidx);
	int operator[](int typeidx) const;


	Money& operator +=(const Money& other);
	Money& operator -=(const Money& other);

	Money& operator =(const Money& other);

	friend std::ostream& operator << (std::ostream& out, const Money& mon);
protected:
	int quantity[COIN_COUNT];
private:
};

#endif // _MONEY_H