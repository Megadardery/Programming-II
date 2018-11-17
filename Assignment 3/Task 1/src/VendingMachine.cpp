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
bool VendingMachine::convertMoney(int curr, Money& ans) const
{
    int tmpcurr;
    bool flag = true ,startflag = false;
    for (int start = 0 ; flag && start<ans.COIN_COUNT ; ++start)
    {
        tmpcurr = curr;
        Money tmpans = ans;
        for (int i = start ; (i%ans.COIN_COUNT)!=start || !startflag ; ++i)
        {
            startflag = true;
            i%=ans.COIN_COUNT;
            const int& val = tmpans.CoinValue[i];
            int& qty = tmpans[i];
            int newqty = tmpcurr/val;
            if (newqty>qty)
            {
                newqty = qty;
                qty = 0;
            }
            else
            {
                qty-=newqty;
            }
            tmpcurr-= (newqty*val);
            flag = tmpcurr;

        }
        startflag =0;
        if (!flag)
        {
            //To print the change if needed
           std :: cout << "Here is your change : "<<std :: endl;
            for (int i = 0 ; i<ans.COIN_COUNT ; ++i)
            {
                int val = ans.CoinValue[i] - tmpans.CoinValue[i];
                int q = ans[i] - tmpans[i];
                std :: cout << val << " " << q << std :: endl;
            }
            ans = tmpans;
            return 1;
        }
    }
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
