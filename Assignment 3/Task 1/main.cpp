#include <iostream>
#include "VM_Wrapper.h"
using namespace std;
int main()
{
    // array that contains the items and the price of each one and the quantity is 10 by default
	Food items[] = {
		Food("Rocket Coke",3.5),
		Food("Schweppes",6.0),
		Food("Golden Goose",12.75),
		Food("Mist Twst",7.0),
		Food("Moro",5.0),
		Food("Vanilla Ice",5.5),
		Food("Ice Coffee",8.0),
		Food("Pepsi Can",4.5),
		Food("Chocolate Bar",7.25),
		Food("Eat Yo Money",15.0)
	};
    // making the quantity of each banknote by 3 then changing some quantities
	Money change(3);
	change[TWO_HUNDREDS] = 0;
	change[HUNDREDS] = 1;
	change[FIFTIES] = 4;

	cout << "Machine Inital Money: " << change.getTotalValue() << endl;
	cout << change << endl;
	VendingMachine vm(items, change); // making new machine of the current items and money

	VM_Wrapper wrapper(vm, cout, cin); // simulating the machine functions by another class

	wrapper.showMenu();
	change = vm.getMoney();
	cout << "Machine money now: " << change.getTotalValue() << endl;
	cout << change << endl;

	return 0;
}
