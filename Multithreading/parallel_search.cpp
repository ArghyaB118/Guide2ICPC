// https://www.geeksforgeeks.org/linear-search-using-multi-threading/
#include <iostream>
#include "time.h"
#include "pthread.h"
using namespace std;

#define max_length 16
#define max_thread 4
#define item_range 100

int current_thread = 0;
struct thread_data {
	vector<int> arr;
	int key;
};

void* threadSearch (void* input) {
	int num = current_thread++;	
	int thread_length = max_length / max_thread;
	struct thread_data *args = (struct thread_data *) input;
	for (int i = num * thread_length; i < (num + 1) * thread_length; i++)
		if (args->arr[i] == args->key)
			cout << "found" << endl;
}

int main () {
	srand(time(0));
	struct thread_data *arguments = (struct thread_data *)malloc(sizeof(struct thread_data));
	for (int i = 0; i < max_length; i++) {
		int num = rand() % item_range;
		arguments->arr.push_back(num);
	}
	arguments->key = 69;
	cout << arguments->arr.size() << endl;

	for (auto& i : arguments->arr)
		cout << i << " ";
	cout << endl;

	pthread_t thread[max_thread];
	for (int i = 0; i < max_thread; i++) {
		pthread_create(&thread[i], NULL, &threadSearch, (void *)&arguments);
    }
    for (int i = 0; i < max_thread; i++) {
        pthread_join(thread[i], NULL);
    }

	return 0;
}