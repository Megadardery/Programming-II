#include "Food.h"
#define max(a,b) ((a)>(b)? (a) : (b))

Food::Food() {
	qty = price = 0;
	name = "";
}
Food::Food(std::string n, int p, int q) {
	qty = max(q, 0);
	price = max(p, 0);
	name = n;
}

Food::Food(std::string n, double priceInPounds, int q)
{
	int priceInPiastres = priceInPounds * 100;
	priceInPiastres = (priceInPiastres + 24) / 25;
	priceInPiastres *= 25;

	qty = max(q, 0);
	price = max(priceInPiastres, 0);
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

void Food::takeOne() {
	if (qty > 0)
		qty--;
}
