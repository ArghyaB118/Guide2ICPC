/*
Useful resources: 
https://leetcode.com/discuss/general-discussion/1072418/Disjoint-Set-Union-(DSU)Union-Find-A-Complete-Guide
https://cp-algorithms.com/data_structures/disjoint_set_union.html
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, char> parents;

void __init__(vector<char> &v) {
	for (auto &ch : v)
		parents[ch] = ch;
}

// go up the tree in the parent list
// until you find the node that is its own parent.
char find (char u) {
	if (parents[u] == u)
		return u;
	return find(parents[u]);
}

// make v u's parent.
void combine (char u, char v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return;
	parents[u] = v;
}

void __print__() {
	for (auto &p : parents)
		cout << p.first << " " << p.second << endl;
}

/* Optimization: try to minimize the chain length for find
	by calculating the chain length of u and v. 
	Use the shorter chain's parent to the longer chain's parent.

	Worst case chain length iimproves from O(n) to O(log n).*/

unordered_map<char, char> parentsA;
unordered_map<char, int> depthsA;

void __initA__(vector<char> &v) {
	for (auto &ch : v) {
		parentsA[ch] = ch;
		depthsA[ch] = 1;
	}
}

char findA (char u) {
	if (parentsA[u] == u)
		return u;
	return findA(parentsA[u]);
}

void combineA (char u, char v) {
	u = findA(u);
	v = findA(v);
	if (u == v)
		return;
	else if (depthsA[u] > depthsA[v]) {
		parentsA[v] = u;
		return;
	}
	else if (depthsA[u] <= depthsA[v]) {
		parentsA[u] = v;
		if (depthsA[v] == depthsA[u])
			depthsA[v]++;
		return;
	}
}

void __printA__() {
	for (auto &p : parentsA)
		cout << p.first << " " << p.second << " " << depthsA[p.first] << endl;
}

/* Optimization 2: Shorten the path for find 
	by linking the node to the direct parent node with depth 0
	for everyone in the search path.*/

char findB (char u) {
	if (parentsA[u] == u)
		return u;
	return parentsA[u] = findA(parentsA[u]);
}


int main () {
	vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	__init__(v);
	cout << find('c') << endl;
	combine('c', 'd');
	cout << find('c') << endl;
	combine('c', 'e');
	__print__();

	__initA__(v);
	combineA('c', 'd');
	combineA('c', 'e');
	__printA__();

	return 0;
}