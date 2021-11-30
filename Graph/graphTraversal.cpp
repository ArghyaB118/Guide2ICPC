#include <iostream>
#include <list>
#include <queue>
#include <map>
using namespace std;

class Graph {
	int V; // Number of vertices
	list<int> *adj; // Pointer to edges
public:
	Graph(int V); // Constructor
	void addEdge(int u, int v); // Function to add an edge from node u to v
	void BFS(int s); // BFS traversal from a given source s
	void DFS(int s); // DFS traversal from a given source s
	map<int, bool> visited;
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
	adj[u].push_back(v); // Add node u to node v’s adjacency list
}

// Cost = O(V + E) = O(n ^ 2)
void Graph::BFS(int s) {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	queue<int> q; // A queue for BFS
	visited[s] = true; // Mark the node already visited
	q.push(s);

	list<int>::iterator i; // 'i' iterate over all adjacent nodes of a node

	while (!q.empty()) {
		s = q.front(); // Dequeue a vertex from queue and print it
		cout << s << " ";
		q.pop();

		// Get all adjacent vertices of the dequeued node s.
		// If an adjacent node has not been visited,
		// mark it visited and enqueue it.
		for (i = adj[s].begin(); i != adj[s].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				q.push(*i);
			}
		}
	}
}

// Cost = O(V + E) = O(n ^ 2)
void Graph::DFS(int s) {
    visited[s] = true; // Mark the current node as visited and print it
    cout << s << " ";

    list<int>::iterator i; // Recur for all the vertices adjacent to this vertex
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.BFS(2);
	g.visited.clear(); g.DFS(2);
	return 0;
}

