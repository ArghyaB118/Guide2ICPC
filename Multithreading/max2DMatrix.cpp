// https://www.geeksforgeeks.org/maximum-in-a-2d-matrix-using-multi-threading-in-cpp/
#include <iostream>
#include <pthread.h>
#include "unistd.h"

using namespace std;

typedef vector<vector<int>> container;
container c;
vector<int> thread_ids;
vector<int> thread_max;
int key;

void* linear_search (void* params) {
	int* thread_id = (int*)params;
	int num_row = *thread_id;
	cout << num_row << endl;
	int num_cols = c[num_row].size();
	for (int i = 0; i < num_cols; i++) {
		if (c[num_row][i] == key)
			cout << "found" << endl;
	}
}

struct container2 {
	int thread_id;
	int key;
};

void* linear_search2 (void* params) {
	struct container2* inputs = (struct container2 *) params;
	cout << inputs->key << " " << inputs->thread_id << endl;
	int num_cols = c[inputs->thread_id].size();
	for (int i = 0; i < num_cols; i++) {
		if (c[inputs->thread_id][i] == inputs->key)
			cout << "found" << endl;
	}
}

int main () {
	c = {{1, 2, 3}, {2, 3, 4}};
	key = 5;
	int max_thread = c.size();
	for (int i = 0; i < max_thread; i++) {
		thread_ids.push_back(i);
		thread_max.push_back(0);
	}

	pthread_t thread[max_thread];
	for (int i = 0; i < max_thread; i++)
		pthread_create(&thread[i], NULL, &linear_search, (void*) &thread_ids[i]);
	for (int i = 0; i < max_thread; i++)
		pthread_join(thread[i], NULL);
	sleep(1);

	// Induces error as we pass the onject c2 as reference.
	// now if we change the value c2.thread_id, 
	// eventually, both the threads access the same value.
	container2 c2;
	c2.key = 4; c2.thread_id = 0;
	pthread_t thread2[max_thread];
	for (int i = 0; i < max_thread; i++) {
		c2.thread_id = i; cout << c2.thread_id << endl;
		pthread_create(&thread2[i], NULL, &linear_search2, (void*) &c2);
	}
	for (int i = 0; i < max_thread; i++)
		pthread_join(thread2[i], NULL);

	return 0;
}