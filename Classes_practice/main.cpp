#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;
const int LEN = 80;
void one_line();
void two_lines();
int count_of_employees = 0;

//enum etype { laborer, secretary, manager, accountant, executive, researcher };
//
//ostream& operator<<(ostream& out, const etype value) {
//	static map <etype, string> strings;
//	if (strings.size() == 0) {
//#define INSERT_ELEMENT(p) strings[p] = #p
//		INSERT_ELEMENT(laborer);
//		INSERT_ELEMENT(secretary);
//		INSERT_ELEMENT(manager);
//		INSERT_ELEMENT(accountant);
//		INSERT_ELEMENT(executive);
//		INSERT_ELEMENT(researcher);
//#undef  INSERT_ELEMENT
//	}
//	return out << strings[value];
//}

class student {
private:
	char school[LEN];
	char degree[LEN];
public:
	void get_edu() {
		cout << "Enter name of education institution: "; cin.ignore(); cin.get(school, LEN);
		cout << "Enter a degree of education: "; cin.ignore(); cin.get(degree, LEN);
	}
	void put_edu() const {
		cout << "Education institution: " << school << endl;
		cout << "Degree of education: " << degree << endl;
	}
};

class date {
	unsigned int month;
	unsigned int year;
	unsigned int day;
public:
	void get_date();
	void show_date()const;
};

class employee {
private:
	int number;
	char name[LEN];
	float salary;
	date date_start;
	//etype post;
public:
	employee(): number(0), salary(0) {}
	employee(int n, float s): number(n), salary(s) {}
	void get_data();
	void put_data()const; 
};

enum periods { hourly, weekly, monthly };

class employee2 {
private:
	double compensation;
	periods period;
public:
	void getdata() {
		cout << "Compensation: "; cin >> compensation;
		cout << "Period (h, w, m): "; 
		char ch; ch = _getche(); cout << endl;
		switch (ch) {
		case 'h': period = hourly; break;
		case 'w': period = weekly; break;
		case 'm': period = monthly; break;
		}
	}
	void putdata() {
		cout << "Compensation: " << compensation << endl;
		cout << "Period: ";
		switch (period) {
		case hourly: cout << "hourly" << endl; break;
		case weekly: cout << "weekly" << endl; break;
		case monthly: cout << "monthly" << endl; break;
		default: cout << "unknown" << endl; break;
		}
	}
};

class manager : private employee, private student, public employee2 {
private:
	char title[LEN];
	double dues;
public:
	void get_data() {
		employee::get_data();
		employee2::getdata();
		cout << "Enter the manager's title: "; cin.ignore(); cin >> title;
		cout << "Enter the sum of dues to the golf club: "; cin >> dues;
		student::get_edu();
		//one_line();
	}
	void put_data() {
		employee::put_data();
		employee2::putdata();
		cout << "Title: " << title << endl;
		cout << "Sum of dues: " << dues << endl;
		student::put_edu();
	}
};

class executive : public manager {
private:
	float annual_bonus;
	unsigned int shares_amount;
public:
	void getdata() {
		manager::get_data();
		cout << "Annual bonus: "; cin >> annual_bonus;
		cout << "Amount of company shares: "; cin >> shares_amount;
	}
	void putdata() {
		manager::put_data();
		cout << "Annual bonus: " << annual_bonus << endl;
		cout << "Amount of company shares: " << shares_amount << endl;
	}
};

class scientist : private employee, private student, public employee2 {
private:
	int pubs;
public:
	void get_data() {
		employee::get_data();
		employee2::getdata();
		cout << "Enter a count of publications: "; cin >> pubs;
		student::get_edu();
		one_line();
	}
	void put_data() {
		employee::put_data();
		employee2::putdata();
		cout << "Count of publications: " << pubs << endl;
		student::put_edu();
	}
};

class laborer : public employee {
	//		========D
	//	-(.)(.)-             it's a gun u know
};

class foreman : public laborer, public employee2 {
private:
	float quotas;
public:
	void get_data() {
		laborer::get_data();
		employee2::getdata();
		cout << "Enter a qoutas: "; cin >> quotas;
	}
	void put_data() {
		laborer::put_data();
		employee2::putdata();
		cout << "Standard: " << quotas;
	}
};

/////////////////////////////////////////////////////////////////////////////////////////
int main() {
	manager m1;
	scientist s1;
	laborer l1;
	foreman f1;
	executive e1;

	e1.getdata();
	e1.putdata();
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////

void employee::get_data() {
	count_of_employees++;
	cout << "Enter the employee " << count_of_employees << " number: ";
	cin >> number;
	cout << "Enter the employee " << count_of_employees << " name: ";
	cin.ignore(); cin.get(name, LEN);
	cout << "Enter the employee " << count_of_employees << " salary: ";
	cin >> salary;
	cout << "Enter the employee " << count_of_employees << " start day ";
	date_start.get_date();
	/*cout << "Enter the employee " << count_of_employees << " post's first letter: ";
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
	} while (check != 1);*/
	//one_line();
}

void employee::put_data()const {
	two_lines();
	cout << "Number: " << number << endl;
	cout << "Name: " << name << endl;
	cout << "Salary: " << salary << " $" << endl;
	cout << "Start date: "; date_start.show_date(); cout << endl;
	//cout << "Post: " << post << endl;
	//two_lines();
}

void date::get_date() {
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