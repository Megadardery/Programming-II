#ifndef _VMACHINE_H
#define _VMACHINE_H
#include "Food.h"
#include "Money.h"

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
	BuyResult buyItem(int idx, const Money& src, Money& rem);
	const Food& getItem(int idx);
	Money getMoney() const;
protected:
	Food items[MAX_ITEMS];
	Money coins;

private:
	bool convertMoney(int curr, Money& ans) const;
	bool convertMoneyRecurse(int, int, int, Money&) const;

};

#endif // _VMACHINE_H