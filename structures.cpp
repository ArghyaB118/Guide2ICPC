#include <iostream>
using namespace std;

struct Employee {
	short id;
	int age;
	double wage;
};

struct Company {
	Employee CEO; //example of nested structure
	int numberOfEmpl;
};

void printInfo(Employee emp) {
	cout << "ID:" << emp.id << "\n";
	cout << "Age:" << emp.age << "\n";
	cout << "Wage:" << emp.wage << "\n";
}

Employee getJohn() {
	Employee John = {3, 25, 1500};
	return John;
}

int main() {
	Employee Joe;
	Joe.id = 1; Joe.age = 23; Joe.wage = 2000;
	Employee Frank = {2, 34, 2500};

	printInfo(Joe);
	cout << "\n";
	printInfo(Frank);
    cout << "\n";
    Employee John = getJohn();
    printInfo(John);

    Company myComp = {Joe, 5}
    cout << "The size of Employee" << sizeof(Employee) << "\n";
    return 0;
}
