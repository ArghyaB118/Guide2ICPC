#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;
std::mutex mtx;

vector<int> v;

void getAtIdx (int idx, int thread_num) {
	cout << v[idx] << " " << thread_num << endl;
}

void putAtIdx (int idx, int val, int thread_num) {
	lock_guard<mutex> lock(mtx);
	v[idx] = val;
}

void program1(int thread_num) {
	getAtIdx(1, thread_num);
	getAtIdx(3, thread_num);
	putAtIdx(3, 5, thread_num);
	getAtIdx(2, thread_num);
}

void program2(int thread_num) {
	getAtIdx(1, thread_num);
	getAtIdx(2, thread_num);
	putAtIdx(2, 6, thread_num);
	getAtIdx(3, thread_num);
}

int main () {
	v = {1, 2, 3, 4};
	std::thread th1(program1, 1);
	std::thread th2(program2, 2);
	th1.join(); th2.join();
	return 0;
}