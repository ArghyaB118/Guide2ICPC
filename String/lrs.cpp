#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void frequency (vector<int>& v) {
	map<int, int> m;
	for (int i = 0; i < v.size(); i++) {
		if (m.find(v[i]) == m.end())
			m[v[i]] = 1;
		else
			m[v[i]]++;
	}
	for (auto& it : m)
		cout << it.first << " " << it.second << endl;
}


vector<int> hashed_string(string s, int n) {
	vector<int> v; 
	for (int i = 0; i <= s.length() - n; i++) {
		string sub = s.substr(i,i+n); cout << sub << n << endl;
		int num = 0;
		for (int i = 0; i < sub.length(); i++)
			num += int(sub[i]);
		v.push_back(num);
	}
	return v;
}

int main () {
	string s = "abbab";
	vector<int> v;
	for (int i = 1; i <= 1; i++) {//s.length() - 1
		v = hashed_string(s, i);
		frequency(v);
	}
	return 0;
}