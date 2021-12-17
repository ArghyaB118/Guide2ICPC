// Assumption: There is only one possible choice

#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
typedef pair<int, int> prerequisite;

list<int> *adj;
map<int, bool> visited;

void DFS(int s) {
    visited[s] = true; // Mark the current node as visited and print it
    cout << s << " ";    
    list<int>::iterator i; // Recur for all the vertices adjacent to this vertex
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

void orderOfCourses (vector<prerequisite> prerequisites, int num_courses) {
	for (int i = 0; i < prerequisites.size(); i++)
		adj[prerequisites[i].first].push_back(prerequisites[i].second);

	for (int i = 0; i < num_courses; i++) {
		visited.clear(); DFS(i);
		if (visited.size() == num_courses)
			break;
	}

}


int main() {
	int num_courses = 3;
	vector<prerequisite> prerequisites{ make_pair(0,2), make_pair(1,2), make_pair(0,1) }; 
	orderOfCourses(prerequisites, num_courses);
	return 0;
}