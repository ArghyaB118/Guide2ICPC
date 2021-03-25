#include <iostream>
#include <string.h>

using namespace std;

void countSort(char arr[]) {
	cout << arr << endl;
	char output[strlen(arr)];
	int count[256];
	memset(count, 0, sizeof(count));
	for (int i = 0; i < strlen(arr); i++)
		count[arr[i]]++;
	for (int i = 1; i < 256; i++)
		count[i] += count[i - 1];
	for (int i = 0; i < strlen(arr); i++) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	cout << output << endl;
}

int main() {
	char arr[] = "geeksforgeeks";
	countSort(arr);
	return 0;
}