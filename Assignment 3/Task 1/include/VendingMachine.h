#ifndef _VMACHINE_H
#define _VMACHINE_H
#include "Food.h"
#include "Money.h"

// Coins : 0.25 0.5 1 5 10 20 50 100 200
// 60
//50 20

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
	const static int MAX_ITEMS = 10;
	VendingMachine();
	VendingMachine(Food* items, const Money& initialCoins);
	bool convertMoney(int curr, Money& ans) const;
	BuyResult buyItem(int idx, const Money& src, Money& rem);
	const Food& getItem(int idx);
protected:
	Food items[MAX_ITEMS];
	Money coins;

};

#endif // _VMACHINE_H
