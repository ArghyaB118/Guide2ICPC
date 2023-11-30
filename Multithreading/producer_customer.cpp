/* LC#1188

Implement a thread-safe bounded blocking queue that has the following methods:

BoundedBlockingQueue(int capacity) 
The constructor initializes the queue with a maximum capacity.
void enqueue(int element) Adds an element to the front of the queue. 
If the queue is full, the calling thread is blocked until the queue is 
no longer full.
int dequeue() Returns the element at the rear of the queue and removes it. 
If the queue is empty, the calling thread is blocked until the queue is 
no longer empty.
int size() Returns the number of elements currently in the queue.

Your implementation will be tested using multiple threads at the same time. 
Each thread will either be a producer thread that only makes calls 
to the enqueue method or a consumer thread that only makes calls 
to the dequeue method. 
The size method will be called after every test case.

Please do not use built-in implementations of bounded blocking queue as this will not be accepted in an interview.
*/
#include <iostream>
#include <queue>
#include <vector>

#include <thread>
#include <mutex>
#include <condition_variable>
#include <semaphore.h>
using namespace std;

vector<int> arr = {1, 2, 3, 4, 5, 6};

queue<int> q;
mutex mtx;
condition_variable unfull, unempty;
int n, count;

void enqueue(int element) {
    unique_lock<mutex> lock(mtx);
    unfull.wait(lock, []{ return count < n; });
    q.push(element);
    count++;
    unempty.notify_one();
}
    
int dequeue() {
    unique_lock<mutex> lock(mtx);
    unempty.wait(lock, []{ return count > 0; });
    int v = q.front();
    q.pop();
    count--;
    unfull.notify_one();
    return v;
}
    
//int size() {
//    lock_guard<mutex> lock(mtx);
//    return count;
//}

void thread_enqueue () {
    for (int i = 0; i < arr.size(); i++)
        enqueue(arr[i]);
}

void thread_dequeue () {
    for (int i = 0; i < arr.size(); i++)
        cout << dequeue() << endl;
}

sem_t unempty2, unfull2;
void enqueue2 () {
    for (int i = 0; i < arr.size(); i++) {
        sem_wait(&unfull2);
        // sem_wait(&mtx); 
        q.push(arr[i]); 
        // sem_post(&mtx);
        sem_post(&unempty2);
    }
}

void dequeue2 () {
    for (int i = 0; i < arr.size(); i++) {
        sem_wait(&unempty2);
        // sem_wait(&mtx); 
        cout << q.front() << endl;
        q.pop(); 
        // sem_post(&mtx);
        sem_post(&unfull2);
    }
}

int main () {
    // std::thread thread1(thread_enqueue);
    // std::thread thread2(thread_dequeue);
    // thread1.join(); thread2.join();
    sem_init(&unfull2, 0, n);
    sem_init(&unempty2, 0, 0);
    // sem_init(&mtx, 0, 1);
    std::thread thread1(enqueue2);
    std::thread thread2(dequeue2);
    thread1.join(); thread2.join();
    return 0;
}