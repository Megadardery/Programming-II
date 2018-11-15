#ifndef _VMACHINE_H
#define _VMACHINE_H
#include "Food.h"
#include "Money.h"

// Coins : 0.25 0.5 1 5 10 20 50 100 200
// 60
//50 20
class VMachine
{
public:
    const static int MAX_ITEMS = 10 ;
    const static int MAX_COINS = 9 ;
    VMachine();
    VMachine(Food* , Money*);
    bool convertMoney (double , Money*);
    bool buyItem(int ,Money* , Money*);
protected:
    Food items[MAX_ITEMS];
    Money coins[MAX_COINS];

};

#endif // _VMACHINE_H
