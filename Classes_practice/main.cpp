#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <map>

using namespace std;
void one_line();
void two_lines();
int count_of_employees = 0;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

ostream& operator<<(ostream& out, const etype value) {
	static map <etype, string> strings;
	if (strings.size() == 0) {
#define INSERT_ELEMENT(p) strings[p] = #p
		INSERT_ELEMENT(laborer);
		INSERT_ELEMENT(secretary);
		INSERT_ELEMENT(manager);
		INSERT_ELEMENT(accountant);
		INSERT_ELEMENT(executive);
		INSERT_ELEMENT(researcher);
#undef  INSERT_ELEMENT
	}
	return out << strings[value];
}


class date {
	unsigned int month;
	unsigned int year;
	unsigned int day;
public:
	void getdate();
	void show_date()const;
};

class employee {
private:
	int number;
	float salary;
	date date_start;
	etype post;
public:
	employee(): number(0), salary(0) {}
	employee(int n, float s): number(n), salary(s) {}
	void add_emp();
	void show_emp()const; 
};

/////////////////////////////////////////////////////////////////////////////////////////
int main() {
	employee e1, e2, e3;
	e1.add_emp();
	e2.add_emp();
	e3.add_emp();
	e1.show_emp();
	e2.show_emp();
	e3.show_emp();
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////

void employee::add_emp() {
	count_of_employees++;
	cout << "Enter the employee " << count_of_employees << " number: ";
	cin >> number;
	cout << "Enter the employee " << count_of_employees << " salary: ";
	cin >> salary;
	cout << "Enter the employee " << count_of_employees << " start day ";
	date_start.getdate();
	cout << "Enter the employee " << count_of_employees << " post's first letter: ";
	char first_letter, check=0;
	do {
		first_letter = _getche();
		switch (first_letter) {
		case 'l': post = laborer; check = 1; break;
		case 's': post = secretary; check = 1; break;
		case 'm': post = manager; check = 1; break;
		case 'a': post = accountant; check = 1; break;
		case 'e': post = executive; check = 1; break;
		case 'r': post = researcher; check = 1; break;
		default: cout << "\nIncorrect letter! Try again."; break;
		}
		cout << endl;
	} while (check != 1);
	one_line();
}

void employee::show_emp()const {
	two_lines();
	cout << "Number: " << number << endl;
	cout << "Salary: " << salary << " $" << endl;
	cout << "Start date: "; date_start.show_date(); cout << endl;
	cout << "Post: " << post << endl;
	//two_lines();
}

void date::getdate() {
	char ch;
	do {
		cout << "(format dd/mm/yyyy): ";
		cin >> day >> ch >> month >> ch >> year;
		if (day > 31 || day == 0 || month == 0 || month > 12 || year == 0) {
			ch = 0;
			cout << "Incorrect date! Try again." << endl;
		}
		else ch = 1;
	} while (ch != 1);
}

void date::show_date()const {
	if (day < 10) cout << 0;
	cout << day << "/";
	if (month < 10) cout << 0;
	cout << month << "/" << year;
}

void one_line() {
	for (int i = 0; i < 75; i++) cout << "-";
	cout << endl;
}

void two_lines() {
	for (int i = 0; i < 75; i++) cout << "=";
	cout << endl;
}