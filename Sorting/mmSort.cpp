// Problem: Sorting the M&M's according to rainbow
#include <iostream>
#include <string.h>
#include <map>
using namespace std;
#define COLORS "bgyor"

void printmap(map<char,int> mmCount) {
	map<char,int> ::iterator itr;
	for (itr = mmCount.begin(); itr != mmCount.end(); ++itr)
		cout << itr->first << '\t' << itr->second << endl;
}


void mmSort(char arr[], map<char,int> mmCount) {
	map<char,int> ::iterator itr;
	for (int i = 0; i < strlen(arr); i++)
		for (itr = mmCount.begin(); itr != mmCount.end(); ++itr)
			if (itr->first == arr[i]) {
				itr->second = itr->second + 1;
			}
	printmap(mmCount);
	char output[strlen(arr)];
	int i = 0, j = 0;
	while (i < strlen(COLORS)) {
		for (itr = mmCount.begin(); itr != mmCount.end(); ++itr) {
			if (itr->first == COLORS[i]) {
				while (itr->second > 0) {
					output[j] = COLORS[i]; itr->second--; j++;
					if (j == strlen(arr))
						output[j] = '\0';
				}
			}
		}
		i++;
	}
	cout << output << endl;
}

int main() {
	char arr[] = "rrbbroyybbbggyorr";
	map<char,int> mmCount;
	for (int i = 0; i < strlen(COLORS); i++)
		mmCount.insert(pair<char,int> (COLORS[i],0));
	printmap(mmCount);
	mmSort(arr, mmCount);
	return 0;
}
