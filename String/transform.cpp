// transform A to B
// operation allowed: stream through A, insert it at the front if need be

#include <iostream>
#include <string.h>
using namespace std;

bool transformable (string& A, string& B) {
	if (A.length() != B.length())
		return false;
	int count1[256], count2[256];
	memset(count1, 0, sizeof(count1));
	memset(count2, 0, sizeof(count2));
	for (int i = 0; i < A.length(); i++)
		count1[A[i]]++;
	for (int i = 0; i < B.length(); i++)
		count2[B[i]]++;
	for (int i = 0; i < 256; i++)
		if (count1[i] != count2[i])
			return false;
	return true;
}

int minOps (string& A, string& B) {
	if (A == B)
		return 0;
	int count = 0;
	while (A != B) {
		int len = A.length();
		for (int i = len - 1; i >= 0; i--) {
			while (A[i] != B[i]) {
				char c = B[i]; 
				// to do the only operation that is allowed
				B.erase(B.begin() + i); 
				B.insert(B.begin(), c);
				// to increase the count as we do the operation
				count++;
			}
		}
	}
	return count;
}

int main () {
	string A = "EACBD";
	string B = "EBACD";
	cout << boolalpha << transformable(A, B) << endl;
	if (transformable(A, B))
		cout << minOps(A, B) << endl;
	return 0;
}