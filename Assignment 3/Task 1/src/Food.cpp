#include "Food.h"
#define max(a,b) ((a)>(b)? (a) : (b))
Food::Food()
{
    qty = price = 0 ;
    name = "";
}
Food::Food(std :: string n , double p , int q)
{
    qty = max(q,0);
    price = max(p,0) ;
    name = n;
}

Food::~Food()
{

}
