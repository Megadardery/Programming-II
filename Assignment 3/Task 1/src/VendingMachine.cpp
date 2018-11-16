#include "VendingMachine.h"

VendingMachine::VendingMachine()
{

}
VendingMachine::VendingMachine(Food* items, const Money& initialCoins)
{
	for (int i = 0; i < MAX_ITEMS; ++i)
		this->items[i] = items[i];
	
	coins = initialCoins;
}
bool VendingMachine::convertMoney(int curr, Money& ans) const
{

	//TODO: BELAL
	return 0;
}
BuyResult VendingMachine::buyItem(int idx, const Money& src, Money& rem)
{
	if (idx < 0 || idx >= MAX_ITEMS)
		return BuyResult::NotAvailable;

	Food& item = items[idx];

	if (item.getQuantity() <= 0)
		return BuyResult::OutOfStock;

	int change = src.getTotalValue() - item.getPrice();
	if (change < 0)
		return BuyResult::NotEnoughMoney;

	coins += src;
	if (!convertMoney(change, rem)) {
		rem = src;
		coins -= src;
		return BuyResult::NoChangeAvailable;
	}
	coins -= rem;
	item.takeOne();
	return BuyResult::Successful;
}

const Food& VendingMachine::getItem(int idx)
{
	return items[idx];
}
