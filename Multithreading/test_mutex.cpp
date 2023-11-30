// https://www.bogotobogo.com/cplusplus/multithreading_pthread.php
#include <iostream>
#include "pthread.h"
#include <unistd.h>
using namespace std;

volatile int counter = 0;
pthread_mutex_t myMutex;

void *mutex_testing(void *param)
{
        int i;
        for(i = 0; i < 5; i++) {
                pthread_mutex_lock(&myMutex);
                counter++;
                // std::cout << (int*)param << " " << counter << std::endl;
                printf("thread %d counter = %d\n", (int*)param, counter);
                pthread_mutex_unlock(&myMutex);
        }
}

void *mutex_testing2(void *param)
{
        int i;
        for(i = 0; i < 5; i++) {
                counter++;
                usleep(1);
                printf("thread %d counter = %d\n", (int*)param, counter);
        }
}

int main()
{
        int one = 1, two = 2, three = 3;
        pthread_t thread1, thread2, thread3;
        pthread_mutex_init(&myMutex,0);
        pthread_create(&thread1, 0, &mutex_testing2, (void *) one);
        pthread_create(&thread2, 0, &mutex_testing2, (void *) two);
        pthread_create(&thread3, 0, &mutex_testing2, (void *) three);
        pthread_join(thread1, 0);
        pthread_join(thread2, 0);
        pthread_join(thread3, 0);
        pthread_mutex_destroy(&myMutex);
        return 0;
}