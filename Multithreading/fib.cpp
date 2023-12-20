#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

int fib (int n) {
	if (n == 1 || n == 2) { 
		return 1;
	}
	return fib(n - 1) +	fib(n - 2);
}

std::mutex mtx;
void fib2 (vector<int> &dp, int n) {
	for (int i = 0; i < n; i++) {
		if (dp[i] != 0)
			continue;
		else if (i == 0 || i == 1) {
			std::lock_guard<std::mutex> lock(mtx);
			dp[i] = 1;
		}
		else {
			std::lock_guard<std::mutex> lock(mtx);
			dp[i] = dp[i - 2] + dp[i - 1];
		}
	}
}

int main () {
	int n = 4;
	cout << fib(n) << endl;
	// cannot return the values
	std::thread th1(fib, n - 1);
	std::thread th2(fib, n - 2);
	th1.join(); th2.join();

	vector<int> dp(n, 0);
	thread th3(fib2, std::ref(dp), n);
	thread th4(fib2, std::ref(dp), n);
	th3.join(); th4.join();
	cout << dp[n - 1] << endl;
	return 0;
}