#include <iostream>
#include <vector>

#include <thread>
#include <mutex>
#include <semaphore.h>
#include <condition_variable>
using namespace std;

#define max_num 20
sem_t semEven, semOdd;

void printOdd () {
	for (int i = 1; i <= max_num; i += 2) {
		sem_wait(&semOdd);
		cout << i << " ";
		sem_post(&semEven);
	}	
}

void printEven () {
	for (int i = 2; i <= max_num; i += 2) {
		sem_wait(&semEven);
		cout << i << " ";
		sem_post(&semOdd);
	}
}

vector<int> v;
std::mutex mtx;

void printOdd2 () {
	for (int i = 1; i < max_num; i += 2) {
		std::unique_lock<std::mutex> lock(mtx);
		v.push_back(i);
		lock.unlock();
	}	
}

void printEven2 () {
	for (int i = 2; i < max_num; i += 2) {
		std::unique_lock<std::mutex> lock(mtx);
		v.push_back(i);
		lock.unlock();
	}
}

// https://medium.com/@its.me.siddh/modern-c-interview-problems-mutex-condition-variable-3b80c6e8d610
int currentNumber = 1;

void printOdd3 () {
	while (true) { 
		std::unique_lock<std::mutex> lock(mtx);
		if (currentNumber > max_num)
			break;
		if (currentNumber % 2 == 1) {
			v.push_back(currentNumber);
			currentNumber++;
		}
	}	
}

void printEven3 () {
	while (true) { 
		std::unique_lock<std::mutex> lock(mtx);
		if (currentNumber > max_num)
			break;
		if (currentNumber % 2 == 0) {
			v.push_back(currentNumber);
			currentNumber++;
		}
	}	
}

std::condition_variable cv;

void printNumbers (int thread_id) {
	while (true) {
		if (currentNumber > max_num)
			break;
		std::unique_lock<std::mutex> lock(mtx);
		if (thread_id % 2 == 0 && currentNumber % 2 == 0 ||
			thread_id % 2 == 1 && currentNumber % 2 == 1) {
			cout << currentNumber << " ";
			currentNumber++;
			cv.notify_all();
		}
		else {
			cv.wait(lock);
		}
	}
}

int main () {
	sem_init(&semOdd, 0, 1);
	sem_init(&semEven, 0, 0);
	
	std::thread thread1(printOdd);
    std::thread thread2(printEven);

    thread1.join();
    thread2.join();

    cout << endl;
    
	std::thread thread3(printOdd2);
    std::thread thread4(printEven2);

    thread3.join();
    thread4.join();

    for (auto& i : v)
    	cout << i << " ";
    cout << endl;
    v.clear();

    std::thread thread5(printOdd3);
    std::thread thread6(printEven3);

    thread5.join();
    thread6.join();

    for (auto& i : v)
    	cout << i << " ";
    cout << endl;

    currentNumber = 1;
    std::thread thread7(printNumbers, 1);
    std::thread thread8(printNumbers, 2);

    thread7.join();
    thread8.join();
    cout << endl;

	return 0;
}