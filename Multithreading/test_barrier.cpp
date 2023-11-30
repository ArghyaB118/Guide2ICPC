// https://www.bogotobogo.com/cplusplus/multithreading_pthread.php
#include <iostream>
#include <vector>
#include <pthread.h>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

int max_thread = 5;
pthread_barrier_t b;
vector<int> thread_id;

void* task (void* param) {
    int* id = (int*) param;
    // printf("before the barrier %d\n", *id);
    cout << "before " << *id << endl;
    pthread_barrier_wait(&b);
    // printf("after the barrier %d\n", *id);
    cout << "after " << *id << endl;
}

int main() {
    pthread_t thread[max_thread];
    pthread_barrier_init(&b, 0, max_thread);
    for (int i = 0; i < max_thread; i++) {
        thread_id.push_back(i);
    }
    for (int i = 0; i < max_thread; i++) {
        pthread_create(&thread[i], NULL, &task, (void *) &thread_id[i]);
    }
    for(int i = 0; i < max_thread; i++)
        pthread_join(thread[i], 0);
    pthread_barrier_destroy(&b);
    return 0;
}