#include "Money.h"
#define max(a,b) ((a)>(b)? (a) : (b))

const int Money::CoinValue[] =
{ 25,50,100,500,1000,2000,5000,10000,20000 };
const std::string Money::CoinNames[] =
{ "Quarters", "Halfs", "Ones", "Fives", "Tens",
  "Twenties", "Fifties", "Hundreds", "Two Hundreds" };

const std::string Money::CoinNamesSingular[] =
{ "Quarter", "Half", "One", "Five", "Ten",
  "Twenty", "Fifty", "Hundred", "Two Hundred" };

Money::Money(int Quantities[COIN_COUNT])
{
	if (Quantities == nullptr) {
		for (int i = 0; i < COIN_COUNT; ++i) {
			quantity[i] = 0;
		}
	}
	else {
		for (int i = 0; i < COIN_COUNT; ++i) {
			quantity[i] = Quantities[i];
		}
	}
}

Money::Money(int Quantity)
{
	for (int i = 0; i < COIN_COUNT; ++i) {
		quantity[i] = Quantity;
	}
}

Money::Money(const Money & other)
{
	*this = other;
}

int Money::getTotalValue() const
{
	int sum = 0;
	for (int i = 0; i < COIN_COUNT; ++i) {
		sum += CoinValue[i] * quantity[i];
	}
	return sum;
}

int& Money::operator[](int typeidx)
{
	return quantity[typeidx];
}

int Money::operator[](int typeidx) const
{
	return quantity[typeidx];
}

Money& Money::operator+=(const Money & other)
{
	for (int i = 0; i < COIN_COUNT; ++i) {
		quantity[i] += other.quantity[i];
	}
	return *this;
}

Money& Money::operator-=(const Money & other)
{
	for (int i = 0; i < COIN_COUNT; ++i) {
		quantity[i] -= other.quantity[i];
		if (quantity[i] < 0)
			quantity[i] = 0;
	}
	return *this;
}

Money& Money::operator=(const Money& other)
{
	for (int i = 0; i < COIN_COUNT; ++i) {
		quantity[i] = other.quantity[i];
	}
	return *this;
}

std::ostream & operator<<(std::ostream & out, const Money & mon)
{
	int value = mon.getTotalValue();
	if (value == 0) return out << "No money";
	for (int i = Money::COIN_COUNT - 1; i >= 0; i--) {
		if (mon[i]) {
			if (mon[i] == 1)
				out << mon[i] << " " << Money::CoinNamesSingular[i];
			else
				out << mon[i] << " " << Money::CoinNames[i];

			value -= mon[i] * Money::CoinValue[i];

			if (value != 0)
				out << ", ";
		}
	}
	return out;
}
