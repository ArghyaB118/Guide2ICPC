#include <iostream>
#include "pthread.h"
using namespace std;

#define max_thread 4

struct thread_data {
	int thread_id;
};
struct thread_data thread_data_array[max_thread];

void* myprint (void* input) {
	struct thread_data *args = (struct thread_data *) input;
	cout << args->thread_id << endl;
	// cout << i << endl;
}

void* myMutexF (void* params) {
	cout << (int*)params << endl;
}

int main () {
	pthread_t thread[max_thread];
	for (int i = 0; i < max_thread; i++) {
		thread_data_array[i].thread_id = i;
		pthread_create(&thread[i], NULL, &myprint, (void *) &thread_data_array[i]);
	}

	for (int i = 0; i < max_thread; i++)
		pthread_join(thread[i], NULL);

	pthread_t thread1, thread2, thread3;
	pthread_mutex_t myMutex;
	int one = 1, two = 2, three = 3;
	pthread_mutex_init (&myMutex, 0);

	pthread_create(&thread1, 0, &myMutexF, (void *) &one);
    pthread_create(&thread2, 0, &myMutexF, (void *) &two);
    pthread_create(&thread3, 0, &myMutexF, (void *) &three);
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    pthread_join(thread3, 0);
	pthread_mutex_destroy(&myMutex);
	
	return 0;
}
