#include <iostream>
using namespace std;

int main() {
	int f_s = 111, f_d = 99;
	int maxm = max(f_s, f_d);
	int minm = min(f_s, f_d);
	cout << maxm << " " << minm << endl;
	int count = 0, i = minm + 1;
	bool has_zero = false;
	while (i <= maxm) {
		cout << i << endl;
		while (i > 0) {
			// if (i % 10 == 0) {
			// 	has_zero = true;
			// }
			i = i / 10;
			cout << i << endl;
		}
		if (has_zero)
			count++;
		i++;
	}
	cout << count << endl;
	return 0;
}