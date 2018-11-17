#ifndef _VM_WRAPPER_H
#define _VM_WRAPPER_H
#include <iostream>
#include "VendingMachine.h"
class VM_Wrapper
{
public:
	VM_Wrapper(VendingMachine& vm, std::ostream &out, std::istream &in); // acts like the screen which the user interacts with it
	void showMenu();

protected:
	Money inputMoney(Food item, Money mon = Money());
	int getFood();

	std::ostream& out;
	std::istream& in;
	VendingMachine& vm;
};

#endif
