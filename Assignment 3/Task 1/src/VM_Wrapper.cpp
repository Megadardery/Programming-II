#include "VM_Wrapper.h"
VM_Wrapper::VM_Wrapper(VendingMachine & vm, std::ostream & out, std::istream & in)
	: in(in), out(out), vm(vm)
{
}

void VM_Wrapper::showMenu()
{
	using std::endl;

	while (true) {
		out << endl;
		int choice;
		while (true) {
			choice = getFood();
			if (choice == -1) {
				out << "Thanks for using our Vending Machine!\n";
				return;
			}
			if (vm.getItem(choice).getQuantity() <= 0)
				out << "Out of stock :( Please choose another item.\n";
			else
				break;
		}

		Money src = inputMoney(vm.getItem(choice));
		if (src.getTotalValue() == 0) continue;
		Money rem;
		BuyResult result = vm.buyItem(choice, src, rem);
		if (result == BuyResult::NoChangeAvailable) {
			out << "Sorry, the machine doesn't have enough change for you. Please take money and enter exact amount.\n";
			out << "In the coin dispenser: " << rem << endl;
		}
		else if (result == BuyResult::Successful) {
			out << "Here is your item :)\n";
			out << "In the coin dispenser: " << rem;
		}

	}
}

Money VM_Wrapper::inputMoney(Food item, Money mon)
{
	using std::endl;

	Money value = mon;

	out << "Allowed Coins:\n";
	for (int i = 0; i < Money::COIN_COUNT; i++) {
		out << i + 1 << " - " << Money::CoinNames[i] << endl;
	}
	out << "0 - Stop entering coins\n";
	int idx;
	while (true) {
		out << "Which coin are you going to push next? (0 - 9) : ";
		in >> idx;
		while (idx < 0 || idx > Money::COIN_COUNT) {
			out << "Please enter a valid choice (0 - 9) : ";
			in >> idx;
		}
		if (idx == 0) break;
		value[idx - 1]++;
	}
	char response;
	int entered = value.getTotalValue();
	while (true) {
		if (entered < item.getPrice()) {
			out << "You entered " << entered / 100.0 << " pounds, which is not enough for "
				<< item.getName() << " ( " << item.getPrice() / 100.0 << " pounds )\n";
			out << "Do you want to enter more money (y/n): ";
			in >> response;
			if (response == 'y')
				return inputMoney(item, value);
			else if (response == 'n') {
				out << "In the coin dispenser: " << value << endl;
				return Money();
			}
			else
				out << "Invalid response\n";
		}
		else {
			out << "You entered " << entered / 100.0 << " pounds. Do you confirm (y/n): ";
			in >> response;
			if (response == 'y')
				return value;
			else if (response == 'n') {
				out << "Operation restarted\n";
				out << "In the coin dispenser: " << value << endl;
				return inputMoney(item);
			}
			else {
				out << "Invalid response\n";
			}
		}
	}

}

int VM_Wrapper::getFood()
{
	out << "Allowed Items : \n";
	for (int i = 0; i < VendingMachine::MAX_ITEMS; i++) {
		Food curr = vm.getItem(i);
		if (curr.getQuantity() <= 0) continue;
		out << i + 1 << " - " << curr.getName() << " for " << curr.getPrice() / 100.0 << " pounds\n";
	}
	out << "0 - Stop the program\n";
	int idx;
	while (true) {
		out << "Which item do you want to purchase (0 - 10) : ";
		in >> idx;
		while (idx < 0 || idx > VendingMachine::MAX_ITEMS) {
			out << "Please enter a valid choice (0 - 10) : ";
			in >> idx;
		}
		return idx - 1;
	}
}
