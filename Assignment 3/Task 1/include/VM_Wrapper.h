#ifndef _VM_WRAPPER_H
#define _VM_WRAPPER_H
#include <iostream>
#include "VendingMachine.h"
class VM_Wrapper
{
public:
	VM_Wrapper(VendingMachine& vm, std::ostream &out, std::istream &in);
	void showMenu();

protected:
	Money inputMoney(Food item, Money mon = Money());
	int getFood();

	std::ostream& out;
	std::istream& in;
	VendingMachine& vm;
};

#endif