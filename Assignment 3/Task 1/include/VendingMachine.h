#ifndef _VMACHINE_H
#define _VMACHINE_H
#include "Food.h"
#include "Money.h"
// enum to simulate the case of the result and different errors that may occur
enum class BuyResult {
	Successful,
	NotEnoughMoney,
	OutOfStock,
	NoChangeAvailable,
	NotAvailable
};

class VendingMachine
{
public:
	const static int MAX_ITEMS = 10; // maximum number of items that the machine can hold
	VendingMachine();
	VendingMachine(Food* items, const Money& initialCoins); // gives the machine array of available items and currencies and their quantities
	BuyResult buyItem(int idx, const Money& src, Money& rem); // buying item that takes the required item and the buyer's money and remainder which will come back to the buyer
	const Food& getItem(int idx);
	Money getMoney() const; // returns the current machine money
protected:
	Food items[MAX_ITEMS]; // current items in the machine
	Money coins; // current coins in the machine

private:
	bool convertMoney(int curr, Money& ans) const; // calls the second function but with different parameters
	bool convertMoneyRecurse(int, int, int, Money&) const; // by recursion calculates the change and puts it in the last parameter

};

#endif // _VMACHINE_H
