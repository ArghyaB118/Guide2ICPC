// Traveling Salesman Problem (TSP)
// https://www.geeksforgeeks.org/traveling-salesman-problem-tsp-implementation/
#include <iostream>
#include <vector>
using namespace std;
#define V 4


// This is to get the TSP from a graph.
// The graph is complete.
int tsp (int graph[V][V], int s) {
	vector<int> vertex;
	for (int i = 0; i < V; i++)
		if (i != s)
			vertex.push_back(i);
	int min_path = INT_MAX;
	do {
		int current_path = 0, k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_path += graph[s][vertex[i]];
			k = vertex[i];
		}
		current_path += graph[k][s];
		min_path = min(min_path, current_path);
	}
	while (next_permutation(vertex.begin(), vertex.end()));
	return min_path;
}

int tsp (int graph[V][V], int path_length, int cost, int currPos) {
	if (path_length == n)
		return min(ans, cost + graph[currPos][0]);
	for (int i = 0; i < V; i++) {
		
	}
}

int main () {
	int graph[V][V] = {{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
	cout << tsp(graph, 0) << endl;
	return 0;
}