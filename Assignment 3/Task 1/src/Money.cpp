#include "Money.h"
#define max(a,b) ((a)>(b)? (a) : (b))

const int Money::CoinValue[] =
{ 25,50,100,500,1000,2000,5000,10000,20000 }; // values of the coins
const std::string Money::CoinNames[] =
{ "Quarters", "Halfs", "Ones", "Fives", "Tens",
  "Twenties", "Fifties", "Hundreds", "Two Hundreds" }; // names of the coins in plural

const std::string Money::CoinNamesSingular[] =
{ "Quarter", "Half", "One", "Five", "Ten",
  "Twenty", "Fifty", "Hundred", "Two Hundred" }; // names of the coins in single

  // takes array of quantities and put it in the coins quantities as it may be different not the same quantity for all
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

// if all quantities are the same then it takes the quantity and put it in the array directly
Money::Money(int Quantity)
{
	for (int i = 0; i < COIN_COUNT; ++i) {
		quantity[i] = Quantity;
	}
}
// copy constructor
Money::Money(const Money & other)
{
	*this = other;
}
// gets the total money in the machine
int Money::getTotalValue() const
{
	int sum = 0;
	for (int i = 0; i < COIN_COUNT; ++i) {
		sum += CoinValue[i] * quantity[i];
	}
	return sum;
}
// accessing the quantities of the item by square brackets operator
int& Money::operator[](int typeidx)
{
	return quantity[typeidx];
}
// same as the above but to make " ++ " operator runs
int Money::operator[](int typeidx) const
{
	return quantity[typeidx];
}
// adds the quantities of other coins to the current quantities
Money& Money::operator+=(const Money & other)
{
	for (int i = 0; i < COIN_COUNT; ++i) {
		quantity[i] += other.quantity[i];
	}
	return *this;
}
// subtracts the quantities of other coins to the current quantities
Money& Money::operator-=(const Money & other)
{
	for (int i = 0; i < COIN_COUNT; ++i) {
		quantity[i] -= other.quantity[i];
		if (quantity[i] < 0)
			quantity[i] = 0;
	}
	return *this;
}
// equates the quantities of other coins to the current quantities
Money& Money::operator=(const Money& other)
{
	for (int i = 0; i < COIN_COUNT; ++i) {
		quantity[i] = other.quantity[i];
	}
	return *this;
}
// printing the current money of the machine regarding the singular and plural
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
