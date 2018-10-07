#include <iostream>
#include <cstring>

using namespace std;

void military_time(char*);

int main() {
	char input[16];
	cout << "Enter a time in the format \"HH:MM AM\" or \"HH:MM PM\"" << endl;
	cin.getline(input, 15);

	cout << "The military equivilant time is: ";
	military_time(input);
	cout << input;
}

void military_time(char* str) {
	char ap, m;
	int hour, minute;
	sscanf(str, "%d : %d %c%c", &hour, &minute, &ap, &m);
	m = tolower(m), ap = tolower(ap);

	//the last letter must be m, the one before it must be either a or p.
	if (m != 'm' || (ap != 'a' && ap != 'p')) {
		strcpy(str, "Invalid Input\n");
		return;
	}
	//if it is 12 AM or it is PM but not 12
	if ((ap == 'p') != (hour == 12))
		hour += 12;
	hour %= 24;
	sprintf(str, "%02d%02d hours\n", hour, minute);
}

