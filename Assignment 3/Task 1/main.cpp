#include <iostream>
#include "VendingMachine.h";
using namespace std;
Money inputMoney(Food item, Money mon = Money()) {
	Money value = mon;

	cout << "Allowed Coins:\n";
	for (int i = 0; i < Money::COIN_COUNT; i++) {
		cout << i + 1 << " - " << Money::CoinNames[i] << endl;
	}
	cout << "0 - Stop entering coins\n";
	int idx;
	while (true) {
		cout << "Which coin are you going to push next? (0 - 9) : ";
		cin >> idx;
		while (idx < 0 || idx >= Money::COIN_COUNT) {
			cout << "Please enter a valid choice (0 - 9) : ";
			cin >> idx;
		}
		if (idx == 0) break;
		value[idx - 1]++;
	} 
	char response;
	int entered = value.getTotalValue();
	while (true) {
		if (entered < item.getPrice()) {
			cout << "You entered " << entered / 100.0 << " pounds, which is not enough for "
				<< item.getName() << " ( " << item.getPrice() / 100.0 << " pounds )\n";
			cout << "Do you want to enter more money (y/n)";
			cin >> response;
			if (response == 'y')
				return inputMoney(item, value);
			else if (response == 'n')
				return Money();
			else
				cout << "Invalid response\n";
		}
		else {
			cout << "You entered " << entered / 100.0 << " pounds. Do you confirm (y/n)";
			cin >> response;
			if (response == 'y')
				return value;
			else if (response == 'n') {
				cout << "Operation restarted\n";
				return inputMoney(item);
			}
			else {
				cout << "Invalid response\n";
			}
		}
	}	
}
int getFood(VendingMachine vm) {
	cout << "Allowed Items : \n";
	for (int i = 0; i < VendingMachine::MAX_ITEMS; i++) {
		Food curr = vm.getItem(i);
		if (curr.getQuantity() <= 0) continue;
		cout << i + 1 << " - " << curr.getName() << " for " <<curr.getPrice()/100.0 << " pounds\n";
	}
	cout << "0 - Stop the program\n";
	int idx;
	while (true) {
		cout << "Which item do you want to purchase (0 - 10) : ";
		cin >> idx;
		while (idx < 0 || idx >= VendingMachine::MAX_ITEMS) {
			cout << "Please enter a valid choice (0 - 10) : ";
			cin >> idx;
		}
		if (idx == 0) return 0;
		return idx - 1;
	}
}
int main()
{
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
	Money change(30);
	change[TWO_HUNDREDS] = 0;
	change[HUNDREDS] = 10;
	
	cout << "Machine Inital Money: " << change.getTotalValue() << endl;
	VendingMachine vm(items, change);
	int choice;
	while (true) {
		choice = getFood(vm);
		if (choice == 0) {
			cout << "Thanks for using our Vending Machine!\n";
			return 0;
		}
		if (vm.getItem(choice).getQuantity() <= 0)
			cout << "Out of stock :( Please choose another item.\n";
		else
			break;
	}
	while (true) {

		Money src = inputMoney(vm.getItem(choice));
		Money rem;
		BuyResult result = vm.buyItem(choice, src, rem);
		if (result == BuyResult::NoChangeAvailable)
			cout << "Sorry, the machine doesn't have enough change for you. Please take money and enter exact amount.\n";
		else if (result == BuyResult::Successful) {
			cout << "Here is your item :)\n";
			break;
		}
	}
	


	return 0;
}
