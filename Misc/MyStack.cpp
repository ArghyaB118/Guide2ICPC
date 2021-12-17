#include <iostream>
#include <stack>
using namespace std;

struct MyStack {
	stack<int> s;
	int minElt;

	void printMin() {
		if (s.empty())
			cout << "Stack is empty" << endl;
		else
			cout << "Minm element is: " << minElt << endl;
	}

	void peek () {
		int t = s.top();
		t < minElt ? cout << (2*t - minElt) << endl : cout << t << endl;
	}

	// If we push a new min element x, we store minElt = x
	// we store in the stack 2*x - minElt
	void push (int x) {
		if (s.empty()) {
			s.push(x); minElt = x;
		}
		else {
			if (x < minElt) {
				minElt = x; s.push(2*x - minElt);
			}
			else {
				s.push(x);
			}
		}
	}


	// If the element y pops out, where y < minElt
	// we modify minElt = 2*minElt - y 
	void pop () {
		if (!s.empty()) {
			int t = s.top();
			if (t < minElt) {
				s.pop(); minElt = 2*minElt - t;
			}
			else {
				s.pop();
			}
		}
	}
};


int main () {
	MyStack s;
    s.push(3);
    s.push(5);
    s.printMin();
    s.push(2);
    s.push(1);
    s.printMin();
    s.pop();
    s.printMin();
    s.pop();
    s.peek();
	return 0;
}