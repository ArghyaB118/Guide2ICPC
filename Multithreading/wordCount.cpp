#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

unordered_map<string, int> dict;
mutex mtx;

void wordCount (vector<string> &s, int start_idx, int end_idx) {
	for (int i = start_idx; i <= end_idx; i++) {
		lock_guard<mutex> lock(mtx);
		if (dict.find(s[i]) != dict.end())
			dict[s[i]]++;
		else
			dict[s[i]] = 1;
	}
} 

void printHashmap () {
	for (auto &i : dict)
		cout << i.first << " " << i.second << endl;
}

int main () {
	vector<string> s = {"this", "is", "a", "test", "this", "is", "not", "a", "test"};
	wordCount(s, 0, 8);
	printHashmap();
	dict.clear();

	thread th1(wordCount, std::ref(s), 0, 3);
	thread th2(wordCount, std::ref(s), 4, 8);
	th1.join(); th2.join();
	printHashmap();
	
	return 0;
}