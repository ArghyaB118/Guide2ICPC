// https://www.geeksforgeeks.org/longest-path-in-a-directed-acyclic-graph-dynamic-programming/
// DFS
// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int u, int v);
	int longestPath();
	void DFS(int s, bool *visited, int *dp);
};

Graph::Graph (int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge (int u, int v) {
	adj[u].push_back(v);
}

void Graph::DFS(int s, bool *visited, int *dp) {
	visited[s] = true;
	list<int>::iterator i; 
	for (i = adj[s].begin(); i != adj[s].end(); ++i) {
        if (!visited[*i])
            DFS(*i, visited, dp);
    	dp[s] = max(dp[s], 1 + dp[*i]);
	}
}


int Graph::longestPath() {
	int *dp = new int[V]; memset(dp, 0, sizeof *dp);
	bool *visited = new bool[V]; memset(visited, false, sizeof *visited);
	for (int i = 0; i < V; i++) {
		if (!visited[i])
			Graph::DFS(i, visited, dp); 
	}
	for (int i = 0; i < V; i++)
		cout << dp[i] << endl;
	return 0;
}


int main() {
	Graph g(4);
	g.addEdge(0, 1); g.addEdge(0, 2);
	g.addEdge(1, 2); g.addEdge(2, 0);
	g.addEdge(2, 3); g.addEdge(3, 3);
	cout << g.longestPath() << endl;
	return 0;
}