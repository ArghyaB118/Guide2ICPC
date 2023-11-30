/*
You're having a grand old time clicking through the rabbit hole 
that is your favorite online encyclopedia.
The encyclopedia consists of N different web pages, 
numbered from 1 to N. Each page 
i contains nothing but a single link to a different page L_i.

A session spent on this website involves beginning on one of the 
N pages, and then navigating around using the links until 
you decide to stop. That is, while on page i, 
you may either move to page L_i, or stop your browsing session.
Assuming you can choose which page you begin the session on, 
what's the maximum number of different pages you can visit 
in a single session? Note that a page only counts once 
even if visited multiple times during the session.
*/

#include <iostream>
#include <unordered_set>
#include <map>
#include <queue>
#include <utility>
using namespace std;

int getMaxVisitableWebpages(int N, vector<int> L) {
	int res = 0;
	queue<int> chain;
	unordered_set<int> chainElements;
	map<int, int> chainLength;
	for (int i = 1; i <= N; i++) {
		int item = i;
		if (chainLength.find(i) != chainLength.end())
			continue;
		else {
			chain = {};
			chainElements.clear();
			while (chainElements.find(item) == chainElements.end()) {
				if (chainLength.find(item) != chainLength.end()) {
					while (!chain.empty()) {
						chainLength.insert({chain.front(), chain.size() + chainLength[item]});
						chain.pop();
					}
					break;
				}
				chain.push(item);
				chainElements.insert(item);
				item = L[i - 1];
			}
			while (!chain.empty()) {
				chainLength.insert({chain.front(), chain.size()});
				chain.pop();
			}
		}
	}
	for (auto& c : chainLength) {
		cout << c.first << " " << c.second << endl;
		res = max(res, c.second);
	}
	return res;
}

// Idea:
// 1. Ignores the starting points already part of a chain
// 2. Memorizes the precomputed results
// Some wrong resultrs, some timed out.
int getMaxVisitableWebpages2(int N, vector<int> L) {
  	int res = 0;
  	unordered_set<int> chain;
  	map<int, int> chainLength;
  	vector<bool> isVisited (N, false);
	for (int i = 1; i <= N; i++) {
		if (!isVisited[i - 1]) {
			chain.clear();
			int item = i; // cout << item << endl;
			int length_i = 0;
			while (chain.find(item) == chain.end()) {
				if (chainLength.find(item) != chainLength.end()) {
					length_i = (int)chain.size() + chainLength[item];
					break;
				}
				chain.insert(item);
				isVisited[item - 1] = true;
				item = L[item - 1];
				length_i++;
			}
			chainLength.insert({i, length_i});
			res = max(res, length_i);
			if (res == N)
				return res;
		}
	}
  	return res;
}

int getMaxVisitableWebpagesOldImproved(int N, vector<int> L) {
  	int res = 0;
  	unordered_set<int> chain;
  	vector<bool> isVisited (N, false);
	for (int i = 1; i <= N; i++) {
		if (!isVisited[i - 1]) {
			chain.clear();
			int item = i; // cout << item << endl;
			while (chain.find(item) == chain.end()) {
				chain.insert(item);
				isVisited[item - 1] = true;
				item = L[item - 1];
			}
			res = max(res, (int)chain.size());
			if (res == N)
				return res;
		}
	}
  	return res;
}

int getMaxVisitableWebpagesOld(int N, vector<int> L) {
  	int res = 0;
  	unordered_set<int> chain;
	for (int i = 1; i <= N; i++) {
		chain.clear();
		chain.insert(i);
		int item = L[i - 1];
		chain.insert(item);
		while (chain.find(L[item - 1]) == chain.end()) {
			chain.insert(L[item - 1]);
			item = L[item - 1];
		}
		if (res == N)
			return res;
		res = max(res, (int)chain.size());
	}
  	return res;
}

int main () {
	cout << getMaxVisitableWebpages(5, {2, 4, 2, 2, 3}) << " "
		<< getMaxVisitableWebpages2(5, {2, 4, 2, 2, 3}) << " "
		<< getMaxVisitableWebpagesOldImproved(5, {2, 4, 2, 2, 3}) << " "
		<< getMaxVisitableWebpagesOld(5, {2, 4, 2, 2, 3}) << endl;
	return 0;
}