#include <iostream>
#include "pthread.h"
using namespace std;

#define max_length 16
#define max_thread 4
#define item_range 100

vector<int> arr(max_length);
vector<int> sum(max_thread);

struct thread_data {
	int thread_id;
	vector<int> arr;
};
struct thread_data thread_data_array[max_thread];

pthread_mutex_t myMutex;

void* myAdd (void* input) {
	int thread_length = max_length / max_thread;
	int unit_sum = 0;
	struct thread_data *args = (struct thread_data *) input;
	cout << (int)args->thread_id << endl;
	pthread_mutex_lock(&myMutex);
	for (int i = args->thread_id * thread_length; i < (args->thread_id + 1) * thread_length; i++)
		unit_sum += arr[i];
	pthread_mutex_unlock(&myMutex);
	cout << unit_sum << endl;
	
}

void* myAdd2 (void* input) {
	int thread_length = max_length / max_thread;
	int unit_sum = 0;
	struct thread_data *args = (struct thread_data *) input;
	cout << (int)args->thread_id << endl;
	for (int i = args->thread_id * thread_length; i < (args->thread_id + 1) * thread_length; i++)
		unit_sum += arr[i];
	cout << unit_sum << endl;
	sum[(int)args->thread_id] = unit_sum;
}

int main () {
	srand(time(0));
	struct thread_data *arguments = (struct thread_data *)malloc(sizeof(struct thread_data));
	for (int i = 0; i < max_length; i++) {
		int num = rand() % item_range;
		arr[i] = num;
	}

	cout << arr.size() << endl;
	for (auto& i : arr)
		cout << i << " ";
	cout << endl;

	pthread_t thread[max_thread];
	pthread_mutex_init(&myMutex,0);

	for (int i = 0; i < max_thread; i++) {
		thread_data_array[i].thread_id = i;
		pthread_create(&thread[i], NULL, &myAdd2, (void *) &thread_data_array[i]);
	}

	for (int i = 0; i < max_thread; i++)
		pthread_join(thread[i], NULL);
	
	pthread_mutex_destroy(&myMutex);

	for (auto& i : sum)
		cout << i << " ";
	cout << endl;
	return 0;
}
