#include "VendingMachine.h"
#include<iostream>
VendingMachine::VendingMachine()
{

}
VendingMachine::VendingMachine(Food* items, const Money& initialCoins)
{
	for (int i = 0; i < MAX_ITEMS; ++i)
		this->items[i] = items[i];

	coins = initialCoins;
}
bool VendingMachine::convertMoneyRecurse(int qty, int taken, int i, Money& ans) const
{
	if (i == -1) return qty == 0;
	const int coinValue = Money::CoinValue[i];

	if (qty >= coinValue && taken < coins[i]) {
		if (convertMoneyRecurse(qty - coinValue, taken + 1, i, ans)) {
			if (ans[i] == 0)
				ans[i] = taken + 1;
			return 1;
		}
	}
	if (convertMoneyRecurse(qty, 0, i - 1, ans)) {
		if (ans[i] == 0)
			ans[i] = taken;
		return 1;
	}
	return 0;
}

bool VendingMachine::convertMoney(int curr, Money& ans) const
{
	ans = Money(0);
	return convertMoneyRecurse(curr, 0, Money::COIN_COUNT - 1, ans);
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

Money VendingMachine::getMoney() const
{
	return coins;
}
