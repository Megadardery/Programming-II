#include "VMachine.h"

VMachine::VMachine()
{

}
VMachine::VMachine(Food* it , Money* co)
{
    for (int i = 0 ; i<MAX_ITEMS ; ++i)
        items[i] = it[i];
    for (int i = 0 ; i<MAX_COINS ; ++i)
        coins[i] = co[i];
}
bool VMachine ::  convertMoney(double curr , Money* ans)
{

        //TODO: BELAL
}
bool VMachine :: buyItem(int idx,Money* source , Money* rem)
{
    //TODO : DRDR
}
