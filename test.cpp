#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
	public:
		string m_name; int m_age;
		string getname() const { return m_name; };
		int getage() const { return m_age; }
		Person(string name = "", int age = 0)
			: m_name(name), m_age(age)
		{}
};

class Employee : public Person {
	public: 
		double m_hourlysalary; long m_employeeid;
		Employee(double hourlysalary = 0, long employeeid = 0)
			: m_hourlysalary(hourlysalary), m_employeeid(employeeid)
		{}
		void printNameAndSalary() const
		{
			cout << m_name << ":" << m_hourlysalary << "\n";
		}
};

void func (int *n) {
	cout << n << " " << *n << " " << ++(*n) << " " << &n << endl;
}


void test(int* x){
    *x *= 2;
}

int main () {
	int a = 5;
	cout << typeid(a).name() << endl;
	vector<int> b{1,2};
	cout << typeid(b).name() << endl;
	int n = 0;
	func(&n);

	Employee frank(20.25, 123);
	frank.m_name = "Frank";
	frank.printNameAndSalary();

	int a  = 6;
    int *p = &a;
    test(p);
    printf("%d\n", *p);
    
	return 0;
}