// https://www.geeksforgeeks.org/multithreading-in-cpp/
#include <iostream>
#include <thread>
#include "time.h" // for sleeping and time
#include <unistd.h> // for usleep
using namespace std;


/* Way 1: Use function pointers */
void foo_dont_wait (int x) {
	cout << "input: " << x << endl;
}

void foo_wait (int x, int w) {
	usleep(w);
	cout << "input: " << x << endl;
}

class Base {
private:
	vector<int> v;
public:
	Base (vector<int> &arr) {
		for (int &i : arr)
			this->v.push_back(i);
	}
	/* Way 3: Use static member function
		Observation: has to be public
		does not require a class object to be invoked
		cannot have a vector referenced as input 
		cannot call non-static members, 
		such as private members of the class */
	static void foo_static (int x, int w) {
		usleep(w);
		cout << "input: " << x << endl;
		// Wrong: cout << "input: " << x << " size: " << this->v.size() << endl;
	};

	/* Way 4: Use non-static member function 
		Observation: requires a class object 
		can call non-static members easily
		by making it a class object, even private */
	void foo_non_static (int x, int w) {
		usleep(w);
		cout << "input: " << x << " size: " << this->v.size() << endl;
	}
};

/* Way 5: Using function objects */
class Base2 {
public:
	void operator()(int x) {
		cout << "input: " << x << endl;
	}
};


int main () {
	thread th1(foo_dont_wait, 1);
	thread th2(foo_dont_wait, 2);
	th1.join();	
	th2.join();

	thread th3(&foo_wait, 3, 1);
	thread th4(&foo_wait, 4, 2);
	th3.join();	
	th4.join();

	// can pass the name of the function as well
	thread th3a(foo_wait, 3, 1);
	thread th4a(foo_wait, 4, 2);
	th3a.join();	
	th4a.join();


	/* Way 2: Use lambda expressions */
	auto f = [](int x, int w) {
		usleep(w);
		cout << "input: " << x << endl;
	};
	thread th4b(f, 100, 5);
	th4b.join();

	thread th5(foo_wait, 5, 1);
	thread th6(foo_wait, 6, 2);
	th5.join();	
	th6.join();

	vector<int> v = {7, 8, 9};
	thread th7(&Base::foo_static, v[0], 1);
	thread th8(&Base::foo_static, v[1], 2);
	thread th9(&Base::foo_static, v[2], 3);
	
	th7.join();
	th8.join();
	th9.join();

	v.push_back(10); v.push_back(11);
	Base b(v);
	/* Skipping this as the member is private.
	for (int &i : v)
		b.v.push_back(i); */
	thread th10(&Base::foo_non_static, &b, v[3], 1);
	thread th11(&Base::foo_non_static, &b, v[4], 2);
	th10.join();
	th11.join();
	
	thread th12(Base2(), 12);
	thread th13(Base2(), 13);
	th12.join();
	th13.join();

	/* Failed attempt: how do we create 
		a number of threads in a parameterized manner?

	vector<thread::id> thread_ids = {};
	thread_ids.push_back(thread::id(th14));
	thread thread_ids[0](&foo_wait, 1, 1);
	thread_ids[0].join(); */

	return 0;
}