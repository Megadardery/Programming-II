#ifndef _MONEY_H
#define _MONEY_H


class Money
{
    public:
        Money();
        virtual ~Money();
        friend class VMachine;
    protected:
        double value ;
        int quantity;
    private:
};

#endif // _MONEY_H
