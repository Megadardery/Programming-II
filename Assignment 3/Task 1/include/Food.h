#ifndef _FOOD_H
#define _FOOD_H
#include<string>

class Food
{
public:
	Food();
	Food(std::string n, int priceInPiastres, int q = 10); // takes the name of the item and the price and the quantity (default 10 as required)
	Food(std::string n, double priceInPounds, int q = 10);
	int getPrice() const;
	std::string getName() const;
	int getQuantity() const;
	void takeOne(); // buying one item of this item if it available
protected:
	int price;
	std::string name;
	int qty;
};

#endif // _FOOD_H
