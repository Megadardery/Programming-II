#ifndef _FOOD_H
#define _FOOD_H
#include<string>

class Food
{
    public:
        Food();
        Food(std :: string n, double p , int q = 10);
        virtual ~Food();
        friend class VMachine;
    protected:
        double price;
        std :: string name;
        int qty;
};

#endif // _FOOD_H
