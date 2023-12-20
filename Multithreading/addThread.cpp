#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;
std::mutex mtx;

void mySum (int start_idx, int end_idx, vector<int> &v, int &sum) {
	for (int i = start_idx; i <= end_idx; i++) {
		lock_guard<mutex> lock(mtx);
		sum += v[i];
	}
}

int main () {
	int sum = 0;
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	std::thread th1(mySum, 0, 3, std::ref(v), std::ref(sum));
	std::thread th2(mySum, 4, 7, std::ref(v), std::ref(sum));
	th1.join();
	th2.join();
	cout << sum << endl;
	return 0;
}