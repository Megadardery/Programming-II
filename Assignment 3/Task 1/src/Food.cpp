#include "Food.h"
#define max(a,b) ((a)>(b)? (a) : (b))
// default constructor for the food that makes the quantity and price and name is nothing
Food::Food() {
	qty = price = 0;
	name = "";
}
// constructor that builds the item and making sure that there's no negative inputs
Food::Food(std::string n, int p, int q) {
	qty = max(q, 0);
	price = max(p, 0);
	name = n;
}

Food::Food(std::string n, double priceInPounds, int q)
{
	int priceInPiasters = priceInPounds * 100; //converts the pounds to piasters
	priceInPiasters = (priceInPiasters + 24) / 25;
	priceInPiasters *= 25; // gets the ceil of the price in piasters to prevent truncation errors

	qty = max(q, 0); // making sure that the quantity is positive
	price = max(priceInPiasters, 0); // making sure that the price is positive
	name = n;
}

int Food::getPrice() const {
	return price;
}

std::string Food::getName() const {
	return name;
}

int Food::getQuantity() const {
	return qty;
}
// taking one item from the warehouse but making sure first that there is available items to take from
void Food::takeOne() {
	if (qty > 0)
		qty--;
}
