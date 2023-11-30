#include <iostream>
#include <vector>
#include <map>
using namespace std;

// For every lookup or insert in the map: O(log n) average
// Overall cost: O(n log n)
vector<int> frequencySortOpt (vector<int>& input) {
    vector<int> result = {};
    map<int, int> m;
    for (auto i : input) {
        if (m.find(i) != m.end())
            m[i]++;
        else
            m[i] = 1;
    }
    for (auto i : m)
        for (int j = 0; j < i.second; j++)
            result.push_back(i.first);
    return result;
}


// extra space used: 3 * N
// uses map, pair, and comparator
bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	if (a.second.second != b.second.second)
		return a.second.second > b.second.second;
	else
		return a.second.first < b.second.first;
}

vector<int> sortvec(map<int, pair<int, int> > M, vector<int> answer) {
	map<int, pair<int,int> >::iterator itr;
	vector<pair<int, pair<int, int> > > A;
	for (auto i : M)
		A.push_back(i);
	sort(A.begin(), A.end(), cmp);
	int index = 0;
	for (auto i : A) {
		for (int j = 0; j < i.second.second; j++) {
			answer[index] = i.first; index++;
		}

	}
	return answer;
} 


vector<int> freqSort(vector<int> listEle) {
	int listEle_size = listEle.size();
	map <int, pair<int,int> > frequency; map<int, pair<int,int> >::iterator itr;
	for (int i = 0; i < listEle_size; i++) {
		bool inserted = false;
		for (itr = frequency.begin(); itr != frequency.end(); ++itr) {
			if (itr->first == listEle[i]) {
				itr->second.second++; inserted = true;
			}
		}
		if (!inserted)
			frequency.insert(pair<int, pair<int, int> > (listEle[i], pair<int, int>(i, 1)));
	}
	for (itr = frequency.begin(); itr != frequency.end(); ++itr)
        cout << itr->first << " " << itr->second.first << " " << itr->second.second << endl;
	vector<int> answer(listEle_size, 0);
	answer = sortvec(frequency, answer);
	return answer;
}


int main() {
	int arr[] = { 20, 40, 26, 25, 40, 20, 40, 20, 40, 25, 20 };
	int listEle_size = sizeof(arr) / sizeof(arr[0]);
    // Array to vector conversion
	vector<int> listEle(arr, arr + listEle_size);
	vector<int> result = freqSort(listEle);

	for (int i = 0; i < listEle_size; i++)
		cout << result[i] << " ";
	cout << endl;
    
    vector<int> input = { 20, 40, 26, 25, 40, 20, 40, 20, 40, 25, 20 };
    vector<int> output = frequencySortOpt (input);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
	return 0;
}
